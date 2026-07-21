#include "ExtraCheese.h"
#include <iostream>

ExtraCheese::ExtraCheese(std::shared_ptr<Pizza> pizza, double cheesePrice) 
    : PizzaDecorator(pizza), cheesePrice(cheesePrice) {
}

double ExtraCheese::getPrice() const {
    return pizza->getPrice() + cheesePrice;
}

std::string ExtraCheese::getName() const {
    return pizza->getName() + " + Extra Cheese";
}

void ExtraCheese::printPizza() const {
    pizza->printPizza();
    std::cout << " + Extra Cheese: R" << cheesePrice << std::endl;
    std::cout << "New Total: R" << getPrice() << std::endl;
}