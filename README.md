
<div align="center">

# 🚀 Freenit

**A minimalist, high-performance Linux init system written in modern C++.**

*Small. Fast. Deterministic.*

![C++](https://img.shields.io/badge/C%2B%2B-20-blue.svg?style=for-the-badge&logo=cplusplus)
![Linux](https://img.shields.io/badge/Linux-PID%201-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![License](https://img.shields.io/github/license/Minish777/freenit?style=for-the-badge)
![Repo Size](https://img.shields.io/github/repo-size/Minish777/freenit?style=for-the-badge)
![Stars](https://img.shields.io/github/stars/Minish777/freenit?style=for-the-badge)
![Issues](https://img.shields.io/github/issues/Minish777/freenit?style=for-the-badge)

</div>

---

# About

**Freenit** is a lightweight Linux init system implemented in **C++20**.

Designed around the **KISS (Keep It Simple, Stupid)** philosophy, Freenit focuses exclusively on what an init system should do:

- Start essential user-space processes
- Manage PID 1 responsibilities
- Reap orphaned child processes (zombies)
- Handle clean shutdowns

No service manager.

No dependency resolver.

No daemon framework.

No unnecessary complexity.

---

# Features

- ⚡ Extremely small memory footprint
- 🚀 Fast startup
- 📦 Fully static binary (optional)
- 🔒 No runtime dependencies
- 🧹 Automatic zombie process reaping
- 🧠 Deterministic process lifecycle
- 🛡️ Graceful reboot and shutdown handling
- 🐧 Compatible with Linux kernels supporting custom init
- 🔧 Easy to modify and extend

---

# Why Freenit?

Modern init systems often evolve into complete operating system frameworks.

Freenit intentionally does **not**.

Its goal is to remain a simple, understandable PID 1 implementation that gives full control back to the user.

If you prefer building your own environment instead of relying on large initialization suites, Freenit is designed for you.

---

# Architecture

```
        Linux Kernel
              │
              ▼
         PID 1 (Freenit)
              │
      ┌───────┴────────┐
      │                │
 Spawn Processes   Reap Zombies
      │                │
      └───────┬────────┘
              ▼
        User-space Services
```

---

# Technical Specifications

| Property | Value |
|-----------|-------|
| Language | C++20 |
| PID | 1 |
| Platform | Linux |
| Dependencies | None |
| Build System | Make |
| License | MIT |

---

# Building

## Requirements

- g++
- make

Clone the repository:

```bash
git clone https://github.com/Minish777/freenit.git
cd freenit
```

Build:

```bash
make
```

---

# Installation

Install the binary:

```bash
sudo make install
```

Configure your bootloader (for example, GRUB) to use Freenit as PID 1:

```text
init=/sbin/freenit
```

Reboot your system.

---

# Project Structure

```
freenit/
├── src/
├── include/
├── Makefile
├── LICENSE
└── README.md
```

---

# Responsibilities

As PID 1, Freenit is responsible for:

- Initializing the userspace environment
- Launching configured processes
- Reaping orphaned child processes
- Handling SIGTERM, SIGINT and shutdown events
- Performing graceful system termination

Nothing more.

Nothing less.

---

# Philosophy

> "Do one thing and do it well."

Freenit embraces classic UNIX design principles.

Instead of becoming another all-in-one system framework, it focuses on being:

- Minimal
- Predictable
- Transparent
- Efficient

Every line of code exists for a reason.

---

# License

This project is licensed under the **MIT License**.

See the [LICENSE](LICENSE) file for details.

---

<div align="center">

### Built for people who still believe PID 1 should stay simple.

⭐ **If you like the project, consider giving it a star.**

</div>
````
