/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#include "Hero.h"
#include <iostream>
using namespace std;

//Allow the hero to set a name for themselves
void Hero::setName(string input)
{
	cin >> input;
	heroName = input;
}

//Return the created name
string Hero::getName()
{
	return heroName;
}

//Collect gold for the hero so he can buy items in the shop
int Hero::collectGold()
{
	if (this->isDead() == false) {
		srand(time(NULL));
		collectingGold = rand() % 15;
		cout <<"\n"<< this->getName() << " has collected " << collectingGold << " gold off of his slain foe\n";
		totalGold = totalGold + collectingGold;
		return totalGold;
	}
}

void Hero::setGold(int g)
{
	totalGold = g;
}

int Hero::getTotalGold()
{
	return totalGold;
}

//Function to let user see there stats
void Hero::displayStats(int waves, Armor& armor, Weapon& weapon)
{
	cout << "Your character's name is: " << this->getName()<<endl;
	cout << "You have this much gold under your name: " << this->totalGold << " gold" <<endl;
	cout << "You have beaten this many round(s): " << waves - 1 << " round(s)" << endl;
	cout << "Your weapon does this much damage: " << weapon.getAttackDamage() << " attack damage." << endl;
	cout << "Your armor provides this much defense: " << armor.getArmorDefense() - 10 << " defense points" << endl;
}

//Function to let save function in game be able to put the name into the .in file
void Hero::setLoadedName(std::string loadedName)
{
	heroName = loadedName;
}

//Polymorphic function which shows a text after the hero dies and then exits the game
void Hero::deadText()
{
	cout << this->getName() <<" has been slain and the village of Wes Gagorian has fallen...";
	exit(0);
}
