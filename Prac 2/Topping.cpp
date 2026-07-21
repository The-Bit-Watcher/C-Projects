#include "Topping.h"

    #include "Topping.h"

Topping::Topping(const std::string& name, double price) 
    : PizzaComponent(name, price) {
}

std::string Topping::getName() {
    return name;
}

double Topping::getPrice() {
    return price;
}
