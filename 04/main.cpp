#include <iostream>
#include "serializer.h"
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

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer) const
    {
        return serializer(a, b, c);
    }
	template <class Deserializer>
    Error deserialize(Deserializer& deserializer)
    {
        return deserializer(a, b, c);
    }
};

int main()
{
    Data x { 1, true, 2 };

    std::stringstream s1;

    Serializer serializer(s1);
    Test(serializer.save(x) == Error::NoError);
    Data y { 0, false, 0 };

    Deserializer d1(s1);
    Test(d1.load(y) == Error::NoError);

    Test(x.a == y.a);
    Test(x.b == y.b);
    Test(x.c == y.c);

    auto s2 = std::stringstream("");
    Deserializer d2(s2);
    Test(d2.load(y) == Error::CorruptedArchive);

    auto s3 = std::stringstream("1 2 3");
    Deserializer d3(s3);
    Test(d3.load(y) == Error::CorruptedArchive);

    auto s5 = std::stringstream("false 1");
    Deserializer d5(s5);
    Test(d5.load(y) == Error::CorruptedArchive);

    y = { 0, true, 0 };

    auto s6 = std::stringstream("100 false 500");
    Deserializer d6(s6);
    Test(d6.load(y) == Error::NoError);

    Test(y.a == 100);
    Test(y.b == false);
    Test(y.c == 500);
    return 0;
}
