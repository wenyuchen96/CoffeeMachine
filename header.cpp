//
//  header.cpp
//  CoffeeMachineProject
//
//  Created by Wenyu Chen on 8/5/24.
//

#include "header.hpp"
#include <iostream>
#include <string>

//currently not passing by reference
CoffeeMachine::CoffeeMachine(int new_water, int new_milk, int new_coffee, float new_money) {
    water = new_water;
    milk = new_milk;
    coffee = new_coffee;
    money = new_money;
}

void CoffeeMachine::setChoice(std::string new_choice){
    choice = new_choice;
}

int CoffeeMachine::getWater(){
    return water;
}

void CoffeeMachine::deductWater(int waterCost){
    water -= waterCost;
}

int CoffeeMachine::getMilk(){
    return milk;
}

void CoffeeMachine::deductMilk(int milkCost){
    milk -= milkCost;
}

int CoffeeMachine::getCoffee(){
    return coffee;
}

void CoffeeMachine::deductCoffee(int coffeeCost){
    coffee -= coffeeCost;
}

float CoffeeMachine::getMoney(){
    return money;
}

void CoffeeMachine::addMoney(float new_money){
    money += new_money;
}

void CoffeeMachine::report(){
    std::cout << "Water: " + std::to_string(getWater()) + "ml" << "\n";
    std::cout << "Milk: " + std::to_string(getMilk()) + "ml" << "\n";
    std::cout << "Coffee: " + std::to_string(getCoffee()) + "g" << "\n";
    std::cout << "Money: $" + std::to_string(getMoney()) << "\n";
}

float CoffeeMachine::transaction(float quarters, float dimes, float nickles, float pennies){
    float monetaryValue = 0.25*quarters + 0.1*dimes + 0.05*nickles + 0.01*pennies;
    return monetaryValue;
}
