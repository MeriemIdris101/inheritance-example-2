/*
 * Title:		Date Unit Test
 * Purpose:		Test all methods of the Date Class
 * Author:		Carlos Arias
 * Date:		April 16, 2020
 */
#include "date.h"

#include <iostream>
#include <sstream>
#include <cassert>
using std::cout;
using std::endl;
using std::stringstream ;

int main(int argc, char* argv[]){
	// Invalid Date [month]
	Date a(2000, 13, 1);
	assert(a.GetDay() == 0);
	assert(a.GetMonth() == 0);
	assert(a.GetYear() == 0);
	cout << "Invalid Month					Passed" << endl;

	// Invalid Date [day]
	Date b(2000, 1, 32);
	assert(b.GetDay() == 0);
	assert(b.GetMonth() == 0);
	assert(b.GetYear() == 0);
	cout << "Invalid Day (Jan/32)			Passed" << endl;

	// Invalid Date [day]
	Date c(2000, 2, 30);
	assert(c.GetDay() == 0);
	assert(c.GetMonth() == 0);
	assert(c.GetYear() == 0);
	cout << "Invalid Day (Feb/30)			Passed" << endl;

	// Invalid Date [day]
	Date d(2000, 4, 31);
	assert(d.GetDay() == 0);
	assert(d.GetMonth() == 0);
	assert(d.GetYear() == 0);
	cout << "Invalid Day (Apr/31)			Passed" << endl;

	// Invalid Date [day]
	Date e(2000, 6, 31);
	assert(e.GetDay() == 0);
	assert(e.GetMonth() == 0);
	assert(e.GetYear() == 0);
	cout << "Invalid Day (Jun/31)			Passed" << endl;

	// Invalid Date [day]
	Date f(2000, 9, 31);
	assert(f.GetDay() == 0);
	assert(f.GetMonth() == 0);
	assert(f.GetYear() == 0);
	cout << "Invalid Day (Sep/31)			Passed" << endl;

	// Invalid Date [day]
	Date g(2000, 9, 31);
	assert(g.GetDay() == 0);
	assert(g.GetMonth() == 0);
	assert(g.GetYear() == 0);
	cout << "Invalid Day (Apr/31)			Passed" << endl;

	// Invalid Date [day]
	Date h(2000, 11, 31);
	assert(h.GetDay() == 0);
	assert(h.GetMonth() == 0);
	assert(h.GetYear() == 0);
	cout << "Invalid Day (Nov/31)			Passed" << endl;

	// Invalid Date [leap year]
	Date i(2021, 2, 29);
	assert(i.GetDay() == 0);
	assert(i.GetMonth() == 0);
	assert(i.GetYear() == 0);
	cout << "2021 not Leap year				Passed" << endl;

	// Invalid Date [leap year]
	Date j(2100, 2, 29);
	assert(j.GetDay() == 0);
	assert(j.GetMonth() == 0);
	assert(j.GetYear() == 0);
	cout << "2100 not Leap year				Passed" << endl;

	// Invalid dates tested!
	// Valid Leap Years
	Date k(2000, 2, 29);
	assert(k.GetDay() == 29);
	assert(k.GetMonth() == 2);
	assert(k.GetYear() == 2000);
	cout << "2000 is Leap year				Passed" << endl;

	Date l(1992, 2, 29);
	assert(l.GetDay() == 29);
	assert(l.GetMonth() == 2);
	assert(l.GetYear() == 1992);
	cout << "1992 is Leap year				Passed" << endl;

	// Testing Difference between dates
	Date m(1976, 8, 5);
	Date n(1977, 8, 5);
	assert(m.Difference(n) == 365);
	cout << "1 year difference				Passed" << endl;

	Date o(1980, 8, 5);
	assert(m.Difference(o) == 1461);
	cout << "4 year difference				Passed" << endl;

	// Testing ToString
	assert(m.ToString() == "Thu Aug  5 1976");
	cout << "ToString [1]					Passed" << endl;
	assert(n.ToString() == "Fri Aug  5 1977");
	cout << "ToString [2]					Passed" << endl;
	assert(o.ToString() == "Tue Aug  5 1980");
	cout << "ToString [3]					Passed" << endl;

	Date p(2000, 11, 15);
	assert(p.ToString() == "Wed Nov 15 2000");
	cout << "ToString [4]					Passed" << endl;

	// Testing stream extraction and insertion operators
	stringstream stream;
	stream.str("2015 10 21 2020 04 10 2005 12 11");
	Date q(0,0,0);
	stream >> q;
	assert(q.GetYear() == 2015);
	assert(q.GetMonth() == 10);
	assert(q.GetDay() == 21);
	cout << "istream >> [1]					Passed" << endl;

	stream >> q;
	assert(q.GetYear() == 2020);
	assert(q.GetMonth() == 4);
	assert(q.GetDay() == 10);
	cout << "istream >> [2]					Passed" << endl;

	stream >> q;
	assert(q.GetYear() == 2005);
	assert(q.GetMonth() == 12);
	assert(q.GetDay() == 11);
	cout << "istream >> [3]					Passed" << endl;

	stream.clear();
	stream.str("");
	stream << q;
	assert(stream.str() == "2005 12 11");
	cout << "ostream <<						Passed" << endl;

	cout << "All Unit Tests Passed --------------" << endl << endl;

	return 0;
}