# 🗣️ get_next_line

**get_next_line** is a project at 42 School that challenges students to create a function capable of reading a text file (or any file descriptor) one line at a time.

The core difficulty lies in handling buffers of varying sizes (`BUFFER_SIZE`) and using **static variables** to "remember" the previous state of the file reading between function calls.

## 🛠️ Features

* **Buffer Management:** Handles variable buffer sizes defined at compilation time.
* **Static Variables:** Uses static storage to persist data (the "stash") across multiple calls.
* **Memory Safety:** Strict management of `malloc` and `free` to ensure zero memory leaks.
* **Multiple FDs:** Capable of managing multiple file descriptors simultaneously (Bonus part).

## 📚 What I Learned

* **Static Variables:** Understanding how static variables in C persist in memory for the lifetime of the program, distinct from local stack variables.
* **File Descriptors:** Deepening knowledge of the `read()` system call and how operating systems handle file offsets.
* **Memory Management:** Implementing safe dynamic memory allocation (`malloc`) and preventing memory leaks using tools like **Valgrind**.
* **Macro Definitions:** Using preprocessor macros to define constants like `BUFFER_SIZE` at compile time.

## 📋 Usage

1.  Include the header in your C file:
    ```c
    #include "get_next_line.h"
    ```

2.  Compile with your source files and the buffer size flag:
    ```bash
    gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
    ```
