#include "ShapeFactory.h"
using namespace std;

Shape* RectangleFactory::createShape() {
    return new Rectangle();
}

string RectangleFactory::toString() const {
    return "Rectangle Factory";
}

Shape* SquareFactory::createShape() {
    return new Square();
}

string SquareFactory::toString() const {
    return "Square Factory";
}


Shape* TextboxFactory::createShape() {
    return new Textbox();
}

string TextboxFactory::toString() const {
    return "Textbox Factory";
}