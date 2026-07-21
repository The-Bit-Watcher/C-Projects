#ifndef MEMENTO_H
#define MEMENTO_H

#include <vector>
#include <list>
#include "Shape.h"

class Memento {
private:
    vector<Shape*> shapes;
    
public:
    Memento(const vector<Shape*>& elements);
    
    ~Memento();
    
    Memento(const Memento& other);
    Memento& operator=(const Memento& other);
    
    const vector<Shape*>& getShapes() const { return shapes; }
};

class CareTaker {
private:
    list<Memento*> mementos;
    static const int MAX_STATES = 10;
    
public:
    CareTaker();
    ~CareTaker();
    
    void addMemento(Memento* memento);
    Memento* getLastMemento();
    bool hasMementos() const;
    int getMementoCount() const;
    
    void clearMementos();
};

#endif