/**
 * @file coin.hpp
 * @author Jeremy Jones <j.jones1232@gmail.com>
 * @brief
 * @version 0.1
 * @date 2022-05-31
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
#ifndef COIN_HPP
#define COIN_HPP

#include "loot.hpp"

enum class CoinType { COPPER, SILVER, GOLD, ELECTRUM, PLATINUM };

/**
 * @brief
 * Represents a coin of any type.
 */
class Coin: public Loot
{
    private:
        // The type of coin (gold, platinum, etc..)
        CoinType _type;

    public:
        // Default Constructor.
        Coin();

        // Non-default Constructor.
        Coin(CoinType, float);

        // Sets the name of this object.
        virtual void setName(CoinType);

        // The number of coins of this type.
        virtual void setValue(float);

        // Creates a string representation of this object.
        virtual std::string toString();
};

#endif /* COIN_HPP */