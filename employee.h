//
// Created by Arias Arevalo, Carlos on 4/15/20.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"
#include "date.h"

#include <string>
#include <iostream>
using std::string;


class Employee : public Person{
	Date _hireDate;
	
};


#endif //INHERITANCE_EXAMPLE_2_EMPLOYEE_H
