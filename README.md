# Freenit

Freenit is a minimalist, high-performance init system written in C++. It is engineered for users who demand absolute control over PID 1 and wish to eliminate the bloat associated with modern, monolithic initialization frameworks.

## Architecture

Freenit follows the KISS (Keep It Simple, Stupid) principle. It serves as the primary system process, responsible for spawning essential user-space processes and reaping orphaned child processes (zombies).

## Key Features

* Minimal Footprint: No heavy dependencies, standard library minimalism, and low memory overhead.
* Static Binary: Built for portability and ease of deployment across various Linux distributions.
* Deterministic Behavior: Predictable process lifecycle management without hidden abstractions.
* Graceful Shutdown: Handles termination signals to ensure system integrity during power-off or reboot.

## Technical Specifications

| Feature | Description |
| :--- | :--- |
| Language | C++20 |
| PID | 1 (Init) |
| Dependency | None (Static) |
| Build Tool | Makefile |

## Building from Source

To compile the project, ensure you have g++ and make installed on your system.

# Clone the repository

git clone https://github.com/Minish777/freenit.git
cd freenit

# Compile the binary
make

## Installation

To deploy Freenit as your system init:

1. Copy the binary to /sbin/:
   sudo make install

2. Update your bootloader (e.g., GRUB) configuration to pass the following kernel parameter:
   init=/sbin/freenit

3. Reboot your system.

## Philosophy

Freenit is not just an init system; it is a declaration of independence from unnecessary system complexity. It is designed for those who prefer to build and maintain their own environment from the ground up, prioritizing efficiency and technical transparency.

## License

This project is licensed under the MIT License. See the LICENSE file for details.
