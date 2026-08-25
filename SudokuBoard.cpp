#include "SudokuBoard.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>



SudokuBoard::SudokuBoard()
{
    grid = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
}


bool SudokuBoard::isValidMove(int row, int col, int value) const
{
    if (row < 0 || row >= 9 || col < 0 || col >= 9) return false;
    if (value < 1 || value > 9) return false;
    for (int c = 0; c < 9; ++c) {
        if (c != col && grid[row][c] == value) return false;
    }
    for (int r = 0; r < 9; ++r) {
        if (r != row && grid[r][col] == value) return false;
    }
    int boxStartRow = (row / 3) * 3;
    int boxStartCol = (col / 3) * 3;
    for (int r = boxStartRow; r < boxStartRow + 3; ++r) {
        for (int c = boxStartCol; c < boxStartCol + 3; ++c) {
            if ((r != row || c != col) && grid[r][c] == value) return false;
        }
    }
    return true;
}
    

bool SudokuBoard::setCell(int row, int col, int value)
{
    if (row < 0 || row >= 9 || col < 0 || col >= 9) return false;
    if (value < 0 || value > 9) return false;

    if (value == 0) {
        grid[row][col] = 0;
        return true;
    }

    if(isValidMove(row, col, value))
    {
        grid[row][col] = value;
        return true;
    }
    return false;
}

int SudokuBoard::getCell(int row, int col) const
{
    if (row < 0 || row >= 9 || col < 0 || col >= 9)     
    {
        throw std::out_of_range("Row or column out of bounds");
    }
    return grid[row][col];
}
    
void SudokuBoard::print() const
{
    for (int r = 0; r < 9; ++r) 
    {
        if (r % 3 == 0 && r != 0) {
            std::cout << "------------------------" << std::endl;
        }
        for (int c = 0; c < 9; ++c) {
            if (c % 3 == 0 && c != 0) {
                std::cout << " | ";
            }
            std::cout << (grid[r][c] == 0 ? "." : std::to_string(grid[r][c])) << " ";
        }   
        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}
    // File I/O
bool SudokuBoard::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (grid[r][c] == 0) {
                file << ". ";
            } else {
                file << grid[r][c] << " ";
            }
        }
        file << "\n";
    }
    return true;
}

bool SudokuBoard::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        return false;
    }
    for (int r = 0; r < 9; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            char ch;
            file >> ch;
            if (ch == '.')
            {
                grid[r][c] = 0;
            }
            else if(ch >= '1' && ch <= '9')
            {
                grid[r][c] = ch - '0';
            }
        }
    }
    file.close();
    return true;
}

//Solved check
bool SudokuBoard::isSolved() const {
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
            if (grid[r][c] == 0) return false;
            if (!isValidMove(r, c, grid[r][c])) return false;
        }
    }
    return true;
}

const std::vector<std::vector<int>>& SudokuBoard::getGrid() const
{
    return grid;
}

void SudokuBoard::setGrid(const std::vector<std::vector<int>>& newGrid)
{
    grid = newGrid;
}


