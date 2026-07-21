#include "ConcreteShapes.h"
using namespace std;

Rectangle::Rectangle(int l, int w, string c, int x, int y) 
    : Shape(l, w, c, x, y) {}

Shape* Rectangle::clone() const {
    return new Rectangle(length, width, colour, positionX, positionY);
}

string Rectangle::toString() const {
    return "Rectangle: " + to_string(length) + "x" + to_string(width) + 
           " Color: " + colour + " Position: (" + to_string(positionX) + "," + to_string(positionY) + ")";
}

Square::Square(int size, string c, int x, int y) 
    : Shape(size, size, c, x, y) {}

Shape* Square::clone() const {
    return new Square(length, colour, positionX, positionY);
}

string Square::toString() const {
    return "Square: " + to_string(length) + "x" + to_string(length) + 
           " Color: " + colour + " Position: (" + to_string(positionX) + "," + to_string(positionY) + ")";
}

Textbox::Textbox(string txt, int l, int w, string c, int x, int y) 
    : Shape(l, w, c, x, y), text(txt) {}

Shape* Textbox::clone() const {
    return new Textbox(text, length, width, colour, positionX, positionY);
}

string Textbox::toString() const {
    return "Textbox: \"" + text + "\" " + to_string(length) + "x" + to_string(width) + 
           " Color: " + colour + " Position: (" + to_string(positionX) + "," + to_string(positionY) + ")";
}