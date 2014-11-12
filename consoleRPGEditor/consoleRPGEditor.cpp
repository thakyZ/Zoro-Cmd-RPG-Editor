// ConsoleRPG.cpp : Defines the entry point for the console application.
// Created by Nick Mullally a.k.a. thakyZ / Nire Inicana
//

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "time.h"
#include <fstream>
using namespace std;

bool debug = false;

// Roll the dice.
int diceRoll(int qty, int sides)
{
	int subTotal = 0; // Dice addition subtotal.
	// Roll the dice.

	// Loop to roll the dice
	for (int i = 0; i < qty; i++)
	{
		int currentRoll = rand() % sides + 1;
		subTotal += currentRoll;
	}

	return subTotal;
}

// Race types.
enum RACE { HUMAN, ELF, DARKELF, ANGEL, MONGREL, SHAMANI, NIBELUNG, UNDEAD };

// Class types.
enum OCC { FIGHTER, CLERIC, THEIF, BARD, ROUGE, TINKER, MAGE };

// Loations types.
enum LOCATION { QUIT, TOWN, FOREST, VIEWSTATS, MONSTER, SAVE, ARMORSMITH, BUYARMOR, SELLARMOR, TAVERN, WEAPONSMITH, BUYWEAPON, SELLWEAPON, CHAPEL, BANK, PUTMONEY, TAKEMONEY, ALCHIMEST, BUYPOTION, SELLPOTION, DEBUG };

// Armors types.
enum ARMOR { LOINCLOTH, CLOTH, LEATHER, CHAIN, PLATE, ANCIENTPLATE, MAGICPLATE, ARCHANEPLATE, IMPERVIUMPLATE };

// Weapons types.
enum WEAPON { FISTS, DAGGER, STAFF, SWORD, ANCIENTBLADE, MAGICBLADE, ARCHANEBLADE, VOIDEXCALIBUR };

// Potions.
enum POTION { NONE, HEALTH, MANA, EXP, CHEAT };

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

struct LEVELS
{
	int charLvl;
	int charExp;
	int reqExp;
};

// Display the stats of the roll.
void displayStats(ATTRIBUTES atts)
{
	cout << "Stats:\n";
	cout << "   Strength:      " << atts.strength << "\n";
	cout << "   Faith:         " << atts.faith << "\n";
	cout << "   Dexterity:     " << atts.dexterity << "\n";
	cout << "   Insperation:   " << atts.insperation << "\n";
	cout << "   Cleverness:    " << atts.cleverness << "\n";
	cout << "   Focus:         " << atts.focus << "\n";
	cout << "\n\n";
}

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

int calcReqExp(int tmpExp)
{
	int remainder = tmpExp % 5;

	if (remainder == 0)
	{
		return tmpExp;
	}

	return tmpExp + 5 - remainder;
}

class monster
{
	public:
		int hp, hpMax; // The var for hitpoints.
		ATTRIBUTES atts; // The var for stats.
		char *mName; // The name of the monster.
		char *attackText; // The text when the monster attacks.
		char *deathText; // The text when the monster dies.
		char *winText; // The text when the player dies.
		int masteries; // Unknown.
		int copper; // The amout of money the monster drops.
		ARMOR armor; // The armor the monster has.
		WEAPON weapon; // The weapon the monster has.

		// Create the monster class.
		monster()
		{
		}

		void genMonster(int charLvl)
		{
			masteries = 0; // Declare this for now to 0.

			int tmpLvl = 0;

			// Switch to figure out what monster the player will face.

			if (charLvl >= 0 && charLvl < 15)
			{
				tmpLvl = 2;
			}
			else if (charLvl >= 15 && charLvl < 35)
			{
				tmpLvl = 5;
			}

			switch (diceRoll(1, tmpLvl))
			{
				case 1:
					mName = "A Small Goblin";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(2, 6);
					atts.focus = diceRoll(2, 6);
					atts.cleverness = diceRoll(2, 6);
					atts.dexterity = diceRoll(2, 6);
					atts.faith = diceRoll(2, 6);
					atts.insperation = diceRoll(2, 6);
					copper = diceRoll(10, 5);
					armor = LOINCLOTH;
					weapon = DAGGER;
					attackText = "A Moldy Stick";
					deathText = "the Goblin cries out \"why use hits mes sos hards?\"";
					winText = "the Goblin celibrates its victory by dancing around with his moldy stick.";
					break;
				case 2:
					mName = "A Giant Rat";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(2, 6);
					atts.focus = diceRoll(2, 6);
					atts.cleverness = diceRoll(2, 6);
					atts.dexterity = diceRoll(2, 6);
					atts.faith = diceRoll(2, 6);
					atts.insperation = diceRoll(2, 6);
					copper = diceRoll(10, 5);
					armor = LOINCLOTH;
					weapon = FISTS;
					attackText = "Sharp Pointy Teeth";
					deathText = "the Rat goes squee and keels over dead.";
					winText = "the Rat starts eating your dead carcus.";
					break;
				case 3:
					mName = "A Troll";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(3, 6);
					atts.focus = diceRoll(3, 6);
					atts.cleverness = diceRoll(3, 6);
					atts.dexterity = diceRoll(3, 6);
					atts.faith = diceRoll(3, 6);
					atts.insperation = diceRoll(3, 6);
					copper = diceRoll(15, 5);
					armor = CLOTH;
					weapon = STAFF;
					attackText = "A Club";
					deathText = "the Troll goes \"MOMMY!\" and keels over dead.";
					winText = "the Troll starts looting your body.";
					break;
				case 4:
					mName = "A Venomous Snake";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(3, 6);
					atts.focus = diceRoll(3, 6);
					atts.cleverness = diceRoll(3, 6);
					atts.dexterity = diceRoll(3, 6);
					atts.faith = diceRoll(3, 6);
					atts.insperation = diceRoll(3, 6);
					copper = diceRoll(15, 5);
					armor = CLOTH;
					weapon = STAFF;
					attackText = "Sharp Pointy Phangs";
					deathText = "the Snake goes \"HISSS!\" and curls up dead.";
					winText = "the Snake devours your body.";
					break;
				case 5:
					mName = "A Mini Knight";
					hp = hpMax = diceRoll(3, 6);
					atts.strength = diceRoll(3, 6);
					atts.focus = diceRoll(3, 6);
					atts.cleverness = diceRoll(3, 6);
					atts.dexterity = diceRoll(3, 6);
					atts.faith = diceRoll(3, 6);
					atts.insperation = diceRoll(3, 6);
					copper = diceRoll(15, 5);
					armor = CLOTH;
					weapon = STAFF;
					attackText = "A Mini Sword";
					deathText = "the Mini Knight says \"I have fought bravely!\" and dies.";
					winText = "the Mini Knight starts to loot your body.";
					break;
			}
		}

		// Get or set methods.
		// Get the monster's hitpoints.
		int getHealth()
		{
			return hp;
		}

		// Get the monster's max hitpoints.
		int getMaxHealth()
		{
			return hpMax;
		}

		// We do not need this right now...
		/*int getMana()
		{
			return mp;
		}

		int getMaxMana()
		{
			return mpMax;
		}*/

		// Get the monster's name.
		char *getName()
		{
			return mName;
		}

		// Get the monster's attack text.
		char *getAttackText()
		{
			return attackText;
		}

		// Get the monster's death text.
		char *getDeathText()
		{
			return deathText;
		}

		// Get the player's death text.
		char *getWinText()
		{
			return winText;
		}

		// Get the monster's skill level.
		int getMasteries()
		{
			return masteries;
		}

		// Get how much copper the monster will drop.
		int getCopper()
		{
			return copper;
		}

		// Get the monster's armor.
		ARMOR getArmor()
		{
			return armor;
		}

		// Get the monster's weapon.
		WEAPON getWeapon()
		{
			return weapon;
		}

		// Get the monster's attributes.
		ATTRIBUTES getAtts()
		{
			return atts;
		}

		// Subtract Health
		void subHealth(int tmpDamage)
		{
			hp -= tmpDamage;
		}

		void addHealth(int tmpDamage)
		{
			hp += tmpDamage;
		}

		// Damaging
		// Damaging the monster.
		int mitigate(int tmpDamage)
		{
			// The balace for the armor of the monster and it's dexterity
			int dice = getAtts().dexterity + getArmor();

			// The tmpDamage set by the armor and dexterity all rolled in a dice.
			tmpDamage -= diceRoll(dice, 3);

			// Debugging.
			if (debug)
			{
				cout << "\n";
				cout << "After Mit: " << tmpDamage << "\n";
			}

			// Check if the damage is nothing or less than nothing.
			if (tmpDamage <= 0)
			{
				tmpDamage = 1;
			}

			// Subtract hp from the monster.
			subHealth(tmpDamage);

			// Return the damage.
			return tmpDamage;
		}
};

// Class for the character.
class character
{
	protected:
		ATTRIBUTES atts; // The stats that the player has.
		LEVELS levels; // The leveling stuff the player has.
		int copper; // The amount of money the player has.
		OCC charClass; // The characters class.
		RACE charRace; // The characters race.
		int hp, hpMax; // The hitpoints for the character.
		int mp, mpMax; // The mana or stamina for the character.
		LOCATION location; // The location the player is at.
		WEAPON weapon; // The weapon the character has.
		ARMOR armor; // The armor the character has.
		bool cheated; // If the player cheated.
		POTION potion; // The potion the player currently has.
		int bankCopper; // The copper the player has in the bank.
		bool null; // If the player's save file returns null.

	public:
		// Constructors
		// Create the character class.
		character()
		{
			// Set the default copper.
			copper = 100;

			// Set the default location of the menu.
			location = VIEWSTATS;

			// Set the default potion var.
			potion = NONE;

			// Set the bank copper.
			bankCopper = 0;
		}

		// Accessors
		// Get the player's hitpoints.
		int getHealth()
		{
			return hp;
		}

		// Get the player's max hitpoints.
		int getMaxHealth()
		{
			return hpMax;
		}

		// Get the player's mana.
		int getMana()
		{
			return mp;
		}

		// Get the player's max mana.
		int getMaxMana()
		{
			return mpMax;
		}

		// Get how much copper the player has.
		int getCopper()
		{
			return copper;
		}

		// Get the player's class.
		OCC getClass()
		{
			return charClass;
		}

		// Get the player's race.
		RACE getRace()
		{
			return charRace;
		}

		// Get the player's level stuff.
		LEVELS getLevels()
		{
			return levels;
		}

