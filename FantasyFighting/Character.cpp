/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#include "Character.h"
#include <iostream>

using namespace std;

//Check to see if character is dead
bool Character::isDead()
{
	if (health <= 0) {
		//Show the characters deadText whether they are an enemy or hero
		this->deadText();
		return true;
	}
	else
		return false;	
}

//Function to help set health in game constructor
void Character::setHealth(int h)
{
	health = h;
}

//Get the health of the current characters
int Character::getHealth()
{
	return this->health;
}

//Function to set health back to its original state
void Character::resetHealth()
{
	this->health = 10;
}
