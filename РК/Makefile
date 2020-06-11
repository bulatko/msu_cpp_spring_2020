all: run

run: test
	./test

test: main.o
	g++ -o test main.o -pthread

main.o: main.cpp
	g++ -c --std=c++14 main.cpp

clean:
	rm -rf *.o test