/**
 * @file main.cpp
 * @author Jeremy Jones <j.jones1232@gmail.com>
 * @brief
 * @version 0.1
 * @date 2022-03-12
 *
 * @copyright Copyright (c) 2022
 *
 *
 * This file is part of Loot Generator <https://github.com/chiditarod/dogtag>.
 *
 * Loot Generator is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Loot Generator is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Loot Generator.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../src/treasureGenerator.hpp"
#include <chrono>
#include <iostream>

#define PASS "[\033[0;32mpass\033[0;m]"
#define FAIL "[\033[0;31mfail\033[0;m]"

void printCoin(Loot* loot);

void printLoot(Loot* loot);

void printTreasure(Treasure* treasure);

void printMainMenu();

Treasure* rollTreasure();

bool isNumber(const std::string& str);

bool testCoinage();

bool testCoin();

int main()
{
    // Treasure* genTreasure = nullptr;

    // bool isDone = false;
    // while (!isDone)
    // {
    //     std::string again;
    //     genTreasure = rollTreasure();
    //     printTreasure(genTreasure);
    //     delete genTreasure;
    //     genTreasure = nullptr;
    //     std::cout << "Again? [y/n]\n>>";
    //     std::cin >> again;

    //     if (again == "N" or again == "n")
    //     {
    //         isDone = true;
    //     }
    testCoin();
    return 0;
}

bool testCoin()
{
    std::string result;
    std::string test;
    test = "Creating \"Copper\" Coin with value 1";
    std::cout << "\033[0;33m***Testing Coin creation***\n"
              << "---------------------------\033[0;m\n";
    Coin coin = Coin("Copper", 1);
    if (coin.getName() == "Copper" and coin.getValue() == 1)
    {
        std::cout << PASS << " " << test << "\n";
    }
    else
    {
        std::cout << FAIL << " " << test << "\n";
    }


    return true;
}

bool testCoinage()
{

}

void printTreasure(Treasure* treasure)
{
    if (treasure)
    {
        std::cout << treasure->toString() << std::endl;
    }
}

void printMainMenu()
{
    std::cout << "Select one.\n"
              << "---------------------\n"
              << "[1] Generate Individual Treasure\n"
              << "[2] Generate Hoard Treasure\n"
              << ">>";
}

void printCrMenu()
{
    std::cout << "Enter CR (must be between 1 and 20\n"
              << ">>";
}

Treasure* rollTreasure()
{
    bool isDone = false;
    bool isIndividual;
    Treasure* treasure = nullptr;

    while (!isDone)
    {
        printMainMenu();
        unsigned int selection;
        std::string reply;
        std::cin >> reply;

        if (isNumber(reply) and
                 std::stoi(reply) > 0 and
                 std::stoi(reply) <= 2)
        {
            selection = std::stoi(reply);
            if (selection == 1)
            {
                isIndividual = true;
            }
            else
            {
                isIndividual = false;
            }
            isDone = true;
        }
        else
        {
            std::cout << "Invalid input\n";
        }
    }

    isDone = false;
    int cr;
    while (!isDone)
    {
        std::string reply;
        int cr;
        printCrMenu();
        std::cin >> reply;

        if (isNumber(reply))
        {
            cr = std::stoi(reply);
            if (cr > 0 and cr <= 20)
            {
                treasure = TreasureGenerator::generateLoot(cr, isIndividual);
                isDone = true;
            }
        }

    }
    return treasure;
}


bool isNumber(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() and std::isdigit(*it))
    {
        ++it;
    }
    return !str.empty() and it == str.end();
}