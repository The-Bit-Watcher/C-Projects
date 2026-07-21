# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -g
TARGET = chat_system
OBJDIR = obj

# Source files - ADD userIterator.cpp
SOURCES = main.cpp Users.cpp ChatRoom.cpp Command.cpp SendMessageCommand.cpp LogMessageCommand.cpp userIterator.cpp NotificationSystem.cpp
HEADERS = Users.h ChatRoom.h Command.h SendMessageCommand.h LogMessageCommand.h userIterator.h NotificationSystem.h

# Object files
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

# Default target
all: $(TARGET)

# Create target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Create object files directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile source files to object files
$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug with gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# Phony targets
.PHONY: all clean run debug