		// Get the player's weapon.
		WEAPON getWeapon()
		{
			return weapon;
		}

		// Get the attributes from outside this class.
		ATTRIBUTES getAtts()
		{
			// Return the attributes because thats what we want to do.
			return atts;
		}

		// Get the player's armor.
		ARMOR getArmor()
		{
			return armor;
		}

		// Get the location.
		LOCATION getLoc()
		{
			// Return the location because thats what we want to do.
			return location;
		}

		// Get the cheated var.
		bool getCheated()
		{
			return cheated;
		}

		// Get the player's current potion.
		POTION getPotion()
		{
			return potion;
		}

		// Get the player's copper in the bank.
		int getBankCopper()
		{
			return bankCopper;
		}

		// Get if the player file doesn't load.
		bool getNull()
		{
			return null;
		}

		// Set arguments.
		// Set the player's hitpoints.
		void setHealth(int tmpHp)
		{
			hp = tmpHp;
		}

		// Set the player's max hitpoints.
		void setMaxHealth(int tmpHpMax)
		{
			hpMax = tmpHpMax;
		}

		// Set the player's mana.
		void setMana(int tmpMp)
		{
			mp = tmpMp;
		}

		// Set the player's max mana.
		void setMaxMana(int tmpMpMax)
		{
			mpMax = tmpMpMax;
		}

		// Set the player's copper ammount.
		void setCopper(int tmpCopper)
		{
			copper = tmpCopper;
		}

		// Set the player's class.
		void setClass(OCC tmpCharClass)
		{
			charClass = tmpCharClass;
		}

		// Set the player's race.
		void setRace(RACE tmpCharRace)
		{
			charRace = tmpCharRace;
		}

		// Set the player's level stuff.
		void setLevels(LEVELS tmpLevels)
		{
			levels = tmpLevels;
		}

		// Set the player's armor.
		void setArmor(ARMOR tmpArmor)
		{
			armor = tmpArmor;
		}

		// Set the player's weapon.
		void setWeapon(WEAPON tmpWeapon)
		{
			weapon = tmpWeapon;
		}

		// Set the attributes from outside this class.
		void setAtts(ATTRIBUTES tmpAtts)
		{
			// Set the attributes to the character.
			atts = tmpAtts;
		}

		// Set the attributes outside of this class in parts.
		void setAttsTest(int tmpStrength, int tmpCleverness, int tmpDexterity, int tmpFaith, int tmpFocus, int tmpInsperation)
		{
			ATTRIBUTES tmpAtts;

			tmpAtts.strength = tmpStrength;
			tmpAtts.cleverness = tmpCleverness;
			tmpAtts.dexterity = tmpDexterity;
			tmpAtts.faith = tmpFaith;
			tmpAtts.focus = tmpFocus;
			tmpAtts.insperation = tmpInsperation;

			atts = tmpAtts;
		}

		// Set the player's location.
		void setLoc(LOCATION tmpLoc)
		{
			location = tmpLoc;
		}

		// Set if the player cheated.
		void setCheat(bool tmpCheated)
		{
			cheated = tmpCheated;
		}

		// Set the player's current potion.
		void setPotion(POTION tmpPotion)
		{
			potion = tmpPotion;
		}

		// Set the player's copper in the bank.
		void setBankCopper(int tmpCopper)
		{
			bankCopper = tmpCopper;
		}

		// Set the player's Level for checks
		void setLvl(int tmpLvl)
		{
			levels.charLvl = tmpLvl;
		}

		// Set if the player save file doesn't load
		void setNull(bool tmpNull)
		{
			null = tmpNull;
		}

		// Computing Functions
		// Subtract Health
		void subHealth(int tmpHp)
		{
			hp -= tmpHp;

			if (hp < 0)
			{
				hp = 0;
			}
		}

		// Add Max Health
		void addMaxHealth(int tmpHpMax)
		{
			hpMax += tmpHpMax;
		}

		// Add Health
		void addHealth(int tmpHp)
		{
			hp += tmpHp;

			if (hp > hpMax)
			{
				hp = hpMax;
			}
		}

		// Add bank copper.
		void addBankCopper(int tmpCopper)
		{
			bankCopper += tmpCopper;
		}

		// Subtract Copper.
		void subBankCopper(int tmpCopper)
		{
			bankCopper -= tmpCopper;

			if (bankCopper < 0)
			{
				bankCopper = 0;
			}
		}

		// Subtract Copper
		void subCopper(int tmpCopper)
		{
			copper -= tmpCopper;

			if (copper < 0)
			{
				copper = 0;
			}
		}

		// Add Health
		void addCopper(int tmpCopper)
		{
			copper += tmpCopper;

			if (copper > 25000 && !debug)
			{
				addBankCopper(copper - 25000);

				setCopper(25000);
			}
			if (copper > 50000 && debug)
			{
				addBankCopper(copper - 50000);

				setCopper(50000);
			}
		}

		// Subtract Mana
		void subMana(int tmpMp)
		{
			mp -= tmpMp;

			if(mp < 0)
			{
				mp = 0;
			}
		}

		// Add Max Mana
		void addMaxMana(int tmpMpMax)
		{
			mpMax += tmpMpMax;
		}

		// Add Mana
		void addMana(int tmpMp)
		{
			mp = tmpMp;

			if (mp > mpMax)
			{
				mp = mpMax;
			}
		}

		// Add Exp
		void addExp(int tmpExp)
		{
			levels.charExp += tmpExp;
		}

		// Subtract Exp
		void subExp(int tmpExp)
		{
			levels.charExp -= tmpExp;

			if (levels.charExp < 0)
			{
				levels.charExp = 0;
			}
		}

		// Experiance/Skill calculations
		void upgradeStats(int mod)
		{
			ATTRIBUTES tmpAtts = getAtts();

			tmpAtts.strength += diceRoll(1, 3) * mod;
			tmpAtts.cleverness += diceRoll(1, 3) * mod;
			tmpAtts.dexterity += diceRoll(1, 3) * mod;
			tmpAtts.faith += diceRoll(1, 3) * mod;
			tmpAtts.focus += diceRoll(1, 3) * mod;
			tmpAtts.insperation += diceRoll(1, 3) * mod;

			setAtts(tmpAtts);

			addMaxHealth(diceRoll(1, 3) * mod);
			addHealth(diceRoll(1, 3) * mod);
			addMaxMana(diceRoll(1, 3) * mod);
			addMana(diceRoll(1, 3) * mod);
		}

		void levelUp()
		{
			if (levels.charExp > levels.reqExp)
			{
				levels.charExp = levels.charExp - levels.reqExp;
			}

			int mod = levels.charLvl % levels.reqExp;

			levels.reqExp += 10 * mod;

			levels.charLvl += 1;

			upgradeStats(levels.charLvl);
		}

		void checkLvl()
		{
			if (levels.charExp >= levels.reqExp)
			{
				levelUp();
			}
			else if (levels.charExp < levels.reqExp)
			{
			}
			else if (levels.charExp < 0)
			{
				levels.charExp = 0;
			}
			else
			{
				// Do nothing
			}
		}

		// Attack functions
		// Damaging the player.
		int mitigate(int tmpDamage)
		{
			// The balace for the armor of the player and their dexterity
			int dice = getAtts().dexterity + getArmor();

			// The tmpDamage set by the armor and dexterity all rolled in a dice.
			tmpDamage -= diceRoll(dice, 3);

			// Debugging.
			if (debug)
			{
				cout << "\n";
				cout << "After Mit: " << tmpDamage << "\n";
			}

			// If the damage is below or equal to 0 then set to 1.
			if (tmpDamage <= 0)
			{
				tmpDamage = 1;
			}

			// Subtract hp from the player.
			subHealth(tmpDamage);

			// Return the Damage.
			return tmpDamage;
		}

		// Attack functions for classes.
		virtual void attack(monster* monster1) {}

		// The monster's attack function.
		void monsterAttack(monster* tmpMonster)
		{
			int damage = 0; // The damage var.

			// Calculate the target roll.
			int targetRoll = 10 + (tmpMonster->getAtts().strength + tmpMonster->getAtts().dexterity) - (atts.strength + atts.dexterity);

			if (targetRoll > 17) // If the target roll is above 17 then set to 17.
			{
				targetRoll = 17;
			}
			if (targetRoll < 3) // If the target roll is below 3 then set to 3.
			{
				targetRoll = 3;
			}

			// Tell if the monster hit or missed.
			bool hit = targetRoll >= diceRoll(1, 20);

			// If the monster hit or missed
			if (!hit)
			{
				cout << tmpMonster->getName() << " missed!\n";
			}
			else
			{
				// Get the dice modifier.
				int dice = tmpMonster->getAtts().strength + tmpMonster->weapon + tmpMonster->getMasteries();

				// Roll the dice modifier.
				damage = diceRoll(dice, 3) - dice;

				if (debug) // If 'debug == true' then output debug.
				{
					cout << "\n";
					cout << "Monster damage: " << damage << "\n";
				}

				// Do damage.
				damage = mitigate(damage);

				cout << "\n";

				cout << tmpMonster->getName() << " Attacks you with " << tmpMonster->getAttackText() << " for " << damage << " damage!";
			}
		}

		// Buying/Selling Functions
		// Function to pawn the item.
		int pawnItem(int item, int sell)
		{
			int tmpGold = 0;

			switch (item)
			{
				case 7:
					tmpGold += 1600;
				case 6:
					tmpGold += 800;
				case 5:
					tmpGold += 400;
				case 4:
					tmpGold += 200;
				case 3:
					tmpGold += 100;
				case 2:
					tmpGold += 50;
				case 1:
					tmpGold += 50;
				default:
					break;
			}

			if (sell == 1)
			{
				addCopper(tmpGold);
			}

			return tmpGold;
		}

