# C++ Mini Projects Collection

## Description
This repository contains a collection of C++ applications demonstrating algorithmic logic, data structure manipulation, and command-line interface design. The projects currently included are an **Autonomous Robot Cleaner simulation** using search algorithms and a **Smart Memory Calculator** for state-managed arithmetic operations.

## Projects

### 1. Autonomous Robot Cleaner
A grid-based simulation where a robot navigates a 5x5 room to identify and clean "dirt" tiles.

*   **File:** `robot_cleaner.cpp` (Assumed name)
*   **Key Concepts:**
    *   **Breadth-First Search (BFS):** Used to calculate the distance to target locations.
    *   **Grid Navigation:** Logic to handle 2D arrays, boundaries, and directional movement (Up, Down, Left, Right).
    *   **Greedy Strategy:** The robot attempts to move toward dirty tiles (`d`) starting from the base (`b`).
*   **Output:** The program prints the directional moves the robot takes and announces when a tile is "Clean".

### 2. Smart Memory Calculator
A functional command-line calculator that supports basic arithmetic and features a memory buffer to store results.

*   **File:** `calculator.cpp` (Assumed name)
*   **Key Concepts:**
    *   **Vectors (STL):** used to implement a dynamic memory storage system (capped at 5 slots).
    *   **State Management:** Flags and loops to maintain the program lifecycle until the user turns it off.
    *   **Input Handling:** robust processing of operators, numbers, and custom commands.
*   **Features:**
    *   Basic Operations: `+`, `-`, `*`, `/`
    *   **v**: View current values in memory.
    *   **r**: Reset/Clear memory.
    *   **m**: Manually store a number in memory.
    *   **o**: Turn off the calculator.

## Getting Started

### Prerequisites
To run these programs, you need a C++ compiler installed on your machine (e.g., GCC/G++).

### Compilation & Execution

**1. Robot Cleaner:**
```bash
g++ robot_cleaner.cpp -o robot
./robot
```

**2. Calculator:**
```bash
g++ calculator.cpp -o calculator
./calculator
```

## Usage Examples

**Calculator Commands:**
```text
Enter an operator: +
Enter two numbers: 10 5
Result: 15
Store in memory? (y/n): y
Value stored.

Enter an operator: v
Memory: 15 
```

## Technologies Used
*   **Language:** C++
*   **Libraries:** `<iostream>`, `<vector>`, `<queue>` (Standard Template Library)

---

## Author
sadeepa lakshan 
