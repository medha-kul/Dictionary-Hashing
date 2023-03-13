runHashing:  Hashing.o
	g++ -g -Wall Hashing.o  -o runHashing

Hashing.o: Hashing.h TimeInterval.h Hashing.cpp
	g++ -g -Wall -c Hashing.cpp

clean:
	rm *.o
	rm runHashing

run: runHashing
	./runHashing

valgrind: runHashing
		valgrind ./runHashing
