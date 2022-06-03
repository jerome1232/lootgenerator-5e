/**
 * @file lootFactory.cpp
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

#include "lootFactory.hpp"

Dice LootFactory::d100(100);
Dice LootFactory::d12(12);
Dice LootFactory::d10(10);
Dice LootFactory::d8(8);
Dice LootFactory::d6(6);
Dice LootFactory::d4(4);

Coin* LootFactory::coinFactory(int numDie, int numDieSides,
                               CoinType coinType, int multiplier)
{
    std::string name;
    int amount = 0;
    Dice die(numDieSides);

    amount = die.roll(numDie);
    amount *= multiplier;

    return new Coin(coinType, amount);
};

Gemstone* LootFactory::gemFactory(const int value)
{
    Gemstone* gem = nullptr;

    switch (value)
    {
        case 10:
            gem = _gen10gpGem(value);
            break;
        case 50:
            gem = _gen50gpGem(value);
            break;
        case 100:
            gem = _gen100gpGem(value);
            break;
        case 500:
            gem = _gen500gpGem(value);
            break;
        case 1000:
            gem = _gen1000gpGem(value);
            break;
        case 5000:
            gem = _gen5000gpGem(value);
            break;
    }
    return gem;
};

Gemstone* LootFactory::_gen10gpGem(const int value)
{
    std::string name;
    int roll = d12.roll();

    switch (roll)
    {
        case 1:
            name = "Azurite (Opaque mottled deep blue)";
            break;
        case 2:
            name = "Banded agate (Translucent striped "
                   "brown blue, white, or red)";
            break;
        case 3:
            name = "Blue quartz (Transparent pale blue)";
            break;
        case 4:
            name = "Eye agate "
                   "(Translucent circles of gray, white, "
                   "brown, blue, or green)";
            break;
        case 5:
            name = "Hematite "
                   "(Opaque gray-black)";
            break;
        case 6:
            name = "Lapis lazuli "
                   "(Opaque light and dark blue with yellow flecks)";
            break;
        case 7:
            name = "Malachite "
                   "(Opaque striated light and dark green)";
            break;
        case 8:
            name = "Moss agate "
                   "(Translucent pink or yellow-white with mossy "
                   "gray or green markings)";
            break;
        case 9:
            name = "Obsidian (Opaque black)";
            break;
        case 10:
            name = "Rhodochrosite (Opaque light pink)";
            break;
        case 11:
            name = "Tiger eye "
                   "(Translucent brown with golden center";
            break;
        case 12:
            name = "Turquoise"
                   " (Opaque light blue-green)";
            break;
    }
    return new Gemstone(name, value);
}

Gemstone* LootFactory::_gen50gpGem(const int value)
{
    std::string name;
    int roll = d12.roll();

    switch (roll)
    {
        case 1:
            name = "Bloodstone "
                   "(Opaque dark gray with red flecks)";
            break;
        case 2:
            name = "Carnelian "
                   "(Opaque orange to red-brown)";
            break;
        case 3:
            name = "Chalcedony "
                   "(Opaque white)";
            break;
        case 4:
            name = "Chrysoprase "
                   "(Translucent green)";
            break;
        case 5:
            name = "Citrine "
                   "(Transparent pale yellow-brown)";
            break;
        case 6:
            name = "Jasper "
                   "(Opaque blue, black, or brown)";
            break;
        case 7:
            name = "Moonstone "
                   "(Translucent white with pale blue glow)";
            break;
        case 8:
            name = "Onyx "
                   "(Opaque bands of black and white, or pure black or white)";
            break;
        case 9:
            name = "Quartz "
                   "(Transparent white, smokey gray, or yellow)";
            break;
        case 10:
            name = "Sardonyx "
                   "(Opaque bands of red and white)";
            break;
        case 11:
            name = "Star rose quartz "
                   "(Translucent rosy stone with white star-shaped center)";
            break;
        case 12:
            name = "Zircon "
                   "(Transparent pale blue-green)";
            break;
    }
    return new Gemstone(name, value);
}

Gemstone* LootFactory::_gen100gpGem(const int value)
{
    std::string name;
    int roll = d10.roll();
    switch (roll)
    {
        case 1:
            name = "Amber "
                   "(Transparent deep purple)";
            break;
        case 2:
            name = "Amethyst "
                   "(Transparent deep purple)";
            break;
        case 3:
            name = "Chrysoberyl "
                   "(Transparent yellow-green to pale green)";
            break;
        case 4:
            name = "Coral "
                   "(Opaque crimson)";
            break;
        case 5:
            name = "Garnet "
                   "(Transparent red, brown-green, or violet)";
            break;
        case 6:
            name = "Jade "
                   "(Translucent light green, deep green, or white)";
            break;
        case 7:
            name = "Jet "
                   "(Opaque deep black)";
            break;
        case 8:
            name = "Pearl "
                   "(Opaque lustrous white, yellow, or pink)";
            break;
        case 9:
            name = "Spinel "
                   "(Transparent red, red-brow, or deep green)";
            break;
        case 10:
            name = "Tourmaline "
                   "(Transparent pale green, blue, brown, or red)";
            break;
    }
    return new Gemstone(name, value);
}

Gemstone* LootFactory::_gen500gpGem(const int value)
{
    std::string name;
    int roll = d6.roll();

    switch (roll)
    {
        case 1:
            name = "Alexandrite "
                   "(Transperent dark green)";
            break;
        case 2:
            name = "Aquamarine "
                   "(Transparent pale blue-green)";
            break;
        case 3:
            name = "Black pearl "
                   "(Opaque pure black)";
            break;
        case 4:
            name = "Blue spinel "
                   "(Transparent deep blue)";
            break;
        case 5:
            name = "Peridot "
                   "(Transparent rich olive green)";
            break;
        case 6:
            name = "Topaz "
                   "Transparent golden yellow";
            break;
    }
    return new Gemstone(name, value);
}

Gemstone* LootFactory::_gen1000gpGem(const int value)
{
    std::string name;
    int roll = d8.roll();
    switch (roll)
    {
        case 1:
            name = "Black opal "
                   "(Tranlucent dark green with "
                   "black mottling and golden flecks)";
            break;
        case 2:
            name = "Blue sapphire "
                   "(Transparent blue-white to medium blue)";
            break;
        case 3:
            name = "Emerald "
                   "(Transparent deep bright green)";
            break;
        case 4:
            name = "Fire opal "
                   "(Tranlucent fiery red)";
            break;
        case 5:
            name = "Opal "
                   "(Translucent pale blue with green and golden mottling)";
            break;
        case 6:
            name = "Star ruby "
                   "(Translucent pale blue with green and golden mottling)";
            break;
        case 7:
            name = "Star sapphire "
                   "(Translucent blue sapphire with white star-shaped center)";
            break;
        case 8:
            name = "Yellow sapphire "
                   "(Transparent fiery yellow or yellow-green)";
            break;
    }
    return new Gemstone(name, value);
}

Gemstone* LootFactory::_gen5000gpGem(const int value)
{
    std::string name;
    int roll = d4.roll();
    switch (roll)
    {
        case 1:
            name = "Black sapphire "
                   "(Translucent lustrous black with glowing highlights)";
            break;
        case 2:
            name = "Diamond "
                   "(Transparent blue-white, canary, pink, brown, or blue)";
            break;
        case 3:
            name = "Jacinth "
                   "(Transparent fiery orange)";
            break;
        case 4:
            name = "Ruby "
                   "(Transparent clear red to deep crimson)";
            break;
    }
    return new Gemstone(name, value);
}


Art* LootFactory::artFactory(const int value)
{
    Art* art = nullptr;
    switch (value)
    {
        case 25:
            art = _gen25gpArt(value);
            break;
        case 250:
            art = _gen250gpArt(value);
            break;
        case 750:
            art = _gen750gpArt(value);
            break;
        case 2500:
            art = _gen2500gpArt(value);
            break;
        case 7500:
            art = _gen7500gpArt(value);
            break;
    }
    return art;
};

Art* LootFactory::_gen25gpArt(const int value)
{
    std::string name;
    int roll = d10.roll();
    switch (roll)
    {
        case 1:
            name = "Silver ewer";
            break;
        case 2:
            name = "Carved bone statuette";
            break;
        case 3:
            name = "Small gold bracelet";
            break;
        case 4:
            name = "Cloth-of-gold vestments";
            break;
        case 5:
            name = "Black velvet mask stitched with silver thread";
            break;
        case 6:
            name = "Copper chalice with silver filigree";
            break;
        case 7:
            name = "Pair of engraved bone dice";
            break;
        case 8:
            name = "Small mirror set in a painted wooden frame";
            break;
        case 9:
            name = "Embroidered silk handkerchief";
            break;
        case 10:
            name = "Gold locket with a painted portrait inside";
            break;
    }

    return new Art(name, value);
}

Art* LootFactory::_gen250gpArt(const int value)
{
    std::string name;
    int roll = d10.roll();
    switch (roll)
    {
        case 1:
            name = "Gold ring set with bloodstones";
            break;
        case 2:
            name = "Carved ivory statuette";
            break;
        case 3:
            name = "Large gold bracelet";
            break;
        case 4:
            name = "Silver necklace with a gemstone pendant";
            break;
        case 5:
            name = "Bronze crown";
            break;
        case 6:
            name = "Silk robe with gold embroidery";
            break;
        case 7:
            name = "Large well-made tapestry";
            break;
        case 8:
            name = "Brass mug with jade inlay";
            break;
        case 9:
            name = "Box of turquoise animal figurines";
            break;
        case 10:
            name = "Gold bird cage with electrum filigree";
            break;
    }
    return new Art(name, value);
}

Art* LootFactory::_gen750gpArt(const int value)
{
    std::string name;
    int roll = d10.roll();
    switch (roll)
    {
        case 1:
            name = "Silver chalice set with moonstones";
            break;
        case 2:
            name = "Silver-plated steel longsword with jet set in hilt";
            break;
        case 3:
            name = "Carved harp of exotic wood with ivory inlay "
                   "and zircon gems";
            break;
        case 4:
            name = "Small gold idol";
            break;
        case 5:
            name = "Gold dragon comb set with red garnets as eyes";
            break;
        case 6:
            name = "Bottle stopper cork embossed with gold leaf "
                   "and set with amethysts";
            break;
        case 7:
            name = "Ceremonial electrum dagger with a black "
                   "pearl in the pommel";
            break;
        case 8:
            name = "Silver and gold brooch";
            break;
        case 9:
            name = "Obsidian statuette with gold fittings and inlay";
            break;
        case 10:
            name = "Painted gold war mask";
            break;
    }

    return new Art(name, value);
}

Art* LootFactory::_gen2500gpArt(const int value)
{
    std::string name;
    int roll = d10.roll();
    switch (roll)
    {
        case 1:
            name = "Fine gold chain set with a fire opal";
            break;
        case 2:
            name = "Old masterpiece painting";
            break;
        case 3:
            name = "Embroidered silk and velvet mantle "
                   "set with numerous moonstones";
            break;
        case 4:
            name = "Platinum bracelet set with a sapphire";
            break;
        case 5:
            name = "Embroidered glove set with jewel chips";
            break;
        case 6:
            name = "Jeweled anklet";
            break;
        case 8:
            name = "Gold circlet set with four aquamarines";
            break;
        case 9:
            name = "Eye patch with a mock eye set in "
                   "blue sapphire and moonstone";
            break;
        case 10:
            name = "A necklace string of small pink pearls";
            break;
    }

    return new Art(name, value);
}

Art* LootFactory::_gen7500gpArt(const int value)
{
    std::string name;
    int roll = d8.roll();
    switch (roll)
    {
        case 1:
            name = "Jeweled gold crown";
            break;
        case 2:
            name = "Jeweled platinum ring";
            break;
        case 3:
            name = "Small gold statuette set with rubies";
            break;
        case 4:
            name = "Gold cup set with emeralds";
            break;
        case 5:
            name = "Gold jewelry box with platinum filigree";
            break;
        case 6:
            name = "Painted gold child's sarcophagus";
            break;
        case 7:
            name = "Jade game board with solid gold playing pieces";
            break;
        case 8:
            name = "Bejeweled ivory drinking horn with gold filigree";
            break;
    }

    return new Art(name, value);
}

MagicItem* LootFactory::magicItemFactory(char table)
{
    MagicItem* magicItem = nullptr;
    switch (table)
    {
        case 'A':
        case 'a':
            magicItem = _magicItemFactoryTableA();
            break;
        case 'B':
        case 'b':
            magicItem = _magicItemFactoryTableB();
            break;
        case 'C':
        case 'c':
            magicItem = _magicItemFactoryTableC();
            break;
        case 'D':
        case 'd':
            magicItem = _magicItemFactoryTableD();
            break;
        case 'E':
        case 'e':
            magicItem = _magicItemFactoryTableE();
            break;
        case 'F':
        case 'f':
            magicItem = _magicItemFactoryTableF();
            break;
        case 'G':
        case 'g':
            magicItem = _magicItemFactoryTableG();
            break;
        case 'H':
        case 'h':
            magicItem = _magicItemFactoryTableH();
            break;
        case 'I':
        case 'i':
            magicItem = _magicItemFactoryTableI();
            break;
    }
    return magicItem;
}

MagicItem* LootFactory::_magicItemFactoryTableA()
{
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 50:
            name = "Potion of healing";
            break;
        case 51 ... 60:
            name = "Spell scroll (cantrip)";
            break;
        case 61 ... 70:
            name = "Potion of climbing";
            break;
        case 71 ... 90:
            name = "Spell scroll (1st level)";
            break;
        case 91 ... 94:
            name = "Spell scroll (2nd level)";
            break;
        case 95 ... 98:
            name = "Potion of greater healing";
            break;
        case 99:
            name = "Bag of holding";
            break;
        case 100:
            name = "Driftglobe";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableB()
{
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 15:
            name = "Potion of greater healing";
            break;
        case 16 ... 22:
            name = "Potion of fire breath";
            break;
        case 23 ... 29:
            name = "Potion of resistance";
            break;
        case 30 ... 34:
            name = "Ammunition, +1";
            break;
        case 35 ... 39:
            name = "Potion of Animal Friendship";
            break;
        case 40 ... 44:
            name = "Potion of Hill Giant Strength";
            break;
        case 45 ... 49:
            name = "Potion of growth";
            break;
        case 50 ... 54:
            name = "Potion of water breathing";
            break;
        case 55 ... 59:
            name = "Spell scroll (2nd level)";
            break;
        case 60 ... 64:
            name = "Spell scroll (3rd level)";
            break;
        case 65 ... 67:
            name = "Bag of holding";
            break;
        case 68 ... 70:
            name = "Keoghtom's ointment";
            break;
        case 71 ... 73:
            name = "Oil of slipperiness";
            break;
        case 74 ... 75:
            name = "Dust of disapperance";
            break;
        case 76 ... 77:
            name = "Dust of dryness";
            break;
        case 78 ... 79:
            name = "Dust of sneezing and choking";
            break;
        case 80 ... 81:
            name = "Elemental gem";
            break;
        case 82 ... 83:
            name = "Philter of love";
            break;
        case 84:
            name = "Alchemy jug";
            break;
        case 85:
            name = "Cap of water breathing";
            break;
        case 86:
            name = "Cloak of the manta ray";
            break;
        case 87:
            name = "Driftglobe";
            break;
        case 88:
            name = "Goggles of night";
            break;
        case 89:
            name = "Helm of comprehending languages";
            break;
        case 90:
            name = "Immovable Rob";
            break;
        case 91:
            name = "Lantern of revealing";
            break;
        case 92:
            name = "Mariner's armor";
            break;
        case 93:
            name = "Mithral armor";
            break;
        case 94:
            name = "Potion of poison";
            break;
        case 95:
            name = "Ring of swimming";
            break;
        case 96:
            name = "Robe of useful items";
            break;
        case 97:
            name = "Rope of climbing";
            break;
        case 98:
            name = "Saddle of the cavalier";
            break;
        case 99:
            name = "Wand of magic detection";
            break;
        case 100:
            name = "Wand of secrets";
            break;
    }
    return new MagicItem(name, 0);

}

MagicItem* LootFactory::_magicItemFactoryTableC()
{
        int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 15:
            name = "Potion of superior healing";
            break;
        case 16 ... 22:
            name = "Spell scroll (4th level)";
            break;
        case 23 ... 27:
            name = "Aummunition, +2";
            break;
        case 28 ... 32:
            name = "Potion of clairvoyance";
            break;
        case 33 ... 37:
            name = "Potion of duminution";
            break;
        case 38 ... 42:
            name = "Potion of gaseous form";
            break;
        case 43 ... 47:
            name = "Potion of frost giant strength";
            break;
        case 48 ... 52:
            name = "Potion of stone giant strength";
            break;
        case 53 ... 57:
            name = "Potion of heroism";
            break;
        case 58 ... 62:
            name = "Potion of invulnerability";
            break;
        case 63 ... 67:
            name = "Potion of mind reading";
            break;
        case 68 ... 72:
            name = "Spell scroll (5th level)";
            break;
        case 73 ... 75:
            name = "Elixir of health";
            break;
        case 76 ... 78:
            name = "Oil of ehterealness";
            break;
        case 79 ... 81:
            name = "Potion of fire giant strength";
            break;
        case 82 ... 84:
            name = "Quaal's feather token";
            break;
        case 85 ... 87:
            name = "Scroll of protection";
            break;
        case 88 ... 89:
            name = "Bag of beans";
            break;
        case 90 ... 91:
            name = "Bead of force";
            break;
        case 92:
            name = "Chime of opening";
            break;
        case 93:
            name = "Decanter of endless water";
            break;
        case 94:
            name = "Eyes of minute seeing";
            break;
        case 95:
            name = "Folding boat";
            break;
        case 96:
            name = "Heward's handy haversack";
            break;
        case 97:
            name = "Horseshoes of speed";
            break;
        case 98:
            name = "Necklace of fireballs";
            break;
        case 99:
            name = "Periapt of health";
            break;
        case 100:
            name = "Sending stones";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableD()
{
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 20:
            name = "Potion of supreme healing";
            break;
        case 21 ... 30:
            name = "Potion of invisibility";
            break;
        case 31 ... 40:
            name = "Potion of speed";
            break;
        case 41 ... 50:
            name = "Spell scroll (6th level)";
            break;
        case 51 ... 57:
            name = "Spell scroll (7th level)";
            break;
        case 58 ... 62:
            name = "Aummunition , +3";
            break;
        case 63 ... 67:
            name = "Oil of sharpness";
            break;
        case 68 ... 72:
            name = "Potion of flying";
            break;
        case 73 ... 77:
            name = "Potion of cloud giant strength";
            break;
        case 78 ... 82:
            name = "Potion of longevity";
            break;
        case 83 ... 87:
            name = "Potion of vitality";
            break;
        case 88 ... 92:
            name = "Spell scroll (8th level)";
            break;
        case 93 ... 95:
            name = "Horseshoes of a zephyr";
            break;
        case 96 ... 98:
            name = "Nolzur's marvelous pigments";
            break;
        case 99:
            name = "Bag of devouring";
            break;
        case 100:
            name = "Portable hole";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableE()
{
 int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 30:
            name = "Spell scroll (8th level)";
            break;
        case 31 ... 55:
            name = "Potion of storm giant strength";
            break;
        case 56 ... 70:
            name = "potion of supreme healing";
            break;
        case 71 ... 85:
            name = "Spell scroll (9th level)";
            break;
        case 86 ... 93:
            name = "Universal solvent";
            break;
        case 94 ... 98:
            name = "Arrow of slaying";
            break;
        case 99 ... 100:
            name = "Sovereign glue";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableF()
{
    MagicItem* magicItem = nullptr;

    return magicItem;
}

MagicItem* LootFactory::_magicItemFactoryTableG()
{
    MagicItem* magicItem = nullptr;

    return magicItem;
}

MagicItem* LootFactory::_magicItemFactoryTableH()
{
    MagicItem* magicItem = nullptr;

    return magicItem;
}

MagicItem* LootFactory::_magicItemFactoryTableI()
{
    MagicItem* magicItem = nullptr;

    return magicItem;
}