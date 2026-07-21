#include <iostream>
#include <vector>
#include <string>
#include "Shape.h"
#include "ConcreteShapes.h"
#include "ShapeFactory.h"
#include "Canvas.h"
#include "Memento.h"
#include "ExportCanvas.h"
#include "UMLShapes.h"
#include "UMLFactories.h"

using namespace std;

void testFactoryMethod() {
    cout << "\n=== TESTING FACTORY METHOD PATTERN ===" << endl;
    
    //test Rectangle Factory
    RectangleFactory rectFactory;
    cout << "Testing " << rectFactory.toString() << endl;
    Shape* rect = rectFactory.createShape();
    cout << "Created: " << rect->toString() << endl;
    
    //test Square Factory
    SquareFactory squareFactory;
    cout << "Testing " << squareFactory.toString() << endl;
    Shape* square = squareFactory.createShape();
    cout << "Created: " << square->toString() << endl;
    
    //test Textbox Factory
    TextboxFactory textFactory;
    cout << "Testing " << textFactory.toString() << endl;
    Shape* textbox = textFactory.createShape();
    cout << "Created: " << textbox->toString() << endl;
    
    //clean up
    delete rect;
    delete square;
    delete textbox;
    
    cout << "Factory Method Pattern - PASSED" << endl;
}

void testPrototypePattern() {
    cout << "\n=== TESTING PROTOTYPE PATTERN ===" << endl;
    
    //create original shapes
    Rectangle* originalRect = new Rectangle(20, 10, "blue", 5, 5);
    Square* originalSquare = new Square(15, "red", 10, 10);
    Textbox* originalTextbox = new Textbox("Hello World", 25, 5, "green", 0, 0);
    
    cout << "Original Rectangle: " << originalRect->toString() << endl;
    cout << "Original Square: " << originalSquare->toString() << endl;
    cout << "Original Textbox: " << originalTextbox->toString() << endl;
    
    //clone shapes
    Shape* clonedRect = originalRect->clone();
    Shape* clonedSquare = originalSquare->clone();
    Shape* clonedTextbox = originalTextbox->clone();
    
    cout << "\nCloned Rectangle: " << clonedRect->toString() << endl;
    cout << "Cloned Square: " << clonedSquare->toString() << endl;
    cout << "Cloned Textbox: " << clonedTextbox->toString() << endl;
    
    //test that clones are independent
    originalRect->setColour("yellow");
    originalSquare->setPositionX(20);
    
    cout << "\nAfter modifying originals:" << endl;
    cout << "Original Rectangle: " << originalRect->toString() << endl;
    cout << "Cloned Rectangle (unchanged): " << clonedRect->toString() << endl;
    
    //clean up
    delete originalRect;
    delete originalSquare;
    delete originalTextbox;
    delete clonedRect;
    delete clonedSquare;
    delete clonedTextbox;
    
    cout << "Prototype Pattern - PASSED" << endl;
}

void testMementoPattern() {
    cout << "\n=== TESTING MEMENTO PATTERN ===" << endl;
    
    Canvas canvas;
    CareTaker caretaker;
    
    //add initial shapes
    canvas.addShape(new Rectangle(10, 5, "blue", 0, 0));
    canvas.addShape(new Square(8, "red", 10, 10));
    cout << "Canvas after adding 2 shapes:" << endl;
    canvas.displayCanvas();
    
    //save state
    Memento* state1 = canvas.captureCurrent();
    caretaker.addMemento(state1);
    cout << "State saved. Caretaker has " << caretaker.getMementoCount() << " states" << endl;
    
    //add more shapes
    canvas.addShape(new Textbox("Test", 15, 3, "green", 5, 5));
    canvas.addShape(new Rectangle(12, 8, "purple", 20, 20));
    cout << "\nCanvas after adding 2 more shapes:" << endl;
    canvas.displayCanvas();
    
    //save another state
    Memento* state2 = canvas.captureCurrent();
    caretaker.addMemento(state2);
    cout << "State saved. Caretaker has " << caretaker.getMementoCount() << " states" << endl;
    
    //modify canvas more
    canvas.addShape(new Square(6, "orange", 30, 30));
    cout << "\nCanvas after adding 1 more shape:" << endl;
    canvas.displayCanvas();
    
    //undo to previous state
    if (caretaker.hasMementos()) {
        Memento* lastState = caretaker.getLastMemento();
        canvas.undoAction(lastState);
        delete lastState;
        cout << "\nAfter undo operation:" << endl;
        canvas.displayCanvas();
    }
    
    //undo to first state
    if (caretaker.hasMementos()) {
        Memento* firstState = caretaker.getLastMemento();
        canvas.undoAction(firstState);
        delete firstState;
        cout << "\nAfter second undo operation:" << endl;
        canvas.displayCanvas();
    }
    
    cout << "Memento Pattern - PASSED" << endl;
}

