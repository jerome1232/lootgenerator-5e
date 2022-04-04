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

int main()
{
    treasure* genTreasure = TreasureGenerator::generate_loot(5, true);

    if (genTreasure && genTreasure->coinage)
    {
        printLoot(genTreasure->coinage->copper);
        printLoot(genTreasure->coinage->silver);
        printLoot(genTreasure->coinage->electrum);
        printLoot(genTreasure->coinage->gold);
        printLoot(genTreasure->coinage->platinum);
    }

    if (genTreasure->coinage->copper)
    {
        delete genTreasure->coinage->copper;
        genTreasure->coinage->copper = nullptr;
    }
    if (genTreasure->coinage->silver)
    {
        delete genTreasure->coinage->silver;
        genTreasure->coinage->silver = nullptr;
    }
    if (genTreasure->coinage->electrum)
    {
        delete genTreasure->coinage->electrum;
        genTreasure->coinage->electrum = nullptr;
    }
    if (genTreasure->coinage->gold)
    {
        delete genTreasure->coinage->gold;
        genTreasure->coinage->gold = nullptr;
    }
    if (genTreasure->coinage->platinum)
    {
        delete genTreasure->coinage->platinum;
        genTreasure->coinage->platinum = nullptr;
    }

    delete genTreasure->coinage;
    genTreasure->coinage = nullptr;
    delete genTreasure;
    genTreasure = nullptr;
}