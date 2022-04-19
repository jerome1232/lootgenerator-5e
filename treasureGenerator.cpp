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

Treasure* TreasureGenerator::generateLoot(const int cr, const bool individual)
{

    Treasure* generatedTreasure = new Treasure();

    if (individual)
    {
        generatedTreasure->coinage = _coinageGenerator(cr);
    }
    else
    {
        generatedTreasure->coinage = _hoardCoinageGenerator(cr);
        _treasureGenerator(cr, generatedTreasure);
    }

    return generatedTreasure;
}

Coinage* TreasureGenerator::_coinageGenerator(const int cr)
{
    std::random_device r;
    std::default_random_engine gen(r());
    std::uniform_int_distribution<int> d100(1, 100);

    Coinage* genCoins = new Coinage();
    int roll = d100(gen);

    // std::cout << "DEBUG: " << roll << " :: " << cr << std::endl;

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
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        if (1 <= roll and roll <= 20)
        {
            genCoins->silver = LootFactory::coinFactory(4, 6, "copper", 100);
            genCoins->gold = LootFactory::coinFactory(1, 6, "gold", 10);
        }
        else if (20 < roll and roll <= 35)
        {
            genCoins->electrum = LootFactory::coinFactory(1, 6, "electrum", 100);
            genCoins->gold = LootFactory::coinFactory(1, 6, "gold", 100);
        }
        else if (35 < roll and roll <= 75)
        {
            genCoins->gold = LootFactory::coinFactory(2, 6, "gold", 100);
            genCoins->platinum = LootFactory::coinFactory(1, 6, "platinum", 10);
        }
        else
        {
            genCoins->gold = LootFactory::coinFactory(2, 6, "gold", 100);
            genCoins->platinum = LootFactory::coinFactory(2, 6, "platinum", 10);
        }
        break;
    default:
        if (1 <= roll and roll <= 15)
        {
            genCoins->electrum = LootFactory::coinFactory(2, 6, "electrum", 1000);
            genCoins->gold = LootFactory::coinFactory(8, 6, "gold", 100);
        }
        else if (15 < roll and roll <= 55)
        {
            genCoins->gold = LootFactory::coinFactory(1, 6, "gold", 1000);
            genCoins->platinum = LootFactory::coinFactory(1, 6, "platinum", 100);
        }
        else
        {
            genCoins->gold = LootFactory::coinFactory(1, 6, "gold", 1000);
            genCoins->platinum = LootFactory::coinFactory(2, 6, "platinum", 100);
        }
        break;
    }
    return genCoins;
}

Coinage* TreasureGenerator::_hoardCoinageGenerator(const int cr)
{
    Coinage* generatedCoins = new Coinage();

    if (0 <= cr and cr <= 4)
    {
        generatedCoins->copper = LootFactory::coinFactory(6, 6, "copper", 100);
        generatedCoins->silver= LootFactory::coinFactory(3, 6, "silver", 100);
        generatedCoins->gold= LootFactory::coinFactory(3, 6, "gold", 10);
    }
    else if (5 <= cr and cr <= 10)
    {
        generatedCoins->copper = LootFactory::coinFactory(2, 6, "copper", 100);
        generatedCoins->silver= LootFactory::coinFactory(2, 6, "silver", 1000);
        generatedCoins->gold= LootFactory::coinFactory(6, 6, "gold", 100);
        generatedCoins->platinum = LootFactory::coinFactory(3, 6, "platinum", 10);
    }
    else if (11 <= cr and cr <= 16)
    {
        generatedCoins->gold= LootFactory::coinFactory(4, 6, "gold", 1000);
        generatedCoins->platinum = LootFactory::coinFactory(5, 6, "platinum", 100);
    }
    else
    {
        generatedCoins->gold= LootFactory::coinFactory(12, 6, "gold", 1000);
        generatedCoins->platinum = LootFactory::coinFactory(8, 6, "platinum", 1000);

    }
    return generatedCoins;
}

void TreasureGenerator::_treasureGenerator(const int cr, Treasure* treasure)
{
    if (cr <= 4)
    {
        _treasureGeneratorCr4(treasure);
    }
}

void TreasureGenerator::_treasureGeneratorCr4(Treasure* treasure)
{
    std::random_device r;
    std::default_random_engine gen (r());
    std::uniform_int_distribution<int> d100(1, 100);
    std::uniform_int_distribution<int> d4(1, 4);
    std::uniform_int_distribution<int> d6(1, 6);

    int roll = d100(gen);
    if (7 <= roll and roll <= 16)
    {
        int numItems = d6(gen) + d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->gems.push_back(LootFactory::gemFactory(10));
        }
    }
    else if (17 <= roll and roll <= 26)
    {
        int numItems = d4(gen) + d4(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->artwork.push_back(LootFactory::artFactory(25));
        }
    }
    else if (27 <= roll and roll <= 36)
    {
        int numItems = d6(gen) + d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->gems.push_back(LootFactory::gemFactory(50));
        }
    }
    else if (37 <= roll and roll <= 44)
    {
        int numItems = d6(gen) + d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->gems.push_back(LootFactory::gemFactory(10));
        }
        numItems = d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->magicItems.push_back(LootFactory::magicItemFactory('A'));
        }
    }
    else if (45 <= roll and roll <= 52)
    {
        int numItems = d4(gen) + d4(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->artwork.push_back(LootFactory::artFactory(25));
        }
        numItems = d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->magicItems.push_back(LootFactory::magicItemFactory('A'));
        }
    }
    else if (53 <= roll and roll <= 60)
    {
        int numItems = d6(gen) + d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->gems.push_back(LootFactory::gemFactory(50));
        }
        numItems = d6(gen);
        for (int i = 0; i < numItems; i++)
        {
            treasure->magicItems.push_back(LootFactory::magicItemFactory('A'));
        }
    }
}


void TreasureGenerator::_treasureGeneratorCr10(Treasure* treasure)
{
    // TODO
}

void TreasureGenerator::_treasureGeneratorCr16(Treasure* treasure)
{
    // TODO
}

void TreasureGenerator::_treasureGeneratorCr17(Treasure* treasure)
{
    // TODO
}


