#ifndef UML_SHAPES_H
#define UML_SHAPES_H

#include "Shape.h"
#include <vector>

// UML Class shape for class diagrams
class UMLClass : public Shape {
private:
    string className;
    vector<string> attributes;
    vector<string> methods;
    
public:
    UMLClass(string name = "Class", int l = 120, int w = 80, string c = "white", int x = 0, int y = 0);
    
    Shape* clone() const override;
    string toString() const override;
    
    // UML-specific methods
    void setClassName(const string& name) { className = name; }
    void addAttribute(const string& attr) { attributes.push_back(attr); }
    void addMethod(const string& method) { methods.push_back(method); }
    
    string getClassName() const { return className; }
    const vector<string>& getAttributes() const { return attributes; }
    const vector<string>& getMethods() const { return methods; }
};

// UML Association line for relationships
class UMLAssociation : public Shape {
private:
    string associationType; // "association", "inheritance", "composition", etc.
    int startX, startY, endX, endY;
    string multiplicity1, multiplicity2;
    
public:
    UMLAssociation(int sX, int sY, int eX, int eY, string type = "association", 
                   string c = "black", string mult1 = "", string mult2 = "");
    
    Shape* clone() const override;
    string toString() const override;
    
    // Association-specific methods
    void setAssociationType(const string& type) { associationType = type; }
    void setMultiplicity(const string& m1, const string& m2) { 
        multiplicity1 = m1; multiplicity2 = m2; 
    }
    
    string getAssociationType() const { return associationType; }
};

// UML Object instance for object diagrams
class UMLObject : public Shape {
private:
    string objectName;
    string className;
    vector<pair<string, string>> attributeValues; // attribute name, value pairs
    
public:
    UMLObject(string objName = "obj", string clsName = "Class", 
              int l = 100, int w = 60, string c = "lightblue", int x = 0, int y = 0);
    
    Shape* clone() const override;
    string toString() const override;
    
    // Object-specific methods
    void setObjectName(const string& name) { objectName = name; }
    void setClassName(const string& name) { className = name; }
    void addAttributeValue(const string& attr, const string& value) {
        attributeValues.push_back(make_pair(attr, value));
    }
    
    string getObjectName() const { return objectName; }
    string getClassName() const { return className; }
};

#endif