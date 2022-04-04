/**
 * @file lootFactory.cpp
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

#include "lootFactory.hpp"
#include <exception>
#include <iostream>

std::random_device LootFactory::r;
std::default_random_engine LootFactory::gen (r());
std::uniform_int_distribution<int> d100(1, 100);
std::uniform_int_distribution<int> d12(1, 12);
std::uniform_int_distribution<int> d10(1, 10);
std::uniform_int_distribution<int> d8(1, 8);
std::uniform_int_distribution<int> d6(1, 6);
std::uniform_int_distribution<int> d4(1, 4);

Coin* LootFactory::coinFactory(int numDie, int numDieSides,
                               std::string coinType, int multiplier)
{
    std::string name;
    std::string desc;
    int amount = 0;
    std::uniform_int_distribution<int> dieRoll(1, numDieSides);

    if (coinType == "copper")
    {
        name = "copper";
        desc = "solid copper";
    }
    else if (coinType == "silver")
    {
        name = "silver";
        desc = "solid silver";
    }
    else if (coinType == "electrum")
    {
        name = "electrum";
        desc = "solid electrum";
    }
    else if (coinType == "gold")
    {
        name = "gold";
        desc = "solid gold";
    }
    else if (coinType == "platinum")
    {
        name = "platinum";
        desc = "solid platinum";
    }
    else
    {
        throw std::invalid_argument("Invalid coinType");
    }

    for (int i = 0; i < numDie; i++)
    {
        amount += dieRoll(gen);
    }
    amount *= multiplier;

    return new Coin(name, desc, amount);
};

Gemstone* LootFactory::gemFactory(int value)
{
    std::string name;
    std::string desc;
    int roll;

    switch (value)
    {
        case 10:
            roll = d12(gen);
            switch (roll)
            {
                case 1:
                    name = "Azurite";
                    desc = "Opaque mottled deep blue";
                    break;
                case 2:
                    name = "Banded agate";
                    desc = "Translucent striped brown blue, white, or red";
                    break;
                case 3:
                    name = "Blue quartz";
                    desc = "Transparent pale blue";
                    break;
                case 4:
                    name = "Eye agate";
                    desc = "Translucent circles of gray, white, brown, blue, or green";
                    break;
                case 5:
                    name = "Hematite";
                    desc = "Opaque gray-black";
                    break;
                case 6:
                    name = "Lapis lazuli";
                    desc = "Opaque light and dark blue with yellow flecks";
                    break;
                case 7:
                    name = "Malachite";
                    desc = "Opaque striated light and dark green";
                    break;
                case 8:
                    name = "Moss agate";
                    desc = "Translucent pink or yellow-white with mossy gray or green markings";
                    break;
                case 9:
                    name = "Obsidian";
                    desc = "Opaque black";
                    break;
                case 10:
                    name = "Rhodochrosite";
                    desc = "Opaque light pink";
                    break;
                case 11:
                    name = "Tiger eye";
                    desc = "Translucent brown with golden center";
                    break;
                case 12:
                    name = "Turquoise";
                    desc = "Opaque light blue-green";
                    break;
            }
            break;
        case 50:
            roll = d12(gen);
            switch (roll)
            {
            case 1:
                name = "Bloodstone";
                desc = "Opaque dark gray with red flecks";
                break;
            case 2:
                name = "Carnelian";
                desc = "Opaque orange to red-brown";
                break;
            case 3:
                name = "Chalcedony";
                desc = "Opaque white";
                break;
            case 4:
                name = "Chrysoprase";
                desc = "Translucent green";
                break;
            case 5:
                name = "Citrine";
                desc = "Transparent pale yellow-brown";
                break;
            case 6:
                name = "Jasper";
                desc = "Opaque blue, black, or brown";
                break;
            case 7:
                name = "Moonstone";
                desc = "Translucent white with pale blue glow";
                break;
            case 8:
                name = "Onyx";
                desc = "Opaque bands of black and white, or pure black or white";
                break;
            case 9:
                name = "Quartz";
                desc = "Transparent white, smokey gray, or yellow";
                break;
            case 10:
                name = "Sardonyx";
                desc = "Opaque bands of red and white";
                break;
            case 11:
                name = "Star rose quartz";
                desc = "Translucent rosy stone with white star-shaped center";
            case 12:
                name = "Zircon";
                desc = "Transparent pale blue-green";
            }
            break;
        case 100:
            roll = d10(gen);
            switch (roll)
            {
            case 1:
                name = "Amber";
                desc = "Transparent deep purple";
                break;
            case 2:
                name = "Amethyst";
                desc = "Transparent deep purple";
                break;
            case 3:
                name = "Chrysoberyl";
                desc = "Transparent yellow-green to pale green";
                break;
            case 4:
                name = "Coral";
                desc = "Opaque crimson";
                break;
            case 5:
                name = "Garnet";
                desc = "Transparent red, brown-green, or violet";
                break;
            case 6:
                name = "Jade";
                desc = "Translucent light green, deep green, or white";
                break;
            case 7:
                name = "Jet";
                desc = "Opaque deep black";
                break;
            case 8:
                name = "Pearl";
                desc = "Opaque lustrous white, yellow, or pink";
                break;
            case 9:
                name = "Spinel";
                desc = "Transparent red, red-brow, or deep green";
                break;
            case 10:
                name = "Tourmaline";
                desc = "Transparent pale green, blue, brown, or red";
                break;
            }
            break;
        case 500:
            roll = d6(gen);
            switch (roll)
            {
            case 1:
                name = "Alexandrite";
                desc = "Transperent dark green";
                break;
            case 2:
                name = "Aquamarine";
                desc = "Transparent pale blue-green";
                break;
            case 3:
                name = "Black pearl";
                desc = "Opaque pure black";
                break;
            case 4:
                name = "Blue spinel";
                desc = "Transparent deep blue";
                break;
            case 5:
                name = "Peridot";
                desc = "Transparent rich olive green";
                break;
            case 6:
                name = "Topaz";
                desc = "Transparent golden yellow";
                break;
            }
            break;
        case 1000:
            roll = d8(gen);
            switch (roll)
            {
            case 1:
                name = "Black opal";
                desc = "Tranlucent dark green with black mottling and golden flecks";
                break;
            case 2:
                name = "Blue sapphire";
                desc = "Transparent blue-white to medium blue";
                break;
            case 3:
                name = "Emerald";
                desc = "Transparent deep bright green";
                break;
            case 4:
                name = "Fire opal";
                desc = "Tranlucent fiery red";
                break;
            case 5:
                name = "Opal";
                desc = "Translucent pale blue with green and golden mottling";
                break;
            case 6:
                name = "Star ruby";
                desc = "Translucent pale blue with green and golden mottling";
                break;
            case 7:
                name = "Star sapphire";
                desc = "Translucent blue sapphire with white star-shaped center";
                break;
            case 8:
                name = "Yellow sapphire";
                desc = "Transparent fiery yellow or yellow-green";
                break;
            }
            break;
        case 5000:
            roll = d4(gen);
            switch (roll)
            {
            case 1:
                name = "Black sapphire";
                desc = "Translucent lustrous black with glowing highlights";
                break;
            case 2:
                name = "Diamond";
                desc = "Transparent blue-white, canary, pink, brown, or blue";
                break;
            case 3:
                name = "Jacinth";
                desc = "Transparent fiery orange";
                break;
            case 4:
                name = "Ruby";
                desc = "Transparent clear red to deep crimson";
                break;
            }
            break;
    }
    return new Gemstone(name, desc, value);
};

Art* LootFactory::artFactory(std::string name, std::string desc, float value)
{
    return new Art(name, desc, value);
};

MagicItem* LootFactory::magicItemFactory(std::string name, std::string desc, float value)
{
    return new MagicItem(name, desc, value);
}
