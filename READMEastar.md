# A* Pathfinding on a 2D Grid

## Overview
This Python program implements the A* search algorithm to find the shortest path on a 2D grid from a start point to a goal point. The grid contains traversable cells (`1`) and blocked cells (`0`). The algorithm calculates the path with minimum cost while considering diagonal and straight movements.

---

## Features
- **User Input**: Allows custom grid size and start/goal positions.  
- **A* Search Algorithm**: Uses `f(n) = g(n) + h(n)` for optimal pathfinding.  
- **Heuristic Function**: Euclidean distance guides the search efficiently.  
- **Diagonal & Straight Movements**: Supports 8-directional moves with appropriate costs.  
- **Interactive Visualization**: Shows the path on a graphical grid using Tkinter.  
- **Step-by-Step Animation**: Highlights the path dynamically from start to goal.  

---

## How the Algorithm Works

### Heuristic Function (Euclidean Distance)
- Calculates the straight-line distance between the current cell and the goal.  
- Provides an estimate of remaining cost to reach the goal.  

### A* Search (a_star)
1. Start from the initial position.  
2. Maintain a priority queue ordered by `f(n) = g(n) + h(n)`:
   - `g(n)`: cost from start to current node.  
   - `h(n)`: heuristic estimate to goal.  
3. Expand the node with the smallest `f(n)` value.  
4. Generate valid neighboring cells (up, down, left, right, and diagonals).  
5. Continue until the goal node is reached or no path exists.  

### Move Generation
- Checks bounds of the grid and whether the cell is traversable (`1`).  
- Diagonal moves have higher cost (`1.5`) while straight moves cost `1`.  

### Termination
- **Success**: Goal is reached; the path and its cost are returned.  
- **Failure**: No path exists; the algorithm terminates with an indication of failure.  

---

## Use Case
This program is useful for:

Demonstrating A* pathfinding in AI and robotics.

Understanding heuristic-guided search and cost-based exploration.

---

### Run the program
```bash
python a_star_grid.py`
