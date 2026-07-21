#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape {
protected:
    int length;
    int width;
    string colour;
    int positionX;
    int positionY;

public:
    Shape(int l = 0, int w = 0, string c = "black", int x = 0, int y = 0);
    
    virtual ~Shape() = default;
    
    virtual Shape* clone() const = 0;
    
    int getLength() const { return length; }
    int getWidth() const { return width; }
    string getColour() const { return colour; }
    int getPositionX() const { return positionX; }
    int getPositionY() const { return positionY; }
    
    void setLength(int l) { length = l; }
    void setWidth(int w) { width = w; }
    void setColour(const string& c) { colour = c; }
    void setPositionX(int x) { positionX = x; }
    void setPositionY(int y) { positionY = y; }
    
    virtual string toString() const = 0;
};

#endif