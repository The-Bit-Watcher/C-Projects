#include <iostream>
#include <memory>
#include "Topping.h"
#include "ToppingGroup.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "BasePizza.h"

int main() {
    //individual toppings
    std::shared_ptr<Topping> cheese = std::make_shared<Topping>("Mozzarella Cheese", 2.50);
    std::shared_ptr<Topping> pepperoni = std::make_shared<Topping>("Pepperoni", 3.00);
    std::shared_ptr<Topping> mushrooms = std::make_shared<Topping>("Mushrooms", 1.75);
    std::shared_ptr<Topping> olives = std::make_shared<Topping>("Black Olives", 1.50);
    std::shared_ptr<Topping> bacon = std::make_shared<Topping>("Bacon", 2.75);
    
    //topping groups
    std::shared_ptr<ToppingGroup> veggieGroup = std::make_shared<ToppingGroup>("Vegetable Toppings");
    std::shared_ptr<ToppingGroup> meatGroup = std::make_shared<ToppingGroup>("Meat Toppings");
    
    //add
    veggieGroup->add(mushrooms);
    veggieGroup->add(olives);  
    meatGroup->add(pepperoni);
    meatGroup->add(bacon);
    
    std::shared_ptr<ToppingGroup> pizza = std::make_shared<ToppingGroup>("Large Pizza", 12.99);
    pizza->add(cheese);
    pizza->add(veggieGroup);
    pizza->add(meatGroup);
    
    std::cout << "=== PIZZA ORDER ===" << std::endl;
    std::cout << "Item: " << pizza->getName() << std::endl;
    std::cout << "Total Price: R" << pizza->getPrice() << std::endl;
    std::cout << "===================" << std::endl;

    std::cout << "====================" << std::endl;
    std::cout<<"Start of Decorator Testing"<<std::endl;

    std::shared_ptr<BasePizza> margherita = std::make_shared<BasePizza>("Margherita", 8.99); 
    //add toppings
    margherita->addTopping(std::make_shared<Topping>("Mozzarella", 1.50));
    margherita->addTopping(std::make_shared<Topping>("Tomato Sauce", 0.50));
    margherita->addTopping(std::make_shared<Topping>("Basil", 0.75));
    
    //extra cheese
    std::shared_ptr<ExtraCheese> withCheese = std::make_shared<ExtraCheese>(margherita);  
    //stuffed crust
    std::shared_ptr<StuffedCrust> deluxePizza = std::make_shared<StuffedCrust>(withCheese);
    
    std::cout << "=== PIZZA ORDER ===" << std::endl;
    deluxePizza->printPizza();
    std::cout << "===================" << std::endl;
    
    return 0;
}