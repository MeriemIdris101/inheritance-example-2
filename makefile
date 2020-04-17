CFLAGS = -std=c++14 -Wall -g

inheritance:	main.o date.o person.o employee.o warrior.o
	g++ main.o date.o person.o employee.o warrior.o -o inheritance $(CFLAGS)

memory:	inheritance
	valgrind --leak-check=full ./inheritance

main.o:	main.cpp date.h person.h employee.h warrior.h
	g++ -c main.cpp $(CFLAGS)

date.o: date.cpp date.h
	g++ -c date.cpp $(CFLAGS)

person.o:	person.cpp person.h date.h
	g++ -c person.cpp $(CFLAGS)

employee.o:	employee.cpp employee.h person.h date.h
	g++ -c employee.cpp $(CFLAGS)

warrior.o:	warrior.cpp warrior.h person.h date.h
	g++ -c warrior.cpp $(CFLAGS)

date-test.o:	datetest.cpp date.h
	g++ -c datetest.cpp $(CFLAGS)

person-test.o:	persontest.cpp person.h date.h
	g++ -c persontest.cpp $(CFLAGS)

employee-test.o:	employeetest.cpp date.h person.h employee.h
	g++ -c employeetest.cpp $(CFLAGS)

warrior-test.o:	warriortest.cpp date.h person.h warrior.h
	g++ -c warriortest.cpp $(CFLAGS)

date-test:	date-test.o date.o
	g++ date-test.o date.o -o test $(CFLAGS)

person-test:	person-test.o date.o person.o
	g++ person-test.o date.o person.o -o test $(CFLAGS)

employee-test: employee-test.o date.o person.o employee.o
	g++ employee-test.o date.o person.o employee.o -o test $(CFLAGS)

warrior-test: warrior-test.o date.o person.o warrior.o
	g++ warrior-test.o date.o person.o warior.o -o test $(CFLAGS)

clean:
	rm -f *.o inheritance test

