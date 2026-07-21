# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++98

# Target executable
TARGET = run

# Source files
SRCS = main.cpp call.cpp call_handler.cpp incoming.cpp missed.cpp call_center.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = call.h call_handler.h incoming.h missed.h call_center.h exceptions.h

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
