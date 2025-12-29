
*This project has been created as part of the 42 curriculum by adkhan*
# Get_Next_Line

**get_next_line** is a project at 42 School that challenges students to create a function capable of reading a text file (or any file descriptor) one line at a time.

The core difficulty lies in handling buffers of varying sizes (`BUFFER_SIZE`) and using **static variables** to "remember" the previous state of the file reading between function calls.

---
## Features

- **Buffer Management:** Handles variable buffer sizes defined at compilation time.
- **Static Variables:** Uses static storage to persist data (the "stash") across multiple calls.
- **Memory Safety:** Strict management of `malloc` and `free` to ensure zero memory leaks.

---
## I. Core Concepts

### 1. The "Stash" (Static Variable)

Standard variables die when a function returns. To implement GNL, we need a variable that "remembers" the data we read but haven't returned yet (the leftovers after the `\n`).

- **The Mechanism:** `static char *stash` (Mandatory) 
- **Memory Location:** Stored in the **Data Segment**, not the Stack. It persists for the program's entire life. 
### 2. The "Buffer" (Heap Allocation)

We read files in chunks (`BUFFER_SIZE`). Because this size is variable (and could be massive), we must allocate the buffer on the **Heap** using `malloc`. Allocating a large buffer on the Stack would cause a Stack Overflow.

### 3. The Algorithm (3-Phase Flow)

The logic follows three distinct phases:

1. **Read & Accumulate:** Keep reading chunks and gluing them to the stash until a newline is found.
2. **Extract:** Copy everything up to the newline into a new string (the return value).
3. **Clean:** Save everything _after_ the newline into a new stash and free the old one.
 
---
## II.Instructions

Include the header in your C file:

  ```c
  #include "get_next_line.h"
  ```
   

Compile with your source files and the buffer size flag:

```shell
gcc main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42
```

---
## III.AI Statement & Resources Used

### AI Statement

AI was used to support brainstorming, gather ideas, and structure concepts. No coding was completed with the assistance of AI.

### Resources & Tools

A myriad of resources were used during this project some of which are listed below.

- Geeks for Geeks [Static Variables in C.](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Valgrind for Testing](https://valgrind.org/)
	- Valgrind was used to test whether the code had memory leaks or not.
- Geeks for Geeks [Storage Classes in C](https://www.geeksforgeeks.org/c/storage-classes-in-c/)
- Education Innovation YouTube [Video on File Descriptors](https://www.youtube.com/watch?v=WCrTRPu1bQk)
- Ariane YouTube [Video on GNL](https://www.youtube.com/watch?v=kR4FyNzVDBE)

