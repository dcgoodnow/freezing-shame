CC=g++
CFLAGS= -Wall
DEPS= string.h uno.h
Uno_main: Uno_main.o uno.o
	g++ -o Uno_main Uno_main.o uno.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *o
