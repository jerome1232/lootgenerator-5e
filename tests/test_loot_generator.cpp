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

bool testCoin();

bool testArt();

void printPass(std::string msg);

void printFail(std::string msg, std::string expected, std::string got);

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
    if (testCoin())
    {
        printPass("All coin tests passed");
    }
    else
    {
        printFail("Some coin tests failed", "", "");
    }
    return 0;
}

void printPass(std::string msg)
{
    std::cout << PASS << " "<< msg << "\n";
}

void printFail(std::string msg, std::string expected, std::string got)
{
    std::cout << FAIL << " " << msg << "\n"
              << "EXPECTED: " << expected << "\n"
              << "GOT:      " << got << "\n";
}

bool testCoin()
{
    std::string result;
    std::string test;
    std::string expected;
    std::string got;
    std::ostringstream oss;
    bool pass = true;

    test = "Creating \"Copper\" Coin with value 1";
    std::cout << "---------------------------\033[0;m\n"
              << "\033[0;33m***Testing Coin creation***\n"
              << "---------------------------\033[0;m\n";
    Coin coin = Coin("Copper", 1);
    if (coin.getName() == "Copper" and coin.getValue() == 1)
    {
        printPass(test);
    }
    else
    {
        oss.str("");
        oss.clear();
        oss << "Expected Name: Copper | Value: 1";
        expected = oss.str();
        oss.str("");
        oss.clear();
        oss << "Got Name: " << coin.getName() << " | Value: "
            << coin.getValue() << "\n";
        got = oss.str();
        printFail(test, expected, got);
        pass = false;
    }
    test = "Creating \"Copper\" Coin with negative value";
    coin = Coin("Copper", -1);
    if (coin.getName() == "Copper" and coin.getValue() == 0)
    {
        printPass(test);
    }
    else
    {
        oss.str("");
        oss.clear();
        oss << "Expected Name: Copper | Value: 0";
        expected = oss.str();
        oss.str("");
        oss.clear();
        oss << "Got Name: " << coin.getName() << " | Value: "
            << coin.getValue() << "\n";
        got = oss.str();
        printFail(test, expected, got);
        pass = false;
    }
    test = "Creating \"Gold\" Coin with high value";
    int highValue = 2147483647;
    coin = Coin("Gold", highValue);
    if (coin.getName() == "Gold" and coin.getValue() == highValue)
    {
        printPass(test);
    }
    else
    {
        oss.str("");
        oss.clear();
        oss << "Expected Name: Gold | Value: " << highValue;
        expected = oss.str();
        oss.str("");
        oss.clear();
        oss << "Got Name: " << coin.getName() << " | Value: "
            << coin.getValue() << "\n";
        got = oss.str();
        printFail(test, expected, got);
        pass = false;
    }
    return pass;
}

bool testArt()
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