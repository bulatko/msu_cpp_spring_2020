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
    Long a = 5, b = a + 3, c = 8, d = 3, e = -5;
    Test(b != a);
    Test(b > a);
    Test(b < a == false);
    Test(b >= a);
    Test(a >= a);
    Test(a <= a);
    Test(a < a == false);
    Test(a < b);
    Test(b == c);
    Test(c - d == a);
    Test(a + e == b - c);
    Test(a + 3 == b);
    Test(a != 5 == false);
    Test(a == 5);
    Test(a <= a - 0);
    stringstream ss1, ss2;
    ss1 << a + b + c + d + e;
    ss2 << 19;
    Test(ss1.str() == ss2.str());
    a = 1;
    for(int i = 0; i < 500; i++)
        a = a + a;
    string pow_2_500 = "3273390607896141870013189696827599152216642046043064789483291368096133796404674554883270092325904157150886684127560071009217256545885393053328527589376"; 
    stringstream ss3, ss4;
    ss3 << a;
    ss4 << pow_2_500;
    Test(ss3.str() == ss4.str());

    return 0;
}
