/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#pragma once
#include <string>
class Armor
{
private:
	int defaultDefense = 10;
	int defense = 0;
	int inputArmor = 0;
public:
	Armor(int protection);
	void setDefense(int inputed);
	int inputedArmor();
	int getArmorDefense();
};

