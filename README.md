# Magic Square Generator (C++)

## Overview
This C++ program generates a Magic Square of an odd size `n × n`.  
A magic square is a grid where:
- The sum of each row, column, and both diagonals is the same magic constant.
- The numbers `1` to `n²` are arranged without repetition.

The program uses the Siamese Method (De la Loubère’s algorithm) to fill the grid.

## Features
- Works for any odd value of `n`.
- Automatically arranges numbers so that all rows, columns, and diagonals sum to the same number.
- Displays the generated magic square in a clean grid format.

## Algorithm
1. Start with position `(0, n/2)` (first row, middle column).
2. Place numbers from `1` to `n²` in the grid:
   - Move up one row and right one column for the next number.
   - Wrap around if going outside the grid (modulo indexing).
   - If the target cell is already filled, move down one row instead.
3. Continue until all cells are filled.

## Use Case
Magic squares have several interesting applications:
- Mathematics and puzzles: Often used in recreational math problems.
- Tic Tac Toe number trick: A 3×3 magic square can be used so that every winning line sums to the same number.
- Art and architecture: Incorporated into designs (e.g., the Sagrada Familia in Barcelona).
- Cryptography: Certain encryption methods use magic square patterns for scrambling data.
- Game theory: Can be applied in strategy-based games for balanced setups.

## Example Run
Enter an odd number for MagicSquare: 3
Magic square of size 3:
8 1 6
3 5 7
4 9 2


## Notes
- Only odd `n` is supported.
- The magic constant (sum of each row, column, diagonal) is given by:
M = n * (n² + 1) / 2
