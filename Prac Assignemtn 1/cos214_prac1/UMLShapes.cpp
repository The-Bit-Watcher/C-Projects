#include "UMLShapes.h"
using namespace std;

// UMLClass Implementation
UMLClass::UMLClass(string name, int l, int w, string c, int x, int y) 
    : Shape(l, w, c, x, y), className(name) {}

Shape* UMLClass::clone() const {
    UMLClass* cloned = new UMLClass(className, length, width, colour, positionX, positionY);
    cloned->attributes = this->attributes;
    cloned->methods = this->methods;
    return cloned;
}

string UMLClass::toString() const {
    string result = "UML Class: " + className + " at (" + to_string(positionX) + "," + to_string(positionY) + ")";
    result += "\nAttributes: ";
    for (const string& attr : attributes) {
        result += attr + "; ";
    }
    result += "\nMethods: ";
    for (const string& method : methods) {
        result += method + "; ";
    }
    return result;
}

// UMLAssociation Implementation  
UMLAssociation::UMLAssociation(int sX, int sY, int eX, int eY, string type, string c, string mult1, string mult2)
    : Shape(abs(eX - sX), abs(eY - sY), c, min(sX, eX), min(sY, eY)), 
      associationType(type), startX(sX), startY(sY), endX(eX), endY(eY),
      multiplicity1(mult1), multiplicity2(mult2) {}

Shape* UMLAssociation::clone() const {
    UMLAssociation* cloned = new UMLAssociation(startX, startY, endX, endY, 
                                               associationType, colour, multiplicity1, multiplicity2);
    return cloned;
}

string UMLAssociation::toString() const {
    return "UML " + associationType + " from (" + to_string(startX) + "," + to_string(startY) + 
           ") to (" + to_string(endX) + "," + to_string(endY) + ") [" + 
           multiplicity1 + " -> " + multiplicity2 + "]";
}

// UMLObject Implementation
UMLObject::UMLObject(string objName, string clsName, int l, int w, string c, int x, int y)
    : Shape(l, w, c, x, y), objectName(objName), className(clsName) {}

Shape* UMLObject::clone() const {
    UMLObject* cloned = new UMLObject(objectName, className, length, width, colour, positionX, positionY);
    cloned->attributeValues = this->attributeValues;
    return cloned;
}

string UMLObject::toString() const {
    string result = "UML Object: " + objectName + ":" + className + 
                   " at (" + to_string(positionX) + "," + to_string(positionY) + ")";
    result += "\nAttribute Values: ";
    for (const auto& pair : attributeValues) {
        result += pair.first + "=" + pair.second + "; ";
    }
    return result;
}