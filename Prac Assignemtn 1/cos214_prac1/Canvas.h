#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "ConcreteShapes.h"

class Memento;

class Canvas {
private:
    vector<Shape*> shapes;

public:
    Canvas();
    ~Canvas();
    
    Canvas(const Canvas& other);
    Canvas& operator=(const Canvas& other);
    
    void addShape(Shape* shape);
    void removeShape(int index);
    void clearShapes();
    
    const vector<Shape*>& getShapes() const { return shapes; }
    int getShapeCount() const { return shapes.size(); }
    Shape* getShape(int index) const;
    
    Memento* captureCurrent() const;
    void undoAction(Memento* prev);
    
    string toString() const;
    void displayCanvas() const;
};

#endif