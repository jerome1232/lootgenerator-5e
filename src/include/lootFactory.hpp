/**
 * @file lootFactory.hpp
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

#ifndef LOOT_FACTORY_HPP
#define LOOT_FACTORY_HPP

#include "loot.hpp"
#include "coin.hpp"
#include "gemstone.hpp"
#include "art.hpp"
#include "magicItem.hpp"
#include "dice.hpp"
#include <exception>
#include <iostream>
#include <random>

/**
 * @brief Produces loot.
 *
 */
class LootFactory
{
    private:

        /**
         * @brief A 100 sided die.
         *
         */
        static Dice d100;

        /**
         * @brief A 12 sided die.
         *
         */
        static Dice d12;

        /**
         * @brief A 10 sided die.
         *
         */
        static Dice d10;

        /**
         * @brief An 8 sided die.
         *
         */
        static Dice d8;

        /**
         * @brief A 6 sided die.
         *
         */
        static Dice d6;

        /**
         * @brief A 4 sided die.
         *
         */
        static Dice d4;

        /**
         * @brief Generates a random Gem worth 10 gp. See DMG p 134.
         *
         * @return Gemstone*
         */
        static Gemstone* _gen10gpGem(const int);

        /**
         * @brief Generates a random Gem worth 50 gp. See DMG p 134.
         *
         * @return Gemstone*
         */
        static Gemstone* _gen50gpGem(const int);

        /**
         * @brief Generates a random Gem worth 100 gp. See DMG p 134.
         *
         * @return Gemstone*
         */
        static Gemstone* _gen100gpGem(const int);

        /**
         * @brief Generates a random Gem worth 500 gp. See DMG p 134.
         *
         * @return Gemstone*
         */
        static Gemstone* _gen500gpGem(const int);

        /**
         * @brief Generates a random Gem worth 1000 gp. See DMG p 134.
         *
         * @return Gemstone*
         */
        static Gemstone* _gen1000gpGem(const int);

        /**
         * @brief Generates a random Gem worth 5000 gp. See DMG p 134.
         *
         * @return Gemstone*
         */
        static Gemstone* _gen5000gpGem(const int);

        /**
         * @brief Generates a random Art piece worth 25 gp. See DMG p 134.
         *
         * @return Art*
         */
        static Art* _gen25gpArt(const int);

        /**
         * @brief Generates a random Art piece worth 250 gp. See DMG p 135.
         *
         * @return Art*
         */
        static Art* _gen250gpArt(const int);

        /**
         * @brief Generates a random Art piece worth 750 gp. See DMG p 135.
         *
         * @return Art*
         */
        static Art* _gen750gpArt(const int);

        /**
         * @brief Generates a random Art piece worth 2500 gp. See DMG p 135.
         *
         * @return Art*
         */
        static Art* _gen2500gpArt(const int);

        /**
         * @brief Generates a random Art piece worth 7500 gp. See DMG p 135.
         *
         * @return Art*
         */
        static Art* _gen7500gpArt(const int);

        /**
         * @brief Generates a random magic item from table A. See DMG p 144.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableA();

        /**
         * @brief Generates a random magic item from table B. See DMG p 144.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableB();

        /**
         * @brief Generates a random magic item from table C. See DMG p 145.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableC();

        /**
         * @brief Generates a random magic item from table D. See DMG p 145.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableD();

        /**
         * @brief Generates a random magic item from table E. See DMG p 145.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableE();

        /**
         * @brief Generates a random magic item from table F. See DMG p 146.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableF();

        /**
         * @brief Generates a random magic item from table G. See DMG p 147.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableG();

        /**
         * @brief Generates a random magic item from table H. See DMG p 148.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableH();

        /**
         * @brief Generates a random magic item from table I. See DMG p 149.
         *
         * @return MagicItem*
         */
        static MagicItem* _magicItemFactoryTableI();
    public:

        /**
         * @brief Produces a random amount of coins of specified type.
         *
         * @param int numDie The number of dice to roll.
         * @param int numDieSides The number of sides each die has.
         * @param Coin::CoinType enumeration of coin types.
         * @param int multiplier number to multiply result by. Defaults to 1.
         *
         * @return Coin*
         */
        static Coin* coinFactory(const int,
                                 const int,
                                 const CoinType,
                                 const int = 1);

        /**
         * @brief Produces a random gemstone worth passed in amount in gold.
         * @param int value gp value the gem will be worth.
         *
         * @return Gemstone*
         */
        static Gemstone* gemFactory(const int);

        /**
         * @brief Produces a random art piece worth passed in amount in gold.
         * @param int value gp value the art piece will be worth.
         *
         * @return Art*
         */
        static Art* artFactory(const int);

        /**
         * @brief Produces a random magic item, based on DMG tables.
         * @param char table The table to roll on for a magic item.
         *
         * @return MagicItem*
         */
        static MagicItem* magicItemFactory(const char);
};


#endif /* LOOT_FACTORY_HPP */