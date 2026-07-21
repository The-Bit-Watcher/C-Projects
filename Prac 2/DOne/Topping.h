#ifndef TOPPING_H
#define TOPPING_H

#include "PizzaComponent.h"
#include <string>

class Topping : public PizzaComponent {
public:
    Topping(const std::string& name, double price);
    ~Topping() override = default;
    
    std::string getName() override;
    double getPrice() override;
};

#endif