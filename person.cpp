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
/**
 * Person default constructor
 * Creates a person with "anonymous" as name and with birthday
 * at the system's date at the moment of instantiation
 */
Person::Person(): _name("anonymous"), _birthDay(Date::Now()) {

}
/**
 * Person Constructor
 * Sets the name of the person, and the birthday at the system's date
 * at the moment of instantiation.
 * @param name the name of the person
 */
Person::Person(const string &name): _name(name), _birthDay(Date::Now()) {

}
/**
 * Person Constructor
 * Sets the name and birthday of the person
 * @param name the person's name
 * @param birthDay the person's birthday
 */
Person::Person(const string &name, const Date &birthDay): _name(name), _birthDay(birthDay) {

}
/**
 * Person Constructor
 * Sets the name and birthday of the person. However this constructor does not take in
 * a Date for the birthday, instead it takes year, month and day of the birthday
 * @param name the person's name
 * @param year the person's birthday year
 * @param month the person's birthday month
 * @param day  the person's birthday day
 */
Person::Person(const string &name, size_t year, size_t month, size_t day)
	: _name(name), _birthDay(Date(year, month, day)) {

}
/**
 * To String
 * Returns a string representation of the person. Will have the name and
 * birthday of the person.
 * @return string representation of person
 */
string Person::ToString() const {
	stringstream ss;
	ss << "Name: " << _name << ", Birthday: " << _birthDay.ToString();
	return ss.str();
}
/**
 * Name Accessor
 * @return the person's name
 */
string Person::GetName() const {
	return _name;
}
/**
 * Birthday Accessor
 * @return the person's birthday
 */
Date Person::GetBirthDay() const {
	return _birthDay;
}
/**
 * Age Accessor
 * Calculates the age based on the birthday of the person and system's current
 * date.
 * @return the age of the person in years
 */
size_t Person::GetAge() const {
	return _birthDay.Difference(Date::Now()) / 365;
}
