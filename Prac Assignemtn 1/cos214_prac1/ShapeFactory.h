#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "ConcreteShapes.h"

class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;
    
    virtual Shape* createShape() = 0;
    
    virtual string toString() const = 0;
};


class RectangleFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    string toString() const override;
};

class SquareFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    string toString() const override;
};

class TextboxFactory : public ShapeFactory {
public:
    Shape* createShape() override;
    string toString() const override;
};

#endif