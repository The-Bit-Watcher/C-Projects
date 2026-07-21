# Compiler
CXX = g++
CXXFLAGS = -g -Wall

# Source files
SOURCES = Player.cpp Party.cpp RandomNumberGenerator.cpp Ranger.cpp main.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXEC = program

# Valgrind options
VALGRIND_OPTS = --leak-check=full --show-leak-kinds=all

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Run with Valgrind
valgrind: $(EXEC)
	valgrind $(VALGRIND_OPTS) ./$(EXEC)

# Run with GDB
gdb: $(EXEC)
	gdb ./$(EXEC)

# Clean up
clean:
	rm -f $(OBJECTS) $(EXEC)