		// Locations
		// Display stats.
		void locStats()
		{
			bool reroll = true; // Check for the loop.
			char menuItem; // The var for the menus.

			// Start the loop.
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "You look yourself over...\n";
				cout << "\n";

				// Display the stats.
				cout << "Stats:\n";
				cout << "   Strength:      " << getAtts().strength << "\n";
				cout << "   Faith:         " << getAtts().faith << "\n";
				cout << "   Dexterity:     " << getAtts().dexterity << "\n";
				cout << "   Insperation:   " << getAtts().insperation << "\n";
				cout << "   Cleverness:    " << getAtts().cleverness << "\n";
				cout << "   Focus:         " << getAtts().focus << "\n";

				cout << "\n";

				cout << "Hitpoints:        " << getHealth() << "/" << getMaxHealth() << "\n";
				cout << "Mana:             " << getMana() << "/" << getMaxMana() << "\n";
				cout << "Exp:              " << getLevels().charExp << "\n";
				cout << "   Levels:        " << getLevels().charLvl << "\n";
				cout << "   ReqExp:        " << getLevels().reqExp << "\n";

				cout << "\n";

				cout << "Copper:           " << getCopper() << "\n";

				cout << "\n";

				cout << "Armor:            " << displayArmorName(getArmor(), getClass()) << "\n";

				cout << "Weapon:           " << displayWeaponName(getWeapon(), getClass()) << "\n";

				cout << "\n";
				cout << "[G]o back to Town\n";

				// Get the input for the menu.
				cin >> menuItem;

				// Choose to go back to the town, no matter what.
				switch (menuItem)
				{
					case 'g':
					case 'G':
						setLoc(TOWN); // Set the location town because after we display
						break;					 // stats we want to go back to town.
					default:
						reroll = true; // If you do not type in the right input this will repeat.
						break;
				}
			}
		}

		// Display town code.
		void locTown()
		{
			bool reroll = true; // Check for the menu.
			char menuItem; // The var for the menus.

			// Start the loop.
			while (reroll)
			{
				// End the loop.
				reroll = false;

				cout << "\n";

				cout << "You find the small village of Zoro. This village is very small but strategic as it sits on the hotly contested bore bewteen Ipana and Seragul. You go to:\n";
				cout << "[1] The Forest\t\t [6] The Weaponsmith\n";
				cout << "[2] The Armorsmith\t [7] Chapel of the Void\n";
				cout << "[3] The Tavern\t\t [8] The Money Lender\n";
				cout << "[4] View your Stats\t [9] Quit\n";
				cout << "[5] Save game\t\t ";

				if (debug)
				{
					cout << "[D] Debug";
				}

				cout << "\n";

				// Get the menuItem.
				cin >> menuItem;

				// Choose from the locations in the town.
				switch (menuItem)
				{
					case '1':
						setLoc(FOREST); // Go to the forest.
						break;
					case '2':
						setLoc(ARMORSMITH); // Go to the armor smith.
						break;
					case '3':
						setLoc(TAVERN); // Go to the tavern.
						break;
					case '4':
						setLoc(VIEWSTATS); // Go to the view stats screen.
						break;
					case '5':
						setLoc(SAVE); // Go to the save screen.
						break;
					case '6':
						setLoc(WEAPONSMITH); // Go to the weapon smith.
						break;
					case '7':
						setLoc(CHAPEL); // Go to the chapel.
						break;
					case '8':
						setLoc(BANK); // Go to the bank.
						break;
					case '9':
						setLoc(QUIT); // Quit the game.
						break;
					case 'd':
					case 'D':
						if (!debug)
						{
							reroll = true;
						}
						else
						{
							setLoc(DEBUG); // Debug the game.
						}
						break;
					default:
						reroll = true; // If you do not type in a correct input then loop.
						break;
				}
			}
		}

		// Display forest code.
		void locForest()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";

				cout << "You enter the woods near Zoro. It's dark a spoopy, you think you hear some noise in the bushes. You:\n";
				cout << "[1] Look for monsters\t [3] Visit the alchimest\n";
				cout << "[2] Return To town\n";

				// Input for the menu.
				cin >> menuItem;

				// Choose from the locations in the forest.
				switch (menuItem)
				{
					case '1':
						setLoc(MONSTER); // Go find a monster.
						break;
					case '2':
						setLoc(TOWN); // Go to the town.
						break;
					case '3':
						setLoc(ALCHIMEST); // Go to the alchimest.
						break;
					default:
						reroll = true; // If you do not type in the right input then repeat.
						break;
				}
			}
		}

		// Display monster locations.
		void locMonster()
		{
			monster monster1; // Monster variable.

			monster1.genMonster(getLevels().charLvl);

			cout << "\n";
			cout << "You hear a rustel in the bushes. " << monster1.getName() << " jumps out at you\n";

			// Start the loop.
			while (hp > 0 && monster1.getHealth() > 0)
			{
				cout << "\n";
				cout << monster1.getName() << ": " << monster1.getHealth() << "/" << monster1.getMaxHealth() << "\n";
				cout << "You: " << hp << "/" << hpMax << "\n\n";
				cout << "Action?\n";

				// Attack the monster with it's data.
				attack(&monster1); // Start the battle.

				// If the monster is still alive then let the monster attack.
				if (monster1.getHealth() > 0)
				{
					// Let the monster attack with it's data.
					monsterAttack(&monster1);
				}
			}

			if (monster1.getHealth() <= 0) // The monster dies and you get loot.
			{
				cout << "As it dies, " << monster1.getDeathText() << "\n";
				// Set the location back to forest.
				setLoc(FOREST);
				cout << "You collect " << monster1.getCopper() << " copper from the corpse.\n";
				// Collect copper.
				copper += monster1.getCopper();
				int tmpExp = diceRoll(2, 5);
				addExp(tmpExp);
				cout << "You gain " << tmpExp << " exp from killing " << monster1.getName() << "\n";

				checkLvl();
			}
			if (hp <= 0) // You die and quit.
			{
				cout << monster1.getWinText() << "\n";
				cout << "You died!";
				// Quit the game.
				setLoc(QUIT);
			}
		}

		// Display armor smith code.
		void locArmorSmith()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";

				cout << "You enter a shop filled with a variaty of armor. Some are made of metal and some are not. Some are enchanted with magic runes. The shop owner asks what is your bussiness:\n";
				cout << "[1] Buy Armor\t [3] Return to town\n";
				cout << "[2] Sell Armor\n";

				// Input for the menu.
				cin >> menuItem;

				cout << "\n";

				// Choose from the locations in the armor smith shop.
				switch (menuItem)
				{
					case '1':
						setLoc(BUYARMOR); // Go buy armor.
						break;
					case '2':
						setLoc(SELLARMOR); // Go sell armor.
						break;
					case '3':
						setLoc(TOWN); // Go back to the town.
						break;
					default:
						reroll = true; // If you do not type in the right input then repeat.
						break;
				}
			}
		}

		// Display sell the armor code.
		void locBuyArmor()
		{
			bool reroll = true; // Check the loop
			int menuItem; // The var for the menus.
			bool nosale = false;

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "There are many suits of armor on display. Which do you wish to buy?\n";

				cout << "\n";

				switch (getArmor())
				{
					case LOINCLOTH:
						cout << "[1] " << displayArmorName(CLOTH, getClass()) << "\t100 copper\n";
					case CLOTH:
						cout << "[2] " << displayArmorName(LEATHER, getClass()) << "\t200 copper\n";
					case LEATHER:
						cout << "[3] " << displayArmorName(CHAIN, getClass()) << "\t\t400 copper\n";
					case CHAIN:
						cout << "[4] " << displayArmorName(PLATE, getClass()) << "\t\t800 copper\n";
					case PLATE:
						cout << "[5] " << displayArmorName(ANCIENTPLATE, getClass()) << "\t1600 copper\n";
					case ANCIENTPLATE:
						cout << "[6] " << displayArmorName(MAGICPLATE, getClass()) << "\t\t3200 copper\n";
					case MAGICPLATE:
						cout << "[7] " << displayArmorName(ARCHANEPLATE, getClass()) << "\t6400 copper\n";
					default:
						cout << "[8] Back to Shop\n";
				}

				int lowMenu = getArmor() + 1;

				cout << "\n";

				cin >> menuItem;

				cout << "\n";

				if (menuItem < lowMenu)
				{
					menuItem = 9;
				}

				switch (menuItem)
				{
					case 1:
						if (copper >= 100)
						{
							cout << "You buy " << displayArmorName(CLOTH, getClass()) << " for 100 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(100);
							setArmor(CLOTH);
						}
						else
						{
							nosale = true;
						}
						break;
					case 2:
						if (copper >= 200)
						{
							cout << "You buy " << displayArmorName(LEATHER, getClass()) << " for 200 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(200);
							setArmor(LEATHER);
						}
						else
						{
							nosale = true;
						}
						break;
					case 3:
						if (copper >= 400)
						{
							cout << "You buy " << displayArmorName(CHAIN, getClass()) << " for 400 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(400);
							setArmor(CHAIN);
						}
						else
						{
							nosale = true;
						}
						break;
					case 4:
						if (copper >= 800)
						{
							cout << "You buy " << displayArmorName(PLATE, getClass()) << " for 800 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(800);
							setArmor(PLATE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 5:
						if (copper >= 1600)
						{
							cout << "You buy " << displayArmorName(ANCIENTPLATE, getClass()) << " for 1600 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(1600);
							setArmor(ANCIENTPLATE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 6:
						if (copper >= 3200)
						{
							cout << "You buy " << displayArmorName(MAGICPLATE, getClass()) << " for 3200 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(3200);
							setArmor(MAGICPLATE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 7:
						if (copper >= 6400)
						{
							cout << "You buy " << displayArmorName(ARCHANEPLATE, getClass()) << " for 6400 copper\n";
							cout << "You recive " << pawnItem(getArmor(), 1) << "copper, for selling your old armor.\n";
							subCopper(6400);
							setArmor(ARCHANEPLATE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 8:
						setLoc(ARMORSMITH);
						break;
					case 9:
						reroll = true;
						break;
					default:
						break;
				}
			}

			if (nosale)
			{
				cout << "\n";
				cout << "You cannot afford this...";
			}

			setLoc(WEAPONSMITH);
		}

		// Display sell the armor code.
		void locSellArmor()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "The armor smith looks over your armor, \"I'll give ya " << pawnItem(getArmor(), 0) << " copper for it! Would you like to buy it?\" [Y]es [N]o\n";

				cin >> menuItem;

				switch (menuItem)
				{
					case 'y':
					case 'Y':
						cout << "You sell your armor for " << pawnItem(getArmor(), 1) << "copper\n";
						setArmor(LOINCLOTH);
						break;
					case 'n':
					case 'N':
					default:
						break;
				}
			}

			setLoc(ARMORSMITH);
		}

		// Display weapon smith code.
		void locWeaponSmith()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n\n";

				cout << "You enter a shop filled with a variaty of armor. Some are made of metal and some are not. Some are enchanted with magic runes. The shop owner asks what is your bussiness:\n";
				cout << "[1] Buy Weapons\t [3] Return to town\n";
				cout << "[2] Sell Weapons\n";

				// Input for the menu.
				cin >> menuItem;

				cout << "\n";

				// Choose from the locations in the weapon smith shop.
				switch (menuItem)
				{
					case '1':
						setLoc(BUYWEAPON); // Go buy weapons.
						break;
					case '2':
						setLoc(SELLWEAPON); // Go sell weapons.
						break;
					case '3':
						setLoc(TOWN); // Go back to the town.
						break;
					default:
						reroll = true; // If you do not type in the right input then repeat.
						break;
				}
			}
		}

		// Display buy the weapons code.
		void locBuyWeapon()
		{
			bool reroll = true; // Check the loop
			int menuItem; // The var for the menus.
			bool nosale = false;

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "There are many weapons on display. Which do you wish to buy?\n";

				cout << "\n";

				switch (getWeapon())
				{
					case FISTS:
						cout << "[1] " << displayArmorName(DAGGER, getClass()) << "\t100 copper\n";
					case DAGGER:
						cout << "[2] " << displayArmorName(STAFF, getClass()) << "\t200 copper\n";
					case STAFF:
						cout << "[3] " << displayArmorName(SWORD, getClass()) << "\t400 copper\n";
					case SWORD:
						cout << "[4] " << displayArmorName(ANCIENTBLADE, getClass()) << "\t800 copper\n";
					case ANCIENTBLADE:
						cout << "[5] " << displayArmorName(MAGICBLADE, getClass()) << "\t1600 copper\n";
					case MAGICBLADE:
						cout << "[6] " << displayArmorName(ARCHANEBLADE, getClass()) << "\t3200 copper\n";
					default:
						cout << "[7] Back to Shop\n";
				}

				int lowMenu = getWeapon() + 1;

				cin >> menuItem;

				cout << "\n";

				if (menuItem < lowMenu)
				{
					menuItem = 8;
				}

				switch (menuItem)
				{
					case 1:
						if (copper >= 100)
						{
							cout << "\n";
							cout << "You buy " << displayWeaponName(DAGGER, getClass()) << " for 100 copper\n";
							cout << "You recive " << pawnItem(getWeapon(), 1) << "copper, for selling your old weapon.\n";
							subCopper(100);
							setWeapon(DAGGER);
						}
						else
						{
							nosale = true;
						}
						break;
					case 2:
						if (copper >= 200)
						{
							cout << "\n";
							cout << "You buy " << displayWeaponName(STAFF, getClass()) << " for 200 copper\n";
							cout << "You recive " << pawnItem(getWeapon(), 1) << "copper, for selling your old weapon.\n";
							subCopper(200);
							setWeapon(STAFF);
						}
						else
						{
							nosale = true;
						}
						break;
					case 3:
						if (copper >= 400)
						{
							cout << "\n";
							cout << "You buy " << displayWeaponName(SWORD, getClass()) << " for 400 copper\n";
							cout << "You recive " << pawnItem(getWeapon(), 1) << "copper, for selling your old weapon.\n";
							subCopper(400);
							setWeapon(SWORD);
						}
						else
						{
							nosale = true;
						}
						break;
					case 4:
						if (copper >= 800)
						{
							cout << "\n";
							cout << "You buy " << displayWeaponName(ANCIENTBLADE, getClass()) << " for 800 copper\n";
							cout << "You recive " << pawnItem(getWeapon(), 1) << "copper, for selling your old weapon.\n";
							subCopper(800);
							setWeapon(ANCIENTBLADE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 5:
						if (copper >= 1600)
						{
							cout << "\n";
							cout << "You buy " << displayWeaponName(MAGICBLADE, getClass()) << " for 1600 copper\n";
							cout << "You recive " << pawnItem(getWeapon(), 1) << "copper, for selling your old weapon.\n";
							subCopper(1600);
							setWeapon(MAGICBLADE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 6:
						if (copper >= 3200)
						{
							cout << "\n";
							cout << "You buy " << displayWeaponName(ARCHANEBLADE, getClass()) << " for 3200 copper\n";
							cout << "You recive " << pawnItem(getWeapon(), 1) << "copper, for selling your old weapon.\n";
							subCopper(3200);
							setWeapon(ARCHANEBLADE);
						}
						else
						{
							nosale = true;
						}
						break;
					case 7:
						setLoc(WEAPONSMITH);
						break;
					case 8:
						reroll = true;
						break;
					default:
						break;
				}
			}

			if (nosale)
			{
				cout << "\n";
				cout << "You cannot afford this...";
			}

			setLoc(WEAPONSMITH);
		}

		// Display sell the weapons code.
		void locSellWeapon()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "The armor smith looks over your weapon, \"I'll give ya " << pawnItem(getWeapon(), 0) << " copper for it! Would you like to buy it?\" [Y]es [N]o\n";

				cin >> menuItem;

				switch (menuItem)
				{
					case 'y':
					case 'Y':
						cout << "You sell your weapon for " << pawnItem(getWeapon(), 1) << " copper\n";
						setWeapon(FISTS);
						break;
					case 'n':
					case 'N':
					default:
						break;
				}
			}

			setLoc(WEAPONSMITH);
		}

		// Display the tavern code.
		void locTavern()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "There is nothing to see here...\n";
				cout << "[G]o back to town";

				cin >> menuItem;

				cout << "\n";

				switch (menuItem)
				{
					default:
					case 'g':
					case 'G':
						setLoc(TOWN);
						break;
				}
			}
		}

		// Display the chapel code.
		void locChapel()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "There is nothing to see here...\n";
				cout << "[G]o back to town";

				cin >> menuItem;

				cout << "\n";

				switch (menuItem)
				{
					default:
					case 'g':
					case 'G':
						setLoc(TOWN);
						break;
				}
			}
		}

		// Display the bank code.
		void locBank()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "There is nothing to see here...\n";
				cout << "[1] Deposit Money\t[3] Go back to town\n";
				cout << "[2] Withdraw Money\n";

				cin >> menuItem;

				cout << "\n";

				switch (menuItem)
				{
					case '1':
						setLoc(PUTMONEY);
						break;
					case '2':
						setLoc(TAKEMONEY);
					default:
					case '3':
						setLoc(TOWN);
						break;
				}
			}
		}

		// Display the withdraw money code.
		void locWithdrawMoney()
		{
			int tmpCopper;

			cout << "\n";
			cout << "The banker says, \"How much money do you want to withdraw?\"\n";
			cout << "Bank Money: " << getBankCopper() << " copper\n";
			cout << "Money       " << getCopper() << " copper\n";

			cin >> tmpCopper;

			cout << "\n";

			addBankCopper(tmpCopper);

			setLoc(BANK);
		}

		// Display the deposit money code.
		void locDepositMoney()
		{
			int tmpCopper;

			cout << "\n";
			cout << "The banker says, \"How much money do you want to desposit?\"\n";
			cout << "Money        " << getCopper() << " copper\n";
			cout << "Bank Copper: " << getBankCopper() << " copper\n";
			cin >> tmpCopper;

			cout << "\n";

			subBankCopper(tmpCopper);

			setLoc(BANK);
		}

		// Display the alchimest code.
		void locAlchimest()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "There is nothing to see here...\n";
				cout << "[1] Buy potions\t[3] Go back to torest\n";
				cout << "[2] Sell potions\n";

				cin >> menuItem;

				cout << "\n";

				switch (menuItem)
				{
					case '1':
						setLoc(BUYPOTION);
						break;
					case '2':
						setLoc(SELLPOTION);
						break;
					default:
					case '3':
						setLoc(FOREST);
						break;
				}
			}
		}

		// Display buy a potion code.
		void locBuyPotion()
		{
			bool reroll = true; // Check the loop
			int menuItem; // The var for the menus.
			bool nosale = false;

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "The room smells of brews, there are potions everywhere. Which do you wish to buy?\n";

				cout << "\n";

				cout << "[1] Health Potion\t100 copper\n";
				cout << "[2] Mana Potion\t200 copper\n";
				cout << "[3] Exp Potion\t400 copper\n";
				cout << "[4] Back to Shop\n";

				cin >> menuItem;

				cout << "\n";

				switch (menuItem)
				{
					case 1:
						if (copper >= 100)
						{
							cout << "You buy the health potion for 100 copper\n";

							if (getPotion() != NONE)
							{
								cout << "You recive " << pawnItem(getPotion(), 1) << " copper, for selling your old potion.\n";
							}

							subCopper(100);
							setPotion(HEALTH);
						}
						else
						{
							nosale = true;
						}
						break;
					case 2:
						if (copper >= 200)
						{
							cout << "You buy the mana potion for 200 copper\n";

							if (getPotion() != NONE)
							{
								cout << "You recive " << pawnItem(getPotion(), 1) << " copper, for selling your old potion.\n";
							}

							subCopper(100);
							setPotion(MANA);
						}
						else
						{
							nosale = true;
						}
						break;
					case 3:
						if (copper >= 400)
						{
							cout << "You buy the health potion for 400 copper\n";

							if (getPotion() != NONE)
							{
								cout << "You recive " << pawnItem(getPotion(), 1) << " copper, for selling your old potion.\n";
							}

							subCopper(100);
							setPotion(EXP);
						}
						else
						{
							nosale = true;
						}
						break;
					case 4:
						setLoc(ALCHIMEST);
						break;
					default:
						break;
				}
			}

			if (nosale)
			{
				cout << "\n";
				cout << "You cannot afford this...";
			}

			setLoc(ALCHIMEST);
		}

		// Display sell a potion code.
		void locSellPotion()
		{
			bool reroll = true; // Check the loop
			char menuItem; // The var for the menus.

			// Repeat the menu
			while (reroll)
			{
				// End the reroll.
				reroll = false;

				cout << "\n";
				cout << "The armor smith looks over your potion, \"I'll give ya " << pawnItem(getWeapon(), 0) << " copper for it! Would you like to buy it?\" [Y]es [N]o\n";

				cin >> menuItem;

				cout << "\n";

				switch (menuItem)
				{
					case 'y':
					case 'Y':
						cout << "You sell your potion for " << pawnItem(getWeapon(), 1) << "copper\n";
						setWeapon(FISTS);
						break;
					case 'n':
					case 'N':
					default:
						break;
				}
			}

			setLoc(ALCHIMEST);
		}
};

