
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
#include <iostream>
#include <math.h>

Loot::Loot(std::string name, std::string description, float value)
{
    set_name(name);
    set_description(description);
    set_value(value);
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

void Loot::set_name(std::string name)
{
    _name = name;
}

void Loot::set_description(std::string description)
{
    _description = description;
}

void Coin::set_value(float value)
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

void Gemstone::set_value(float value)
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

void Art::set_value(float value)
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

void MagicItem::set_value(float value)
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

#endif