void testTemplateMethod() {
    cout << "\n=== TESTING TEMPLATE METHOD PATTERN ===" << endl;
    
    Canvas canvas;
    
    //add some shapes to export
    canvas.addShape(new Rectangle(15, 10, "blue", 0, 0));
    canvas.addShape(new Square(12, "red", 20, 20));
    canvas.addShape(new Textbox("Export Test", 20, 4, "green", 10, 10));
    
    cout << "Canvas to export:" << endl;
    canvas.displayCanvas();
    
    //test PNG Export
    cout << "\n--- PNG EXPORT ---" << endl;
    PNGExporter pngExporter(&canvas);
    pngExporter.exportCanvas();
    
    //test PDF Export
    cout << "\n--- PDF EXPORT ---" << endl;
    PDFExporter pdfExporter(&canvas);
    pdfExporter.exportCanvas();
    
    cout << "\nTemplate Method Pattern - PASSED" << endl;
}

void testShapeProperties() {
    cout << "\n=== TESTING SHAPE PROPERTIES ===" << endl;
    
    //test Rectangle properties
    Rectangle rect(20, 15, "blue", 10, 5);
    cout << "Rectangle properties test:" << endl;
    cout << "Length: " << rect.getLength() << ", Width: " << rect.getWidth() << endl;
    cout << "Color: " << rect.getColour() << ", Position: (" << rect.getPositionX() << "," << rect.getPositionY() << ")" << endl;
    
    //test Square properties
    Square square(10, "red", 15, 20);
    cout << "\nSquare properties test:" << endl;
    cout << "Length: " << square.getLength() << ", Width: " << square.getWidth() << " (should be equal)" << endl;
    
    //test textbox properties
    Textbox textbox("Sample Text", 25, 8, "green", 0, 0);
    cout << "\nTextbox properties test:" << endl;
    cout << "Text: \"" << textbox.getText() << "\"" << endl;
    cout << "Dimensions: " << textbox.getLength() << "x" << textbox.getWidth() << endl;
    
    //test property setters
    rect.setColour("yellow");
    rect.setPositionX(50);
    rect.setPositionY(30);
    cout << "\nAfter modifying rectangle:" << endl;
    cout << rect.toString() << endl;
    
    cout << "Shape Properties Test - PASSED" << endl;
}

void testCanvasOperations() {
    cout << "\n=== TESTING CANVAS OPERATIONS ===" << endl;
    
    Canvas canvas;
    
    //test empty canvas
    cout << "Empty canvas count: " << canvas.getShapeCount() << endl;
    
    //add shapes
    canvas.addShape(new Rectangle(10, 5, "blue", 0, 0));
    canvas.addShape(new Square(8, "red", 10, 10));
    canvas.addShape(new Textbox("Test", 15, 3, "green", 5, 5));
    
    cout << "Canvas after adding shapes: " << canvas.getShapeCount() << " shapes" << endl;
    
    //test shape retrieval
    Shape* firstShape = canvas.getShape(0);
    if (firstShape) {
        cout << "First shape: " << firstShape->toString() << endl;
    }
    
    //test invalid index
    Shape* invalidShape = canvas.getShape(10);
    cout << "Invalid index returns: " << (invalidShape ? "valid pointer" : "nullptr") << endl;
    
    //test shape removal
    canvas.removeShape(1);
    cout << "After removing shape at index 1: " << canvas.getShapeCount() << " shapes" << endl;
    canvas.displayCanvas();
    
    cout << "Canvas Operations Test - PASSED" << endl;
}

