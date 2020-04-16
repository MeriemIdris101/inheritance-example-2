/*
 * Title:		Employee Class Method Definition
 * Purpose:		Implementation of all Employee class methods
 * Description:	The Employee Class is derived from Person, additionally it
 * 				will have data members Hire Date and Salary.
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */
#include "employee.h"
#include "person.h"
#include "date.h"

#include <string>
#include <sstream>
using std::string ;
using std::stringstream ;
/**
 * Employee Constructor
 * Basic constructor, will initialize the Person part of Employee and its
 * salary. Sets hire date to the date of the system at instantiation.
 * @param name name of the employee
 * @param birthDay birthday of the employee
 * @param salary salary of the employee
 */
Employee::Employee(const string &name, const Date &birthDay, double salary)
	: Person(name, birthDay), _salary(salary), _hireDate(Date::Now()){

}
/**
 * Employee Constructor
 * This constructor initializes all data members of the employee.
 * @param name name of the employee
 * @param birthDay birthday of the employee
 * @param salary salary of the employee
 * @param hireDate date that the employee was hired
 */
Employee::Employee(const string &name, const Date &birthDay, double salary, const Date &hireDate)
		: Person(name, birthDay), _salary(salary), _hireDate(hireDate) {

}
/**
 * Salary Accessor
 * @return the salary of the employee
 */
double Employee::GetSalary() const {
	return _salary;
}
/**
 * Gives a raise to the employee.
 * @param percentage a number that represents the percentage of raise. 0.10 represents 10%.
 */
void Employee::Raise(double percentage) {
	_salary *= (1 + percentage);
}
/**
 * To String
 * Creates a string representation of the employee, uses the base class ToString to show
 * name and birthday, and appends the Hire Date and the Salary.
 * @return the string representation of the employee
 */
string Employee::ToString() const {
	stringstream ss;
	ss << Person::ToString() << ", Hire Date: " << _hireDate.ToString()
		<< ", Salary: " << _salary;
	return  ss.str();
}
