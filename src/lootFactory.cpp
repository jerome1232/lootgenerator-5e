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
                               std::string coinType, int multiplier)
{
    std::string name;
    int amount = 0;
    Dice die(numDieSides);

    if (coinType == "copper")
    {
        name = "copper";
    }
    else if (coinType == "silver")
    {
        name = "silver";
    }
    else if (coinType == "electrum")
    {
        name = "electrum";
    }
    else if (coinType == "gold")
    {
        name = "gold";
    }
    else if (coinType == "platinum")
    {
        name = "platinum";
    }
    else
    {
        throw std::invalid_argument("Invalid coinType");
    }

    amount = die.roll(numDie);
    amount *= multiplier;

    return new Coin(name, amount);
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
            name = "Dust of disappearance";
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
            name = "Mithril armor";
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
            name = "Ammunition, +2";
            break;
        case 28 ... 32:
            name = "Potion of clairvoyance";
            break;
        case 33 ... 37:
            name = "Potion of diminution";
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
            name = "Oil of etherealness";
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
            name = "Ammunition , +3";
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
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 15:
            name = "Weapon, +1";
            break;
        case 16 ... 18:
            name = "Shield, +1";
            break;
        case 19 ... 21:
            name = "Sentinel shield";
            break;
        case 22 ... 23:
            name = "Amulet of proof against detection and location";
            break;
        case 24 ... 25:
            name = "Boots of elvenkind";
            break;
        case 26 ... 27:
            name = "Boots of striding and springing";
            break;
        case 28 ... 29:
            name = "Bracers of archery";
            break;
        case 30 ... 31:
            name = "Brooch of shielding";
            break;
        case 32 ... 33:
            name = "Broom of flying";
            break;
        case 34 ... 35:
            name = "Cloak of elvenkind";
            break;
        case 36 ... 37:
            name = "Cloak of protection";
            break;
        case 38 ... 39:
            name = "Gauntlets of ogre power";
            break;
        case 40 ... 41:
            name = "Hat of disguise";
            break;
        case 42 ... 43:
            name = "Javelin of lightning";
            break;
        case 44 ... 45:
            name = "Pearl of power";
            break;
        case 46 ... 47:
            name = "Rod of the pact keeper, +1";
            break;
        case 48 ... 49:
            name = "Slippers of spider climbing";
            break;
        case 50 ... 51:
            name = "Staff of the adder";
            break;
        case 52 ... 53:
            name = "Staff of the python";
            break;
        case 54 ... 55:
            name = "Sword of vengeance";
            break;
        case 56 ... 57:
            name = "Trident of fish command";
            break;
        case 58 ... 59:
            name = "Wand of magic missiles";
            break;
        case 60 ... 61:
            name = "Wand of war mage, +1";
            break;
        case 62 ... 63:
            name = "Wand of web";
            break;
        case 64 ... 65:
            name = "Weapon of warning";
            break;
        case 66:
            name = "Adamantine armor (chain mail)";
            break;
        case 67:
            name = "Adamantine armor (chain shirt)";
            break;
        case 68:
            name = "Adamantine armor (scale mail)";
            break;
        case 69:
            name = "Bag of tricks (grey)";
            break;
        case 70:
            name = "Bag of tricks (rust)";
            break;
        case 71:
            name = "Bah of trick (tan)";
            break;
        case 72:
            name = "Boots of the winterlands";
            break;
        case 73:
            name = "Circlet of blasting";
            break;
        case 74:
            name = "Deck of illusions";
            break;
        case 75:
            name = "Eversmoking bottle";
            break;
        case 76:
            name = "Eyes of charming";
            break;
        case 77:
            name = "Eyes of the eagle";
            break;
        case 78:
            name = "Figurine of wondrous power (silver raven)";
            break;
        case 79:
            name = "Gem of brightness";
            break;
        case 80:
            name = "Gloves of missile snaring";
            break;
        case 81:
            name = "Gloves of swimming and climbing";
            break;
        case 82:
            name = "Gloves of thievery";
            break;
        case 83:
            name = "Headband of intellect";
            break;
        case 84:
            name = "Helm of telepathy";
            break;
        case 85:
            name = "Instrument of the bards (Doss lute)";
            break;
        case 86:
            name = "Instrument of the bards (Fochlucan bandore)";
            break;
        case 87:
            name = "Instrument of the bards (Mac-Fuimidh cittern)";
            break;
        case 88:
            name = "Medallion of thoughts";
            break;
        case 89:
            name = "Necklace of adaptation";
            break;
        case 90:
            name = "Periapt of wound closure";
            break;
        case 91:
            name = "Pipes of haunting";
            break;
        case 92:
            name = "Pipes of sewers";
            break;
        case 93:
            name = "Ring of jumping";
            break;
        case 94:
            name = "Ring of mind shielding";
            break;
        case 95:
            name = "Ring of warmth";
            break;
        case 96:
            name = "Ring of water walking";
            break;
        case 97:
            name = "Quiver of Ehlonna";
            break;
        case 98:
            name = "Stone of good luck";
            break;
        case 99:
            name = "Wind fan";
            break;
        case 100:
            name = "Winged boots";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableG()
{
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 11:
            name = "Weapon, +2";
            break;
        case 12 ... 14:
            name = "Figurine of wondrous power (see DMG)";
            {
                int subRoll = d8.roll();
                switch (subRoll)
                {
                case 1:
                    name += " Bronze griffon";
                    break;
                case 2:
                    name += " Ebony fly";
                    break;
                case 3:
                    name += " Golden lions";
                    break;
                case 4:
                    name += " Ivory goats";
                    break;
                case 5:
                    name += " Marble elephant";
                case 6 ... 7:
                    name += " Onyx dog";
                    break;
                case 8:
                    name += " Serpentine owl";
                    break;
                }
            }
            break;
        case 15:
            name = "Adamantine armor (breastplate)";
            break;
        case 16:
            name = "Adamantine armor (splint)";
            break;
        case 17:
            name = "Amulet of health";
            break;
        case 18:
            name = "Armor of vulnerability";
            break;
        case 19:
            name = "Arrow-catching shield";
            break;
        case 20:
            name = "Belt of dwarvenkind";
            break;
        case 21:
            name = "Belt of hill giant strength";
            break;
        case 22:
            name = "Berserker axe";
            break;
        case 23:
            name = "Boots of levitation";
            break;
        case 24:
            name = "Boots of speed";
            break;
        case 25:
            name = "Bowl of commanding water elementals";
            break;
        case 26:
            name = "Bracers of defense";
            break;
        case 27:
            name = "Brazier of commanding fire elementals";
            break;
        case 28:
            name = "Cape of the mountebank";
            break;
        case 29:
            name = "Censer of controlling air elementals";
            break;
        case 30:
            name = "Armor, +1 chain mail";
            break;
        case 31:
            name = "Amor of resistance (chain mail)";
            break;
        case 32:
            name = "Armor, +1 chain shirt";
            break;
        case 33:
            name = "Armor of resistance (chain shirt)";
            break;
        case 34:
            name = "Cloak of displacement";
            break;
        case 35:
            name = "Cloud of the bat";
            break;
        case 36:
            name = "Cube of force";
            break;
        case 37:
            name = "Daern's instant fortress";
            break;
        case 38:
            name = "Dagger of venom";
            break;
        case 39:
            name = "Dimensional shackles";
            break;
        case 40:
            name = "Dragon slayer";
            break;
        case 41:
            name = "Elven chain";
            break;
        case 42:
            name = "Flame tongue";
            break;
        case 43:
            name = "Gem of seeing";
            break;
        case 44:
            name = "Giant slayer";
            break;
        case 45:
            name = "Glamoured studded leather";
            break;
        case 46:
            name = "Helm of teleportation";
            break;
        case 47:
            name = "Horn of blasting";
            break;
        case 48:
            name = "Horn of Valhalla (silver or brass)";
            break;
        case 49:
            name = "Instrument of the bards (Canaith mandolin)";
            break;
        case 50:
            name = "Instrument of the bards (Cli lyre)";
            break;
        case 51:
            name = "Ioun stone (awareness)";
            break;
        case 52:
            name = "Ioun stone (protection)";
            break;
        case 53:
            name = "Ioun stone (reserve)";
            break;
        case 54:
            name = "Ioun stone (sustenance)";
            break;
        case 55:
            name = "Iron bands of Bilarro";
            break;
        case 56:
            name = "Armor, +1 leather";
            break;
        case 57:
            name = "Amor of resistance (leather)";
            break;
        case 58:
            name = "Mace of disruption";
            break;
        case 59:
            name = "Mace of smiting";
            break;
        case 60:
            name = "Mace of terror";
            break;
        case 61:
            name = "Mantle of spell resistance";
            break;
        case 62:
            name = "Necklace of prayer beads";
            break;
        case 63:
            name = "Periapt of proof against poison";
            break;
        case 64:
            name = "Ring of animal influence";
            break;
        case 65:
            name = "Ring of evasion";
            break;
        case 66:
            name = "Ring of feather falling";
            break;
        case 67:
            name = "Ring of free action";
            break;
        case 68:
            name = "Ring of protection";
            break;
        case 69:
            name = "Ring of resistance";
            break;
        case 70:
            name = "Ring of spell storing";
            break;
        case 71:
            name = "Ring of the ram";
            break;
        case 72:
            name = "Ring of X-ray vision";
            break;
        case 73:
            name = "Robe of eyes";
            break;
        case 74:
            name = "Rod of rulership";
            break;
        case 75:
            name = "Rod of the pact keeper, +2";
            break;
        case 76:
            name = "Rope of entanglement";
            break;
        case 77:
            name = "Armor, +1 scale mail";
            break;
        case 78:
            name = "Armor of resistance (scale mail)";
            break;
        case 79:
            name = "Shield, +2";
            break;
        case 80:
            name = "Shield of missile attraction";
            break;
        case 81:
            name = "Staff of charming";
            break;
        case 82:
            name = "Staff of healing";
            break;
        case 83:
            name = "Staff of swarming insects";
            break;
        case 84:
            name = "Staff of the woodlands";
            break;
        case 85:
            name = "Staff of withering";
            break;
        case 86:
            name = "Stone of controlling earth elementals";
            break;
        case 87:
            name = "Sun blade";
            break;
        case 88:
            name = "Sword of life stealing";
            break;
        case 89:
            name = "Sword of wounding";
            break;
        case 90:
            name = "Tentacle rod";
            break;
        case 91:
            name = "Vicious weapon";
            break;
        case 92:
            name = "Wand of binding";
            break;
        case 93:
            name = "Wand of enemy detection";
            break;
        case 94:
            name = "Wand of fear";
            break;
        case 95:
            name = "Wand of fireballs";
            break;
        case 96:
            name = "Wand of lightning bolts";
            break;
        case 97:
            name = "Wand of paralysis";
            break;
        case 98:
            name = "Wand of the war mage, +2";
            break;
        case 99:
            name = "Wand of wonder";
            break;
        case 100:
            name = "Wings of flying";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableH()
{
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
        case 1 ... 10:
            name = "Weapon, +3";
            break;
        case 11 ... 12:
            name = "Amulet of the planes";
            break;
        case 13 ... 14:
            name = "Carpet of flying";
            break;
        case 15 ... 16:
            name = "Crystal ball (very rare version)";
            break;
        case 17 ... 18:
            name = "Ring of regeneration";
            break;
        case 19 ... 20:
            name = "Ring of shooting stars";
            break;
        case 21 ... 22:
            name = "Ring of telekinesis";
            break;
        case 23 ... 24:
            name = "Robe of scintillating colors";
            break;
        case 25 ... 26:
            name = "Robe of stars";
            break;
        case 27 ... 28:
            name = "Rod of absorption";
            break;
        case 29 ... 30:
            name = "Rod of alertness";
            break;
        case 31 ... 32:
            name = "Rod of security";
            break;
        case 33 ... 34:
            name = "Rod of the pact keeper, +3";
            break;
        case 35 ... 36:
            name = "Scimitar of speed";
            break;
        case 37 ... 38:
            name = "Shield, +3";
            break;
        case 39 ... 40:
            name = "Staff of fire";
            break;
        case 41 ... 42:
            name = "Staff of frost";
            break;
        case 43 ... 44:
            name = "Staff of power";
            break;
        case 45 ... 46:
            name = "Staff of striking";
            break;
        case 47 ... 48:
            name = "Staff of thunder and lightning";
            break;
        case 49 ... 50:
            name = "Sword of sharpness";
            break;
        case 51 ... 52:
            name = "Wand of polymorph";
            break;
        case 53 ... 54:
            name = "Wand of war mage, +3";
            break;
        case 55:
            name = "Adamantine armor (half plate)";
            break;
        case 56:
            name = "Adamantine armor (plate)";
            break;
        case 57:
            name = "Animated shield";
            break;
        case 58:
            name = "Belt of fire giant strength";
            break;
        case 59:
            name = "Belt of frost(or stone) giant strength";
            break;
        case 60:
            name = "Armor, +1 breastplate";
            break;
        case 61:
            name = "Armor of resistance (breastplate)";
            break;
        case 62:
            name = "Candle of invocation";
            break;
        case 63:
            name = "Armor, +2 chain mail";
            break;
        case 64:
            name = "Armor, +2 chain shirt";
            break;
        case 65:
            name = "Cloak of arachnidan";
            break;
        case 66:
            name = "Dancing sword";
            break;
        case 67:
            name = "Demon armor";
            break;
        case 68:
            name = "Dragon scale mail";
            break;
        case 69:
            name = "Dwarven plate";
            break;
        case 70:
            name = "Dwarven thrower";
            break;
        case 71:
            name = "Efreeti bottle";
            break;
        case 72:
            name = "figurine of wondrous power(obsidian steed)";
            break;
        case 73:
            name = "Frost brand";
            break;
        case 74:
            name = "Helm of brilliance";
            break;
        case 75:
            name = "Horn of Valhalla";
            break;
        case 76:
            name = "Instrument of the bards (Anstruth harp)";
            break;
        case 77:
            name = "Ioun stone (absorption)";
            break;
        case 78:
            name = "Ioun stone (agility)";
            break;
        case 79:
            name = "Ioun stone (fortitude)";
            break;
        case 80:
            name = "Ioun stone (insight)";
            break;
        case 81:
            name = "Ioun stone (intellect)";
            break;
        case 82:
            name = "Ioun stone (leadership)";
            break;
        case 83:
            name = "Ioun stone (strength)";
            break;
        case 84:
            name = "Armor, +2 leather";
            break;
        case 85:
            name = "Manual of bodily health";
            break;
        case 86:
            name = "Manual of gainful exercise";
            break;
        case 87:
            name = "Manual of golems";
            break;
        case 88:
            name = "Manual of quickness of action";
            break;
        case 89:
            name = "Mirror of life trapping";
            break;
        case 90:
            name = "Nine lives stealer";
            break;
        case 91:
            name = "Oathbow";
            break;
        case 92:
            name = "Armor, +2 scale mail";
            break;
        case 93:
            name = "Spellguard shield";
            break;
        case 94:
            name = "Armor, +1 splint";
            break;
        case 95:
            name = "Armor of resistance (splint)";
            break;
        case 96:
            name = "Armor, +1 (studded leather)";
            break;
        case 97:
            name = "Armor of resistance (studded leather)";
            break;
        case 98:
            name = "Tome of clear thought";
            break;
        case 99:
            name = "Tome of leadership and influence";
            break;
        case 100:
            name = "Tome of understanding";
            break;
    }
    return new MagicItem(name, 0);
}

MagicItem* LootFactory::_magicItemFactoryTableI()
{
    int roll = d100.roll();
    std::string name;

    switch (roll)
    {
            case 1 ... 5:
            name = "Defender";
            break;
        case 6 ... 10:
            name = "Hammer of thunderbolts";
            break;
        case 11 ... 15:
            name = "Luck blade";
            break;
        case 16 ... 20:
            name = "Sword of answering";
            break;
        case 21 ... 23:
            name = "Holy avenger";
            break;
        case 24 ... 26:
            name = "Ring of djinni summoning";
            break;
        case 27 ... 29:
            name = "Ring of invisibility";
            break;
        case 30 ... 35:
            name = "Rod of lordly might";
            break;
        case 36 ... 38:
            name = "Staff of the magi";
            break;
        case 39 ... 41:
            name = "Vorpal sword";
            break;
        case 42 ... 43:
            name = "Belt of cloud giant strength";
            break;
        case 44 ... 45:
            name = "Armor, +2 breastplate";
            break;
        case 46 ... 47:
            name = "Armor, +3 chain mail";
            break;
        case 48 ... 49:
            name = "Armor, +3 chain shirt";
            break;
        case 50 ... 51:
            name = "Cloak of invisibility";
            break;
        case 52 ... 53:
            name = "Crystal ball (legendary version)";
            break;
        case 54 ... 55:
            name = "Armor, +1 half plate";
            break;
        case 56 ... 57:
            name = "Iron flask";
            break;
        case 58 ... 59:
            name = "Armor, +3 leather";
            break;
        case 60 ... 61:
            name = "Armor, +1 plate";
            break;
        case 62 ... 63:
            name = "Robe of the archmagi";
            break;
        case 64 ... 65:
            name = "Rod of resurrection";
            break;
        case 66 ... 67:
            name = "Armor, +1 scale mail";
            break;
        case 68 ... 69:
            name = "Scarab of protection";
            break;
        case 70 ... 71:
            name = "Armor, +2 splint";
            break;
        case 72 ... 73:
            name = "Armor, +2 studded leather";
            break;
        case 74 ... 75:
            name = "Well of many worlds";
            break;
        case 76:
            {
                name = "Armor, ";
                int subRoll = d12.roll();
                switch (subRoll)
                {
                    case 1 ... 2:
                        name  += "+2 half plate";
                        break;
                    case 3 ... 4:
                        name += "+2 plate";
                        break;
                    case 5 ... 6:
                        name += "+3 studded leather";
                        break;
                    case 7 ... 8:
                        name += "+3 breastplate";
                        break;
                    case 9 ... 10:
                        name += "+3 splint";
                    case 11:
                        name += "+3 half plate";
                        break;
                    case 12:
                        name += "+3 plate";
                        break;
                }
            }
            break;
        case 77:
            name = "Apparatus of Kwalish";
            break;
        case 78:
            name = "Armor of invulnerability";
            break;
        case 79:
            name = "Belt of storm giant strength";
            break;
        case 80:
            name = "Cubic gate";
            break;
        case 81:
            name = "Deck of many things";
            break;
        case 82:
            name = "Efreeti chain";
            break;
        case 83:
            name = "Armor of resistance (half plate)";
            break;
        case 84:
            name = "Horn of Valhalla (iron)";
            break;
        case 85:
            name = "Instrument of the bards (Ollamh harp)";
            break;
        case 86:
            name = "Ioun stone (greater absorption)";
            break;
        case 87:
            name = "Ioun stone (mastery)";
            break;
        case 88:
            name = "Ioun stone (regeneration)";
            break;
        case 89:
            name = "Plate armor of etherealness";
            break;
        case 90:
            name = "Plate armor of resistance";
            break;
        case 91:
            name = "Ring of air elemental command";
            break;
        case 92:
            name = "Ring of earth elemental command";
            break;
        case 93:
            name = "Ring of fire elemental command";
            break;
        case 94:
            name = "Ring of three wishes";
            break;
        case 95:
            name = "Ring of water elemental command";
            break;
        case 96:
            name = "Sphere of annihilation";
            break;
        case 97:
            name = "Talisman of pure good";
            break;
        case 98:
            name = "Talisman of the sphere";
            break;
        case 99:
            name = "Talisman of ultimate evil";
            break;
        case 100:
            name = "Tome of stilled tongue";
            break;
    }
    return new MagicItem(name, 0);
}
