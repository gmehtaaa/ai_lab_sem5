# Tic Tac Toe (Magic Square Approach)

## Overview
This project implements a **Human vs. Computer** Tic Tac Toe game in **C++**, using the **Magic Square win-checking method**.  
The computer uses a simple algo that helps to:
1. Wins immediately if possible.
2. Blocks the human’s winning move if necessary.
3. Otherwise, plays the first available move.

This approach is **efficient** and avoids scanning all possible winning lines every time.

---

## Problem Statement
Tic Tac Toe is played on a **3×3 grid**:
- Player **X** (human) and Player **O** (computer) take turns.
- The goal is to be the first to align **three of your symbols** in a row, column, or diagonal.

**Magic Square method** assigns each cell a number so that any winning line sums to **15**.

Magic Square:       Board Positions:
 4 | 9 | 2           1 | 2 | 3
---+---+---         ---+---+---
 3 | 5 | 7           4 | 5 | 6
---+---+---         ---+---+---
 8 | 1 | 6           7 | 8 | 9

---

## Algorithm Used
### **Magic Square Win Detection**
- Each cell is mapped to a **magic square value**.
- A player’s moves are stored as a list of magic square values.
- For each **pair** of moves `(a, b)`:
- needed = 15 - (a + b)
If the needed value corresponds to an empty square, that move completes a win.

---

### **Computer Move Rules**
1. **Win if possible**: If the computer has two moves that sum to less than 15 and the required third cell is free, it plays there.
2. **Block opponent**: If the human can win on their next turn, the computer blocks.
3. **Fallback**: Take the first available cell.

---

## Implementation Details
- **Data Structures Used**:
- `map<int,int>` → stores position → magic square value mapping.
- `vector<char>` → board representation.
- `vector<int>` → moves taken by each player.
- **Functions**:
- `printBoard()` → displays the grid.
- `checkWin()` → checks if a player has already won.
- `canWinNow()` → checks if a winning move is possible this turn.
- `computerMove()` → rule-based move selection.

---

## Sample Input/Output
**Example Gameplay:**
=== Tic Tac Toe (Magic Square Approach) ===
You are X, Computer is O

| |
---+---+---
| |
---+---+---
| |

Enter your move (1-9): 5
Computer chooses: 1
...
Computer wins!

---

## Use Cases
- Demonstrates a **rule-based move selection system** for a classic puzzle.
- Teaches **magic square logic** for efficient win checking.
- Ideal for **educational purposes** in programming or discrete mathematics.
- Can be extended into more advanced strategies.

---

## To Compile and Run
```bash
g++ tictactoe_magic.cpp -o tictactoe
./tictactoe






