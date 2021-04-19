/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#include "Weapon.h"

//Constructor allows for the weapon the have an original start damage
Weapon::Weapon(int inputedDamage)
{
	this->attackDamage = this->defaultAttackDamage + inputedDamage;
}

//Function for setting damage after upgrading of the weapon
void Weapon::weaponUpgrade(int upgrade)
{
	this->attackDamage = this->attackDamage + upgrade;
}

//Function to return the attack damage
int Weapon::getAttackDamage()
{
	return attackDamage;
}

