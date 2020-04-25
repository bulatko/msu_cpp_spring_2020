#include <iostream>
#include "vector.h"
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
    Vector<int> a;

    a.push_back(2);
    Test(a[0] == 2);

    a.push_back(3);
    Test(a[1] == 3 && a[0] == 2);

    a.pop_back();
    Test(a.size() == 1 && a[0] == 2);

    Test(!a.empty());

    a.clear();
    Test(a.size() == 0 && a.empty());

    a.push_back(1);
    a.push_back(6);
    a.push_back(5);
    a.push_back(5);
    a.push_back(52);

    int s = count_if(a.begin(), a.end(), [](int x) { return x % 2 == 0; });

    Test(a.begin() != a.end());
    Test(s == 2);
    size_t size = a.size();
    a.resize(size + 1);
    Test(a.size() == size + 1 && a.capacity() == size + 1);
    size++;

    a.reserve(size + 1);
    Test(a.size() == size && a.capacity() == size + 1);

    Test(a.rbegin() != a.rend());
    int first_even = NULL, first_even_rev = NULL;
    for_each(a.rbegin(), a.rend(), [&first_even_rev](int x) {
        if (first_even_rev == NULL && x % 2 == 0)
            first_even_rev = x;
    });
    for_each(a.begin(), a.end(), [&first_even](int x) {
        if (first_even == NULL && x % 2 == 0)
            first_even = x;
    });
    
    Test(first_even == 6 && first_even_rev == 52);
    return 0;
}
