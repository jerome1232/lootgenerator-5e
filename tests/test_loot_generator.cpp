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

#include "../treasureGenerator.hpp"
#include <chrono>
#include <iostream>

void printCoin(Loot* loot);

void printLoot(Loot* loot);

void printTreasure(Treasure* treasure);

void printMainMenu();

Treasure* rollTreasure();

bool isNumber(const std::string& str);


int main()
{
    Treasure* genTreasure = nullptr;

    bool isDone = false;
    while (!isDone)
    {
        std::string again;
        genTreasure = rollTreasure();
        printTreasure(genTreasure);
        delete genTreasure;
        genTreasure = nullptr;
        std::cout << "Again? [y/n]\n>>";
        std::cin >> again;

        if (again == "N" or again == "n")
        {
            isDone = true;
        }
    }


    // auto start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < SIZE; i++)
    // {
    //     int roll = d20(gen);
    //     generatedTreasures[i] = TreasureGenerator::generateLoot(roll, true);
    // }
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto generationTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < SIZE; i++)
    // {
    //     printTreasure(generatedTreasures[i]);
    // }
    // stop = std::chrono::high_resolution_clock::now();
    // auto printTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);


    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < SIZE; i++)
    // {
    //     delete generatedTreasures[i];
    //     generatedTreasures[i] = nullptr;
    // }
    // stop = std::chrono::high_resolution_clock::now();
    // auto deletionTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // std::cout << SIZE << " Treasures generated\n"
    //           << "Treasure generated in " << generationTime.count() << " milliseconds\n"
    //           << "Treasure printed in " << printTime.count() << " milliseconds\n"
    //           << "Treasure deleted in " << deletionTime.count() << " milliseconds\n";

    // std::cout << "TESTING hoard treasure\n\n\n";

    // auto start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < SIZE; i++)
    // {
    //     // int roll = d20(gen);
    //     int roll = 4;
    //     generatedTreasures[i] = TreasureGenerator::generateLoot(roll, false);
    // }
    // auto stop = std::chrono::high_resolution_clock::now();
    // auto generationTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < SIZE; i++)
    // {
    //     printTreasure(generatedTreasures[i]);
    // }
    // stop = std::chrono::high_resolution_clock::now();
    // auto printTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // start = std::chrono::high_resolution_clock::now();
    // for (int i = 0; i < SIZE; i++)
    // {
    //     delete generatedTreasures[i];
    //     generatedTreasures[i] = nullptr;
    // }
    // stop = std::chrono::high_resolution_clock::now();
    // auto deletionTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // std::cout << SIZE << " Treasures generated\n"
    //           << "Treasure generated in " << generationTime.count() << " milliseconds\n"
    //           << "Treasure printed in " << 0 << " milliseconds\n"
    //           << "Treasure deleted in " << deletionTime.count() << " milliseconds\n";
}

void printCoin(Loot* loot)
{
    if (loot)
    {
        std::cout << loot->get_value() << " " << loot->get_name() << std::endl;
    }
}

void printLoot(Loot* loot)
{
    if (loot)
    {
        std::cout << loot->get_value() << " gp " << loot->get_name() << std::endl;
    }
}

void printTreasure(Treasure* treasure)
{
    if (treasure)
    {
        std::cout << "############\n"
                     "# TREASURE #\n"
                     "############\n";
        if (treasure->coinage)
        {
            std::cout << "### COINAGE ###\n";
            printCoin(treasure->coinage->copper);
            printCoin(treasure->coinage->silver);
            printCoin(treasure->coinage->electrum);
            printCoin(treasure->coinage->gold);
            printCoin(treasure->coinage->platinum);
        }
        if (!treasure->artwork.empty())
        {
            std::cout << "### ARTWORK ###\n";
            for (auto e : treasure->artwork)
            {
                printLoot(e);
            }
        }
        if (!treasure->gems.empty())
        {
            std::cout << "### GEMSTONES ###\n";
            for (auto e : treasure->gems)
            {
                printLoot(e);
            }
        }
        if (!treasure->magicItems.empty())
        {
            std::cout << " ### MAGIC ITEMS ###\n";
            for (auto e : treasure->magicItems)
            {
                printLoot(e);
            }
        }
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