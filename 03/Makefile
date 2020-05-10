all: test

test: main.o 
	g++ -o test main.o

main.o: main.cpp matrix.h
	g++ -c main.cpp


clean: main.cpp
	rm -rf *.o


