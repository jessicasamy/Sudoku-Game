#pragma once

#include <string>
#include <vector>

class SudokuBoard {
private:
    std::vector<std::vector<int>> grid;

public:
    SudokuBoard();
    
    // Validation & Moves
    bool isValidMove(int row, int col, int value) const;
    bool setCell(int row, int col, int value);
    int getCell(int row, int col) const;
    
    // UI Display
    void print() const;

    // File I/O
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);

    //Solved check
    bool isSolved() const;

    const std::vector<std::vector<int>>& getGrid() const;
    void setGrid(const std::vector<std::vector<int>>& newGrid);

};

