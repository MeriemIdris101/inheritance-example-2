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

datetest.o:	datetest.cpp date.h
	g++ -c datetest.cpp $(CFLAGS)

persontest.o:	persontest.cpp person.h date.h
	g++ -c persontest.cpp $(CFLAGS)

employeetest.o:	employeetest.cpp date.h person.h employee.h
	g++ -c employeetest.cpp $(CFLAGS)

warriortest.o:	warriortest.cpp date.h person.h warrior.h
	g++ -c warriortest.cpp $(CFLAGS)

date-test:	datetest.o date.o
	g++ datetest.o date.o -o test $(CFLAGS)
	./test

person-test:	persontest.o date.o person.o
	g++ persontest.o date.o person.o -o test $(CFLAGS)
	./test

employee-test: employeetest.o date.o person.o employee.o
	g++ employeetest.o date.o person.o employee.o -o test $(CFLAGS)
	./test

warrior-test: warriortest.o date.o person.o warrior.o
	g++ warriortest.o date.o person.o warrior.o -o test $(CFLAGS)
	./test

test:	date-test person-test employee-test warrior-test

clean:
	rm -f *.o inheritance test

