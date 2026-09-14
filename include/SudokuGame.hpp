#pragma once

#include "SudokuBoard.hpp"
#include "SudokuSolver.hpp"
#include "SudokuGenerator.hpp"
#include <string>

class SudokuGame {
private:
    SudokuBoard board;
    SudokuSolver solver;
    SudokuGenerator generator;
    bool isRunning;

    // Helper functions for menu options
    void displayMenu() const;
    void handleEnterMove();
    void handleSolveAutomatically();
    void handleLoadFromFile();
    void handleSaveToFile();
    void handleGeneratePuzzle();
    void loadDefaultPuzzle();

public:
    SudokuGame();

    // Starts and runs the main game loop
    void run();
};
