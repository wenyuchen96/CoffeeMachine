//
//  header.hpp
//  CoffeeMachineProject
//
//  Created by Wenyu Chen on 8/5/24.
//

#ifndef header_hpp
#define header_hpp

#include <stdio.h>
#include <string>

class CoffeeMachine {
private:
    int water;
    int milk;
    int coffee;
    float money;
    std::string choice;
    
public:
    //constructors, currently not passing by reference
    CoffeeMachine(int new_water, int new_milk, int new_coffee, float new_money);
    
//    setters and getters
    void setChoice(std::string new_choice);
    int getWater();
    void deductWater(int waterCost);
    int getMilk();
    void deductMilk(int milkCost);
    int getCoffee();
    void deductCoffee(int coffeeCost);
    
    void addMoney(float new_money);
    float getMoney();
    
//    report
    void report();
    
//    transaciton
    float transaction(float quarters, float dimes, float nickles, float pennies);
    
    
};


#endif /* header_hpp */
