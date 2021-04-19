/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#pragma once
#include "Character.h"
#include <string>
#include "Enemy.h"
#include "Weapon.h"
#include "Armor.h"
//The Hero class inherits the character class' functions
class Hero : public Character
{
private:
	std::string heroName;
	Enemy enemy;
	int collectingGold = 0;
	int totalGold = 20;
public:
	void setName(std::string heroName);
	std::string getName();
	int collectGold();
	void setGold(int g);
	int getTotalGold();
	void displayStats(int waves, Armor& armor, Weapon& weapon);
	void setLoadedName(std::string loadedName);
	virtual void deadText();

};

