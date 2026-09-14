CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
TARGET = SudokuProject.exe

SRCS = src/SudokuBoard.cpp \
       src/SudokuSolver.cpp \
       src/SudokuGame.cpp \
       src/main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-del /Q /F src\*.o $(TARGET) 2>NUL || rm -f src/*.o $(TARGET)

.PHONY: all clean
