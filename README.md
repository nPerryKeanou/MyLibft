# MyLibft - C Toolbelt 🛠️

This repository serves as my core foundation in C programming. It is a consolidated library gathering several key projects, built to be modular, efficient, and reusable.

> **Note:** This project is my personal training ground for mastering memory management and algorithms. While my current focus is shifting towards **Rust**, I maintain this library to sharpen my understanding of low-level software concepts.

## 📦 Features

The `libft.a` library merges three essential modules:

* **Libft:** A custom implementation of standard `libc` functions (string manipulation, memory management, linked lists).
* **ft_printf:** A custom version of the famous formatting function, handling standard flags (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`).
* **get_next_line:** A robust function that reads and returns a line from a file descriptor (FD), managing buffers and static variables.

## 🚀 Installation & Usage

The project uses an optimized `Makefile` for a clean and fast compilation process.

```bash
# Clone the repository
git clone https://github.com/nPerryKeanou/MyLibft.git && cd MyLibft

# Compile the library (generates libft.a)
make

# Clean object files (.o)
make clean

# Full cleanup and recompilation
make re