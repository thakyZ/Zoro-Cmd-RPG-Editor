// consoleRPGEditor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "time.h"
#include <fstream>
using namespace std;

bool debug = false;

// Race types.
enum RACE { HUMAN, ELF, DARKELF, ANGEL, MONGREL, SHAMANI, NIBELUNG, UNDEAD };

// Class types.
enum OCC { FIGHTER, CLERIC, THEIF, BARD, ROUGE, TINKER, MAGE };

// Loations types.
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER, SAVE, ARMORSMITH, BUYARMOR, SELLARMOR, TAVERN, WEAPONSMITH, BUYWEAPON, SELLWEAPON, CHAPEL, BANK, ALCHIMEST };

// Armors types.
enum ARMOR { LOINCLOTH, CLOTH, LEATHER, CHAIN, PLATE, ANCIENTPLATE, MAGICPLATE, ARCHANEPLATE, IMPERVIUMPLATE };

// Weapons types.
enum WEAPON { FISTS, DAGGER, STAFF, SWORD, ANCIENTBLADE, MAGICBLADE, ARCHANEBLADE, VOIDEXCALIBUR };

// Potions.
enum Potions { HEALTH, MANA, EXP, CHEAT };

// Stats Tree.
struct ATTRIBUTES
{
	unsigned int strength; // The strength stat of the class.
	unsigned int faith; // The faith stat of the class.
	unsigned int dexterity; // The dexterity stat of the class.
	unsigned int insperation; // The insperation stat of the class.
	unsigned int cleverness; // The cleverness stat of the class.
	unsigned int focus; // The focus stat of the class.
};

class character
{
	public:
		ATTRIBUTES atts; // The stats that the player has.
		int copper; // The amount of money the player has.
		OCC charClass; // The characters class.
		RACE charRace; // The characters race.
		int hp, hpMax; // The hitpoints for the character.
		int mp, mpMax; // The mana or stamina for the character.
		LOCATION location; // The location the player is at.
		WEAPON weapon; // The weapon the character has.
		ARMOR armor; // The armor the character has.
		int masteries; // The skills level of the player.
		bool cheated; // If the player cheated.

		character()
		{
		}

		void setAtts(int tmpStrength, int tmpFaith, int tmpDexterity, int tmpInsperation, int tmpCleverness, int tmpFocus)
		{
			ATTRIBUTES tmpAtts = NULL;

			tmpAtts.strength = tmpStrength;
			tmpAtts.faith = tmpFaith;
			tmpAtts.dexterity = tmpDexterity;
			tmpAtts.insperation = tmpInsperation;
			tmpAtts.cleverness = tmpCleverness;
			tmpAtts.focus = tmpFocus;

			atts = tmpAtts;
		}
};

class playerSaveData
{
	public:
		int strength; // The strength stat of the class.
		int faith; // The faith stat of the class.
		int dexterity; // The dexterity stat of the class.
		int insperation; // The insperation stat of the class.
		int cleverness; // The cleverness stat of the class.
		int focus; // The focus stat of the class.
		int copper; // The amount of money the player has.
		OCC charClass; // The characters class.
		RACE charRace; // The characters race.
		int hp;
		int hpMax; // The hitpoints for the character.
		int mp;
		int mpMax; // The mana or stamina for the character.
		LOCATION location; // The location the player is at.
		WEAPON weapon; // The weapon the character has.
		ARMOR armor; // The armor the character has.
		int masteries; // The skills level of the player.
		bool cheated; // If the player has cheated.

		playerSaveData()
		{
		}

		void init(character *tmpChar)
		{
			strength = tmpChar->atts.strength; // Set the strength.
			faith = tmpChar->atts.faith; // Set the faith.
			dexterity = tmpChar->atts.dexterity; // Set the dexterity.
			insperation = tmpChar->atts.insperation; // Set the insperation.
			cleverness = tmpChar->atts.cleverness; // Set the cleverness.
			focus = tmpChar->atts.focus; // Set the focus.
			copper = tmpChar->copper; // Set the copper.
			charClass = tmpChar->charClass; // Set the class.
			charRace = tmpChar->charRace; // Set the race.
			hp = tmpChar->hp; // Set the hp.
			hpMax = tmpChar->hpMax; // Set the max hp.
			mp = tmpChar->mp; // Set the mana.
			mpMax = tmpChar->mpMax; // Set the max mana.
			location = tmpChar->location; // Set the location.
			weapon = tmpChar->weapon; // Set the weapon.
			armor = tmpChar->armor; // Set the armor.
			masteries = tmpChar->masteries; // Set the masteries.
			cheated = tmpChar->cheated;
		}
};

