/**
 * @file treasureGenerator.hpp
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

#ifndef TREASURE_GENERATOR_HPP
#define TREASURE_GENERATOR_HPP


#include "loot.hpp"
#include "coinage.hpp"
#include "treasure.hpp"
#include "lootFactory.hpp"
#include <vector>
#include <random>


class TreasureGenerator
{
private:
    static Coinage* _coinageGenerator(const int);
    static Coinage* _hoardCoinageGenerator(const int);

    static void _treasureGenerator(const int, Treasure*);
    static void _treasureGeneratorCr4(Treasure*);
    static void _treasureGeneratorCr10(Treasure*);
    static void _treasureGeneratorCr16(Treasure*);
    static void _treasureGeneratorCr17(Treasure*);

public:
    ~TreasureGenerator();
    static Treasure* generateLoot(const int, const bool);
};


#endif /* TREASURE_GENERATOR_HPP */