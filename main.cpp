#include "date.h"
#include "person.h"
#include "employee.h"
#include "warrior.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main() {
	srand(time(NULL)); // This line is VERY needed for warrior to work well

    std::vector<Person*> list;
    list.push_back(new Person());
    list.push_back(new Person("John"));
    list.push_back(new Person("Peter", 2000, 01, 01));
    list.push_back(new Employee("Manny", Date(1995, 02, 22), 3000));


    for(Person* p : list)
        cout << p->ToString() << endl;

    for(size_t i = 0; i < list.size(); i++)
        cout << list[i]->ToString() << endl;

    return 0;
}





    /*Person person("Wilson", Date(1999, 4, 17));
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
	cout << "Finished" << endl;*/
	//return 0;
//}