char *displayWeaponName(int tmpWeapon, int tmpCharClass)
{
	switch (tmpCharClass)
	{
		case 0:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Dagger";
					break;
				case 2:
					return "Staff";
					break;
				case 3:
					return "Sword";
					break;
				case 4:
					return "Ancient Blade";
					break;
				case 5:
					return "Magic Blade";
					break;
				case 6:
					return "Archane Blade";
					break;
				case 7:
					return "Void Excalibur";
					break;
			}
			break;
		case 1:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Cross";
					break;
				case 2:
					return "Long Cross";
					break;
				case 3:
					return "Holy Cross";
					break;
				case 4:
					return "Ancient Cross";
					break;
				case 5:
					return "Magic Cross";
					break;
				case 6:
					return "Archane Cross";
					break;
				case 7:
					return "Void Cross";
					break;
			}
			break;
		case 2:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Rusty Dagger";
					break;
				case 2:
					return "Dagger";
					break;
				case 3:
					return "Barbed Dagger";
					break;
				case 4:
					return "Ancient Dagger";
					break;
				case 5:
					return "Magic Dagger";
					break;
				case 6:
					return "Archane Dagger";
					break;
				case 7:
					return "Void Dagger";
					break;
			}
			break;
		case 3:
			switch (tmpWeapon)
			{
				case 0:
					return "Butter Knife";
					break;
				case 1:
					return "Rusty Sharp Knife";
					break;
				case 2:
					return "Sharp Knife";
					break;
				case 3:
					return "Barbed Knife";
					break;
				case 4:
					return "Ancient Knife";
					break;
				case 5:
					return "Magic Knife";
					break;
				case 6:
					return "Archane Knife";
					break;
				case 7:
					return "Void Long Knife";
					break;
			}
			break;
		case 4:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Rusty Short Blade";
					break;
				case 2:
					return "Short Balde";
					break;
				case 3:
					return "Barbed Short Blade";
					break;
				case 4:
					return "Ancient Short Blade";
					break;
				case 5:
					return "Magic Short Blade";
					break;
				case 6:
					return "Archane Short Blade";
					break;
				case 7:
					return "Void Short Excalibur";
					break;
			}
			break;
		case 5:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Rusty Wrench";
					break;
				case 2:
					return "Wrench";
					break;
				case 3:
					return "Mechanical Wrench";
					break;
				case 4:
					return "Ancient Wrench";
					break;
				case 5:
					return "Magic Wrench";
					break;
				case 6:
					return "Archane Wrench";
					break;
				case 7:
					return "Void Wrench";
					break;
			}
			break;
		case 6:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Dagger";
					break;
				case 2:
					return "Staff";
					break;
				case 3:
					return "Sword";
					break;
				case 4:
					return "Ancient Blade";
					break;
				case 5:
					return "Magic Blade";
					break;
				case 6:
					return "Archane Blade";
					break;
				case 7:
					return "Void Excalibur";
					break;
			}
			break;
		case 7:
			switch (tmpWeapon)
			{
				case 0:
					return "Fists";
					break;
				case 1:
					return "Dagger";
					break;
				case 2:
					return "Staff";
					break;
				case 3:
					return "Sword";
					break;
				case 4:
					return "Ancient Staff";
					break;
				case 5:
					return "Magic Staff";
					break;
				case 6:
					return "Archane Staff";
					break;
				case 7:
					return "Void Staff";
					break;
			}
			break;
	}

	return "";
}

char *displayArmorName(int tmpArmor, int tmpCharClass)
{
	switch (tmpCharClass)
	{
		case 0:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			switch (tmpArmor)
			{
				case 0:
					return "Loin Cloth";
					break;
				case 1:
					return "Cloth Armor";
					break;
				case 2:
					return "Leather Armor";
					break;
				case 3:
					return "Chain Armor";
					break;
				case 4:
					return "Plate Armor";
					break;
				case 5:
					return "Ancient Plate Armor";
					break;
				case 6:
					return "Magic Plate Armor";
					break;
				case 7:
					return "Archane Plate Armor";
					break;
				case 8:
					return "Impervium Plate Armor";
					break;
			}
			break;
		case 1:
		case 7:
			switch (tmpArmor)
			{
				case 0:
					return "Loin Cloth";
					break;
				case 1:
					return "Cloth Robe";
					break;
				case 2:
					return "Leather Robe";
					break;
				case 3:
					return "Chain Robe";
					break;
				case 4:
					return "Iron Robe";
					break;
				case 5:
					return "Ancient Robe";
					break;
				case 6:
					return "Magic Robe";
					break;
				case 7:
					return "Archane Robe";
					break;
				case 8:
					return "Impervium Robe";
					break;
			}
			break;
	}

	return "";
}

