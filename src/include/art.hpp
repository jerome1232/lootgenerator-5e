/**
 * @file art.hpp
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

#ifndef ART_HPP
#define ART_HPP

#include "loot.hpp"
#include <cmath>

/**
 * @brief Represents a work of art.
 *
 */
class Art: public Loot
{
    public:
        /**
         * @brief Construct a new Art object.
         *
         */
        Art(std::string, float);

        /**
         * @brief Set the Value object.
         *
         */
        void setValue(float);

        /**
         * @brief Represent an Art object as a string.
         *
         * @return std::string
         */
        virtual std::string toString();
};

#endif /* ART_HPP */