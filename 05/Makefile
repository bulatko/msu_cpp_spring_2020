all: test

test: main.o long.o
	g++ -o test main.o long.o

main.o: main.cpp long.h
	g++ -c main.cpp

long.o: long.cpp long.h
	g++ -c long.cpp

clean: main.cpp
	rm -rf *.o


