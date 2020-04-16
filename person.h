//
// Created by Arias Arevalo, Carlos on 4/15/20.
//

#ifndef PERSON_H
#define PERSON_H

#include "date.h"

#include <string>
using std::string;

class Person {
	string _name;
	Date _birthDay;
public:
	Person();
	Person(const string& name);
	Person(const string& name, const Date& birthDay);
	Person(const string& name, size_t year, size_t month, size_t day);
	string ToString()const;
	string GetName()const;
	Date GetBirthDay()const;
	size_t GetAge()const;
};


#endif //INHERITANCE_EXAMPLE_2_PERSON_H
