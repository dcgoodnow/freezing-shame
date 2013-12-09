CC=g++
CFLAGS= -g
DEPS=string.h uno.h unoclass.h 
Uno_main: Uno_main.o uno.o string.o unoclass.o
	g++ -o Uno_main Uno_main.o uno.o string.o unoclass.o

maintester: maintester.o string.o unoclass.o uno.o
	g++ -o maintester maintester.o string.o unoclass.o uno.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *o

test: test.cpp 
	g++ -o test test.cpp

