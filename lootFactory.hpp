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
#include <random>


class LootFactory
{
    private:
        static std::random_device r;
        static std::default_random_engine gen;
        static std::uniform_int_distribution<int> distribution;
    public:
        virtual ~LootFactory() {};

        static Coin* coinFactory(int, int, std::string, int = 1);
        static Gemstone* gemFactory(int);
        static Art* artFactory(std::string, std::string, float);
        static MagicItem* magicItemFactory(std::string, std::string, float);
};


#endif /* LOOT_FACTORY_HPP */