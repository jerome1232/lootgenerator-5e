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
#include "dice.hpp"
#include "lootFactory.hpp"
#include <vector>
#include <random>
#include <iostream>


class TreasureGenerator
{
private:

    /**
     * @brief Generates coinage on an individual creature
     *
     * @param cr Challenge Rating
     * @return Coinage*
     */
    static Coinage* _coinageGenerator(const int);

    /**
     * @brief Generates coinage based on cr for a hoard treasure.
     *
     * @param cr Challenge Rating
     * @return Coinage*
     */
    static Coinage* _hoardCoinageGenerator(const int);

    /**
     * @brief Randomly generates Hoard treasure based on Challenge Rating
     *
     * @param cr Challenge Rating
     * @param treasure Pointer to treasure to which to add generated treasures
     */
    static void _treasureGenerator(const int, Treasure*);

    /**
     * @brief Rolls random treasure based on DnD 5e DMG
     * Treasure Hoard: Challenge 0 - 04
     * pg 137
     *
     * @param treasure Pointer to Treasure object to have the generated treasures added to.
     */
    static void _treasureGeneratorCr4(Treasure*);

    /**
     * @brief Rolls random treasure based on DnD 5e DMG
     * Treasure Hoard: Challenge 05 - 10
     * pg 137
     *
     * @param treasure Pointer to Treasure object to have the generated treasures added to.
     */
    static void _treasureGeneratorCr10(Treasure*);

    /**
     * @brief Rolls random treasure based on DnD 5e DMG
     * Treasure Hoard: Challenge 11 - 16
     * pg 138
     *
     * @param treasure Pointer to Treasure object to have the generated treasures added to.
     */
    static void _treasureGeneratorCr16(Treasure*);

    /**
     * @brief Rolls random treasure based on DnD 5e DMG
     * Treasure Hoard: Challenge 17+
     * pg 139
     *
     * @param treasure Pointer to Treasure object to have the generated treasures added to.
     */
    static void _treasureGeneratorCr17(Treasure*);

public:
    ~TreasureGenerator();

    /**
     * @brief Generates loot for individual or Hoard encounters
     *
     * @param cr Challenge Rating
     * @param isIndividual A bool to indicate whether individual or hoard treasure
     *                     should be generated.
     * @return Treasure*
     */
    static Treasure* generateLoot(const int, const bool);
};


#endif /* TREASURE_GENERATOR_HPP */