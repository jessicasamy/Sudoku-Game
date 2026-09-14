#pragma once

#include "SudokuBoard.hpp"

enum class Difficulty {
    Easy,
    Medium,
    Hard
};

class SudokuGenerator {
public:
    SudokuGenerator() = default;

    // Generates a new Sudoku puzzle of the specified difficulty
    SudokuBoard generate(Difficulty difficulty = Difficulty::Medium);

private:
    void fillDiagonalBoxes(SudokuBoard& board);
    void fill3x3Box(SudokuBoard& board, int startRow, int startCol);
    bool solveRandomized(SudokuBoard& board);
    void removeKCells(SudokuBoard& board, int k);
    int countSolutions(SudokuBoard& board, int limit = 2);
    bool findEmpty(const SudokuBoard& board, int& row, int& col) const;
};