// Class for the fighter.
class fighter : public character
{
	public:
		// Create the fighter class.
		fighter()
		{
			cout << "Fighter Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default fighter's hitpoints.
			setMaxMana(20);
			setMana(20); // Set the default fighter's mana.

			setArmor(LEATHER); // Set the default fighter's armor.

			setWeapon(SWORD); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[F]renzy";
				}
				if (getMana() >= 5)
				{
					cout << "\n[D]eadly Strike";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				cout << "\n";

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Basic Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'f':
					case 'F':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Frenzy Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'd':
					case 'D':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Deadly Strike Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					case 'p':
					case 'P':
						switch (getPotion())
						{
							case HEALTH:
								addHealth(30);
								break;
							case MANA:
								addMana(20);
								break;
							case EXP:
								addExp(10);
								break;
							case CHEAT:
								addHealth(1000);
								addMana(1000);
								addExp(1000);
								break;
						}
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

// Class for the Cleric.
class cleric : public character
{
	public:
		cleric()
		{
			cout << "Cleric Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the cleric.
			setMaxMana(50);
			setMana(50); // Set the default stamina for the cleric.

			setArmor(CLOTH); // Set the default fighter's armor.

			setWeapon(STAFF); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[J]ab";
				}
				if (getMana() >= 5)
				{
					cout << "\nP[o]und\n";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Basic Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'j':
					case 'J':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Jab Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'o':
					case 'O':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Pound Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					case 'p':
					case 'P':
						switch (getPotion())
						{
							case HEALTH:
								addHealth(30);
								break;
							case MANA:
								addMana(20);
								break;
							case EXP:
								addExp(10);
								break;
							case CHEAT:
								addHealth(1000);
								addMana(1000);
								addExp(1000);
								break;
						}
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

// Class for the Rouge.
class rouge : public character
{
	public:
		// Create the rogue class.
		rouge()
		{
			cout << "Rouge Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the rouge.
			setMaxMana(20);
			setMana(20); // Set the default stamina for the rouge.

			setArmor(LEATHER); // Set the default fighter's armor.

			setWeapon(SWORD); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[J]ab";
				}
				if (getMana() >= 5)
				{
					cout << "\n[S]pin Attack\n";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Basic Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'j':
					case 'J':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Jab Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 's':
					case 'S':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Spin Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

// Class for the Bard.
class bard : public character
{
	public:
		// Create the bard class.
		bard()
		{
			cout << "Bard Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the bard.
			setMaxMana(50);
			setMana(50); // Set the default stamina for the bard.

			setArmor(LEATHER); // Set the default fighter's armor.

			setWeapon(SWORD); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[F]renzy";
				}
				if (getMana() >= 5)
				{
					cout << "\nP[o]und";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Basic Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'f':
					case 'F':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Frenzy Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'o':
					case 'O':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Pound Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					case 'p':
					case 'P':
						switch (getPotion())
						{
							case HEALTH:
								addHealth(30);
								break;
							case MANA:
								addMana(20);
								break;
							case EXP:
								addExp(10);
								break;
							case CHEAT:
								addHealth(1000);
								addMana(1000);
								addExp(1000);
								break;
						}
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

// Class for the Rouge.
class theif : public character
{
	public:
		// Create the rogue class.
		theif()
		{
			cout << "Theif Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the rouge.
			setMaxMana(20);
			setMana(20); // Set the default stamina for the rouge.

			setArmor(CLOTH); // Set the default fighter's armor.

			setWeapon(SWORD); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[S]wipe";
				}
				if (getMana() >= 5)
				{
					cout << "\n[M]assacure";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Swipe Attack (F): " << damage << "\n";
							}
						}
						break;
					case 's':
					case 'S':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Massacure Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'm':
					case 'M':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Deadly Strike Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					case 'p':
					case 'P':
						switch (getPotion())
						{
							case HEALTH:
								addHealth(30);
								break;
							case MANA:
								addMana(20);
								break;
							case EXP:
								addExp(10);
								break;
							case CHEAT:
								addHealth(1000);
								addMana(1000);
								addExp(1000);
								break;
						}
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

// Class for the Tinker.
class tinker : public character
{
	public:
		tinker()
		{
			// Create the tinker class.
			cout << "Tinker Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the tinker.
			setMaxMana(20);
			setMana(20); // Set the default stamina for the tinker.

			setArmor(LEATHER); // Set the default fighter's armor.

			setWeapon(SWORD); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[A]ttack";

				if (getMana() >= 1)
				{
					cout << "\t[W]rench";
				}
				if (getMana() >= 5)
				{
					cout << "\n[E]nergy Pound";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Basic Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'w':
					case 'W':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Wrench Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'e':
					case 'E':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Energy Pound Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					case 'p':
					case 'P':
						switch (getPotion())
						{
							case HEALTH:
								addHealth(30);
								break;
							case MANA:
								addMana(20);
								break;
							case EXP:
								addExp(10);
								break;
							case CHEAT:
								addHealth(1000);
								addMana(1000);
								addExp(1000);
								break;
						}
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

// Class for the Mage.
class mage : public character
{
	public:
		// Create the mage class.
		mage()
		{
			cout << "Mage Created.\n";

			setMaxHealth(diceRoll(7, 6));
			setHealth(diceRoll(7, 6)); // Set the default hitpoints for the mage.
			setMaxMana(50);
			setMana(50); // Set the default mana for the mage.

			setArmor(CLOTH); // Set the default fighter's armor.

			setWeapon(STAFF); // Set the default fighter's weapon.
		}

		// This is to attack the monster.
		virtual void attack(monster* monster1)
		{
			char inputs; // The var for the menus.
			bool reroll = true; // Check for the loop.
			int damage = 0; // Damage that is being done.

			// Start the loop.
			while (reroll)
			{
				reroll = false; // End the loop.

				cout << "[S]pell";

				if (getMana() >= 1)
				{
					cout << "\t[M]agic Frenzy";
				}
				if (getMana() >= 5)
				{
					cout << "\n[A]steriod Beam";
				}
				if (getPotion() != NONE)
				{
					cout << "\nDrink [P]otion";
				}

				// Get the input of what attack to use.
				cin >> inputs;

				// Set the target roll
				int targetRoll = 10 + (getAtts().dexterity + getAtts().strength) - (monster1->getAtts().dexterity + monster1->getAtts().strength);

				// Make the maximum of target roll to 17.
				if (targetRoll > 17)
				{
					targetRoll = 17;
				}
				// Make the minimum of target roll to 3.
				if (targetRoll < 3)
				{
					targetRoll = 3;
				}

				// Get if the dice roll is the same as the target roll.
				bool hit = targetRoll >= diceRoll(1, 20);

				cout << "\n";

				// If the dice roll doesn't equal the target roll.
				if (!hit)
				{
					cout << "Missed!\n";
				}

				switch (inputs)
				{
					case 's':
					case 'S':
						// If the dice roll matches the target roll or is higher than it.
						if (hit)
						{
							// Set the damage pre-roll
							int dice = getAtts().strength + getWeapon() + getLevels().charLvl;
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Spell Attack (F): " << damage << "\n";
							}
						}
						break;
					case 'm':
					case 'M':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to one.
						if (hit && getMana() >= 1)
						{
							// Set the damage pre-roll and since it is a higher damage attack then double the attack.
							int dice = 2 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 3) - dice;
							if (debug) // For now output the damage.
							{
								cout << "\n";
								cout << "Magic Frenzy Attack (F): " << damage << "\n";
							}
							// Since this is a special attack then remove some mana points.
							subMana(1);
						}
						break;
					case 'a':
					case 'A':
						// If the dice roll matches the target roll or is higher than it and the player's mana is greater than or equal to five.
						if (hit && getMana() >= 5)
						{
							// Set the damage pre-roll and since this is a deadly attack
							int dice = 100 * (getAtts().strength + getWeapon() + getLevels().charLvl);
							// Roll the damage from the pre-roll.
							damage = diceRoll(dice, 6) - dice;
							if (debug) // If debug then output the damage.
							{
								cout << "\n";
								cout << "Asteroid Beam Attack (F): " << damage << "\n";
							}
							subMana(5);
							// Since this is a special attack then remove some mana points.
						}
						break;
					case 'p':
					case 'P':
						switch (getPotion())
						{
							case HEALTH:
								addHealth(30);
								break;
							case MANA:
								addMana(20);
								break;
							case EXP:
								addExp(10);
								break;
							case CHEAT:
								addHealth(1000);
								addMana(1000);
								addExp(1000);
								break;
						}
					default:
						reroll = true; // If the input is not valid restart the loop.
				}
			}

			if (damage > 0)
			{
				damage = monster1->mitigate(damage);
			}
		}
};

class saveFileData
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
		bool cheated; // If the player has cheated.
		POTION potion; // The current potion the player has.
		int bankCopper; // The amount of copper the player has in his bank.
		int charExp; // The total amount of exp the player has.
		int charLvl; // The level the player's level is for checks.
		int reqExp; // The requires amount of exp to level up.

		saveFileData()
		{
		}

		void init(character *tmpChar)
		{
			strength = tmpChar->getAtts().strength; // Set the strength.
			faith = tmpChar->getAtts().faith; // Set the faith.
			dexterity = tmpChar->getAtts().dexterity; // Set the dexterity.
			insperation = tmpChar->getAtts().insperation; // Set the insperation.
			cleverness = tmpChar->getAtts().cleverness; // Set the cleverness.
			focus = tmpChar->getAtts().focus; // Set the focus.
			copper = tmpChar->getCopper(); // Set the copper.
			charClass = tmpChar->getClass(); // Set the class.
			charRace = tmpChar->getRace(); // Set the race.
			hp = tmpChar->getHealth(); // Set the hp.
			hpMax = tmpChar->getMaxHealth(); // Set the max hp.
			mp = tmpChar->getMana(); // Set the mana.
			mpMax = tmpChar->getMaxMana(); // Set the max mana.
			location = tmpChar->getLoc(); // Set the location.
			weapon = tmpChar->getWeapon(); // Set the weapon.
			armor = tmpChar->getArmor(); // Set the armor.
			cheated = tmpChar->getCheated(); // Set if the player cheated.
			potion = tmpChar->getPotion(); // Set the player's current potion.
			bankCopper = tmpChar->getBankCopper(); // Set the player's money in the bank.
			charExp = tmpChar->getLevels().charExp;
			charLvl = tmpChar->getLevels().charLvl;
			reqExp = tmpChar->getLevels().reqExp;
		}
};

void debugSave(saveFileData tmpSaveFile)
{
	cout << "+=================================+\n";
	cout << "   Debug -> STARTING\n";
	cout << "+=================================+\n";
	cout << "Player Save Data: " << ((char *)&tmpSaveFile) << "\n";
	cout << "Player Save Size: " << (sizeof(tmpSaveFile)) << "\n";
	cout << "+=================================+\n";
	cout << "   Save Class Debug\n";
	cout << "+=================================+\n";

	cout << "Stats:\n";
	cout << "   Strength:      " << tmpSaveFile.strength << "\n";
	cout << "   Faith:         " << tmpSaveFile.faith << "\n";
	cout << "   Dexterity:     " << tmpSaveFile.dexterity << "\n";
	cout << "   Insperation:   " << tmpSaveFile.insperation << "\n";
	cout << "   Cleverness:    " << tmpSaveFile.cleverness << "\n";
	cout << "   Focus:         " << tmpSaveFile.focus << "\n";
	cout << "Copper:           " << tmpSaveFile.copper << "\n";

	switch (tmpSaveFile.charClass)
	{
		case FIGHTER:
			cout << "Class:            FIGHTER\n";
			break;
		case CLERIC:
			cout << "Class:            CLERIC\n";
			break;
		case ROUGE:
			cout << "Class:            ROUGE\n";
			break;
		case BARD:
			cout << "Class:            BARD\n";
			break;
		case THEIF:
			cout << "Class:            THEIF\n";
			break;
		case TINKER:
			cout << "Class:            TINKER\n";
			break;
		case MAGE:
			cout << "Class:            MAGE\n";
			break;
		default:
			cout << "Class:            BROKEN\n";
			break;
	}

	switch (tmpSaveFile.charRace)
	{
		case HUMAN:
			cout << "Race:             HUMAN\n";
			break;
		case ELF:
			cout << "Race:             ELF\n";
			break;
		case DARKELF:
			cout << "Race:             DARKELF\n";
			break;
		case ANGEL:
			cout << "Race:             ANGEL\n";
			break;
		case MONGREL:
			cout << "Race:             MONGREL\n";
			break;
		case SHAMANI:
			cout << "Race:             SHAMANI\n";
			break;
		case NIBELUNG:
			cout << "Race:             NIBELUNG\n";
			break;
		case UNDEAD:
			cout << "Race:             UNDEAD\n";
			break;
		default:
			cout << "Race:             BROKEN\n";
			break;
	}

	cout << "Hitpoints:        " << tmpSaveFile.hp << "\n";
	cout << "Max Hitpoints:    " << tmpSaveFile.hpMax << "\n";
	cout << "Mana:             " << tmpSaveFile.mp << "\n";
	cout << "Max Mana:         " << tmpSaveFile.mpMax << "\n";

	switch (tmpSaveFile.location)
	{
		case QUIT:
			cout << "Location:         QUIT\n";
			break;
		case VIEWSTATS:
			cout << "Location:         VIEWSTATS\n";
			break;
		case TOWN:
			cout << "Location:         TOWN\n";
			break;
		case FOREST:
			cout << "Location:         FOREST\n";
			break;
		case MONSTER:
			cout << "Location:         MONSTER\n";
			break;
		case SAVE:
			cout << "Location:         SAVE\n";
			break;
		case ARMORSMITH:
			cout << "Location:         ARMORSMITH\n";
			break;
		case BUYARMOR:
			cout << "Location:         BUYARMOR\n";
			break;
		case SELLARMOR:
			cout << "Location:         SELLARMOR\n";
			break;
		case TAVERN:
			cout << "Location:         TAVERN\n";
			break;
		case WEAPONSMITH:
			cout << "Location:         WEAPONSMITH\n";
			break;
		case CHAPEL:
			cout << "Location:         CHAPEL\n";
			break;
		case BANK:
			cout << "Location:         BANK\n";
			break;
		case ALCHIMEST:
			cout << "Location:         ALCHIMEST\n";
			break;
		default:
			cout << "Location:         BROKEN\n";
	}

	switch (tmpSaveFile.weapon)
	{
		case FISTS:
			cout << "Weapon:           FISTS\n";
			break;
		case DAGGER:
			cout << "Weapon:           DAGGER\n";
			break;
		case SWORD:
			cout << "Weapon:           SWORD\n";
			break;
		case STAFF:
			cout << "Weapon:           STAFF\n";
			break;
		case ANCIENTBLADE:
			cout << "Weapon:           ANCIENTBLADE\n";
			break;
		case MAGICBLADE:
			cout << "Weapon:           MAGICBLADE\n";
			break;
		case ARCHANEBLADE:
			cout << "Weapon:           ARCHANEBLADE\n";
			break;
		case VOIDEXCALIBUR:
			cout << "Weapon:           VOIDEXCALIBUR\n";
			break;
		default:
			cout << "Weapon:           BROKEN\n";
	}

	cout << "Weapon set name:  " << displayWeaponName(tmpSaveFile.weapon, tmpSaveFile.charClass) << "\n";

	switch (tmpSaveFile.armor)
	{
		case LOINCLOTH:
			cout << "Armor:            LOINCLOTH\n";
			break;
		case CLOTH:
			cout << "Armor:            CLOTH\n";
			break;
		case LEATHER:
			cout << "Armor:            LEATHER\n";
			break;
		case CHAIN:
			cout << "Armor:            CHAIN\n";
			break;
		case PLATE:
			cout << "Armor:            PLATE\n";
			break;
		case ANCIENTPLATE:
			cout << "Armor:            ANCIENTPLATE\n";
			break;
		case MAGICPLATE:
			cout << "Armor:            MAGICPLATE\n";
			break;
		case ARCHANEPLATE:
			cout << "Armor:            ARCHANEPLATE\n";
			break;
		case IMPERVIUMPLATE:
			cout << "Armor:            IMPERVIUMPLATE\n";
			break;
		default:
			cout << "Armor:            BROKEN\n";
	}

	cout << "Armor set name:   " << displayArmorName(tmpSaveFile.armor, tmpSaveFile.charClass) << "\n";

	switch (tmpSaveFile.cheated)
	{
		case true:
			cout << "Cheated:          TRUE\n";
			break;
		case false:
			cout << "Cheated:          FALSE\n";
			break;
	}

	cout << "Bank Copper:      " << tmpSaveFile.bankCopper << "\n";

	switch (tmpSaveFile.potion)
	{
		case NONE:
			cout << "Potion:           NONE\n";
			break;
		case HEALTH:
			cout << "Potion:           HEALTH\n";
			break;
		case MANA:
			cout << "Potion:           MANA\n";
			break;
		case EXP:
			cout << "Potion:           EXP\n";
			break;
		case CHEAT:
			cout << "Potion:           CHEAT\n";
			break;
	}

	cout << "Exp:             " << tmpSaveFile.charExp << "\n";

	cout << "   Levels:       " << tmpSaveFile.charLvl << "\n";

	cout << "   ReqExp:       " << tmpSaveFile.reqExp << "\n";

	cout << "+=================================+\n";
	cout << "   Debug -> ENDED\n";
	cout << "+=================================+\n";
}

void debugSave(character tmpSaveFile)
{
	cout << "+=================================+\n";
	cout << "   Debug -> STARTING\n";
	cout << "+=================================+\n";
	cout << "Player Save Data: " << ((char *)&tmpSaveFile) << "\n";
	cout << "Player Save Size: " << (sizeof(tmpSaveFile)) << "\n";
	cout << "+=================================+\n";
	cout << "   Save Class Debug\n";
	cout << "+=================================+\n";

	cout << "Stats:\n";
	cout << "   Strength:      " << tmpSaveFile.getAtts().strength << "\n";
	cout << "   Faith:         " << tmpSaveFile.getAtts().faith << "\n";
	cout << "   Dexterity:     " << tmpSaveFile.getAtts().dexterity << "\n";
	cout << "   Insperation:   " << tmpSaveFile.getAtts().insperation << "\n";
	cout << "   Cleverness:    " << tmpSaveFile.getAtts().cleverness << "\n";
	cout << "   Focus:         " << tmpSaveFile.getAtts().focus << "\n";
	cout << "Copper:           " << tmpSaveFile.getCopper() << "\n";

	switch (tmpSaveFile.getClass())
	{
		case FIGHTER:
			cout << "Class:            FIGHTER\n";
			break;
		case CLERIC:
			cout << "Class:            CLERIC\n";
			break;
		case ROUGE:
			cout << "Class:            ROUGE\n";
			break;
		case BARD:
			cout << "Class:            BARD\n";
			break;
		case THEIF:
			cout << "Class:            THEIF\n";
			break;
		case TINKER:
			cout << "Class:            TINKER\n";
			break;
		case MAGE:
			cout << "Class:            MAGE\n";
			break;
		default:
			cout << "Class:            BROKEN\n";
			break;
	}

	switch (tmpSaveFile.getRace())
	{
		case HUMAN:
			cout << "Race:             HUMAN\n";
			break;
		case ELF:
			cout << "Race:             ELF\n";
			break;
		case DARKELF:
			cout << "Race:             DARKELF\n";
			break;
		case ANGEL:
			cout << "Race:             ANGEL\n";
			break;
		case MONGREL:
			cout << "Race:             MONGREL\n";
			break;
		case SHAMANI:
			cout << "Race:             SHAMANI\n";
			break;
		case NIBELUNG:
			cout << "Race:             NIBELUNG\n";
			break;
		case UNDEAD:
			cout << "Race:             UNDEAD\n";
			break;
		default:
			cout << "Race:             BROKEN\n";
			break;
	}

	cout << "Hitpoints:        " << tmpSaveFile.getHealth() << "\n";
	cout << "Max Hitpoints:    " << tmpSaveFile.getMaxHealth() << "\n";
	cout << "Mana:             " << tmpSaveFile.getMana() << "\n";
	cout << "Max Mana:         " << tmpSaveFile.getMaxMana() << "\n";

	switch (tmpSaveFile.getLoc())
	{
		case QUIT:
			cout << "Location:         QUIT\n";
			break;
		case VIEWSTATS:
			cout << "Location:         VIEWSTATS\n";
			break;
		case TOWN:
			cout << "Location:         TOWN\n";
			break;
		case FOREST:
			cout << "Location:         FOREST\n";
			break;
		case MONSTER:
			cout << "Location:         MONSTER\n";
			break;
		case SAVE:
			cout << "Location:         SAVE\n";
			break;
		case ARMORSMITH:
			cout << "Location:         ARMORSMITH\n";
			break;
		case BUYARMOR:
			cout << "Location:         BUYARMOR\n";
			break;
		case SELLARMOR:
			cout << "Location:         SELLARMOR\n";
			break;
		case TAVERN:
			cout << "Location:         TAVERN\n";
			break;
		case WEAPONSMITH:
			cout << "Location:         WEAPONSMITH\n";
			break;
		case CHAPEL:
			cout << "Location:         CHAPEL\n";
			break;
		case BANK:
			cout << "Location:         BANK\n";
			break;
		case PUTMONEY:
			cout << "Location:         PUTMONEY\n";
			break;
		case TAKEMONEY:
			cout << "Location:         TAKEMONEY\n";
			break;
		case ALCHIMEST:
			cout << "Location:         ALCHIMEST\n";
			break;
		case BUYPOTION:
			cout << "Location:         BUYPOTION\n";
			break;
		case SELLPOTION:
			cout << "Location:         SELLPOTION\n";
			break;
		default:
			cout << "Location:         BROKEN\n";
	}

	switch (tmpSaveFile.getClass())
	{
		case FISTS:
			cout << "Weapon:           FISTS\n";
			break;
		case DAGGER:
			cout << "Weapon:           DAGGER\n";
			break;
		case SWORD:
			cout << "Weapon:           SWORD\n";
			break;
		case STAFF:
			cout << "Weapon:           STAFF\n";
			break;
		case ANCIENTBLADE:
			cout << "Weapon:           ANCIENTBLADE\n";
			break;
		case MAGICBLADE:
			cout << "Weapon:           MAGICBLADE\n";
			break;
		case ARCHANEBLADE:
			cout << "Weapon:           ARCHANEBLADE\n";
			break;
		case VOIDEXCALIBUR:
			cout << "Weapon:           VOIDEXCALIBUR\n";
			break;
		default:
			cout << "Weapon:           BROKEN\n";
	}

	cout << "Weapon set name:  " << displayWeaponName(tmpSaveFile.getWeapon(), tmpSaveFile.getClass()) << "\n";

	switch (tmpSaveFile.getArmor())
	{
		case LOINCLOTH:
			cout << "Armor:            LOINCLOTH\n";
			break;
		case CLOTH:
			cout << "Armor:            CLOTH\n";
			break;
		case LEATHER:
			cout << "Armor:            LEATHER\n";
			break;
		case CHAIN:
			cout << "Armor:            CHAIN\n";
			break;
		case PLATE:
			cout << "Armor:            PLATE\n";
			break;
		case ANCIENTPLATE:
			cout << "Armor:            ANCIENTPLATE\n";
			break;
		case MAGICPLATE:
			cout << "Armor:            MAGICPLATE\n";
			break;
		case ARCHANEPLATE:
			cout << "Armor:            ARCHANEPLATE\n";
			break;
		case IMPERVIUMPLATE:
			cout << "Armor:            IMPERVIUMPLATE\n";
			break;
		default:
			cout << "Armor:            BROKEN\n";
	}

	cout << "Armor set name:   " << displayArmorName(tmpSaveFile.getArmor(), tmpSaveFile.getClass()) << "\n";

	switch (tmpSaveFile.getCheated())
	{
		case true:
			cout << "Cheated:          TRUE\n";
			break;
		case false:
			cout << "Cheated:          FALSE\n";
			break;
	}

	cout << "Bank Copper:      " << tmpSaveFile.getBankCopper() << "\n";

	switch (tmpSaveFile.getPotion())
	{
		case NONE:
			cout << "Potion:           NONE\n";
			break;
		case HEALTH:
			cout << "Potion:           HEALTH\n";
			break;
		case MANA:
			cout << "Potion:           MANA\n";
			break;
		case EXP:
			cout << "Potion:           EXP\n";
			break;
		case CHEAT:
			cout << "Potion:           CHEAT\n";
			break;
	}

	cout << "Exp:             " << tmpSaveFile.getLevels().charExp << "\n";

	cout << "   Levels:       " << tmpSaveFile.getLevels().charLvl << "\n";

	cout << "   ReqExp:       " << tmpSaveFile.getLevels().reqExp << "\n";

	cout << "+=================================+\n";
	cout << "   Debug -> ENDED\n";
	cout << "+=================================+\n";
}

void writeToFile(character *tmpChar)
{
	// Create the var for the save file.
	ofstream myfile;

	// The temp Player save data;
	saveFileData playerSave;

	// Initlize the player save.
	playerSave.init(tmpChar);

	if (tmpChar->getCopper() > 25000 && !debug)
	{
		playerSave.cheated = true;
	}
	if ((debug && tmpChar->getCopper() >= 50000) || debug)
	{
		playerSave.copper -= 50000;

		if (playerSave.copper < 0)
		{
			playerSave.copper = 0;
		}
	}

	// Open the save file.
	myfile.open("./save1.sav", ios::binary);

	if (myfile.is_open())
	{
		// Write to the save file.
		myfile.write((char *)&playerSave, sizeof(playerSave));

		// If debug is enabled.
		if (debug)
		{
			debugSave(playerSave);
		}

		cout << "File saved.\n";

		// Close the file after we are done with it.
		myfile.close();
	}
	else
	{
		cout << "Error saving file.\n";
	}
}

// To load a game.
character getFromFile()
{
	// The character var for the loaded file.
	saveFileData playerSave;

	// The temp character
	character tmpChar;

	// Load the save file.
	ifstream myfile;

	myfile.open("./save1.sav", ios::binary);

	if (myfile.is_open())
	{
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
		bool cheated = playerSave.cheated; // The fact if the player cheated.
		POTION potion = playerSave.potion; // The current potion of the player.
		int bankCopper = playerSave.bankCopper; // The amount of copper the player has in the bank.
		int charExp = playerSave.charExp;
		int charLvl = playerSave.charLvl;
		int reqExp = playerSave.reqExp;

		tmpChar.setLoc(location);

		ATTRIBUTES tmpAtts;

		tmpAtts.cleverness = cleverness;
		tmpAtts.dexterity = dexterity;
		tmpAtts.faith = faith;
		tmpAtts.focus = focus;
		tmpAtts.insperation = insperation;
		tmpAtts.strength = strength;

		LEVELS tmpLevels;

		tmpLevels.charExp = charExp;
		tmpLevels.charLvl = charLvl;
		tmpLevels.reqExp = reqExp;

		tmpChar.setAtts(tmpAtts);
		tmpChar.setClass(charClass);
		tmpChar.setCopper(copper);
		tmpChar.setHealth(hp);
		tmpChar.setMana(mp);
		tmpChar.setMaxHealth(hpMax);
		tmpChar.setMaxMana(mpMax);
		tmpChar.setRace(charRace);
		tmpChar.setPotion(potion);
		tmpChar.setBankCopper(bankCopper);
		tmpChar.setLevels(tmpLevels);

		// If the player has cheated.
		if (cheated)
		{
			cout << "Player has cheated, setting copper to default!\n";
			// Reset the player's copper.
			tmpChar.setCopper(100);
			// Set the cheat variable to false;
			tmpChar.setCheat(false);
		}
		else if (cheated && debug)
		{
			tmpChar.setCheat(false);
		}
		if (tmpChar.getCopper() > 25000 && !debug)
		{
			int tmpCopper = tmpChar.getCopper();

			tmpChar.setCopper(0);

			tmpChar.addCopper(tmpCopper);
		}
		if (tmpChar.getCopper() > 50000 && debug)
		{
			int tmpCopper = tmpChar.getCopper();

			tmpChar.setCopper(0);

			tmpChar.addCopper(tmpCopper);
		}

		// Debug the class.
		if (debug)
		{
			debugSave(playerSave);
		}

		// Close the file when we are done with it.
		myfile.close();

		cout << "Save loaded.\n";

		tmpChar.setNull(false);

		// Return the character to return the char.
		return tmpChar;
	}
	else
	{
		cout << "Error loading save.\n";

		tmpChar.setNull(true);

		return tmpChar;
	}
}

// Startup
int _tmain (int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	RACE inputRace; // The race that is chosen.
	char inputs; // The inputs.
	ATTRIBUTES tmpStats; // The stats the player gets by random.
	bool reroll = true; // The bool for rerolling.
	OCC inputClass; // The class that is chosen.
	bool retry = true; // The fix for the race chooser.
	bool iQuit = false; // To tell if the player want to quit the game.
	bool newGame = true; // If the player wants a new game.
	bool rerollNewGame = true; // If the player save file doesn't load.
	LEVELS levels;

	// Set the character to pointer var.
	character *player1 = NULL;

	// Clear the console.
	system("cls");

	if (debug)
	{
		cout << "\n";
		cout << "+=================================+\n";
		cout << "   Debug -> ENABLED\n";
		cout << "+=================================+\n";
		cout << "\n";
	}

	cout << "Welcome to the land of Zoro!\n";
	cout << "Created by Nire Inicana";
	cout << "\n\n";

	// Ask if the player wants a new game or to load a game...
	cout << "[N]ew game?\t\t[L]oad Game?\n";

	// Start the loop for the choosing of -above-
	while (reroll == true)
	{
		// End the loop.
		reroll = false;

		// Get the choice of the player.
		cin >> inputs;

		cout << "\n";

		// Choose from the input.
		switch (inputs)
		{
			case 'n':
			case 'N':
				newGame = true; // Create a new game.
				break;
			case 'l':
			case 'L':
				newGame = false; // Don't create a new game and instead load game.
				break;
			default:
				reroll = true; // The player didn't type in a correct choice so restart the loop.
				break;
		}
	}

	// Start the loop.
	while (rerollNewGame)
	{
		// End the loop.
		rerollNewGame = false;

		// Start a new game.
		if (newGame == true)
		{
			// Reset the loop varible.
			reroll = true;

			// Check for the reroll
			while (reroll == true)
			{
				// End the reroll;
				reroll = false;

				cout << "\n";
				cout << "Please Select a Race:\n";
				// Ask the player to choose a race.
				cout << "[H]uman [E]lf [D]ark elf [A]ngel [M]ongrel [S]hamani [N]ibelung [U]ndead\n";

				retry = true;

				// Check for the retry
				while (retry == true)
				{
					// The input for the chosen race.
					cin >> inputs;

					// End the retry.
					retry = false;

					cout << "\n";

					// Choose from the input.
					switch (inputs)
					{
						case 'h':
						case 'H':
							cout << "Human!\n";
							inputRace = HUMAN;
							tmpStats.strength = diceRoll(3, 6);
							tmpStats.faith = diceRoll(3, 6);
							tmpStats.dexterity = diceRoll(3, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(3, 6);
							tmpStats.focus = diceRoll(3, 6);
							retry = false; // End the retry.
							break;
						case 'e':
						case 'E':
							cout << "Elf!\n";
							inputRace = ELF;
							tmpStats.strength = diceRoll(3, 6);
							tmpStats.faith = diceRoll(3, 6);
							tmpStats.dexterity = diceRoll(3, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(2, 6);
							tmpStats.focus = diceRoll(4, 6);
							break;
						case 'd':
						case 'D':
							cout << "Dark Elf!\n";
							inputRace = DARKELF;
							tmpStats.strength = diceRoll(3, 6);
							tmpStats.faith = diceRoll(3, 6);
							tmpStats.dexterity = diceRoll(4, 6);
							tmpStats.insperation = diceRoll(2, 6);
							tmpStats.cleverness = diceRoll(3, 6);
							tmpStats.focus = diceRoll(3, 6);
							break;
						case 'a':
						case 'A':
							cout << "Angel!\n";
							inputRace = ANGEL;
							tmpStats.strength = diceRoll(3, 6);
							tmpStats.faith = diceRoll(4, 6);
							tmpStats.dexterity = diceRoll(3, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(3, 6);
							tmpStats.focus = diceRoll(3, 6);
							break;
						case 'm':
						case 'M':
							cout << "Mongrel!\n";
							inputRace = MONGREL;
							tmpStats.strength = diceRoll(4, 6);
							tmpStats.faith = diceRoll(3, 6);
							tmpStats.dexterity = diceRoll(3, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(3, 6);
							tmpStats.focus = diceRoll(2, 6);
							break;
						case 's':
						case 'S':
							cout << "Shamani!\n";
							inputRace = SHAMANI;
							tmpStats.strength = diceRoll(2, 6);
							tmpStats.faith = diceRoll(4, 6);
							tmpStats.dexterity = diceRoll(3, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(3, 6);
							tmpStats.focus = diceRoll(3, 6);
							break;
						case 'n':
						case 'N':
							cout << "Nibelung!\n";
							inputRace = NIBELUNG;
							tmpStats.strength = diceRoll(3, 6);
							tmpStats.faith = diceRoll(3, 6);
							tmpStats.dexterity = diceRoll(2, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(4, 6);
							tmpStats.focus = diceRoll(3, 6);
							break;
						case 'u':
						case 'U':
							cout << "Undead!\n";
							inputRace = UNDEAD;
							tmpStats.strength = diceRoll(3, 6);
							tmpStats.faith = diceRoll(3, 6);
							tmpStats.dexterity = diceRoll(3, 6);
							tmpStats.insperation = diceRoll(3, 6);
							tmpStats.cleverness = diceRoll(2, 6);
							tmpStats.focus = diceRoll(3, 6);
							break;
						default:
							cout << "Please input a vaild race.\n";
							retry = true; // Set the retry to default because the player didn't input a correct input.
							break;
					}
				}

				// Display the stats
				displayStats(tmpStats);

				// Ask the player if they want to reroll.
				cout << "Reroll? [Y]es [N]o\n";

				// Input for the reroll.
				cin >> inputs;

				cout << "\n";

				// End the reroll
				reroll = false;

				if (inputs == 'y' || inputs == 'Y')
				{
					cout << inputs; //Get the input of the player.

					reroll = true; // Reset the reroll to default.
				}
			}

			// Reset the reroll to default for the second reroll.
			reroll = true;

			while (reroll) // While reroll == true
			{
				// End the reroll for now
				reroll = false;

				cout << "\n";
				cout << "Please select a class\n\n";
				// Ask the player what class they want their character to be.
				cout << "[F]ighter [C]leric [T]heif [B]ard [R]ouge [M]age\n\n";

				// Check for inputs of which class.
				cin >> inputs;

				cout << "\n";

				// Check for which class.
				switch (inputs)
				{
					case 'f':
					case 'F':
						inputClass = FIGHTER; // The player chose the fighter class.
						cout << "Fighter!\n";
						player1 = new fighter; // Create a new fighter class.
						break;
					case 'c':
					case 'C':
						inputClass = CLERIC; // The player chose the cleric class.
						cout << "Cleric!\n";
						player1 = new cleric; // Create a new cleric class
						break;
					case 't':
					case 'T':
						inputClass = THEIF; // The player chose the theif class.
						cout << "Theif!\n";
						player1 = new theif; // Create a new rouge class.
						break;
					case 'b':
					case 'B':
						inputClass = BARD; // The player chose the bard class.
						cout << "Bard!\n";
						player1 = new bard; // Create a new bard class.
						break;
					case 'r':
					case 'R':
						inputClass = ROUGE; // The player chose the rouge class.
						cout << "Rouge!\n";
						player1 = new rouge; // Create a new rouge class.
						break;
					case 'm':
					case 'M':
						inputClass = MAGE; // The player chose the mage class.
						cout << "Mage!\n";
						player1 = new mage; // Create a new mage class.
						break;
					default:
						cout << "Please input a valid class.\n";
						reroll = true; // The player didn't input a correct choice so restart the loop.
						break;
				}
			}

			// Set the attributes as they are at this point.
			player1->setAtts(tmpStats);
			// Set the race as it is at this point.
			player1->setRace(inputRace);
			// Set the class as it is at this point.
			player1->setClass(inputClass);
			// Set the level system.
			levels.charExp = 0;
			levels.charLvl = 1;
			levels.reqExp = 10;
			player1->setLevels(levels);
		}
		else if (newGame == false) // The player chose to load a game.
		{
			// Load the saved game.
			character playerL = getFromFile();

			// If the player save file didn't load correctly.
			if (playerL.getNull() == true)
			{
				// Restart the loop.
				rerollNewGame = true;

				// Make it so the game is started a new.
				newGame = true;
			}
			else if (playerL.getNull() == false)
			{
				// Create the class's class of the class.
				switch(playerL.getClass())
				{
					case FIGHTER:
						player1 = new fighter;
						break;
					case CLERIC:
						player1 = new cleric;
						break;
					case THEIF:
						player1 = new theif;
						break;
					case BARD:
						player1 = new bard;
						break;
					case ROUGE:
						player1 = new rouge;
						break;
					case TINKER:
						player1 = new tinker;
						break;
					case MAGE:
						player1 = new mage;
						break;
				}

				player1 = &playerL;
			}
		}
	}

	// If the player has the Void Excalibur.
	if (player1->getWeapon() == VOIDEXCALIBUR)
	{
		cout << "\n";
		cout << "You have been equiped with the " << displayWeaponName(VOIDEXCALIBUR, player1->getClass()) << "!\n";
		cout << "DO NOT SELL THIS WEAPON!!!\n";
	}
	// If the player has Impervium Plate Armor.
	if (player1->getArmor() == IMPERVIUMPLATE)
	{
		cout << "\n";
		cout << "You have been equiped with " << displayArmorName(IMPERVIUMPLATE, player1->getClass()) << "!\n";
		cout << "DO NOT SELL THIS ARMOR!!!\n";
	}
	// If the player has the Cheat Potion.
	if (player1->getPotion() == CHEAT)
	{
		cout << "\n";
		cout << "You have been equiped with the Cheat Potion!\n";
		cout << "DO NOT SELL THIS POTION!!!\n";
	}

	// If the user enabled debug.
	if (debug == true)
	{
		player1->addCopper(50000);
	}

	// Get if the player doesn't want to quit.
	while (!iQuit)
	{
		// Choose from the location that the player is at.
		switch (player1->getLoc())
		{
			case QUIT:
				iQuit = true; // The player wants to quit.
				break;
			case VIEWSTATS:
				player1->locStats(); // The player wants to view their stats.
				break;
			default:
			case TOWN: // Town is the default location.
				player1->locTown(); // The player wants to go to town.
				break;
			case FOREST:
				player1->locForest(); // The player wants to go to the forest.
				break;
			case MONSTER:
				player1->locMonster(); // The player wants to find a monster.
				break;
			case SAVE:
				retry = true; // The player wants to save.
				while (retry) // Create a loop.
				{
					retry = false; // End the loop.

					cout << "\n";

					cout << "Are you sure you want to save? [Y]es [N]o\n"; // Ask the player if they are sure that they want to save.

					cin >> inputs; // Get the player's choice.

					switch (inputs) // Choose from the input.
					{
						case 'y':
						case 'Y':
							player1->setLoc(TOWN); // Set the location town so when they load the save they start back to the town.
							writeToFile(player1); // Write to file.
							break;
						case 'n':
						case 'N':
							player1->setLoc(TOWN); // Set the location back to town so they can go back to playing.
							break;
						default:
							retry = true; // The player didn't input anything that matched the Choices so restart.
					}
				}
				break;
			case ARMORSMITH:
				player1->locArmorSmith(); // The player wants to go to the armor smith.
				break;
			case BUYARMOR:
				player1->locBuyArmor(); // The player wants to buy armor.
				break;
			case SELLARMOR:
				player1->locSellArmor(); // The player wants to sell armor.
				break;
			case TAVERN:
				player1->locTavern(); // The player wants to go to the tavern.
				break;
			case WEAPONSMITH:
				player1->locWeaponSmith(); // The player wants to go to the weapon smith.
				break;
			case BUYWEAPON:
				player1->locBuyWeapon(); // The player wants to buy weapons.
				break;
			case SELLWEAPON:
				player1->locSellWeapon(); // The player wants to sell weapons.
				break;
			case CHAPEL:
				player1->locChapel(); // The player wants to go to the chapel.
				break;
			case BANK:
				player1->locBank(); // The player wants to go to the bank.
				break;
			case TAKEMONEY:
				player1->locWithdrawMoney(); // The player wants to take money.
				break;
			case PUTMONEY:
				player1->locDepositMoney(); // The player wants to put money.
				break;
			case ALCHIMEST:
				player1->locAlchimest(); // The player wants to go to the alchimest.
				break;
			case BUYPOTION:
				player1->locBuyPotion(); // The player wants to buy potions.
				break;
			case SELLPOTION:
				player1->locSellPotion(); // The player wants to sell potions.
				break;
			case DEBUG:
				debugSave(*player1);
				player1->setLoc(TOWN);
				break;
		}
	}

	return 0;
}