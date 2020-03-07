all: test

test: main.o allocator.o
	g++ -o test main.o allocator.o

main.o: main.cpp allocator.h
	g++ -c main.cpp

allocator.o: allocator.cpp allocator.h
	g++ -c allocator.cpp

clean: main.cpp
	rm -rf *.o test


