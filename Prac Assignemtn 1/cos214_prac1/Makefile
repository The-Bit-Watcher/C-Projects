# Makefile for OpenCanvas Design Patterns Project
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov
TARGET = main
SOURCES = TestingMain.cpp Canvas.cpp Shape.cpp ConcreteShapes.cpp ShapeFactory.cpp Memento.cpp ExportCanvasBase.cpp ExportCanvas.cpp UMLShapes.cpp

# Default target - compile and run
run: clean $(TARGET)
	./$(TARGET)

# Compile the program with coverage
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(LDFLAGS) -o $(TARGET)

# Generate coverage report
coverage: run
	gcov -b -c *.cpp

# Clean up generated files
clean:
	rm -f $(TARGET) *.gcno *.gcda *.gcov

# Help target
help:
	@echo "Available targets:"
	@echo "  run      - Compile and run the program"
	@echo "  coverage - Run program and generate coverage report"
	@echo "  clean    - Remove generated files"
	@echo "  help     - Show this help message"

.PHONY: run coverage clean help