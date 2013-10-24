
CC=g++
CFLAGS= -Wall -g
DEPS= string.h uno.h unoclass.h


tester: tester2.o uno.o string.o unoclass.o
	g++ -o tester tester2.o uno.o string.o unoclass.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
