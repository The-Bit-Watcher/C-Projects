#include "BasePizza.h"
#include <iostream>

BasePizza::BasePizza(const std::string& name, double basePrice) 
    : name(name), basePrice(basePrice) {
}

void BasePizza::addTopping(std::shared_ptr<PizzaComponent> topping) {
    toppings.push_back(topping);
}

double BasePizza::getPrice() const {
    double total = basePrice;
    for (const auto& topping : toppings) {
        total += topping->getPrice();
    }
    return total;
}

std::string BasePizza::getName() const {
    return name;
}

void BasePizza::printPizza() const {
    std::cout << "Pizza: " << name << std::endl;
    std::cout << "Base Price: R" << basePrice << std::endl;
    for (const auto& topping : toppings) {
        std::cout << " - " << topping->getName() << ": R" << topping->getPrice() << std::endl;
    }
    std::cout << "Total: R" << getPrice() << std::endl;    
}