# Prolog Blocksworld 

This project implements the classic **Blocks World problem** using Prolog, demonstrating a fundamental application of logic programming in automated planning and Artificial Intelligence (AI).

---

## Prolog: An Introduction to Logic Programming

Prolog (PROgramming in LOGic) is a unique programming language based on the principles of first-order logic.

| Aspect | Detail |
|--------|--------|
| Paradigm | Declarative/Logic Programming. Instead of telling the computer how to achieve a result (imperative languages like Python/Java), you tell it what is true (Facts) and what relationships exist (Rules). The Prolog engine figures out the steps (search/inference). |
| Creation | Created around 1972 by Alain Colmerauer and Robert Kowalski at the University of Aix-Marseille. |
| Original Use | Specifically designed for Artificial Intelligence (AI) research, particularly in Natural Language Processing (NLP) and automated theorem proving, aiming to mimic human deductive reasoning. |
| Modern Use | Expert Systems (e.g., medical diagnosis), Natural Language Understanding, Automated Planning (like this problem), Constraint Logic Programming (CLP) for complex scheduling and optimization, and Knowledge Graph databases (e.g., TerminusDB). |
| Unique Niche | Excels at problems where logical constraints, relations, and search are the core challenge. Problems like Sudoku solver, N-Queens puzzle, and complex scheduling/timetabling can be implemented with remarkably little code. Built-in backtracking makes it perfect for combinatorial search problems. |

---

## The Blocks World Problem

The Blocks World is a classic AI problem used to study **automated planning algorithms**.

### Problem Statement
The system simulates a domain with a flat table and a set of cubic blocks (`a`, `b`, `c`). The goal is to find a sequence of actions (a plan) to transform an **initial configuration** of blocks into a **desired goal configuration**.

### State Representation
A state is a list of facts (predicates) that are currently true about the world:

- `ontable(X)`: Block X is directly on the table.
- `on(X, Y)`: Block X is directly on block Y.
- `clear(X)`: Block X has no other block on top of it.
- `holding(X)`: The robot arm is holding block X.
- `holding(none)`: The robot arm is empty.

### Actions (Operators)
The four possible actions, with their Preconditions, Delete Effects, and Add Effects:

| Action | Description | Preconditions | Delete Effects | Add Effects |
|--------|------------|---------------|----------------|-------------|
| `pickup(X)` | Pick up block X from the table. | `clear(X), ontable(X), holding(none)` | `ontable(X), clear(X), holding(none)` | `holding(X)` |
| `putdown(X)` | Put down block X onto the table. | `holding(X)` | `holding(X)` | `ontable(X), clear(X), holding(none)` |
| `unstack(X, Y)` | Pick up block X from block Y. | `on(X, Y), clear(X), holding(none)` | `on(X, Y), clear(X), holding(none)` | `holding(X), clear(Y)` |
| `stack(X, Y)` | Place block X onto block Y. | `holding(X), clear(Y)` | `holding(X), clear(Y)` | `on(X, Y), clear(X), holding(none)` |

---

## Implementation Details and Algorithm

### The Planning Algorithm
The core of the system is **Depth-First Search (DFS)** implemented by the `plan/3` and `search/4` predicates.

- **search(State, Goal, Actions, Plan)**: Recursively tries to find a path from the current `State` to the `Goal`.
- **Actions**: Tracks the plan found so far.
- Uses Prolog's **backtracking** to explore alternative action sequences when a path hits a dead end.

### State Transition
- `applicable(Action, State)`: Checks if all Preconditions of an action are met in the current State.
- `apply(Action, State, NewState)`: Computes the NewState by removing DeleteEffects and adding AddEffects.

### Loop Prevention
- `redundant_move/2` prevents immediate undoing of the last action (e.g., pickup immediately followed by putdown), pruning the search space.

### Depth Limit
- Maximum search depth of 10 moves (`Len < 10`) prevents infinite loops in complex scenarios and ensures termination.

---

### Key Predicates

| Predicate | Arity | Description |
|-----------|-------|------------|
| `plan(Init, Goal, Plan)` | 3 | Top-level predicate that initiates the search. |
| `action(Name, Pre, Del, Add)` | 4 | Defines the mechanics of a single action. |
| `applicable(A, S)` | 2 | True if action A can be executed in state S. |
| `apply(A, S, NS)` | 3 | Calculates the next state NS resulting from action A in state S. |
| `run_tests` | 0 | Executes three predefined test scenarios. |

---

## Sample Input and Output

### Test Query
`?- run_tests. `

#### Expected Output
`Testing simple stacking...
SUCCESS! Plan: [pickup(a),stack(a,b)]`

`Testing tower building...
SUCCESS! Plan: [pickup(a),stack(a,b),pickup(b),stack(b,c)]`

`Testing complex rearrangement...
SUCCESS! Plan: [unstack(b,a),putdown(b),pickup(c),stack(c,b)]`

### How to Run
Copy the entire Prolog code block into any standard Prolog environment (e.g., SWISH, SWI-Prolog, or Tutorialspoint Prolog compiler).

In the Prolog query prompt, enter:

`?- run_tests.`
Press Enter to see the plan for all three scenarios.
