#include <iostream>
#include "allocator.h"


using namespace std;


int main()
{
makeAllocator(1000);

char* p1 = alloc(100);
char* p2 = alloc(200);
char* p3 = alloc(800);


if(p2 == p1){
    cerr << "Test 1 error: p2 == p1";
    return 1;
}

    cout << "test 1 is OK" << endl;

if(p2 - p1 != 100 ){
    cerr << "Test 2 error: p2 - p1 != 100";
    return 1;
}
    cout << "test 2 is OK" << endl;

if(p3 != nullptr){
    cerr << "Test 3 error: p3 is not nullptr";
    return 1;
}

    cout << "test 3 is OK" << endl;

reset();

char* p4 = alloc(800);

if(p4 == nullptr){
    cerr << "Test 4 error: p4 is nullptr";
    return 1;
}

cout << "test 4 is OK" << endl;

cin.get();

    return 0;
}
