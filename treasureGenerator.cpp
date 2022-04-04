/**
 * @file treasureGenerator.cpp
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

#include "treasureGenerator.hpp"
#include "lootFactory.hpp"
#include <iostream>

treasure* TreasureGenerator::generate_loot(int cr, bool individual)
{

    treasure* generatedTreasure = new treasure();
    generatedTreasure->coinage = nullptr;

    if (individual)
    {
        generatedTreasure->coinage = _coinage_generator(cr);
    }
    else
    {
        // TODO
    }

    return generatedTreasure;
}

coins* TreasureGenerator::_coinage_generator(int cr)
{
    std::random_device r;
    std::default_random_engine gen(r());
    std::uniform_int_distribution<int> d100(1, 100);

    coins* genCoins = new coins();
    genCoins->copper = nullptr;
    genCoins->silver = nullptr;
    genCoins->electrum = nullptr;
    genCoins->gold = nullptr;
    genCoins->platinum = nullptr;
    int roll = d100(gen);

    switch (cr)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        if  (1 <= roll and roll <= 30)
        {
            genCoins->copper = LootFactory::coinFactory(5, 6, "copper");
        }
        else if (30 < roll and roll <= 60)
        {
            genCoins->silver = LootFactory::coinFactory(4, 6, "silver");
        }
        else if (60 < roll and roll <= 70)
        {
            genCoins->electrum = LootFactory::coinFactory(3, 6, "electrum");
        }
        else if (70 < roll and roll <= 95)
        {
            genCoins->gold = LootFactory::coinFactory(3, 6, "gold");
        }
        else
        {
            genCoins->platinum = LootFactory::coinFactory(1, 6, "platinum");
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if (1 <= roll and roll <= 30)
        {
            genCoins->copper = LootFactory::coinFactory(4, 6, "copper", 100);
            genCoins->electrum = LootFactory::coinFactory(1, 6, "electrum", 10);
        }
        else if (30 < roll and roll <= 60)
        {
            genCoins->silver = LootFactory::coinFactory(6, 6, "silver", 10);
            genCoins->gold = LootFactory::coinFactory(2, 6, "gold", 10);
        }
        else if (60 < roll and roll <= 70)
        {
            genCoins->electrum = LootFactory::coinFactory(3, 6, "electrum", 10);
            genCoins->gold = LootFactory::coinFactory(2, 6, "gold", 10);
        }
        else if (70 < roll and roll <= 95)
        {
            genCoins->gold = LootFactory::coinFactory(4, 6, "gold", 10);
        }
        else
        {
            genCoins->gold = LootFactory::coinFactory(2, 6, "gold", 10);
            genCoins->platinum = LootFactory::coinFactory(3, 6, "platinum");
        }
        break;
    default:
        break;
    }

    return genCoins;
}