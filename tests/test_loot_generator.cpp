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
#include <iostream>

void printLoot(Loot* loot)
{
    if (loot)
    {
        std::cout << loot->get_value() << " " << loot->get_name() << std::endl;
    }
}

void delTreasure(treasure* pTreasure)
{
    if (!pTreasure)
    {
        return;
    }
    if (!pTreasure->coinage)
    {
        delete pTreasure;
        pTreasure = nullptr;
        return;
    }
    if (pTreasure->coinage->copper)
    {
        delete pTreasure->coinage->copper;
        pTreasure->coinage->copper = nullptr;
    }
    if (pTreasure->coinage->silver)
    {
        delete pTreasure->coinage->silver;
        pTreasure->coinage->silver = nullptr;
    }
    if (pTreasure->coinage->electrum)
    {
        delete pTreasure->coinage->electrum;
        pTreasure->coinage->electrum = nullptr;
    }
    if (pTreasure->coinage->gold)
    {
        delete pTreasure->coinage->gold;
        pTreasure->coinage->gold = nullptr;
    }
    if (pTreasure->coinage->platinum)
    {
        delete pTreasure->coinage->platinum;
        pTreasure->coinage->platinum = nullptr;
    }
    delete pTreasure->coinage;
    pTreasure->coinage = nullptr;
    delete pTreasure;
    pTreasure = nullptr;
}

int main()
{
    std::random_device r;
    std::default_random_engine gen(r());
    std::uniform_int_distribution<int> d20(1, 20);
    treasure* genTreasure;

    for (int i = 0; i < 1000; i++)
    {
        int roll = d20(gen);
        std::cout << "##########################################\n"
                  << "Generating Individual treasure for CR: "
                  << roll << std::endl;
        genTreasure = TreasureGenerator::generate_loot(roll, true);
        if (genTreasure && genTreasure->coinage)
        {
            printLoot(genTreasure->coinage->copper);
            printLoot(genTreasure->coinage->silver);
            printLoot(genTreasure->coinage->electrum);
            printLoot(genTreasure->coinage->gold);
            printLoot(genTreasure->coinage->platinum);
        }
        delTreasure(genTreasure);
    }
}