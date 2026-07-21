#include "Canvas.h"
#include "Memento.h"
#include <iostream>
using namespace std;

Canvas::Canvas() {}

Canvas::~Canvas() {
    clearShapes();
}

Canvas::Canvas(const Canvas& other) {
    for (const Shape* shape : other.shapes) {
        if (shape != nullptr) {
            shapes.push_back(shape->clone());
        }
    }
}

Canvas& Canvas::operator=(const Canvas& other) {
    if (this != &other) {
        clearShapes();
        for (const Shape* shape : other.shapes) {
            if (shape != nullptr) {
                shapes.push_back(shape->clone());
            }
        }
    }
    return *this;
}

void Canvas::addShape(Shape* shape) {
    if (shape != nullptr) {
        shapes.push_back(shape);
    }
}

void Canvas::removeShape(int index) {
    if (index >= 0 && index < static_cast<int>(shapes.size())) {
        delete shapes[index];
        shapes.erase(shapes.begin() + index);
    }
}

void Canvas::clearShapes() {
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

Shape* Canvas::getShape(int index) const {
    if (index >= 0 && index < static_cast<int>(shapes.size())) {
        return shapes[index];
    }
    return nullptr;
}

Memento* Canvas::captureCurrent() const {
    return new Memento(shapes);
}

void Canvas::undoAction(Memento* prev) {
    if (prev == nullptr) return;
    
    clearShapes();
    
    const vector<Shape*>& mementoShapes = prev->getShapes();
    for (const Shape* shape : mementoShapes) {
        if (shape != nullptr) {
            shapes.push_back(shape->clone());
        }
    }
}

string Canvas::toString() const {
    string result = "Canvas contains " + to_string(shapes.size()) + " shapes:\n";
    for (size_t i = 0; i < shapes.size(); i++) {
        if (shapes[i] != nullptr) {
            result += to_string(i + 1) + ". " + shapes[i]->toString() + "\n";
        }
    }
    return result;
}

void Canvas::displayCanvas() const {
    cout << toString() << endl;
}