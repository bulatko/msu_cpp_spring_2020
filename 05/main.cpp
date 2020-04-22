#include <iostream>
#include "long.h"
#include <string>
#include <math.h>
#include <sstream>

using namespace std;
int test_num = 1;
void Test(bool statement)
{
    cout << "Test " << test_num << " : ";
    if (statement)
        cout << "ok";
    else
        cout << "no";
    cout << endl;
    test_num++;
}

int main()
{
    Long a = 1734234;
    for(int i = 0; i < 991500; i++)
        a = a + a;
    cout << a;

    return 0;
}
