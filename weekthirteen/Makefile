DEPS = listA.h listN.h

%.o: %.cpp $(DEPS)
	g++ -g -c -o $@ $<

binarysearch: binarysearch.o listA.o listN.o
	g++ -o binarysearch binarysearch.o listA.o listN.o

clean:
	rm -rf *o
