/*
 * Title:		Warrior Class Method Definition
 * Purpose:		Implementation of all Warrior class methods
 * Description:	The Warrior Class is derived from Person, additionally it
 * 				will have data members _attackDamage, _hitPoints, _shield.
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */

#include "warrior.h"
#include "person.h"
#include "date.h"

#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::stringstream;

#include <iostream>
using std::cerr;
using std::endl;

/**
 * Warrior Constructor
 * This method initializes all data members of the class, and it's parent class. By default
 * a warrior has attack damage, shield and hit points set to 100. The user can decide to change
 * this default values by sending new values to this constructor.
 * @param name name of the warrior
 * @param birthday birthday of the warrior
 * @param attackDamage the maximum attack damage this warrior can inflict
 * @param shield the initial shield value, this will protect the hit points until it runs out
 * @param hitPoints the life of the warrior, once it becomes zero the warrior is dead
 */
Warrior::Warrior(const string &name, const Date &birthday, size_t attackDamage, size_t shield, size_t hitPoints)
	:Person(name, birthday), _attackDamage(attackDamage), _shield(shield), _hitPoints(hitPoints){

}
/**
 * Attack of the Warrior
 * This method returns the attack value of the warrior. The value is calculated by the throw
 * of a six face die. The value of the attack is equal to the number of the die divided by 6
 * multiplied by the attack damage set of the warrior. The minimum attack of a warrior is 1/6
 * of its attack damage.
 * @return the amount of attack calculated
 */
size_t Warrior::Attack() const {
	int die = rand() % 6 + 1;
	size_t attack = static_cast<size_t>(_attackDamage * die / 6.0);
	return attack;
}
/**
 * Defense of a Warrior
 * This method represents the warrior receiving damage. The parameter represents how
 * much attack damage is being received. The attack damage will first affect the shield
 * once the warrior runs out of shield, it will start affecting the hit points. Once the
 * warrior runs out of hit points the warrior dies.
 * @param attack the amount of attack received.
 * @return the available hit points for this warrior
 */
size_t Warrior::Defend(size_t attack) {
	if (_shield > 0){
		if (_shield > attack){
			_shield -= attack;
			return _hitPoints;
		}else{
			attack -= _shield;
			_shield = 0;
			_hitPoints -= attack;
			return _hitPoints;
		}
	}else if (_hitPoints >= attack){
		_hitPoints -= attack;
		return _hitPoints;
	} else{
		_hitPoints = 0;
		return 0;
	}

}
/**
 * Is Alive
 * Method to determine if the warrior is still alive.
 * @return true if the warrior still has hit points, false otherwise.
 */
bool Warrior::IsAlive() const {
	return _hitPoints != 0;
}
/**
 * To String
 * Creates a string representation of the warrior. This representations is composed
 * by the name of the warrior with its characteristics: hit points, shield and attack damage
 * @return a string representing the warrior
 */
string Warrior::ToString() const {
	stringstream ss;
	ss << "Name: " << GetName() << ", Hit Points: " << _hitPoints
		<< ", Shield: " << _shield << ", Attack: " << _attackDamage;
	return ss.str();
}
