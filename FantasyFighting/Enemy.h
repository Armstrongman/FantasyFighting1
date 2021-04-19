/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#pragma once
#include "Character.h"
#include <string>
//The Enemy class inherits the character class' functions
class Enemy : public Character
{
private:
	std::string enemyName = "Skeleton";
public:
	virtual void deadText();
	std::string getEnemyName();
};

