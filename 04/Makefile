all: test

test: main.o
	g++ -o test main.o --std=c++17

main.o: main.cpp serializer.h
	g++ -c main.cpp --std=c++17


clean: main.cpp
	rm -rf *.o
