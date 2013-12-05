CC=g++
CFLAGS= -Wall -g
DEPS= string.h uno.h unoclass.h list.h 
Uno_main: Uno_main.o uno.o string.o unoclass.o
	g++ -o Uno_main Uno_main.o uno.o string.o unoclass.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *o

test: test.o uno.o string.o unoclass.o
	g++ -o test test.o uno.o string.o unoclass.o

maintester: maintester.o uno.o string.o unoclass.o list.o
	g++ -o maintester maintester.o string.o unoclass.o list.o
