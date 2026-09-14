# Sudoku Game in C++

A robust, console-based implementation of the classic Sudoku puzzle written in modern C++ (C++17). Designed with clean Object-Oriented Programming (OOP) principles and full separation of concerns between grid representation, backtracking solver, dynamic puzzle generator, and the user interface.

---

## Features

- **Modular OOP Architecture**: Distinct modules for the board, solver algorithm, puzzle generator, and game coordinator.
- **Interactive Gameplay**:
  - Clean ASCII board rendering using `.` for empty cells and standard 3×3 grid separators.
  - 1-based indexing for intuitive player coordinates (`row: 1-9`, `col: 1-9`, `val: 1-9`).
  - Strict move validation preventing row, column, or 3×3 box rule violations.
  - Resilient input validation that gracefully handles invalid characters without crashing.
- **Backtracking Solver**:
  - Fast, recursive backtracking solver that completes puzzles in milliseconds or detects unsolvable boards.
- **Dynamic Puzzle Generator (Bonus Feature)**:
  - Generates valid Sudoku boards on the fly across three difficulty levels: **Easy**, **Medium**, and **Hard**.
  - Employs randomized backtracking to ensure each puzzle has a single, unique solution.
- **File I/O**:
  - Save current games to local `.txt` files to resume later.
  - Load custom puzzles directly into the grid.

---

## Project Structure

```text
Sudoku-Project/
├── CMakeLists.txt              # CMake build configuration
├── Makefile                    # Makefile for mingw32-make (MinGW-W64)
├── README.md                   # Project documentation
├── .gitignore                  # Git ignore rules for build artifacts
├── include/                    # Header files (.hpp)
│   ├── SudokuBoard.hpp         # 9×9 Board representation, validation & file I/O
│   ├── SudokuSolver.hpp        # Recursive backtracking solver
│   ├── SudokuGame.hpp          # Console UI, input handling & game loop
│   └── SudokuGenerator.hpp     # Dynamic puzzle generator with uniqueness check
├── src/                        # Source files (.cpp)
│   ├── SudokuBoard.cpp
│   ├── SudokuSolver.cpp
│   ├── SudokuGame.cpp
│   ├── SudokuGenerator.cpp
│   └── main.cpp                # Application entry point
└── puzzles/                    # Sample puzzle text files
    └── sample_puzzle.txt       # Standard 9×9 test puzzle
```

---

## Compilation & Building

This project can be compiled with **MinGW GCC (`g++`)** via `Makefile` or with **CMake**.

### Option 1: Using Makefile (Recommended for MinGW)

Run the following command in the project root:

```bash
mingw32-make
```

To remove generated object files and executable:
```bash
mingw32-make clean
```

### Option 2: Using CMake

```bash
cmake -S . -B build
cmake --build build
```

---

## How to Play

Run the compiled executable:

```powershell
.\SudokuProject.exe
```

Upon launching, the current 9×9 board is displayed alongside the interactive menu:

```text
5 3 .  | . 7 .  | . . . 
6 . .  | 1 9 5  | . . . 
. 9 8  | . . .  | . 6 . 
------------------------
8 . .  | . 6 .  | . . 3 
4 . .  | 8 . 3  | . . 1 
7 . .  | . 2 .  | . . 6 
------------------------
. 6 .  | . . .  | 2 8 . 
. . .  | 4 1 9  | . . 5 
. . .  | . 8 .  | . 7 9 
------------------------
1) Enter a move
2) Solve automatically
3) Load puzzle from file
4) Save current puzzle to file
5) Exit
6) [Optional] Generate new puzzle
Choice:
```

### Menu Options:
1. **Enter a move**: Prompts for `row (1-9)`, `column (1-9)`, and `value (1-9)` separated by spaces (e.g., `1 3 4`).
2. **Solve automatically**: Triggers the backtracking algorithm and prints the completed puzzle.
3. **Load puzzle from file**: Loads an external puzzle file (e.g., `puzzles/sample_puzzle.txt`).
4. **Save current puzzle to file**: Writes the current board state to a text file.
5. **Exit**: Gracefully exits the application.
6. **Generate new puzzle**: Generates a new puzzle with chosen difficulty (Easy, Medium, Hard).

---

## File Format for Puzzles

Puzzle files are plain text files containing 81 characters (numbers `1-9` or `.` for empty cells) separated by spaces or newlines. Example:

```text
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```
