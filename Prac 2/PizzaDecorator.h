#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "Pizza.h"
#include <memory>

class PizzaDecorator : public Pizza {
protected:
    std::shared_ptr<Pizza> pizza;

public:
    PizzaDecorator(std::shared_ptr<Pizza> pizza);
    virtual ~PizzaDecorator() = default;
    
    double getPrice() const override = 0;
    std::string getName() const override = 0;
    void printPizza() const override = 0;
};

#endif