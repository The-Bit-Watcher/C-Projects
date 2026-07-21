#include "Memento.h"
using namespace std;

Memento::Memento(const vector<Shape*>& elements) {
    for (const Shape* shape : elements) {
        if (shape != nullptr) {
            shapes.push_back(shape->clone());
        }
    }
}

Memento::~Memento() {
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}

Memento::Memento(const Memento& other) {
    for (const Shape* shape : other.shapes) {
        if (shape != nullptr) {
            shapes.push_back(shape->clone());
        }
    }
}

Memento& Memento::operator=(const Memento& other) {
    if (this != &other) {
        for (Shape* shape : shapes) {
            delete shape;
        }
        shapes.clear();
        
        for (const Shape* shape : other.shapes) {
            if (shape != nullptr) {
                shapes.push_back(shape->clone());
            }
        }
    }
    return *this;
}

CareTaker::CareTaker() {}

CareTaker::~CareTaker() {
    clearMementos();
}

void CareTaker::addMemento(Memento* memento) {
    if (memento == nullptr) return;
    
    mementos.push_back(memento);
    
    if (mementos.size() > MAX_STATES) {//remove oldest when exceed max states
        Memento* oldest = mementos.front();
        mementos.pop_front();
        delete oldest;
    }
}

Memento* CareTaker::getLastMemento() {
    if (mementos.empty()) {
        return nullptr;
    }
    
    Memento* last = mementos.back();
    mementos.pop_back();
    return last;
}

bool CareTaker::hasMementos() const {
    return !mementos.empty();
}

int CareTaker::getMementoCount() const {
    return mementos.size();
}

void CareTaker::clearMementos() {
    for (Memento* memento : mementos) {
        delete memento;
    }
    mementos.clear();
}