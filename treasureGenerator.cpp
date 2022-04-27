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

    Coinage* genCoins = new Coinage();
    Dice d100(100);
    int roll = d100.roll();

    switch (cr)
    {
    case 0 ... 4:
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
    case 5 ... 10:
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
    case 11 ... 16:
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
    else if (cr <= 10)
    {
        _treasureGeneratorCr10(treasure);
    }
    else if (cr <= 16)
    {
        _treasureGeneratorCr16(treasure);
    }
    else
    {
        _treasureGeneratorCr17(treasure);
    }
}

void TreasureGenerator::_treasureGeneratorCr4(Treasure* treasure)
{
    Dice d100(100);
    Dice d6(6);
    Dice d4(4);

    int roll = d100.roll();
    switch(roll)
    {
        case 1 ... 6:
            break;
        case 7 ... 16:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 10;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            break;
        }
        case 17 ... 26:
        {
            int numItems = d4.roll(2);
            const int GP_VALUE = 25;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            break;
        }
        case 27 ... 36:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            break;
        }
        case 37 ... 44:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 10;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            numItems = d6.roll();
            const char LOOT_TABLE = 'A';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 45 ... 52:
        {
            int numItems = d4.roll(2);
            const int GP_VALUE = 25;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            numItems = d6.roll();
            const char LOOT_TABLE = 'A';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 53 ... 60:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            numItems = d6.roll();
            const char LOOT_TABLE = 'A';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 61 ... 65:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 10;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'B';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 66 ... 70:
        {
            int numItems = d4.roll();
            const int GP_VALUE = 25;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork.push_back(LootFactory::artFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'B';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 71 ... 75:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(50));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'B';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 76 ... 78:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 10;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'C';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 79 ... 80:
        {
            int numItems = d4.roll(2);
            const int GP_VALUE = 25;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'C';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 81 ... 85:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'C';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 86 ... 92:
        {
            int numItems = d4.roll(2);
            const int GP_VALUE = 25;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'F';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 93 ... 97:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            numItems = d4.roll();
            const char LOOT_TABLE = 'F';
            for (int i = 0; i < numItems; i++)
            {
                treasure->magicItems
                    .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            }
            break;
        }
        case 98 ... 99:
        {
            int numItems = d4.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            const char LOOT_TABLE = 'G';
            treasure->magicItems
                .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            break;
        }
        case 100:
        {
            int numItems = d6.roll(2);
            const int GP_VALUE = 50;
            for (int i = 0; i < numItems; i++)
            {
                treasure->gems
                    .push_back(LootFactory::gemFactory(GP_VALUE));
            }
            const char LOOT_TABLE = 'G';
            treasure->magicItems
                .push_back(LootFactory::magicItemFactory(LOOT_TABLE));
            break;
        }
    }
}


void TreasureGenerator::_treasureGeneratorCr10(Treasure* treasure)
{
    Dice d100(100);
    Dice d6(6);
    Dice d4(4);
    int roll = d100.roll();

    switch(roll)
    {
        case 1 ... 4:
            break;
        case 5 ... 10:
        {
            int numRolls = d4.roll(2);
            const int GP_VALUE = 25;
            for (int i = 0; i < numRolls; i++)
            {
                treasure->gems.push_back(LootFactory::gemFactory(GP_VALUE));
            }
            break;
        }
        case 11 ... 16:
        {
            int numRolls = d6.roll(3);
            const int GP_VALUE = 50;
            for (int i = 0; i < numRolls; i++)
            {
                treasure->artwork.push_back(LootFactory::artFactory(GP_VALUE));
            }
            break;
        }
        case 17 ... 22:
        {
            int numRolls = d6.roll(3);
            const int GP_VALUE = 100;
            for (int i = 0; i < numRolls; i++)
            {
                treasure->gems.push_back(LootFactory::gemFactory(GP_VALUE));
            }
            break;
        }
        case 23 ... 28:
        {
            int numRolls = d4.roll(2);
            const int GP_VALUE = 250;
            for (int i = 0; i < numRolls; i++)
            {
                treasure->artwork
                    .push_back(LootFactory::artFactory(GP_VALUE));
            }
            break;
        }
        case 29 ... 32:
        {
            break;
        }
        case 33 ... 36:
        {
            break;
        }
        case 37 ... 40:
        {
            break;
        }
        case 41 ... 44:
        {
            break;
        }
        case 45 ... 49:
        {
            break;
        }
        case 50 ... 54:
        {
            break;
        }
        case 55 ... 59:
        {
            break;
        }
        case 60 ... 63:
        {
            break;
        }
        case 64 ... 66:
        {
            break;
        }
        case 67 ... 69:
        {
            break;
        }
        case 70 ... 72:
        {
            break;
        }
        case 73 ... 74:
        {
            break;
        }
        case 75 ... 76:
        {
            break;
        }
        case 79:
        {
            break;
        }
        case 80:
        {
            break;
        }
        case 81 ... 84:
        {
            break;
        }
        case 85 ... 88:
        {
            break;
        }
        case 89 ... 91:
        {
            break;
        }
        case 92 ... 94:
        {
            break;
        }
        case 95 ... 96:
        {
            break;
        }
        case 97 ... 98:
        {
            break;
        }
        case 99:
        {
            break;
        }
        case 100:
        {
            break;
        }
    }
}

void TreasureGenerator::_treasureGeneratorCr16(Treasure* treasure)
{
    // TODO
}

void TreasureGenerator::_treasureGeneratorCr17(Treasure* treasure)
{
    // TODO
}
