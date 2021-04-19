/*Cody Armstrong
* 4-17-21
* All this is my own work.
*/

#include "Game.h"
#include <iostream>

using namespace std;

void Game::weaponAttributes()
{
	//Original hero weapon
	heroWeapon = new Weapon(4);
	//Enemy Weapon
	enemyWeapon = new Weapon(2);
}

void Game::armorAttributes()
{
	//Original hero armor
	heroArmor = new Armor(3);
	//Enemy Armor
	enemyArmor = new Armor(1);
}

Game::Game()
{
	//Load OG Attributes of weapons into the game, whether the user loads a save or starts a new game
	armorAttributes();
	weaponAttributes();
	//See if user wants to load a save or not
	load(waves);
	char inputedCharacter = ' ';
	while (hero.isDead() == false) {
		//Save game
		save(waves);
		//Show the Character his stat sheet
		hero.displayStats(waves, *heroArmor, *heroWeapon);
		//Allow character to shop for upgrades
		shopping(*heroArmor, *heroWeapon);
		hero.displayStats(waves, *heroArmor, *heroWeapon);
		//Nighttime/Arena to fight
		nighttime(waves);
		//Plus the wave amount user is currently on
		waves++;
		cout << "\nYou have completed this many waves: " << waves << endl;
		
	}
}

//Function where you can shop for armor and weapon upgrades/buffs
void Game::shopping(Armor& heroArmor, Weapon& heroWeapon)
{
	char input = ' ';
	cout << "\nDo you want to buy anything from the shop? (Press y to browse) Or you can advance to the night by pressing any other character!"<<endl;
	cout << "(You can also exit the game by pressing e) ";
	cin >> input;
	//Check if the user want to exit the game
	if (input == 'e' || input == 'E') {
		cout << "You have quit the game and your stats have been saved " << hero.getName() << "!\n";
		save(waves);
		exit(0);
	}
	//Check if the user wants to shop
	if (input == 'y' || input == 'Y') {
		cout << "What would you like to buy boyo? We have a variety of different things you can purchase.\n";
		cout<<"You can buff either the weapon you yield (by pressing w) or the armor you wear (by pressing a) or even both if you want.\n"; 
		cout<<"Or you can leave if you're done browsing (by pressing l)";		
	do {
		cin >> input;
			//While shopping, If the user doesn't input any of the allowed chars, ask them to try the input again to include a correct char
			while (input != 'w' && input != 'W' && input != 'a' && input != 'A' && input != 'l' && input != 'L') {
				cout << "Please attempt to input a correct character ";
				cin >> input;
			}
			//Check if they want to buy a weapon upgrade
			if (input == 'w' || input == 'W') {
				//If user doesn't have enough money, don't give them the upgrade
				if (hero.getTotalGold() < 10) {
					cout << "Sorry, but you do not have enough gold to afford this... See if you can afford something else. ";
					cin >> input;
				}
				else if (hero.getTotalGold() >= 10) {
					//If the user has the exact amount of money or more, allow them to get the weapon upgrade
					heroWeapon.weaponUpgrade(heroWeapon.getAttackDamage() - 6 + 3);
						hero.setGold(hero.getTotalGold() - 10);
						cout << "Thanks for shopping with us. Do you wanna buy anyone else? ";
				}
			}
			//Check if they want to buy an armor upgrade
			 else if (input == 'a' || input == 'A') {
				//If user doesn't have enough money, don't give them the upgrade
				if (hero.getTotalGold() < 20) {
					cout << "Sorry, but you do not have enough gold to afford this... See if you can afford something else. ";
					cin >> input;
				}
				else if (hero.getTotalGold() >= 20) {
					//If the user has the exact amount of money or more, allow them to get the armor upgrade
					heroArmor.setDefense(heroArmor.getArmorDefense() - 13 + 3);
					hero.setGold(hero.getTotalGold() - 20);
					cout << "Thanks for shopping with us. Do you wanna buy anyone else? ";
				}
			}
			//Let user leave the shop after there done and show their gold
		}while (input != 'l' && input != 'L');
		cout << "After your shopping venture you have " << hero.getTotalGold() << " total Gold in your pockets\n";
	}
}

