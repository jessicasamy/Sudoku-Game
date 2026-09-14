#include "SudokuSolver.hpp"

bool SudokuSolver::findEmptyCell(const SudokuBoard& board, int& row, int& col) const {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (board.getCell(r, c) == 0) {
                row = r;
                col = c;
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::solve(SudokuBoard& board) {
    // Initial validation: verify that existing filled cells don't violate Sudoku rules
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            int val = board.getCell(r, c);
            if (val != 0 && !board.isValidMove(r, c, val)) {
                return false;
            }
        }
    }

    return solveInternal(board);
}

bool SudokuSolver::solveInternal(SudokuBoard& board) {
    int row = -1;
    int col = -1;

    // If no empty cells remain, the board is completely and correctly solved
    if (!findEmptyCell(board, row, col)) {
        return true;
    }

    // Try digits 1 through 9
    for (int num = 1; num <= 9; ++num) {
        if (board.isValidMove(row, col, num)) {
            board.setCell(row, col, num);

            // Recurse to solve the rest of the board
            if (solveInternal(board)) {
                return true;
            }

            // Backtrack if placing num didn't lead to a solution
            board.setCell(row, col, 0);
        }
    }

    return false;
}
