/**
 * @file treasure.hpp
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
#ifndef TREASURE_HPP
#define TREASURE_HPP

#include "coinage.hpp"
#include "gemstone.hpp"
#include "art.hpp"
#include "magicItem.hpp"
#include <vector>
#include <sstream>

/**
 * @brief Represents a treasure hoard.
 *
 */
class Treasure
{
public:
    /**
     * @brief The collection of coins.
     *
     */
    Coinage* coinage;

    /**
     * @brief Gems in the treasure.
     *
     */
    std::vector<Gemstone*> gems;

    /**
     * @brief Art in the treasure.
     *
     */
    std::vector<Art*> artwork;

    /**
     * @brief Magic Items in the treasure.
     *
     */
    std::vector<MagicItem*> magicItems;

    /**
     * @brief Construct a new Treasure object
     *
     */
    Treasure(Coinage* = nullptr, std::vector<Gemstone*> = {},
             std::vector<Art*> = {}, std::vector<MagicItem*> = {});

    /**
     * @brief Destroy the Treasure object
     *
     */
    ~Treasure();

    /**
     * @brief Represent the entire treasure collection as a string.
     *
     * @return std::string
     */
    std::string toString();
};

#endif /* TREASURE_HPP */