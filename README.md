# Sudoku Game in C++

A professional, console-based implementation of the classic Sudoku puzzle, written in modern C++ (C++17).

## Features

- **Modular OOP Architecture**: Clear separation of concerns between board representation, backtracking solver, game coordinator, and optional modules.
- **Interactive Gameplay**:
  - Load puzzles from local text files.
  - Save current games to resume later.
  - User input validation (integer check, range validation).
  - Move verification according to Sudoku rules.
- **Automatic Solver**: Instantly completes the puzzle using a backtracking search algorithm.
- **Puzzle Generator (Optional)**: Generate new unique puzzles of various difficulties.
- **Advanced Logic Hints (Optional)**: Identify locked candidates and naked pairs.

## File Structure

- `SudokuBoard.hpp` / `SudokuBoard.cpp`: Grid representation and file operations.
- `SudokuSolver.hpp` / `SudokuSolver.cpp`: Backtracking solver algorithm.
- `SudokuGame.hpp` / `SudokuGame.cpp`: User interaction and game loop.
- `SudokuGenerator.hpp` / `SudokuGenerator.cpp`: Random puzzle generator.
- `SudokuAdvancedChecks.hpp` / `SudokuAdvancedChecks.cpp`: Helper logic for solving hints.
- `main.cpp`: Program entry point.

## Compilation

You can compile this project using `CMake` or standard `make` (if using MinGW/GCC):

### Using Makefile (MinGW)
```bash
mingw32-make
```

### Using CMake
```bash
cmake -S . -B build
cmake --build build
```
