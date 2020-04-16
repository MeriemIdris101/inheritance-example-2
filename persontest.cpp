#include "person.h"
#include "date.h"

#include <iostream>
#include <cassert>
#include <ctime>
using std::cout;
using std::endl;


int main(int argc, char* argv[]){
	// Calculate current time
	time_t now = time(NULL);
	tm *timeinfo = localtime(&now);
	size_t year = 1900 + static_cast<size_t>(timeinfo->tm_year);
	size_t month = 1 + static_cast<size_t>(timeinfo->tm_mon);
	size_t day = static_cast<size_t>(timeinfo->tm_mday);
	Date today(year, month, day);

	Person p;
	assert(p.GetName() == "anonymous");
	cout << "Default name							Passed" << endl;
	Date pBirthDay = p.GetBirthDay();
	assert(pBirthDay.GetYear() == today.GetYear());
	assert(pBirthDay.GetMonth() == today.GetMonth());
	assert(pBirthDay.GetDay() == today.GetDay());
	cout << "Default birthday						Passed" << endl;
	assert(p.GetAge() == 0);
	cout << "Default birthday age					Passed" << endl;


	Person q("Charlie");
	assert(q.GetName() == "Charlie");
	cout << "Constructor with name					Passed" << endl;
	pBirthDay = q.GetBirthDay();
	assert(pBirthDay.GetYear() == today.GetYear());
	assert(pBirthDay.GetMonth() == today.GetMonth());
	assert(pBirthDay.GetDay() == today.GetDay());
	cout << "Default birthday						Passed" << endl;
	assert(q.GetAge() == 0);
	cout << "Default birthday age					Passed" << endl;

	Person r("Juan", 1963, 4, 9);
	assert(r.GetName() == "Juan");
	cout << "Constructor with name and birthday		Passed" << endl;
	pBirthDay = r.GetBirthDay();
	assert(pBirthDay.GetYear() == 1963);
	assert(pBirthDay.GetMonth() == 4);
	assert(pBirthDay.GetDay() == 9);
	cout << "Default birthday						Passed" << endl;
	assert(r.GetAge() == 57);
	cout << "Person age								Passed" << endl;
	assert(r.ToString() == "Name: Juan, Birthday: Tue Apr  9 1963");
	cout << "Person ToString						Passed" << endl;
	cout << "All Unit Tests Passed --------------" << endl << endl;

	return 0;
}
