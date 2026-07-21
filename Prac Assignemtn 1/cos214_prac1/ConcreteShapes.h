#ifndef CONCRETE_SHAPES_H
#define CONCRETE_SHAPES_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(int l = 10, int w = 5, string c = "blue", int x = 0, int y = 0);
    
    Shape* clone() const override;
    
    string toString() const override;
};

class Square : public Shape {
public:
    Square(int size = 5, string c = "red", int x = 0, int y = 0);
    
    Shape* clone() const override;
    
    string toString() const override;
};

class Textbox : public Shape {
private:
    string text;
    
public:
    Textbox(string txt = "Sample Text", int l = 15, int w = 3, string c = "green", int x = 0, int y = 0);
    
    Shape* clone() const override;
    
    string getText() const { return text; }
    void setText(const string& txt) { text = txt; }
    
    string toString() const override;
};

#endif