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

Treasure* TreasureGenerator::generateLoot(const int cr, const bool isIndividual)
{

    Treasure* generatedTreasure = new Treasure();

    if (isIndividual)
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

    int gemRolls = 0;
    int artRolls = 0;
    int magicRolls = 0;
    int gpValue = 0;
    char magicItemTable = '\0';

    int roll = d100.roll();
    std::cout << "Rolled: " << roll << "\n"
              << "Check result against DMG table\n";
    switch(roll)
    {
        case 1 ... 6:
            break;
        case 7 ... 16:
            gemRolls = d6.roll(2);
            gpValue = 10;
            break;
        case 17 ... 26:
            artRolls = d4.roll(2);
            gpValue = 25;
            break;
        case 27 ... 36:
            gemRolls = d6.roll(2);
            gpValue = 50;
            break;
        case 37 ... 44:
            gemRolls = d6.roll(2);
            gpValue = 10;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 45 ... 52:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 53 ... 60:
            gemRolls = d6.roll(2);
            gpValue = 50;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 61 ... 65:
            gemRolls = d6.roll(2);
            gpValue = 10;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 66 ... 70:
            artRolls = d4.roll();
            gpValue = 25;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 71 ... 75:
            gemRolls = d6.roll(2);
            gpValue = 50;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 76 ... 78:
            gemRolls = d6.roll(2);
            gpValue = 10;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 79 ... 80:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 81 ... 85:
            gemRolls = d6.roll(2);
            gpValue = 50;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 86 ... 92:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = d4.roll();
            magicItemTable = 'F';
            break;
        case 93 ... 97:
            artRolls = d6.roll(2);
            gpValue = 50;
            magicRolls = d4.roll();
            magicItemTable = 'F';
            break;
        case 98 ... 99:
            artRolls = d4.roll(2);
            gpValue = 50;
            magicRolls = 1;
            magicItemTable = 'G';
            break;
        case 100:
            gemRolls = d6.roll(2);
            gpValue = 50;
            magicRolls = 1;
            magicItemTable = 'G';
            break;
    }
    for (int i = 0; i < gemRolls; i++)
    {
        treasure->gems
            .push_back(LootFactory::gemFactory(gpValue));
    }
    for (int i = 0; i < artRolls; i++)
    {
        treasure->artwork
            .push_back(LootFactory::artFactory(gpValue));
    }
    for (int i = 0; i < magicRolls; i++)
    {
        treasure->magicItems
            .push_back(LootFactory::magicItemFactory(magicItemTable));
    }
}

void TreasureGenerator::_treasureGeneratorCr10(Treasure* treasure)
{
    Dice d100(100);
    Dice d6(6);
    Dice d4(4);
    int gemRolls = 0;
    int artRolls = 0;
    int magicRolls = 0;
    int gpValue = 0;
    char magicItemTable = '\0';

    int roll = d100.roll();
    std::cout << "Rolled: " << roll << "\n"
              << "Check result against DMG table\n";
    switch(roll)
    {
        case 1 ... 4:
            break;
        case 5 ... 10:
            gemRolls = d4.roll(2);
            gpValue = 25;
            break;
        case 11 ... 16:
            artRolls = d6.roll(3);
            gpValue = 50;
            break;
        case 17 ... 22:
            gemRolls = d6.roll(3);
            gpValue = 100;
            break;
        case 23 ... 28:
            artRolls = d4.roll(2);
            gpValue = 250;
            break;
        case 29 ... 32:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 33 ... 36:
            gemRolls = d6.roll(3);
            gpValue = 50;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 37 ... 40:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 41 ... 44:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d6.roll();
            magicItemTable = 'A';
            break;
        case 45 ... 49:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 50 ... 54:
            gemRolls = d6.roll(3);
            gpValue = 50;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 55 ... 59:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 60 ... 63:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'B';
            break;
        case 64 ... 66:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 67 ... 69:
            gemRolls = d6.roll(3);
            gpValue = 50;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 70 ... 72:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 73 ... 74:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'C';
            break;
        case 75 ... 76:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = 1;
            magicItemTable = 'D';
            break;
        case 77 ... 78:
            gemRolls = d6.roll(3);
            gpValue = 50;
            magicRolls = 1;
            magicItemTable = 'D';
            break;
        case 79:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = 1;
            magicItemTable = 'D';
            break;
        case 80:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = 1;
            magicItemTable = 'D';
            break;
        case 81 ... 84:
            artRolls = d4.roll(2);
            gpValue = 25;
            magicRolls = d4.roll();
            magicItemTable = 'F';
            break;
        case 85 ... 88:
            gemRolls = d6.roll(3);
            gpValue = 50;
            magicRolls = d4.roll();
            magicItemTable = 'F';
            break;
        case 89 ... 91:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = d4.roll();
            magicItemTable = 'F';
            break;
        case 92 ... 94:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'F';
            break;
        case 95 ... 96:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = d4.roll();
            magicItemTable = 'G';
            break;
        case 97 ... 98:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'G';
            break;
        case 99:
            gemRolls = d6.roll(3);
            gpValue = 100;
            magicRolls = 1;
            magicItemTable = 'H';
            break;
        case 100:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = 1;
            magicItemTable = 'H';
            break;
    }
    for (int i = 0; i < gemRolls; i++)
    {
        treasure->gems
            .push_back(LootFactory::gemFactory(gpValue));
    }
    for (int i = 0; i < artRolls; i++)
    {
        treasure->artwork
            .push_back(LootFactory::artFactory(gpValue));
    }
    for (int i = 0; i < magicRolls; i++)
    {
        treasure->magicItems
            .push_back(LootFactory::magicItemFactory(magicItemTable));
    }
}

