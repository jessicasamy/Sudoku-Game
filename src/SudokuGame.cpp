#include "SudokuGame.hpp"
#include <iostream>
#include <limits>

SudokuGame::SudokuGame() : isRunning(true) {
    loadDefaultPuzzle();
}

void SudokuGame::loadDefaultPuzzle() {
    // Standard sample puzzle from specification (Page 4)
    // 5 3 . | . 7 . | . . .
    // 6 . . | 1 9 5 | . . .
    // . 9 8 | . . . | . 6 .
    // 8 . . | . 6 . | . . 3
    // 4 . . | 8 . 3 | . . 1
    // 7 . . | . 2 . | . . 6
    // . 6 . | . . . | 2 8 .
    // . . . | 4 1 9 | . . 5
    // . . . | . 8 . | . 7 9

    board.setCell(0, 0, 5); board.setCell(0, 1, 3); board.setCell(0, 4, 7);
    board.setCell(1, 0, 6); board.setCell(1, 3, 1); board.setCell(1, 4, 9); board.setCell(1, 5, 5);
    board.setCell(2, 1, 9); board.setCell(2, 2, 8); board.setCell(2, 7, 6);
    board.setCell(3, 0, 8); board.setCell(3, 4, 6); board.setCell(3, 8, 3);
    board.setCell(4, 0, 4); board.setCell(4, 3, 8); board.setCell(4, 5, 3); board.setCell(4, 8, 1);
    board.setCell(5, 0, 7); board.setCell(5, 4, 2); board.setCell(5, 8, 6);
    board.setCell(6, 1, 6); board.setCell(6, 6, 2); board.setCell(6, 7, 8);
    board.setCell(7, 3, 4); board.setCell(7, 4, 1); board.setCell(7, 5, 9); board.setCell(7, 8, 5);
    board.setCell(8, 4, 8); board.setCell(8, 7, 7); board.setCell(8, 8, 9);
}

void SudokuGame::displayMenu() const {
    std::cout << "1) Enter a move\n"
              << "2) Solve automatically\n"
              << "3) Load puzzle from file\n"
              << "4) Save current puzzle to file\n"
              << "5) Exit\n";
}

void SudokuGame::handleEnterMove() {
    std::cout << "Enter row (1-9), column (1-9), and value (1-9): ";
    int r, c, val;
    if (!(std::cin >> r >> c >> val)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter integer numbers only.\n\n";
        return;
    }

    if (r < 1 || r > 9) {
        std::cout << "Row must be between 1 and 9.\n\n";
        return;
    }
    if (c < 1 || c > 9) {
        std::cout << "Column must be between 1 and 9.\n\n";
        return;
    }
    if (val < 1 || val > 9) {
        std::cout << "Value must be between 1 and 9.\n\n";
        return;
    }

    // Convert 1-based indexing to 0-based
    int boardRow = r - 1;
    int boardCol = c - 1;

    if (board.setCell(boardRow, boardCol, val)) {
        std::cout << "Move accepted!\n\n";
        if (board.isSolved()) {
            board.print();
            std::cout << "Congratulations! You have solved the puzzle!\n\n";
        }
    } else {
        std::cout << "Invalid move! Conflicts with row, column, or 3x3 box.\n\n";
    }
}

void SudokuGame::handleSolveAutomatically() {
    if (solver.solve(board)) {
        std::cout << "Puzzle solved!\n\n";
    } else {
        std::cout << "Unable to solve: Puzzle is unsolvable or already has conflicting values.\n\n";
    }
}

void SudokuGame::handleLoadFromFile() {
    std::cout << "Enter file path to load: ";
    std::string filename;
    std::cin >> filename;
    if (board.loadFromFile(filename)) {
        std::cout << "Puzzle successfully loaded from " << filename << "!\n\n";
    } else {
        std::cout << "Error: Could not open or read file '" << filename << "'.\n\n";
    }
}

void SudokuGame::handleSaveToFile() {
    std::cout << "Enter file path to save current board: ";
    std::string filename;
    std::cin >> filename;
    if (board.saveToFile(filename)) {
        std::cout << "Puzzle successfully saved to " << filename << "!\n\n";
    } else {
        std::cout << "Error: Could not save to file '" << filename << "'.\n\n";
    }
}

void SudokuGame::run() {
    while (isRunning) {
        board.print();
        displayMenu();
        std::cout << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice! Please enter a number between 1 and 5.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                handleEnterMove();
                break;
            case 2:
                handleSolveAutomatically();
                break;
            case 3:
                handleLoadFromFile();
                break;
            case 4:
                handleSaveToFile();
                break;
            case 5:
                isRunning = false;
                std::cout << "Exiting Sudoku Game. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option! Choice must be between 1 and 5.\n\n";
                break;
        }
    }
}
