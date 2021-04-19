/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#pragma once
#include "Armor.h"
#include "Weapon.h"
#include "Hero.h"
#include "Enemy.h"
#include <fstream>
#include <iostream>

class Game
{
private:
	//Characters in the game
	Hero hero;
	Enemy enemy;
	//Weapons in the game, this is also object composition meaning that the game has these objects
	Weapon* heroWeapon;
	Weapon* enemyWeapon;
	//Armor in the game this is also object composition meaning that the game has these objects
	Armor* heroArmor;
	Armor* enemyArmor;
	//Game variables
	int waves = 1;
public:
	//Constructor to play game
	Game();
	void save(int waves);
	void shopping(Armor& heroArmor, Weapon& heroWeapon);
	void nighttime(int waves);
	void weaponAttributes();
	void armorAttributes();
	int load(int waves);
};

