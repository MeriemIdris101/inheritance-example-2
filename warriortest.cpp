#include "person.h"
#include "warrior.h"
#include "date.h"

#include <iostream>
#include <cassert>
#include <ctime>
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
	Warrior w("Alexander", Date::Now());
	assert(w.GetName() == "Alexander");
	cout << "Warrior Name						Passed" << endl;
	assert(w.IsAlive() == true);
	cout << "IsAlive							Passed" << endl;
	size_t attack;
	for (int i = 0; i < 10; ++i) {
		attack = w.Attack();
		assert(attack >= 100 / 6.0 && attack <= 100);
		cout << "Attack								Passed" << endl;
	}
	assert(w.ToString() == "Name: Alexander, Hit Points: 100, Shield: 100, Attack: 100");
	cout << "ToString								Passed" << endl;
	attack = 15;
	for (int i = 0; i < 6; ++i) {
		assert(w.Defend(attack) == 100);
		cout << "Defend								Passed" << endl;
	}
	assert(w.Defend(attack) == 95);
	cout << "Defend								Passed" << endl;
	attack = 50;
	assert(w.Defend(attack) == 45);
	cout << "Defend								Passed" << endl;
	assert(w.Defend(attack) == 0);
	cout << "Defend								Passed" << endl;
	assert(w.IsAlive() == false);
	cout << "IsAlive							Passed" << endl;
	return 0;
}