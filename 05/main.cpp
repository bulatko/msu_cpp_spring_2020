#include <iostream>
#include "long.h"
#include <string>
#include <math.h>

using namespace std;
int test_num = 1;
void Test(bool statement){
    cout << "Test " << test_num << " : ";
    if(statement)
        cout << "ok";
    else
        cout << "no";
    cout << endl;
    test_num++;
    
}

int main()
{
    Long a = 5, b = a + 3, c = 8, d = 3, e = -5;
    Test(b != a);
    Test(b > a);
    Test(a < b);
    Test(b == c);
    Test(c - d == a);
    Test(a + e == b - c);
    Test(a + 3 == b);
    cout << a + b + c + d + e;//19

    return 0;
}
