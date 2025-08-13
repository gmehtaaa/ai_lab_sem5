# BFS 8-Puzzle Solver

This program solves the classic **8-Puzzle Problem** using **Breadth-First Search (BFS)**.

---

## 📜 Problem Description
The **8-Puzzle Problem** consists of a 3x3 grid with 8 numbered tiles and one blank space (`0`).  
The goal is to move the tiles into the correct order:

1 2 3
4 5 6
7 8 0

You can move the blank (`0`) **up, down, left, or right**.

---

## 🚀 How It Works
This implementation uses **Breadth-First Search (BFS)** to explore all possible configurations of the puzzle until it reaches the goal.

1. **`is_soln`** → Checks if the current state is the goal state.
2. **`findblank`** → Finds the position of the blank (`0`) in the puzzle.
3. **`genmoves`** → Generates all possible moves by swapping the blank with its neighbors.
4. **`bfsQueue`** → Performs BFS using a queue:
   - Keeps track of visited states using a set.
   - Stores the path from the initial state to the solution.
   - Prints the solution sequence when found.

---

## 🖥️ Example Run

**Input:**
Enter the puzzle values (0 for blank), row-wise:
1 2 3
4 5 6
0 7 8

**Output:**
Problem Matrix:
1 2 3
4 5 6
0 7 8

--- Solution Found ---
1 2 3
4 5 6
0 7 8
1 2 3
4 5 6
7 0 8
1 2 3
4 5 6
7 8 0

---

## BFS Logic
- Start with the initial puzzle configuration.
- Use a queue to store `(current_state, path_to_state)`.
- For each state:
  - If it's the goal, print the path.
  - Otherwise, generate valid moves and add them to the queue if not visited.

---

## How to Compile and Run

### **Compile**
```bash
g++ bfs_8puzzle.cpp -o bfs_8puzzle
Run
./bfs_8puzzle


