Uno_main: Uno_main.o uno.o
	g++ -o Uno_main Uno_main.o uno.o

Uno_main.o: Uno_main.cpp uno.h
	g++ -c Uno_main.cpp

uno.o: uno.cpp uno.h
	g++ -c uno.cpp

clean:
	rm -rf *o
