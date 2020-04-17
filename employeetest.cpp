#include "employee.h"
#include "date.h"

#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
using std::cout;
using std::endl;

bool DoubleEquals(double a, double b, double epsilon = 1e-6){
	return abs(a - b) < epsilon;
}

int main(int argc, char* argv[]) {
	// Calculate current time
	time_t now = time(NULL);
	tm *timeinfo = localtime(&now);
	size_t year = 1900 + static_cast<size_t>(timeinfo->tm_year);
	size_t month = 1 + static_cast<size_t>(timeinfo->tm_mon);
	size_t day = static_cast<size_t>(timeinfo->tm_mday);
	Date today(year, month, day);

	Employee a("John", Date(1980, 12, 10), 5000);
	assert(a.ToString() == "Name: John, Birthday: Wed Dec 10 1980, Hire Date: " + today.ToString() + ", Salary: 5000");
	cout << "ToString                               Passed" << endl;
	assert(DoubleEquals(a.GetSalary(), 5000));
	cout << "GetSalary                              Passed" << endl;
	a.Raise(0.10);
	assert(DoubleEquals(a.GetSalary(), 5500));
	cout << "GetSalary, after raise                 Passed" << endl;

	cout << "All Unit Tests Passed --------------" << endl << endl;


	return 0;
}
