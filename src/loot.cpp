/**
 * @file loot.cpp
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

#ifndef LOOT_H
#define LOOT_H

#include "loot.hpp"

Loot::Loot(std::string name)
{
    setName(name);
}

bool Loot::isInt(float num)
{
    if (rintf(num) - num <= 0.0000001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Loot::setName(std::string name)
{
    _name = name;
}

std::string Loot::getName()
{
    return _name;
}

float Loot::getValue()
{
    return _value;
}

Coin::Coin(std::string name, float value)
    : Loot(name)
    {
        setValue(value);
    };

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

Gemstone::Gemstone(std::string name, float value)
    : Loot(name)
{
    setValue(value);
}

void Gemstone::setValue(float value)
{
    if (value >= 0)
    {
        _value = round(value);
    }
    else
    {
        _value = 0;
    }
}

std::string Gemstone::toString()
{
    std::ostringstream oss;
    oss << getName() << " gem worth " << getValue() << " gp";
    return oss.str();
}

Art::Art(std::string name, float value)
    : Loot(name)
{
    setValue(value);
}

void Art::setValue(float value)
{
    if (value >= 0)
    {
        _value = round(value);
    }
    else
    {
        _value = 0;
    }
}

std::string Art::toString()
{
    std::ostringstream oss;
    oss << getName() << " art worth " << getValue() << " gp";
    return oss.str();
}

MagicItem::MagicItem(std::string name, float value)
    : Loot(name)
{
    setValue(value);
}

void MagicItem::setValue(float value)
{
    if (value >= 0)
    {
        _value = round(value);
    }
    else
    {
        _value = 0;
    }
}

std::string MagicItem::toString()
{
    return getName();
}

#endif