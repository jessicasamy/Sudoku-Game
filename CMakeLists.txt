cmake_minimum_required(VERSION 3.8)
project(SudokuProject)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for headers
include_directories(include)

# Optional puzzle generator module
option(BUILD_GENERATOR "Build the SudokuGenerator module for puzzle generation" ON)

# Core source files
set(SOURCES
    src/SudokuBoard.cpp
    src/SudokuSolver.cpp
    src/SudokuGame.cpp
    src/main.cpp
)

# Header files
set(HEADERS
    include/SudokuBoard.hpp
    include/SudokuSolver.hpp
    include/SudokuGame.hpp
)

# If building puzzle generator, include its source/header
if(BUILD_GENERATOR)
    list(APPEND SOURCES src/SudokuGenerator.cpp)
    list(APPEND HEADERS include/SudokuGenerator.hpp)
endif()

# Create the final executable
add_executable(SudokuProject ${SOURCES} ${HEADERS})
target_include_directories(SudokuProject PRIVATE include)
