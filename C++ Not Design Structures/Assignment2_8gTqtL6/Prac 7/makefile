# Compiler and flags
CC = g++
CFLAGS = -g -Wall -std=c++98

# Source files
SRC = main.cpp Plot.cpp Plant.cpp SmallPlant.cpp MediumPlant.cpp Carrot.cpp Radish.cpp Cabbage.cpp Pineapple.cpp
OBJ = $(SRC:.cpp=.o)

# Executable
EXE = program

# Default target to compile the program
all: $(EXE)

# Link the object files to create the executable
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ)

# Compile each source file into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Run gdb for debugging
debug: $(EXE)
	gdb ./$(EXE)

# Run valgrind for memory leak detection
valgrind: $(EXE)
	valgrind --leak-check=full --track-origins=yes ./$(EXE)

# Clean up the compiled files
clean:
	rm -f $(OBJ) $(EXE)

.PHONY: all clean debug valgrind
