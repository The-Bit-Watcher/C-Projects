#include "StuffedCrust.h"
#include <iostream>

StuffedCrust::StuffedCrust(std::shared_ptr<Pizza> pizza, double crustPrice) 
    : PizzaDecorator(pizza), crustPrice(crustPrice) {
}

double StuffedCrust::getPrice() const {
    return pizza->getPrice() + crustPrice;
}

std::string StuffedCrust::getName() const {
    return pizza->getName() + " + Stuffed Crust";
}

void StuffedCrust::printPizza() const {
    pizza->printPizza();
    std::cout << " + Stuffed Crust: R" << crustPrice << std::endl;
    std::cout << "New Total: R" << getPrice() << std::endl;
}