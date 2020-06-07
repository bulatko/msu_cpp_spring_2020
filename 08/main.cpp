#include <iostream>
#include "pool.h"
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
int foo(int x) {
    return x;
}

struct A
{
    int data;
    A() : data(0) {}
};

struct B
{
    int data;
    B() : data(0) {}
    int bar(int x) {
        return data + x;
    }
    static int foo(int x) {
        return x;
    }
};

int bar(const A& a) {
    return a.data;
}

int main() {
    ThreadPool pool(5);
    A a;
    auto task0 = pool.exec(bar, a);
    Test(task0.get() == 0);
    auto task1 = pool.exec([]() { return 1; });
    Test(task1.get() == 1);
    auto task2 = pool.exec(foo, 2);
    Test(task2.get() == 2);
    auto task3 = pool.exec(&B::foo, 3);
    Test(task3.get() == 3);
    B b;
    auto f = bind(&B::bar, &b, placeholders::_1);
    auto task4 = pool.exec(f, 4);
    Test(task4.get() == 4);
    cout << "done" << endl;
    return 0;
}
