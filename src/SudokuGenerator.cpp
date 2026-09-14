#include "SudokuGenerator.hpp"
#include <random>
#include <algorithm>
#include <vector>
#include <numeric>

static std::mt19937& getRNG() {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    return rng;
}

void SudokuGenerator::fill3x3Box(SudokuBoard& board, int startRow, int startCol) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(nums.begin(), nums.end(), getRNG());

    int idx = 0;
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            board.setCell(startRow + r, startCol + c, nums[idx++]);
        }
    }
}

void SudokuGenerator::fillDiagonalBoxes(SudokuBoard& board) {
    for (int i = 0; i < 9; i += 3) {
        fill3x3Box(board, i, i);
    }
}

bool SudokuGenerator::findEmpty(const SudokuBoard& board, int& row, int& col) const {
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

bool SudokuGenerator::solveRandomized(SudokuBoard& board) {
    int row = -1, col = -1;
    if (!findEmpty(board, row, col)) {
        return true;
    }

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::shuffle(nums.begin(), nums.end(), getRNG());

    for (int num : nums) {
        if (board.isValidMove(row, col, num)) {
            board.setCell(row, col, num);
            if (solveRandomized(board)) {
                return true;
            }
            board.setCell(row, col, 0);
        }
    }
    return false;
}

int SudokuGenerator::countSolutions(SudokuBoard& board, int limit) {
    int row = -1, col = -1;
    if (!findEmpty(board, row, col)) {
        return 1;
    }

    int solutions = 0;
    for (int num = 1; num <= 9; ++num) {
        if (board.isValidMove(row, col, num)) {
            board.setCell(row, col, num);
            solutions += countSolutions(board, limit);
            board.setCell(row, col, 0);

            if (solutions >= limit) {
                break;
            }
        }
    }
    return solutions;
}

void SudokuGenerator::removeKCells(SudokuBoard& board, int k) {
    std::vector<std::pair<int, int>> positions;
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            positions.emplace_back(r, c);
        }
    }
    std::shuffle(positions.begin(), positions.end(), getRNG());

    int removed = 0;
    for (const auto& pos : positions) {
        if (removed >= k) break;

        int r = pos.first;
        int c = pos.second;
        int backup = board.getCell(r, c);
        if (backup == 0) continue;

        board.setCell(r, c, 0);

        // Check if solution is still unique
        if (countSolutions(board, 2) != 1) {
            // Uniqueness violated; put value back
            board.setCell(r, c, backup);
        } else {
            removed++;
        }
    }
}

SudokuBoard SudokuGenerator::generate(Difficulty difficulty) {
    SudokuBoard board;

    // 1. Fill diagonal 3x3 boxes
    fillDiagonalBoxes(board);

    // 2. Solve the remaining empty cells with random choices
    solveRandomized(board);

    // 3. Remove cells according to difficulty while ensuring unique solution
    int cellsToRemove = 30; // Easy
    if (difficulty == Difficulty::Medium) {
        cellsToRemove = 42;
    } else if (difficulty == Difficulty::Hard) {
        cellsToRemove = 52;
    }

    removeKCells(board, cellsToRemove);

    return board;
}
