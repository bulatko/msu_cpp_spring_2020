CC=C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++
all: threadpool
threadpool: main.o pool.o
	$(CC) main.o pool.o -pthread -o threadpool --std=c++14 -O2
main.o: main.cpp
	$(CC) main.cpp -c --std=c++14 -O2
pool.o: pool.cpp
	$(CC) pool.cpp -c --std=c++14 -O2
clean:
	rm -rf *.o threadpool
test:
	./threadpool
