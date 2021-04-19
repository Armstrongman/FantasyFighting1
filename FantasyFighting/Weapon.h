/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#pragma once
class Weapon
{
private:
	int defaultAttackDamage = 2;
	int attackDamage = 0;
	int beforeUpgradeDamage = 0;
public:
	Weapon(int attackDamage);
	void weaponUpgrade(int upgrade);
	int getAttackDamage();
};