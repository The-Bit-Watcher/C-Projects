#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent {
protected:
    std::string name;
    double price;

public:
    PizzaComponent(const std::string& name, double price);
    virtual ~PizzaComponent() = default;
    
    virtual std::string getName() = 0;
    virtual double getPrice() = 0;
};

#endif