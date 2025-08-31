#  Tic-Tac-Toe using Minimax Algorithm  

---

## Problem Statement  
This project implements a **Tic-Tac-Toe** game with the following rules:  
- The board is a **3×3 grid**.  
- The **player plays first** as `X`.  
- The **computer plays second** as `O`.  
- The AI plays **optimally** and never loses.  

---

**Time & Space Complexity**

**Time Complexity**
At most 9! game states.

Minimax explores all possibilities: O(b^d) where:

b = branching factor (≤ 9)

d = depth of game tree (≤ 9)

Worst case: O(9!) ≈ 362,880 states (manageable).

**Space Complexity**
O(d) = O(9) due to recursion depth.

Board state stored globally.

**Use Cases**
Classic demonstration of Minimax algorithm.

Educational tool for game theory & decision-making.

Useful in teaching recursion, backtracking, and adversarial search.

**Learning Outcomes**
Understand how heuristic functions guide search.

Learn hill climbing approach and its drawbacks.

Gain hands-on coding experience with 8-puzzle & game AI problems.