void writeToFile(character *tmpChar)
{
	// Create the var for the save file.
	ofstream myfile;

	// The temp Player save data;
	saveFileData playerSave;

	// Initlize the player save.
	playerSave.init(tmpChar);

	// Open the save file.
	myfile.open("./save1.sav",'w');

	// Write to the save file.
	myfile.write((char *)&playerSave, sizeof(playerSave));

	// If debug is enabled.
	if (debug)
	{
		debugSave(playerSave);
	}

	// Close the file after we are done with it.
	myfile.close();

	cout << "File saved.\n";
}

// To load a game.
character getFromFile()
{
	// The character var for the loaded file.
	saveFileData playerSave;

	// The temp character
	character tmpChar;

	// Load the save file.
	ifstream myfile("./save1.sav", ios::binary);

	// Read the save file.
	myfile.read((char *)&playerSave, sizeof(playerSave));

	LOCATION location = playerSave.location;
	int strength = playerSave.strength; // The strength stat of the class.
	int faith = playerSave.faith; // The faith stat of the class.
	int dexterity = playerSave.dexterity; // The dexterity stat of the class.
	int insperation =  playerSave.insperation; // The insperation stat of the class.
	int cleverness = playerSave.cleverness; // The cleverness stat of the class.
	int focus = playerSave.focus; // The focus stat of the class.
	int copper = playerSave.copper; // The amount of money the player has.
	OCC charClass = playerSave.charClass; // The characters class.
	RACE charRace = playerSave.charRace; // The characters race.
	int hp = playerSave.hp; // The hitpoints for the character.
	int hpMax = playerSave.hpMax; // The max hitpoints for the character.
	int mp = playerSave.mp; // The mana or stamina for the character.
	int mpMax = playerSave.mpMax; // The max mana or stamina for the character.
	WEAPON weapon = playerSave.weapon; // The weapon the character has.
	ARMOR armor = playerSave.armor; // The armor the character has.
	int masteries = playerSave.masteries; // The skills level of the player.
	bool cheated = playerSave.cheated;

	tmpChar.location  = location;
	tmpChar.setAtts(strength, cleverness, dexterity, faith, focus, insperation);
	tmpChar.charClass = charClass;
	tmpChar.copper = copper;
	tmpChar.hp = hp;
	tmpChar.mp = mp;
	tmpChar.masteries = masteries;
	tmpChar.hpMax = hpMax;
	tmpChar.mpMax = mpMax;
	tmpChar.charRace = charRace;

	// Debug the class.
	if (debug)
	{
		debugSave(playerSave);
	}

	// Close the file when we are done with it.
	myfile.close();

	cout << "Save loaded.\n";

	// Return the character to return the char.
	return tmpChar;
}

