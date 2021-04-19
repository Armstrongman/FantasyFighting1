/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#include "Armor.h"

using namespace std;

//Constructor to set original armor protection
Armor::Armor(int protection)
{
	 this->defense = protection + defaultDefense;
}

//Function to help set the defense/total armor protection
void Armor::setDefense(int inputed)
{
	this->defense = this->defense + inputed;
	inputArmor = inputed;
}

//Function to help save in the gameClass
int Armor::inputedArmor()
{
	return inputArmor;
}

//Function to return the total amount of armor protection
int Armor::getArmorDefense()
{
	return defense;
}
