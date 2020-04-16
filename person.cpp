/*
 * Title:		Person Class Method Definition
 * Purpose:		Implementation of all Person class methods
 * Description:	The Person Class is going to represent a person with two data members
 * 				name and birthday.
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */

#include "person.h"
#include "date.h"

#include <iostream>
#include <string>
#include <sstream>
using std::istream;
using std::ostream;
using std::string;
using std::stringstream;

Person::Person(): _name("anonymous"), _birthDay(Date::Now()) {

}

Person::Person(const string &name): _name(name), _birthDay(Date::Now()) {

}

Person::Person(const string &name, const Date &birthDay): _name(name), _birthDay(birthDay) {

}

Person::Person(const string &name, size_t year, size_t month, size_t day)
	: _name(name), _birthDay(Date(year, month, day)) {

}

string Person::ToString() const {
	stringstream ss;
	ss << "Name: " << _name << ", Birthday: " << _birthDay.ToString();
	return ss.str();
}

string Person::GetName() const {
	return _name;
}

Date Person::GetBirthDay() const {
	return _birthDay;
}

size_t Person::GetAge() const {
	return _birthDay.Difference(Date::Now()) / 365;
}