void TreasureGenerator::_treasureGeneratorCr16(Treasure* treasure)
{
    Dice d100(100);
    Dice d6(6);
    Dice d4(4);

    int gemRolls = 0;
    int artRolls = 0;
    int magicRolls = 0;
    int magicRolls2 = 0;
    int gpValue = 0;
    char magicItemTable = '\0';
    char magicItemTable2 = '\0';

    int roll = d100.roll();
    std::cout << "Rolled: " << roll << "\n"
              << "Check result against DMG table\n";

    switch (roll)
    {
        case 1 ... 3:
            break;
        case 4 ... 6:
            artRolls = d4.roll(2);
            gpValue = 250;
            break;
        case 7 ... 9:
            artRolls = d4.roll(2);
            gpValue = 750;
            break;
        case 11 ... 12:
            gemRolls = d6.roll(3);
            gpValue = 500;
            break;
        case 13 ... 15:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            break;
        case 16 ... 19:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'A';
            magicRolls2 = d6.roll();
            magicItemTable2 = 'B';
            break;
        case 20 ... 23:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = d4.roll();
            magicItemTable = 'A';
            magicRolls2 = d6.roll();
            magicItemTable2 = 'B';
            break;
        case 24 ... 26:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = d4.roll();
            magicItemTable = 'A';
            magicRolls2 = d6.roll();
            magicItemTable2 = 'B';
            break;
        case 27 ... 29:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d4.roll();
            magicItemTable = 'A';
            magicRolls2 = d6.roll();
            magicItemTable2 = 'B';
            break;
        case 30 ... 35:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d6.roll();
            magicItemTable = 'C';
            break;
        case 36 ... 40:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = d6.roll();
            magicItemTable = 'C';
            break;
        case 41 ... 45:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = d6.roll();
            magicItemTable = 'C';
            break;
        case 46 ... 50:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d6.roll();
            magicItemTable = 'C';
            break;
        case 51 ... 54:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'D';
            break;
        case 55 ... 58:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = d4.roll();
            magicItemTable = 'D';
            break;
        case 59 ... 62:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = d4.roll();
            magicItemTable = 'D';
            break;
        case 63 ... 66:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d4.roll();
            magicItemTable = 'D';
            break;
        case 67 ... 68:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = 1;
            magicItemTable = 'E';
            break;
        case 69 ... 70:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = 1;
            magicItemTable = 'E';
            break;
        case 71 ... 72:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = 1;
            magicItemTable = 'E';
            break;
        case 73 ... 74:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = 1;
            magicItemTable = 'E';
            break;
        case 75 ... 76:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = 1;
            magicItemTable = 'F';
            magicRolls2 = d4.roll();
            magicItemTable2 = 'G';
            break;
        case 77 ... 78:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = 1;
            magicItemTable = 'F';
            magicRolls2 = d4.roll();
            magicItemTable2 = 'G';
            break;
        case 79 ... 80:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = 1;
            magicItemTable = 'F';
            magicRolls2 = d4.roll();
            magicItemTable2 = 'G';
            break;
        case 81 ... 82:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = 1;
            magicItemTable = 'F';
            magicRolls2 = d4.roll();
            magicItemTable2 = 'G';
            break;
        case 83 ... 85:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = d4.roll();
            magicItemTable = 'H';
            break;
        case 86 ... 88:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = d4.roll();
            magicItemTable = 'H';
            break;
        case 89 ... 90:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = d4.roll();
            magicItemTable = 'H';
            break;
        case 91 ... 92:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d4.roll();
            magicItemTable = 'H';
            break;
        case 93 ... 94:
            artRolls = d4.roll(2);
            gpValue = 250;
            magicRolls = 1;
            magicItemTable = 'I';
            break;
        case 95 ... 96:
            artRolls = d4.roll(2);
            gpValue = 750;
            magicRolls = 1;
            magicItemTable = 'I';
            break;
        case 97 ... 98:
            gemRolls = d6.roll(3);
            gpValue = 500;
            magicRolls = 1;
            magicItemTable = 'I';
            break;
        case 99 ... 100:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = 1;
            magicItemTable = 'I';
            break;
    }
    for (int i = 0; i < gemRolls; i++)
    {
        treasure->gems
            .push_back(LootFactory::gemFactory(gpValue));
    }
    for (int i = 0; i < artRolls; i++)
    {
        treasure->artwork
            .push_back(LootFactory::artFactory(gpValue));
    }
    for (int i = 0; i < magicRolls; i++)
    {
        treasure->magicItems
            .push_back(LootFactory::magicItemFactory(magicItemTable));
    }
    for (int i = 0; i < magicRolls2; i++)
    {
        treasure->magicItems
            .push_back(LootFactory::magicItemFactory(magicItemTable2));
    }
}

