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

void loadSave()
{
	character player1 = getFromFile();

	cout << "\n";
	cout << "Player Save File:";

	cout << "+-----+--------------------+----------\n";
	cout << "| [#]  | Property           | Value    \n";
	cout << "+-----+--------------------+----------\n";
	cout << "| [-]  | Attributes:        |          \n";
	cout << "| [1]  |    Strength:       | " << player1.atts.strength << "\n";
	cout << "| [2]  |    Cleverness:     | " << player1.atts.cleverness << "\n";
	cout << "| [3]  |    Dexterity:      | " << player1.atts.dexterity << "\n";
	cout << "| [4]  |    Faith:          | " << player1.atts.faith << "\n";
	cout << "| [5]  |    Focus:          | " << player1.atts.focus << "\n";
	cout << "| [6]  |    Insperation:    | " << player1.atts.insperation << "\n";
	cout << "| [7]  | Copper:            | " << player1.copper << "\n";
	cout << "| [8]  | Hitpoints:         | " << player1.hp << "\n";
	cout << "| [9]  | Max Hitpoints:     | " << player1.hpMax << "\n";
	cout << "| [10] | Mana/Stamina:      | " << player1.mp << "\n";
	cout << "| [11] | Max Mana/Stamina:  | " << player1.mpMax << "\n";
	cout << "| [12] | Masteries:         | " << player1.masteries << "\n";
	cout << "| [13] | Location:          | ";
	switch (player1.location)
	{
		case QUIT:
			cout << "Quit";
			break;
		case TOWN:
			cout << "Town";
			break;
		case FOREST:
			cout << "Forest";
			break;
		case VIEWSTATS:
			cout << "View Stats";
			break;
		case MONSTER:
			cout << "Monster";
			break;
		case SAVE:
			cout << "Save";
			break;
		case ARMORSMITH:
			cout << "Armor Smith";
			break;
		case BUYARMOR:
			cout << "Buy Armor";
			break;
		case SELLARMOR:
			cout << "Sell Armor";
			break;
		case TAVERN:
			cout << "Tavern";
			break;
		case WEAPONSMITH:
			cout << "Weapon Smith";
			break;
		case BUYWEAPON:
			cout << "Buy Weapon";
			break;
		case SELLWEAPON:
			cout << "Sell Weapon";
			break;
		case CHAPEL:
			cout << "Chapel";
			break;
		case BANK:
			cout << "Bank";
			break;
		case ALCHIMEST:
			cout << "Alchimest";
			break;
	}
	cout << "\n";
	cout << "| [14] | Class:             | ";
	switch (player1.charClass)
	{
		case FIGHTER:
			cout << "Fighter";
			break;
		case CLERIC:
			cout << "Cleric";
			break;
		case THEIF:
			cout << "Theif";
			break;
		case BARD:
			cout << "Bard";
			break;
		case ROUGE:
			cout << "Rouge";
			break;
		case TINKER:
			cout << "Tinker";
			break;
		case MAGE:
			cout << "Mage";
			break;
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
