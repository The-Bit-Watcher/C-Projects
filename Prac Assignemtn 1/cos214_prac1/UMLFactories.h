#ifndef UML_FACTORIES_H
#define UML_FACTORIES_H

#include "ShapeFactory.h"
#include "UMLShapes.h"

class UMLClassFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new UMLClass();
    }
    
    string toString() const override {
        return "UML Class Factory";
    }
};

class UMLAssociationFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new UMLAssociation(0, 0, 50, 50); // Default association
    }
    
    string toString() const override {
        return "UML Association Factory";
    }
};

class UMLObjectFactory : public ShapeFactory {
public:
    Shape* createShape() override {
        return new UMLObject();
    }
    
    string toString() const override {
        return "UML Object Factory";
    }
};

#endif