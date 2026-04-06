# LRU Cache System in C++

This project implements a **high-performance LRU (Least Recently Used) Cache** in C++ using a **hash map** and a **doubly linked list** to achieve **O(1) time complexity** for `get` and `put` operations.

The cache keeps track of cache **hits**, **misses**, and **total operations**, providing useful **cache statistics**.

---

## Features
1. **O(1) get and put operations** using HashMap + Doubly Linked List.  
2. Automatic **eviction of least recently used elements** when capacity is full.  
3. **Cache statistics**: Hits, Misses, Hit Rate.  
4. Modular code structure with **separate include and src folders**.  
5. Fully **C++17 compatible**.  

---

## Project Structure
LRUcachesystem/
├── include/
│   └── LRUCache.h            # LRUCache class definition
├── src/
│   ├── LRUCache.cpp          # LRUCache function implementations
│   └── main.cpp              # CLI interface / demo program
├── README.md                 # Project description and usage
└── .gitignore                # Files/folders to ignore in Git



---

## Usage

1. **Compile the project** (from the root folder):
```bash
g++ -std=c++17 -Iinclude src/main.cpp src/LRUCache.cpp -o lru

Run the compiled executable:
./lru       # On Linux/Mac
lru.exe     # On Windows

Commands (interactive CLI)

put <key> <value> → Inserts a key-value pair into the cache.
get <key> → Retrieves the value for a key if present.
stats → Shows cache hits, misses, total operations, and hit rate.
exit → Exits the program.


Example:
Enter capacity:
2
> put 1 10
Inserted
> put 2 20
Inserted
> get 1
Value: 10
> stats
Total Operations: 3
Hits: 1
Misses: 0
Hit Rate: 33.33%
> exit

Aakriti Srivastava – Pre-final Year CSE Student
