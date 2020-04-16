/*
 * Title:		Warrior Class Declaration
 * Purpose:		A Class to represent a simple Warrior with three attributes:
 * 				Attack Damage, how much attack the warrior can inflict in battle
 * 				Shield, how much shield the warrior has
 * 				Hit Points, how much "life" the warrior has
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */
#ifndef INHERITANCE_EXAMPLE_2_WARRIOR_H
#define INHERITANCE_EXAMPLE_2_WARRIOR_H

#include "person.h"

#include <string>
using std::string;

class Warrior : public Person{
	size_t _attackDamage;
	size_t _shield;
	size_t _hitPoints;
public:
	Warrior(const string& name, const Date& birthday, size_t attackDamage = 100, size_t shield = 100, size_t
	hitPoints = 100);

	size_t Attack()const;
	size_t Defend(size_t attack);
	bool IsAlive()const;
	string ToString()const;
};


#endif //INHERITANCE_EXAMPLE_2_WARRIOR_H