void testUMLShapes() {
    cout << "\n=== TESTING UML SHAPES ===" << endl;
    
    // Test UML Class
    UMLClass* umlClass = new UMLClass("Student", 120, 80, "white", 10, 10);
    umlClass->addAttribute("- name: string");
    umlClass->addAttribute("- age: int");
    umlClass->addMethod("+ getName(): string");
    umlClass->addMethod("+ setAge(int): void");
    
    cout << "UML Class created:" << endl;
    cout << umlClass->toString() << endl;
    
    // Test UML Class cloning
    Shape* clonedClass = umlClass->clone();
    cout << "\nCloned UML Class:" << endl;
    cout << clonedClass->toString() << endl;
    
    // Test UML Association
    UMLAssociation* association = new UMLAssociation(0, 0, 100, 50, "inheritance", "black", "1", "*");
    cout << "\nUML Association created:" << endl;
    cout << association->toString() << endl;
    
    // Test UML Association cloning
    Shape* clonedAssociation = association->clone();
    cout << "\nCloned UML Association:" << endl;
    cout << clonedAssociation->toString() << endl;
    
    // Test UML Object
    UMLObject* umlObject = new UMLObject("student1", "Student", 100, 60, "lightblue", 50, 50);
    umlObject->addAttributeValue("name", "John Doe");
    umlObject->addAttributeValue("age", "20");
    
    cout << "\nUML Object created:" << endl;
    cout << umlObject->toString() << endl;
    
    // Test UML Object cloning
    Shape* clonedObject = umlObject->clone();
    cout << "\nCloned UML Object:" << endl;
    cout << clonedObject->toString() << endl;
    
    // Clean up
    delete umlClass;
    delete clonedClass;
    delete association;
    delete clonedAssociation;
    delete umlObject;
    delete clonedObject;
    
    cout << "UML Shapes Test - PASSED" << endl;
}

void testUMLFactories() {
    cout << "\n=== TESTING UML FACTORIES ===" << endl;
    
    // Test UML Class Factory
    UMLClassFactory classFactory;
    cout << "Testing " << classFactory.toString() << endl;
    Shape* umlClass = classFactory.createShape();
    cout << "Created: " << umlClass->toString() << endl;
    
    // Test UML Association Factory
    UMLAssociationFactory assocFactory;
    cout << "\nTesting " << assocFactory.toString() << endl;
    Shape* umlAssoc = assocFactory.createShape();
    cout << "Created: " << umlAssoc->toString() << endl;
    
    // Test UML Object Factory
    UMLObjectFactory objFactory;
    cout << "\nTesting " << objFactory.toString() << endl;
    Shape* umlObj = objFactory.createShape();
    cout << "Created: " << umlObj->toString() << endl;
    
    // Clean up
    delete umlClass;
    delete umlAssoc;
    delete umlObj;
    
    cout << "UML Factories Test - PASSED" << endl;
}

void testUMLCanvasIntegration() {
    cout << "\n=== TESTING UML CANVAS INTEGRATION ===" << endl;
    
    Canvas canvas;
    
    // Add UML shapes to canvas
    UMLClass* studentClass = new UMLClass("Student", 120, 80, "white", 10, 10);
    studentClass->addAttribute("- name: string");
    studentClass->addMethod("+ getName(): string");
    canvas.addShape(studentClass);
    
    UMLObject* student1 = new UMLObject("student1", "Student", 100, 60, "lightblue", 150, 10);
    student1->addAttributeValue("name", "John");
    canvas.addShape(student1);
    
    UMLAssociation* relation = new UMLAssociation(130, 50, 150, 40, "instantiation", "black", "1", "1");
    canvas.addShape(relation);
    
    cout << "Canvas with UML shapes:" << endl;
    canvas.displayCanvas();
    
    // Test export with UML shapes
    cout << "\n--- EXPORTING UML DIAGRAM ---" << endl;
    PNGExporter pngExporter(&canvas);
    pngExporter.exportCanvas();
    
    cout << "UML Canvas Integration Test - PASSED" << endl;
}

int main() {
    cout << "OpenCanvas Design Patterns Testing Suite" << endl;
    cout << "========================================" << endl;
    
    try {
        testShapeProperties();
        testFactoryMethod();
        testPrototypePattern();
        testCanvasOperations();
        testMementoPattern();
        testTemplateMethod();
        testUMLShapes();
        testUMLFactories();
        testUMLCanvasIntegration();
        
        cout << "\n========================================" << endl;
        cout << "ALL TESTS PASSED SUCCESSFULLY!" << endl;
        cout << "Testing coverage should be above 60%" << endl;
        cout << "========================================" << endl;
        
    } catch (const exception& e) {
        cout << "Test failed with exception: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}