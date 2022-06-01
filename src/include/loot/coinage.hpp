/**
 * @file coinage.hpp
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
#ifndef COINAGE_HPP
#define COINAGE_HPP

#include "coin.hpp"
#include "ostream"

class Coinage
{
public:
    Coinage(Coin* = nullptr, Coin* = nullptr, Coin* = nullptr,
            Coin* = nullptr, Coin* = nullptr);
    ~Coinage();

    Coin* copper;
    Coin* silver;
    Coin* electrum;
    Coin* gold;
    Coin* platinum;

    std::string toString();
};

#endif
