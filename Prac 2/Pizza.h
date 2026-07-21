#ifndef PIZZA_H
#define PIZZA_H

#include <string>

class Pizza {
public:
    virtual ~Pizza() = default;
    virtual double getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual void printPizza() const = 0;
};

#endif