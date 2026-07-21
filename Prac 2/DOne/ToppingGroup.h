#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

#include "PizzaComponent.h"
#include <vector>
#include <memory>

class ToppingGroup : public PizzaComponent {
private:
    std::vector<std::shared_ptr<PizzaComponent>> toppings;

public:
    ToppingGroup(const std::string& name, double basePrice = 0.0);
    ~ToppingGroup() override = default;
    
    void add(std::shared_ptr<PizzaComponent> component);
    void remove(std::shared_ptr<PizzaComponent> component);
    
    std::string getName() override;
    double getPrice() override;
    
    void clearToppings();
};

#endif