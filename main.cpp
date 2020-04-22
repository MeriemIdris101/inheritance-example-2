#include "date.h"
#include "person.h"
#include "employee.h"
#include "warrior.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
	srand(time(nullptr)); // This line is VERY needed for warrior to work well

	vector<Person> list;
	list.push_back(Person());
	list.push_back(Person("John"));
	list.push_back(Person("Peter", 2000, 01, 01));
	list.push_back(Employee("Manny", Date(1995, 02, 22), 3000));

	for (Person p : list)
		cout << p.ToString() << endl;

	for (size_t i = 0; i < list.size(); i++)
		cout << list[i].ToString() << endl;

	return 0;
}
