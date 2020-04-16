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

Employee::Employee(const string &name, const Date &birthDay, double salary)
	: Person(name, birthDay), _salary(salary), _hireDate(Date::Now()){

}

Employee::Employee(const string &name, const Date &birthDay, double salary, const Date &hireDate)
		: Person(name, birthDay), _salary(salary), _hireDate(hireDate) {

}

double Employee::GetSalary() const {
	return _salary;
}

void Employee::Raise(double percentage) {
	_salary *= (1 + percentage);
}

string Employee::ToString() const {
	stringstream ss;
	ss << Person::ToString() << ", Hire Date: " << _hireDate.ToString()
		<< ", Salary: " << _salary;
	return  ss.str();
}