void displaySave(character player1)
{
	cout << "\n";
	cout << "Player Save File:";

	cout << "+------+--------------------+----------------\n";
	cout << "| [#]  | Property           | Value    \n";
	cout << "+------+--------------------+----------------\n";
	cout << "| [--] | Attributes:        |          \n";
	cout << "| [01] |    Strength:       | " << player1.atts.strength << "\n";
	cout << "| [02] |    Cleverness:     | " << player1.atts.cleverness << "\n";
	cout << "| [03] |    Dexterity:      | " << player1.atts.dexterity << "\n";
	cout << "| [04] |    Faith:          | " << player1.atts.faith << "\n";
	cout << "| [05] |    Focus:          | " << player1.atts.focus << "\n";
	cout << "| [06] |    Insperation:    | " << player1.atts.insperation << "\n";
	cout << "| [07] | Copper:            | " << player1.copper << "\n";
	cout << "| [08] | Hitpoints:         | " << player1.hp << "\n";
	cout << "| [09] | Max Hitpoints:     | " << player1.hpMax << "\n";
	cout << "| [10] | Mana/Stamina:      | " << player1.mp << "\n";
	cout << "| [11] | Max Mana/Stamina:  | " << player1.mpMax << "\n";
	cout << "| [12] | Masteries:         | " << player1.masteries << "\n";
	cout << "| [13] | Location:          | ";
	switch (player1.location)
	{
		case QUIT:
			cout << "QUIT";
			break;
		case TOWN:
			cout << "TOWN";
			break;
		case FOREST:
			cout << "FOREST";
			break;
		case VIEWSTATS:
			cout << "VIEWSTATS";
			break;
		case MONSTER:
			cout << "MONSTER";
			break;
		case SAVE:
			cout << "SAVE";
			break;
		case ARMORSMITH:
			cout << "ARMORSMITH";
			break;
		case BUYARMOR:
			cout << "BUYARMOR";
			break;
		case SELLARMOR:
			cout << "SELLARMOR";
			break;
		case TAVERN:
			cout << "TAVERN";
			break;
		case WEAPONSMITH:
			cout << "WEAPONSMITH";
			break;
		case BUYWEAPON:
			cout << "BUYWEAPON";
			break;
		case SELLWEAPON:
			cout << "SELLWEAPON";
			break;
		case CHAPEL:
			cout << "CHAPEL";
			break;
		case BANK:
			cout << "BANK";
			break;
		case ALCHIMEST:
			cout << "ALCHIMEST";
			break;
	}
	cout << "\n";
	cout << "| [14] | Class:             | ";
	switch (player1.charClass)
	{
		case FIGHTER:
			cout << "FIGHTER";
			break;
		case CLERIC:
			cout << "CLERIC";
			break;
		case THEIF:
			cout << "THEIF";
			break;
		case BARD:
			cout << "BARD";
			break;
		case ROUGE:
			cout << "ROUGE";
			break;
		case TINKER:
			cout << "TINKER";
			break;
		case MAGE:
			cout << "MAGE";
			break;
	}
	cout << "\n";
	cout << "| [15] | Race:              | ";
	switch (player1.charRace)
	{
		case HUMAN:
			cout << "HUMAN";
			break;
		case ELF:
			cout << "ELF";
			break;
		case DARKELF:
			cout << "DARKELF";
			break;
		case ANGEL:
			cout << "ANGEL";
			break;
		case MONGREL:
			cout << "MONGREL";
			break;
		case SHAMANI:
			cout << "SHAMANI";
			break;
		case NIBELUNG:
			cout << "NIBELUNG";
			break;
		case UNDEAD:
			cout << "UNDEAD";
			break;
	}
	cout << "\n";
	cout << "| [16] | Weapon:            | ";
	switch (player1.weapon)
	{
		case FISTS:
			cout << "FISTS";
			break;
		case DAGGER:
			cout << "DAGGER";
			break;
		case STAFF:
			cout << "STAFF";
			break;
		case SWORD:
			cout << "SWORD";
			break;
		case ANCIENTBLADE:
			cout << "ANCIENTBLADE";
			break;
		case MAGICBLADE:
			cout << "MAGICBLADE";
			break;
		case ARCHANEBLADE:
			cout << "ARCHANEBLADE";
			break;
		case VOIDEXCALIBUR:
			cout << "VOIDEXCALIBUR";
			break;
	}
	cout << "\n";
	cout << "| [--] |    Weapon-Class:   | " << displayWeaponName(player1.weapon, player1.charClass) << "\n";
	cout << "| [17] | Armor:             | ";
	switch (player1.armor)
	{
		case LOINCLOTH:
			cout << "LOINCLOTH";
			break;
		case CLOTH:
			cout << "CLOTH";
			break;
		case LEATHER:
			cout << "LEATHER";
			break;
		case CHAIN:
			cout << "CHAIN";
			break;
		case PLATE:
			cout << "PLATE";
			break;
		case ANCIENTPLATE:
			cout << "ANCIENTPLATE";
			break;
		case MAGICPLATE:
			cout << "MAGICPLATE";
			break;
		case ARCHANEPLATE:
			cout << "ARCHANEPLATE";
			break;
		case IMPERVIUMPLATE:
			cout << "IMPERVIUMPLATE";
			break;
	}
	cout << "\n";
	cout << "| [--] | Armor-Class:       | " << displayArmorName(player1.armor, player1.charClass) << "\n";
	cout << "| [18] | Cheated:           | ";
	switch (player1.cheated)
	{
		case true:
			cout << "TRUE";
			break;
		case false:
			cout << "FALSE";
			break;
	}
	cout << "\n";
	cout << "+------+--------------------+----------------\n";
	cout << "| [19] | Done               |\n";
	cout << "+------+--------------------+----------------\n";
}