void Game::nighttime(int waves)
{
	//Set Enemy and Hero by getting the health and +ing it by the armor amount
	enemy.setHealth(enemy.getHealth() + enemyArmor->getArmorDefense());
	hero.setHealth(hero.getHealth() + heroArmor->getArmorDefense());
	for (int i = 0; i < waves; i++) {
		
		//Show user the health before each initial attack
		cout << "\nInitial enemy Health ammount: " << enemy.getHealth() << endl;
		cout << "Initial Hero Health ammount: " << hero.getHealth() << endl;
		while (hero.isDead() == false && enemy.isDead() == false)
		{
			int input = 0;
			cout << "\nPress 1 to attack: ";
			cin >> input;
			while (input != 1) {
				cout << "Please type in 1 to attack. ";
				cin >> input;
			}
			//Hero attacks enemy by setting the enemy's health to its health minus the damage the hero's sword gives
			enemy.setHealth(enemy.getHealth() - heroWeapon->getAttackDamage());
			cout << "The hero did this much damage to the " << enemy.getEnemyName() << ": " << heroWeapon->getAttackDamage();
			cout << "\nThe " << enemy.getEnemyName() << " has this much health: " << enemy.getHealth();
			//Enemy attacks hero by setting the hero's health to its health minus the damage the enemys's sword gives
			hero.setHealth(hero.getHealth() - enemyWeapon->getAttackDamage());
			cout << "\nThe " << enemy.getEnemyName() << " did this much damage to the hero: " << enemyWeapon->getAttackDamage();
			cout << "\nThe Hero has this much health: " << hero.getHealth() << endl << endl;
		}
		//This is for rounds 2 and up when there are multiple enemies so that it can reset the health for the next enemy 
		enemy.setHealth(10 + enemyArmor->getArmorDefense());
		//Collect gold for hero after defeating enemy
		hero.collectGold();
	}
	//Reset both characters health to prepare for the next round/wave
	enemy.resetHealth();
	hero.resetHealth();
}

void Game::save(int waves) {
	//Open file to input 
	ifstream input;
	input.open("File.in");

	//Make variables set to correlated items within game so it can evetually be outputted to the file
	string heroName = hero.getName();
	int waveAmount = waves;
	int armorBonus = heroArmor->inputedArmor();
	int weaponBonus = heroWeapon->getAttackDamage();
	int goldAmount = hero.getTotalGold();

	//Close input file
	input.close();

	//Open fill to output
	ofstream output;
	output.open("File.in", ios::trunc);

	//make sure fin is initialized to the file
	if (!output) {
		cerr << "File not found" << endl;
		exit(1);
	}

	//Outputting variables into to the file after they have been set
	output << heroName << " " << waveAmount << " " << armorBonus << " " << weaponBonus << " " << goldAmount << "\n";

	//Close the file and then tell the user that their stats have been successfully saved
	output.close();
	cout << "Your stats have been saved good sir, or madam." << endl << endl;
}

//Function to load the game for the player, if they want to
int Game::load(int waves) {
	//Open file
	ifstream file("File.in");
	if (!file) {
		cerr << "File not found" << endl;
		exit(1);
	}

	//Set variable names to the variables in the file to be pulled out
	string heroName;
	int waveAmount, armorBonus, weaponBonus, goldAmount;
	char input = ' ';

	while (file >> heroName >> waveAmount >> armorBonus >> weaponBonus >> goldAmount) {
		cout << "Want to load you last previous save or start a new game? If so type in either y or Y.\n";
		cout << "Any other input will make a new game. ";
		cin >> input;
		if (input == 'y' || input == 'Y') {
			cout << "You have officially loaded you previous character whose name is " << heroName << endl << endl;
			//Set variables from the game to the variables pulled from the file respectively
			hero.setLoadedName(heroName);
			//Can't get wave to change value for some weird reason
			waves = waveAmount;
			heroArmor->setDefense(armorBonus);
			heroWeapon->weaponUpgrade(weaponBonus - 6);
			hero.setGold(goldAmount);
			//Close the file
			file.close();
		}
		else {
			//If the user doesn't load the save start a new game
			cout << "Set your new hero's name: ";
			string newName;
			hero.setName(newName);
		}
	}
	return waves;
}