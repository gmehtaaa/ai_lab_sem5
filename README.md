# 8-Puzzle Solver using DFS (C++)

This project solves the classic 8-puzzle problem using **Depth-First Search (DFS)**, implemented in C++ with STL. It allows you to input an initial puzzle state and finds a solution path to the goal configuration.

---

## Problem Statement
Given a 3x3 matrix puzzle with 8 tiles numbered **1–8** and a blank space represented by **0**, the task is to move the blank space around to reach the goal state:

1 2 3
4 5 6
7 8 0


You can move the blank space **up, down, left, or right**, one tile at a time.

---

## Algorithm Used
This implementation uses the **Depth-First Search (DFS)** algorithm. It explores possible puzzle states by moving the blank tile in each valid direction recursively (via a stack), avoiding already visited configurations.

**DFS Characteristics:**
- Uses a **stack (LIFO)**  
- Explores deep paths before backtracking  
- May not always find the shortest solution, but guarantees finding one if it exists  

---

## Implementation Details
- **`is_soln()`** → Checks if current state matches the goal state  
- **`findblank()`** → Locates the blank (0) tile  
- **`genmoves()`** → Generates all valid tile moves (up, down, left, right)  
- **`dfsStack()`** → Handles DFS using an STL stack and avoids revisiting states using a set  

---

## Sample Input Format
You’ll be prompted to enter the puzzle matrix row-wise:

Example input:
1 2 3 4 0 6 7 5 8

This corresponds to:
1 2 3
4 0 6
7 5 8

---

## Example Output
Problem Matrix:
1 2 3
4 0 6
7 5 8

--- Solution Found ---
1 2 3
4 0 6
7 5 8
1 2 3
4 5 6
7 0 8
1 2 3
4 5 6
7 8 0

---

## Use Cases
- Understanding basic search algorithms in AI  
- Building blocks for intelligent puzzle solvers  
- Educational demos for DFS in graph problems  
- Useful for courses in **Artificial Intelligence** or **Game Theory**  

---

## To Compile and Run
```bash
g++ dfs8puzzle.cpp -o dfs8puzzle
./dfs8puzzle


