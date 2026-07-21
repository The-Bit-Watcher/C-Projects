# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Executable name
TARGET = pizza_order

# Source files - added all new files
SRCS = TestMain.cpp \
       PizzaComponent.cpp \
       Topping.cpp \
       ToppingGroup.cpp \
       BasePizza.cpp \
       PizzaDecorator.cpp \
       ExtraCheese.cpp \
       StuffedCrust.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files - added all new headers
HEADERS = PizzaComponent.h \
          Topping.h \
          ToppingGroup.h \
          Pizza.h \
          BasePizza.h \
          PizzaDecorator.h \
          ExtraCheese.h \
          StuffedCrust.h

# Default target
all: $(TARGET)

# Create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
