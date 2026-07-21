#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H

#include "PizzaDecorator.h"

class ExtraCheese : public PizzaDecorator {
private:
    double cheesePrice;

public:
    ExtraCheese(std::shared_ptr<Pizza> pizza, double cheesePrice = 1.50);
    
    double getPrice() const override;
    std::string getName() const override;
    void printPizza() const override;
};

#endif