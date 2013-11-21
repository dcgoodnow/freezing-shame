CC=g++
CFLAGS= -Wall -g
DEPS= string.h person.h student.h employee.h
main: main.o person.o string.o student.o employee.o
	g++ -o main main.o person.o string.o student.o employee.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *o

test: test.o uno.o string.o unoclass.o
	g++ -o test test.o uno.o string.o unoclass.o

tester: tester2.o uno.o string.o unoclass.o
	g++ -o tester tester2.o uno.o string.o unoclass.o
