all: test

test: main.o parser.o
	g++ -o test main.o parser.o

main.o: main.cpp parser.h
	g++ -c main.cpp

parser.o: parser.cpp parser.h
	g++ -c parser.cpp

clean: main.cpp
	rm -rf *.o test


