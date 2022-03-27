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

#include <string>

class Loot
{
protected:
    /* data */
    std::string _name;
    std::string _description;
    float _value;

public:
    Loot(std::string, std::string, float);

    std::string get_name();
    std::string get_description();
    float get_value();

    static bool isInt(float);

    void set_name(std::string);
    void set_description(std::string);
    virtual void set_value(float) = 0;
};

class Coin: protected Loot
{
    public:
        void set_value(float);
};

class Gemstone: protected Loot
{
    public:
        void set_value(float);
};

class Art: protected Loot
{
    public:
        void set_value(float);
};

class MagicItem: protected Loot
{
    public:
        void set_value(float);
};