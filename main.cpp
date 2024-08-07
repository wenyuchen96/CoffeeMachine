//
//  main.cpp
//  CoffeeMachineProject
//
//  Created by Wenyu Chen on 8/5/24.
//

#include <iostream>
#include "header.hpp"
#include <unordered_map>
#include <string>

//coffee machine make 3 hot flavors: espresso, latte, and cappuccino

std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, float>>> MENU =
{
    {"espresso", {
        {"ingredients", {
            {"water", 50},
            {"coffee", 18}
        }},
        {"cost", {{"value", 1.5}}}  // Cost in cents
    }},
    {"latte", {
        {"ingredients", {
            {"water", 200},
            {"milk", 150},
            {"coffee", 24}
        }},
        {"cost", {{"value", 2.5}}}
    }},
    {"cappuccino", {
        {"ingredients", {
            {"water", 250},
            {"milk", 100},
            {"coffee", 24}
        }},
        {"cost", {{"value", 3.0}}}
    }}
};

// Define profit
float profit = 0.0;

// Define resources
std::unordered_map<std::string, int> resources = {
    {"water", 300},
    {"milk", 200},
    {"coffee", 100}
};

//define coffee machine is on or not
bool machineOn = true;

int main() {
    CoffeeMachine newCoffeeMachine(resources["water"], resources["milk"], resources["coffee"], profit);
    //        variables declaration
    std::string customerChoice;
    while(machineOn) {
//        TODO#1: 1. Prompt user by asking “​What would you like? (espresso/latte/cappuccino):”
//        TODO#2: 2. Turn off the Coffee Machine by entering “​off”​ to the prompt.
//        TODO#3: 3. Print report.
        std::cout << "What would you like? (espresso/latte/cappuccino):\n";
        std::cin >> customerChoice;
        if (customerChoice == "off") {
            machineOn = false;
        } else if(customerChoice == "report") {
            newCoffeeMachine.report();
        } else if(customerChoice == "espresso" || customerChoice == "latte" || customerChoice == "cappuccino") {
            newCoffeeMachine.setChoice(customerChoice);
            
//            TODO#4: 4. Check resources sufficient?
            bool sufficientResources = true;
            for (const auto& [ingredient, amount] : MENU[customerChoice]["ingredients"]) {
                if(ingredient == "water" && newCoffeeMachine.getWater() < amount) {
                    std::cout << "Sorry there is not enough water.\n";
                    sufficientResources = false;
                    break;
                } else if(ingredient == "milk" && newCoffeeMachine.getMilk() < amount) {
                    std::cout << "Sorry there is not enough milk.\n";
                    sufficientResources = false;
                    break;
                } else if(ingredient == "coffee" && newCoffeeMachine.getCoffee() < amount) {
                    std::cout << "Sorry there is not enough coffee.\n";
                    sufficientResources = false;
                    break;
                }
            }
//            TODO#5: 5. Process coins.
            if (!sufficientResources) {
                            continue; // Go back to the start of the while loop
            } else {
                float new_quarters;
                float new_dimes;
                float new_nickles;
                float new_pennies;
                
                std::cout << "Please insert coins: \n";
                std::cout << "Amount of quarters you'd like to insert: \n";
                std::cin >> new_quarters;
                std::cout << "Amount of dimes you'd like to insert: \n";
                std::cin >> new_dimes;
                std::cout << "Amount of nickles you'd like to insert: \n";
                std::cin >> new_nickles;
                std::cout << "Amount of pennies you'd like to insert: \n";
                std::cin >> new_pennies;
//                TODO#6: 6. Check transaction successful?
                float totalInserted = newCoffeeMachine.transaction(new_quarters, new_dimes, new_nickles, new_pennies);
                if(totalInserted == MENU[customerChoice]["cost"]["value"]) {
                    
                } else if(totalInserted > MENU[customerChoice]["cost"]["value"]){
                    std::cout << "Here is $" +std::to_string(totalInserted - MENU[customerChoice]["cost"]["value"]) +" dollars in change.\n";
//                    TODO#7 7. Make Coffee
                    std::cout << "Report existing resources: \n";
                    newCoffeeMachine.report();
                    newCoffeeMachine.addMoney(MENU[customerChoice]["cost"]["value"]);
                    newCoffeeMachine.deductWater(MENU[customerChoice]["ingredients"]["water"]);
                    if (MENU[customerChoice]["ingredients"].count("milk")) {
                    newCoffeeMachine.deductMilk(MENU[customerChoice]["ingredients"]["milk"]);
                    }
                    newCoffeeMachine.deductCoffee(MENU[customerChoice]["ingredients"]["coffee"]);
                    std::cout << "Report resources after this transaction: \n";
                    newCoffeeMachine.report();
                    
                    std::cout << "Here is your " + customerChoice + ". Enjoy!\n";
                }else {
                    std::cout << "Sorry that's not enough money. Money refunded.\n";
                    continue;
                }
//
            }
        } else {
            std::cout << "Invalid input:( Please try again.";
        }
    }
    return 0;
}
