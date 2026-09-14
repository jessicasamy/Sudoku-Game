#pragma once

#include "SudokuBoard.hpp"

class SudokuSolver {
public:
    SudokuSolver() = default;

    // Solves the Sudoku board using recursive backtracking.
    // Returns true if a solution was found, or false if the puzzle is unsolvable.
    bool solve(SudokuBoard& board);

private:
    // Core recursive solver
    bool solveInternal(SudokuBoard& board);

    // Finds the next empty cell (value 0) on the board.
    bool findEmptyCell(const SudokuBoard& board, int& row, int& col) const;
};
