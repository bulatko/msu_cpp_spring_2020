#include <iostream>
#include "matrix.h"
#include <string>
#include <math.h>
#include <cassert>

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
    const size_t rows = 5;
    const size_t cols = 3;

    Matrix m(rows, cols);

    assert(m.getRows() == 5);
    assert(m.getColumns() == 3);

    m[1][2] = 5; // строка 1, колонка 2
    Test(m[1][2] == 5);
    double x = m[4][1];
    Test(m[4][1] == 0);
    m *= 3; // умножение на число
    Test(m[4][1] == 0);
    Test(m[1][2] == 15);

    Matrix m1(rows, cols);

    Test((m1 == m) == false);
    m1[1][1] = 1;
    m1 *= 2.5;
    Test(m1[1][1] == 2.5);
    Test(m1[1][2] != 2.5);
    Test(m1 != m1 * 3.1);
    m1[1][2] = m1[1][1] * 2;
    Test(m1[1][2] == m1[1][1] * 2);
    Test(m1[1][2] == 5);

    return 0;
}
