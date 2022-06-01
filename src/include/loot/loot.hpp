/**
 * @file loot.hpp
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
#ifndef LOOT_HPP
#define LOOT_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <math.h>

/**
 * @brief
 * An abstract base class for loot.
 */
class Loot
{
    protected:
        // Common name by which loot is called.
        std::string _name;

        // Value of the loot.
        float _value;

    public:
        // Gets the name.
        std::string getName();

        // Gets the value.
        float getValue();

        // Sets the name.
        void setName(std::string);

        // Sets the value.
        virtual void setValue(float) = 0;

        // Creates a string representation of the loot item.
        virtual std::string toString() = 0;
};


class Gemstone: public Loot
{
    public:
        Gemstone(std::string, float);
        virtual ~Gemstone() {};
        void setValue(float);
        virtual std::string toString();
};

class Art: public Loot
{
    public:
        Art(std::string, float);
        virtual ~Art() {};
        void setValue(float);
        virtual std::string toString();
};

class MagicItem: public Loot
{
    public:
        MagicItem(std::string, float);
        virtual ~MagicItem() {};
        void setValue(float);
        virtual std::string toString();
};

#endif /* LOOT_HPP */