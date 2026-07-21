# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++98 -Wall -Wextra

# Target executable name
TARGET = program

# Source files
SRCS = main.cpp DoublyList.cpp DoublyNode.cpp

# Object files (replace .cpp with .o for each source)
OBJS = $(SRCS:.cpp=.o)

# Default target to build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
