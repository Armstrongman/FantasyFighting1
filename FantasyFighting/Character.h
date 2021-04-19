/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#pragma once
#include "Weapon.h"
#include "Armor.h"
class Character
{
private:
	int health = 10;
	int upgradedHealth = 0;
	int temporaryHealth = 0;
	int damageBoost = 0;
	int attackValue = 0;
	int defenseValue = 0;
public:
	bool isDead();
	void setHealth(int h);
	int getHealth();
	void resetHealth();
	//Sets up for polymorphism
	virtual void deadText() = 0;
};

