all: my_prog

my_prog: main.o allocator.o
	g++ -o my_prog main.o allocator.o

main.o: main.cpp allocator.h
	g++ -c main.cpp

allocator.o: allocator.cpp allocator.h
	g++ -c allocator.cpp

clean:
	rm -rf *.o my_prog


