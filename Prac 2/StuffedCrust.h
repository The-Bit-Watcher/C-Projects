#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H

#include "PizzaDecorator.h"

class StuffedCrust : public PizzaDecorator {
private:
    double crustPrice;

public:
    StuffedCrust(std::shared_ptr<Pizza> pizza, double crustPrice = 2.00);
    
    double getPrice() const override;
    std::string getName() const override;
    void printPizza() const override;
};

#endif