void loadSave()
{
	character player1 = getFromFile();
	char menuItem[2];
	char saveItem;
	char *valueItem = "";
	bool reroll = true;

	while (reroll)
	{
		displaySave(player1);

		cout << "\n";
		cout << "Choose from the selected: [01] to [17]\n";
		cout << "Please input the correct input when editing a property.\n";
		cout << "   If you don't it'll break the save...\n";

		cin >> menuItem;

		cout << "\n\n";

		switch (menuItem)
		{
			case "01":
				cout << "This value has to be a NUMBER.\nStrength = ";
				cin >> valueItem;
				player1.strength = valueItem;
				cout << "   Strength = " << player1.strength;
				reroll = true;
			case "02":
				cout << "This value has to be a NUMBER.\nCleverness = ";
				cin >> valueItem;
				player1.cleverness = valueItem;
				cout << "   Cleverness = " << player1.cleverness;
				reroll = true;
			case "03":
				cout << "This value has to be a NUMBER.\nDexterity = ";
				cin >> valueItem;
				player1.dexterity = valueItem;
				cout << "   Dexterity = " << player1.dexterity;
				reroll = true;
			case "04":
				cout << "This value has to be a NUMBER.\nFaith = ";
				cin >> valueItem;
				player1.faith = valueItem;
				cout << "   Faith = " << player1.faith;
				reroll = true;
			case "05":
				cout << "This value has to be a NUMBER.\nFocus = ";
				cin >> valueItem;
				player1.focus = valueItem;
				cout << "   Focus = " << player1.focus;
				reroll = true;
			case "06":
				cout << "This value has to be a NUMBER.\nInsperation = ";
				cin >> valueItem;
				player1.insperation = valueItem;
				cout << "   Insperation = " << player1.insperation;
				reroll = true;
			case "07":
				cout << "This value has to be a NUMBER.\nCopper = ";
				cin >> valueItem;
				player1.copper = valueItem;
				cout << "   Copper = " << player1.copper;
				reroll = true;
			case "08":
				cout << "This value has to be a NUMBER.\nHitpoints = ";
				cin >> valueItem;
				player1.hp = valueItem;
				cout << "   Hitpoints = " << player1.hp;
				reroll = true;
			case "09":
				cout << "This value has to be a NUMBER.\nMax Hitpoints = ";
				cin >> valueItem;
				player1.hpMax = valueItem;
				cout << "   Max Hitpoints = " << player1.hpMax;
				reroll = true;
			case "10":
				cout << "This value has to be a NUMBER.\nMana/Stamina = ";
				cin >> valueItem;
				player1.mp = valueItem;
				cout << "   Mana/Stamina = " << player1.mp;
				reroll = true;
			case "11":
				cout << "This value has to be a NUMBER.\nMax Mana/Stamina = ";
				cin >> valueItem;
				player1.mpMax = valueItem;
				cout << "   Max Mana/Stamina = " << player1.mpMax;
				reroll = true;
			case "12":
				cout << "This value has to be a NUMBER.\nMasteries = ";
				cin >> valueItem;
				player1.masteries = valueItem;
				cout << "   Masteries = " << player1.masteries;
				reroll = true;
			case "13":
				cout << "This value has to be a NUMBER.\nQUIT=0,TOWN=1,FOREST=2,VIEWSTATS=3,MONSTER=4,SAVE=5,\nARMORSMITH=6,BUYARMOR=7,SELLARMOR=8,TAVERN=9,\nWEAPONSMITH=10,BUYWEAPON=11,SELLWEAPON=12,CHAPEL=13,\nBANK=14,ALCHIMEST=15\nLocation = ";
				cin >> valueItem;
				player1.location = valueItem;
				cout << "Location = ";
				switch (player1.location)
				{
					case QUIT:
						cout << "QUIT";
						break;
					case TOWN:
						cout << "TOWN";
						break;
					case FOREST:
						cout << "FOREST";
						break;
					case VIEWSTATS:
						cout << "VIEWSTATS";
						break;
					case MONSTER:
						cout << "MONSTER";
						break;
					case SAVE:
						cout << "SAVE";
						break;
					case ARMORSMITH:
						cout << "ARMORSMITH";
						break;
					case BUYARMOR:
						cout << "BUYARMOR";
						break;
					case SELLARMOR:
						cout << "SELLARMOR";
						break;
					case TAVERN:
						cout << "TAVERN";
						break;
					case WEAPONSMITH:
						cout << "WEAPONSMITH";
						break;
					case BUYWEAPON:
						cout << "BUYWEAPON";
						break;
					case SELLWEAPON:
						cout << "SELLWEAPON";
						break;
					case CHAPEL:
						cout << "CHAPEL";
						break;
					case BANK:
						cout << "BANK";
						break;
					case ALCHIMEST:
						cout << "ALCHIMEST";
						break;
				}
				cout << "\n";
				reroll = true;
			case "14":
				cout << "This value has to be a NUMBER.\nFIGHTER=0,CLERIC=1,THEIF=2,BARD=3,ROUGE=4,TINKER=5,\nMAGE=6\nClass = ";
				cin >> valueItem;
				player1.charClass = valueItem;
				cout << "Class = ";
				switch (player1.charClass)
				{
					case FIGHTER:
						cout << "FIGHTER";
						break;
					case CLERIC:
						cout << "CLERIC";
						break;
					case THEIF:
						cout << "THEIF";
						break;
					case BARD:
						cout << "BARD";
						break;
					case ROUGE:
						cout << "ROUGE";
						break;
					case TINKER:
						cout << "TINKER";
						break;
					case MAGE:
						cout << "MAGE";
						break;
				}
				cout << "\n";
				reroll = true;
			case "15":
				cout << "This value has to be a NUMBER.\nHUMAN=0,ELF=1,DARKELF=2,ANGEL=3,MONGREL=4,SHAMANI=5\nNIBELUNG=6,UNDEAD=7\nRace = ";
				cin >> valueItem;
				switch (valueItem)
				{
					default:
					case "0":
						player1.race = FISTS;
						break;
					case "1":
						player1.weapon = DAGGER;
						break;
					case "2":
						player1.weapon = STAFF;
						break;
					case "3":
						player1.weapon = SWORD;
						break;
					case "4":
						player1.weapon = ANCIENTBLADE;
						break;
					case "5":
						player1.weapon = MAGICBLADE;
						break;
					case "6":
						player1.weapon = ARCHANEBLADE;
						break;
					case "7":
						player1.weapon = VOIDEXCALIBUR;
						break;
				}
				cout << "\n";
				cout << "Race = ";
				switch (player1.charRace)
				{
					case HUMAN:
						cout << "HUMAN";
						break;
					case ELF:
						cout << "ELF";
						break;
					case DARKELF:
						cout << "DARKELF";
						break;
					case ANGEL:
						cout << "ANGEL";
						break;
					case MONGREL:
						cout << "MONGREL";
						break;
					case SHAMANI:
						cout << "SHAMANI";
						break;
					case NIBELUNG:
						cout << "NIBELUNG";
						break;
					case UNDEAD:
						cout << "UNDEAD";
						break;
				}
				reroll = true;
			case "16":
				cout << "This value has to be a NUMBER.\nQUIT=0,TOWN=1,FOREST=2,VIEWSTATS=3,MONSTER=4,SAVE=5,\nARMORSMITH=6,BUYARMOR=7,SELLARMOR=8,TAVERN=9,\nWEAPONSMITH=10,BUYWEAPON=11,SELLWEAPON=12,CHAPEL=13,\nBANK=14,ALCHIMEST=15\nLocation = ";

				cout << "This value has to be a NUMBER.\nLOINCLOTH=0,CLOTH=1,LEATHER=2,CHAIN=3,PLATE=4,\nANCIENTPLATE=5,VOIDEXCALIBUR=6\nWeapon = ";
				cin >> valueItem;
				switch (valueItem)
				{
					default:
					case "0":
						player1.armor = LOINCLOTH;
						break;
					case "1":
						player1.armor = CLOTH;
						break;
					case "2":
						player1.armor = LEATHER;
						break;
					case "3":
						player1.armor = CHAIN;
						break;
					case "4":
						player1.armor = PLATE;
						break;
					case "5":
						player1.armor = ANCIENTPLATE;
						break;
					case "6":
						player1.armor = MAGICPLATE;
						break;
					case "7":
						player1.armor = ARCHANEPLATE;
						break;
					case "8":
						player1.armor = IMPERVIUMPLATE;
						break;
				}
				cout << "\n";
				cout << "Armor = ";
				switch (player1.armor)
				{
					case LOINCLOTH:
						cout << "LOINCLOTH";
						break;
					case CLOTH:
						cout << "CLOTH";
						break;
					case LEATHER:
						cout << "LEATHER";
						break;
					case CHAIN:
						cout << "CHAIN";
						break;
					case PLATE:
						cout << "PLATE";
						break;
					case ANCIENTPLATE:
						cout << "ANCIENTPLATE";
						break;
					case MAGICPLATE:
						cout << "MAGICPLATE";
						break;
					case ARCHANEPLATE:
						cout << "ARCHANEPLATE";
						break;
					case IMPERVIUMPLATE:
						cout << "IMPERVIUMPLATE";
						break;
				}
				cout << "\n";
				reroll = true;
			case "17":
				cout << "This value has to be a NUMBER.\nFISTS=0,DAGGER=1,STAFF=2,ANCIENTBLADE=3,MAGICBLADE=4,\nARCHANEBLADE=5,VOIDEXCALIBUR=6\nWeapon = ";
				cin >> valueItem;
				switch (valueItem)
				{
					default:
					case "0":
						player1.weapon = FISTS;
						break;
					case "1":
						player1.weapon = DAGGER;
						break;
					case "2":
						player1.weapon = STAFF;
						break;
					case "3":
						player1.weapon = SWORD;
						break;
					case "4":
						player1.weapon = ANCIENTBLADE;
						break;
					case "5":
						player1.weapon = MAGICBLADE;
						break;
					case "6":
						player1.weapon = ARCHANEBLADE;
						break;
					case "7":
						player1.weapon = VOIDEXCALIBUR;
						break;
				}
				cout << "\n";
				cout << "Weapon = ";
				switch (player1.weapon)
				{
					case FISTS:
						cout << "FISTS";
						break;
					case DAGGER:
						cout << "DAGGER";
						break;
					case STAFF:
						cout << "STAFF";
						break;
					case SWORD:
						cout << "SWORD";
						break;
					case ANCIENTBLADE:
						cout << "ANCIENTBLADE";
						break;
					case MAGICBLADE:
						cout << "MAGICBLADE";
						break;
					case ARCHANEBLADE:
						cout << "ARCHANEBLADE";
						break;
					case VOIDEXCALIBUR:
						cout << "VOIDEXCALIBUR";
						break;
				}
				reroll = true;
			case "18":
				cout << "This value has to be a NUMBER.\nFALSE=0,TRUE=1\nCheated = ";
				cin >> valueItem;
				switch (valueItem)
				{
					default:
					case "0":
						player1.cheated = false;
						break;
					case "1":
						player1.cheated = true;
						break;
				}
				cout << "\n";
				cout << "Cheated = ";
				switch (player1.cheated)
				{
					case true:
						cout << "TRUE";
						break;
					case false:
						cout << "FALSE";
						break;
				}
				cout << "\n";
				reroll = true;
			case "19":
				cout << "Are you sure you want to save and exit? [Y]es [N]o\n";
				cin << saveItem;
				switch (saveItem)
				{
					case 'y':
					case 'Y':
						reroll = false;
						break;
					default:
					case 'n':
					case 'N':
						reroll = true;
						break;
				}
				cout << "\n\n";
				writeToFile(player1);
		}
	}
}

void displayAbout()
{

}

int _tmain(int argc, _TCHAR* argv[])
{
	bool reroll = true;
	char menuItem;

	cout << "Welcome to the consoleRPG Editor!\n"
	cout << "   By: Nire Inicana\n";
	cout << "\n"
	cout << "[1] Load 'save1.sav'\t[2] About consoleRPGEditor\n";

	while (reroll)
	{
		reroll = false;

		cin << menuItem;

		cout << "\n";

		switch (menuItem)
		{
			case '1':
				loadSave();
				break;
			case '2':
				displayAbout();
				break;
			default:
				if (menuItem != ('3', '4', '5'))
				{
					cout << "Please choose a correct input.\n";
					reroll = true;
				}
				break;
		}

		if (menuItem == ('3', '4', '5'))
		{
			debug = true;

			cout << "+=================================+\n";
			cout << "   Debug -> ENABLED\n";
			cout << "+=================================+\n";

			reroll = true;
		}
	}
	return 0;
}
