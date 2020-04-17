#include "date.h"
#include "person.h"
#include "employee.h"
#include "warrior.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(NULL)); // This line is VERY needed for warrior to work well
	Person person("Wilson", Date(1999, 4, 17));
	cout << "Person:       " << person.ToString() << endl;
	cout << "Person age:   " << person.GetAge() << endl;

	Employee employee("Ellie", Date(1996, 2, 11), 2500);
	cout << "Employee:     " << employee.ToString() << endl;
	cout << "Giving a Raise of 15%" << endl;
	employee.Raise(0.15);
	cout << "Salary:       " << employee.GetSalary() << endl;
	cout << "Employee age: " << employee.GetAge() << endl;

	Warrior warrior("Genghis", Date(1162, 8, 12), 500, 500);
	cout << "Warrior:       " << warrior.ToString() << endl;
	cout << "Alive?         " << (warrior.IsAlive() ? "Yes" : "No") << endl;
	cout << "Let\'s attack five times" << endl;
	for (int i = 0; i < 5; ++i) {
		size_t attack = warrior.Attack();
		cout << "Attack " << (i + 1) << ": " << attack << endl;
	}
	cout << "Let's defend some random Attacks" << endl;
	while (warrior.IsAlive()){
		size_t attack = rand() % 100 ;
		cout << "Attack: " << attack << " Hit Points left: " << warrior.Defend(attack) << endl;
	}
	cout << "Alive?         " << (warrior.IsAlive() ? "Yes" : "No") << endl;
	cout << "Finished" << endl;
	return 0;
}
