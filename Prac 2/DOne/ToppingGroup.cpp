#include "ToppingGroup.h"
#include <iostream>

ToppingGroup::ToppingGroup(const std::string& name, double basePrice) 
    : PizzaComponent(name, basePrice) {
}

void ToppingGroup::add(std::shared_ptr<PizzaComponent> component) {
    toppings.push_back(component);
}

void ToppingGroup::remove(std::shared_ptr<PizzaComponent> component) {
    for (size_t i = 0; i < toppings.size(); ++i) {
        if (toppings[i] == component) {
            toppings.erase(toppings.begin() + i);
            break;
        }
    }
}

std::string ToppingGroup::getName() {
    std::string result = name + " with: ";
    for (std::shared_ptr<PizzaComponent> topping : toppings) {
        result += topping->getName() + ", ";
    }
    if (!toppings.empty()) {
        result = result.substr(0, result.length() - 2); 
    }
    return result;
}

double ToppingGroup::getPrice() {
    double total = price; // Base price
    for (std::shared_ptr<PizzaComponent> topping : toppings) {
        total += topping->getPrice();
    }
    return total;
}

void ToppingGroup::clearToppings() {
    toppings.clear();
}