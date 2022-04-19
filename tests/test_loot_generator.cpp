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

#include "../lootFactory.hpp"
#include "../treasureGenerator.hpp"
#include "../loot.hpp"
#include "../coinage.hpp"
#include <chrono>
#include <iostream>

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
        std::cout << "##################\n"
                     "# HOARD TREASURE #\n"
                     "##################\n";
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

#define SIZE 100000

int main()
{
    std::random_device r;
    std::default_random_engine gen(r());
    std::uniform_int_distribution<int> d20(1, 20);
    Treasure* genTreasure = nullptr;
    Treasure* generatedTreasures[SIZE];

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

    std::cout << "TESTING hoard treasure\n\n\n";

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
    {
        // int roll = d20(gen);
        int roll = 4;
        generatedTreasures[i] = TreasureGenerator::generateLoot(roll, false);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto generationTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
    {
        printTreasure(generatedTreasures[i]);
    }
    stop = std::chrono::high_resolution_clock::now();
    auto printTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < SIZE; i++)
    {
        delete generatedTreasures[i];
        generatedTreasures[i] = nullptr;
    }
    stop = std::chrono::high_resolution_clock::now();
    auto deletionTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << SIZE << " Treasures generated\n"
              << "Treasure generated in " << generationTime.count() << " milliseconds\n"
              << "Treasure printed in " << 0 << " milliseconds\n"
              << "Treasure deleted in " << deletionTime.count() << " milliseconds\n";

}