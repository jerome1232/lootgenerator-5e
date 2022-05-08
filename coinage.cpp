/**
 * @file coinage.cpp
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

#include "coinage.hpp"

Coinage::Coinage(Coin* ptrCopper, Coin* ptrSilver, Coin* ptrElectrum,
                 Coin* ptrGold, Coin* ptrPlatinum)
{
    copper = ptrCopper;
    silver = ptrSilver;
    electrum = ptrElectrum;
    gold = ptrGold;
    platinum = ptrPlatinum;
}

Coinage::~Coinage()
{
    if (copper)
    {
        delete copper;
        copper = nullptr;
    }
    if (silver)
    {
        delete silver;
        silver = nullptr;
    }
    if (electrum)
    {
        delete electrum;
        electrum = nullptr;
    }
    if (gold)
    {
        delete gold;
        gold = nullptr;
    }
    if (platinum)
    {
        delete platinum;
        platinum = nullptr;
    }
}

std::string Coinage::toString()
{
    std::ostringstream oss;
    if (copper)
        oss << copper->toString() << std::endl;
    if (silver)
        oss << silver->toString() << std::endl;
    if (electrum)
        oss << electrum->toString() << std::endl;
    if (gold)
        oss << gold->toString() << std::endl;
    if (platinum)
        oss << platinum->toString() << std::endl;
    return oss.str();
}
