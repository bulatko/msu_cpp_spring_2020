#include <iostream>
#include "format.h"
#include <string>
#include <bits/stdc++.h>
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
    string s, f;
    s = "{0}";
    f = format(s, 1);
    Test(f == "1");
    
    s = "{0}";
    f = format(s, "1");
    Test(f == "1");
    
    s = "{0}";
    f = format(s, '1');
    Test(f == "1");
    
    s = "{0}({1}){2}-{3}-{4}";
    f = format(s, "+7", 917, 221, "12", 36);
    Test(f == "+7(917)221-12-36");
    string res;
    try {
        s = "{{";
        res = format(s, 1);
    }
    catch ( std::runtime_error & er ) {
        res = er.what();
    }
    Test(res == "wrong order of brackets");
    
    try {
        s = "}{";
        res = format(s, 1);
    }
    catch ( std::runtime_error & er ) {
        res = er.what();
    }
    Test(res == "wrong order of brackets");

    try {
        s = "{0} {1}";
        res = format(s, 1);
    }
    catch ( std::runtime_error & er ) {
        res = er.what();
    }
    Test(res == "wrong number of arguments in formatted string");
    
    
    try {
        s = "{1";
        res = format(s, 1);
    }
    catch ( std::runtime_error & er ) {
        res = er.what();
    }
    Test(res == "No closing bracket");
    


    
    return 0;
}
