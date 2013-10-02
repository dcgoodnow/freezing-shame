CC=g++
CFLAGS= -Wall -g
DEPS= string.h uno.h
Uno_main: Uno_main.o uno.o string.o
	g++ -o Uno_main Uno_main.o uno.o string.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *o
