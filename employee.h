/*
 * Title:		Employee Class Declaration
 * Purpose:		A Class to represent a simple employee
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"
#include "date.h"

#include <string>
#include <iostream>
using std::string;


class Employee : public Person{
	Date _hireDate;
	double _salary;
public:
	Employee(const string& name, const Date& birthDay, double salary);
	Employee(const string& name, const Date& birthDay, double salary, const Date& hireDate);

	double GetSalary()const;
	void Raise(double percentage);

	virtual string ToString()const;
};


#endif //INHERITANCE_EXAMPLE_2_EMPLOYEE_H
