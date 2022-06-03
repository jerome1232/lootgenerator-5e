/**
 * @file coin.cpp
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
#include "coin.hpp"

Coin::Coin(CoinType coinType, float value)
    : Loot(value)
    {
        setName(coinType);
    };

void Coin::setName(CoinType coinType)
{
    switch (coinType)
    {
    case CoinType::COPPER:
        _name = "copper";
        break;
    case CoinType::SILVER:
        _name = "silver";
        break;
    case CoinType::ELECTRUM:
        _name = "electrum";
        break;
    case CoinType::GOLD:
        _name = "gold";
        break;
    case CoinType::PLATINUM:
        _name = "platinum";
        break;
    }
}

void Coin::setValue(float value)
{
    if (value >= 0)
    {
        _value = value;
    }
    else
    {
        _value = 0;
    }
}

std::string Coin::toString()
{
    std::ostringstream oss;
    std::string pluralityOfCoin = getValue() == 1 ? "coin" : "coins";
    oss << getValue() << " " << getName() << " " << pluralityOfCoin;
    return oss.str();
}
