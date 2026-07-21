#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "Pizza.h"
#include "PizzaComponent.h"
#include <memory>
#include <vector>

class BasePizza : public Pizza {
private:
    std::vector<std::shared_ptr<PizzaComponent>> toppings;    
    std::string name;
    double basePrice;
public:
    BasePizza(const std::string& name, double basePrice);
    
    void addTopping(std::shared_ptr<PizzaComponent> topping);
    double getPrice() const override;
    std::string getName() const override;
    void printPizza() const override;
};

#endif