/**
 * @file main.cpp
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

#include "treasureGenerator.hpp"
#include <chrono>
#include <iostream>
#include <string>
#include <unordered_map>

void printHelp();

int main(int argc, char **argv)
{
    // Checking that there are exactly 4 arguments.
    if (argc < 5 or argc > 5)
    {
        printHelp();
        return 1;
    }

    std::unordered_map<std::string, std::string> args;
    args  = { { argv[1], argv[2] },
              { argv[3], argv[4] } };

    int cr;
    bool isIndividual;
    if (args.contains("-cr") and args.contains("-individual"))
    {
        try
        {
            cr = std::stoi(args.at("-cr"));
            if (args.at("-individual") == "true")
            {
                isIndividual = true;
            }
            else if (args.at("-individual") == "false")
            {
                isIndividual = false;
            }
            else
            {
                throw std::invalid_argument("-individual must be \"false\" or \"true\"");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    Treasure* pTreasure = TreasureGenerator::generateLoot(cr, isIndividual);
    std::cout << pTreasure->toString() << "\n";
    return 0;
}

void printHelp()
{
    std::cout << "Add arguments -cr n -individual false\n";
};
