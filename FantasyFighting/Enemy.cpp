/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#include "Enemy.h"
#include <iostream>

using namespace std;

//Text for when the enemy dies
void Enemy::deadText()
{
	cout << "You have defeated the enemy, for now...";
}

//return enemy name for game class
string Enemy::getEnemyName()
{
	return enemyName;
}
