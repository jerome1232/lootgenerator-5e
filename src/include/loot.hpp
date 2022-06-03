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

/**
 * @brief
 * An abstract base class for loot.
 */
class Loot
{
    protected:
        /**
         * @brief Common name by which loot is called.
         *
         */
        std::string _name;

        /**
         * @brief Value of loot.
         *
         */
        float _value;

    public:
        /**
         * @brief Construct a new Loot object.
         *
         */
        Loot(std::string);

        /**
         * @brief Construct a new Loot object
         *
         */
        Loot(float);

        // Constructor to set both name and value.
        Loot(std::string, float);

        // Gets the name.
        std::string getName();

        // Gets the value.
        float getValue();

        // Sets the value.
        virtual void setValue(float) = 0;

        // Creates a string representation of the loot item.
        virtual std::string toString() = 0;
};





#endif /* LOOT_HPP */