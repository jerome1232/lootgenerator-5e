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
#include "dice.hpp"
#include <exception>
#include <iostream>
#include <random>


class LootFactory
{
    private:
        static Dice d100;
        static Dice d12;
        static Dice d10;
        static Dice d8;
        static Dice d6;
        static Dice d4;

        static Gemstone* _gen10gpGem(const int);
        static Gemstone* _gen50gpGem(const int);
        static Gemstone* _gen100gpGem(const int);
        static Gemstone* _gen500gpGem(const int);
        static Gemstone* _gen1000gpGem(const int);
        static Gemstone* _gen5000gpGem(const int);

        static Art* _gen25gpArt(const int);
        static Art* _gen250gpArt(const int);
        static Art* _gen750gpArt(const int);
        static Art* _gen2500gpArt(const int);
        static Art* _gen7500gpArt(const int);

        static MagicItem* _magicItemFactoryTableA();
        static MagicItem* _magicItemFactoryTableB();
        static MagicItem* _magicItemFactoryTableC();
        static MagicItem* _magicItemFactoryTableD();
        static MagicItem* _magicItemFactoryTableE();
        static MagicItem* _magicItemFactoryTableF();
        static MagicItem* _magicItemFactoryTableG();
        static MagicItem* _magicItemFactoryTableH();
        static MagicItem* _magicItemFactoryTableI();
    public:
        virtual ~LootFactory() {};

        static Coin* coinFactory(int, int, std::string, int = 1);
        static Gemstone* gemFactory(int);
        static Art* artFactory(int);
        static MagicItem* magicItemFactory(char);
};


#endif /* LOOT_FACTORY_HPP */