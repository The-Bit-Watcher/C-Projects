#include "PizzaDecorator.h"

PizzaDecorator::PizzaDecorator(std::shared_ptr<Pizza> pizza) 
    : pizza(pizza) {
}