void TreasureGenerator::_treasureGeneratorCr17(Treasure* treasure)
{
    Dice d100(100);
    Dice d10(10);
    Dice d8(8);
    Dice d6(6);
    Dice d4(4);

    int gemRolls = 0;
    int artRolls = 0;
    int magicRolls = 0;
    int gpValue = 0;
    char magicItemTable = '\0';

    int roll = d100.roll();
    switch(roll)
    {
        case 1 ... 2:
            break;
        case 3 ... 5:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d8.roll();
            magicItemTable = 'C';
            break;
        case 6 ... 8:
            artRolls = d10.roll();
            gpValue = 2500;
            magicRolls = d8.roll();
            magicItemTable = 'C';
            break;
        case 9 ... 11:
            artRolls = d4.roll();
            gpValue = 7500;
            magicRolls = d8.roll();
            magicItemTable = 'C';
            break;
        case 12 ... 14:
            gemRolls = d8.roll();
            gpValue = 5000;
            magicRolls = d8.roll();
            magicItemTable = 'C';
            break;
        case 15 ... 22:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d6.roll();
            magicItemTable = 'D';
            break;
        case 23 ... 30:
            artRolls = d10.roll();
            gpValue = 25000;
            magicRolls = d6.roll();
            magicItemTable = 'D';
        case 31 ... 38:
            artRolls = d4.roll();
            gpValue = 7500;
            magicRolls = d6.roll();
            magicItemTable = 'D';
        case 39 ... 46:
            gemRolls = d8.roll();
            gpValue = 5000;
            magicRolls = d6.roll();
            magicItemTable = 'D';
            break;
        case 47 ... 52:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d6.roll();
            magicItemTable = 'E';
            break;
        case 53 ... 58:
            artRolls = d10.roll();
            gpValue = 2500;
            magicRolls = d6.roll();
            magicItemTable = 'E';
            break;
        case 59 ... 63:
            artRolls = d4.roll();
            gpValue = 7500;
            magicRolls = d6.roll();
            magicItemTable = 'E';
            break;
        case 64 ... 68:
            gemRolls = d8.roll();
            gpValue = 5000;
            magicRolls = d6.roll();
            magicItemTable = 'E';
            break;
        case 69:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d4.roll();
            magicItemTable = 'G';
            break;
        case 70:
            artRolls = d10.roll();
            gpValue = 2500;
            magicRolls = d4.roll();
            magicItemTable = 'G';
            break;
        case 71:
            artRolls = d4.roll();
            gpValue = 7500;
            magicRolls = d4.roll();
            magicItemTable = 'G';
            break;
        case 72:
            gemRolls = d8.roll();
            gpValue = 5000;
            magicRolls = d4.roll();
            magicItemTable = 'G';
            break;
        case 73 ... 74:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d4.roll();
            magicItemTable = 'H';
            break;
        case 75 ... 76:
            artRolls = d10.roll();
            gpValue = 2500;
            magicRolls = d4.roll();
            magicItemTable = 'H';
        case 77 ... 78:
            artRolls = d4.roll();
            gpValue = 7500;
            magicRolls = d4.roll();
            magicItemTable = 'H';
        case 79 ... 80:
            gemRolls = d8.roll();
            gpValue = 5000;
            magicRolls = d4.roll();
            magicItemTable = 'H';
            break;
        case 81 ... 85:
            gemRolls = d6.roll(3);
            gpValue = 1000;
            magicRolls = d4.roll();
            magicItemTable = 'I';
            break;
        case 86 ... 90:
            artRolls = d10.roll();
            gpValue = 2500;
            magicRolls = d4.roll();
            magicItemTable = 'I';
            break;
        case 91 ... 95:
            artRolls = d4.roll();
            gpValue = 7500;
            magicRolls = d4.roll();
            magicItemTable = 'I';
            break;
        case 96 ... 100:
            gemRolls = d8.roll();
            gpValue = 5000;
            magicRolls = d4.roll();
            magicItemTable = 'I';
            break;
    }
    for (int i = 0; i < gemRolls; i++)
    {
        treasure->gems
            .push_back(LootFactory::gemFactory(gpValue));
    }
    for (int i = 0; i < artRolls; i++)
    {
        treasure->artwork
            .push_back(LootFactory::artFactory(gpValue));
    }
    for (int i = 0; i < magicRolls; i++)
    {
        treasure->magicItems
            .push_back(LootFactory::magicItemFactory(magicItemTable));
    }
}
