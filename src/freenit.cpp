#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <signal.h>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <dirent.h>

/**
 * Log messages to the current terminal and a persistent log file.
 */
void log(const std::string& message) {
    // 1. Output to the current terminal (stdout)
    std::cout << "[DEBUG] " << message << std::endl;

    // 2. Duplicate to log file for persistent history
    std::ofstream logfile("/var/log/freenit.log", std::ios::app);
    if (logfile.is_open()) {
        logfile << "[DEBUG] " << message << std::endl;
    }
}

/**
 * Configure system pseudo-filesystems.
 */
void setup_fs() {
    log("Mounting filesystems...");
    mount("none", "/proc", "proc", 0, NULL);
    mount("none", "/sys", "sysfs", 0, NULL);
    mount("none", "/dev", "devtmpfs", 0, NULL);
}

/**
 * Execute startup scripts sequentially from /etc/init.d/.
 */
void run_scripts(const std::string& path) {
    DIR* dir = opendir(path.c_str());
    if (!dir) {
        log("Warning: Could not open init.d directory.");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_name[0] == '.') continue;

        std::string script_path = path + "/" + entry->d_name;
        log("Running script: " + std::string(entry->d_name));

        pid_t pid = fork();
        if (pid == 0) {
            execl(script_path.c_str(), script_path.c_str(), NULL);
            _exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    closedir(dir);
}

/**
 * Signal handler for critical failures.
 */
void signal_handler(int sig) {
    log("CRITICAL: Caught signal " + std::to_string(sig));
    exit(1);
}

int main() {
    // 1. Initialize Signal Handling
    signal(SIGSEGV, signal_handler);
    signal(SIGCHLD, SIG_IGN); // Prevent zombie processes

    log("Freenit starting up (PID: " + std::to_string(getpid()) + ")...");

    // 2. Setup core environment
    setup_fs();
    run_scripts("/etc/init.d");

    log("Boot finished. Starting interactive shell.");
    std::cout << "\n\033[1;32mSystem ready.\033[0m\n" << std::endl;

    // 3. Main shell loop
    while (true) {
        pid_t pid = fork();
        if (pid == 0) {
            // Child process: replace with shell
            char* env[] = {(char*)"PATH=/bin:/sbin:/usr/bin", (char*)"TERM=linux", NULL};
            char* argv[] = {(char*)"/bin/sh", NULL};
            execve("/bin/sh", argv, env);

            log("EXEC FAILED: " + std::string(strerror(errno)));
            _exit(1);
        } else if (pid > 0) {
            // Parent process: wait for the shell to exit
            waitpid(pid, NULL, 0);
        } else {
            log("FORK FAILED: " + std::string(strerror(errno)));
            sleep(1);
        }
    }
    return 0;
}
