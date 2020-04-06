#include <cstdlib>
#include <iostream>
class Long
{
private:
    int *arr = NULL, len, sign;

public:
    Long(long long a);
    Long(int *a, int l);
    Long(int *a, int l, int s);

    Long operator-() const;
    friend Long operator+(const Long &a, const Long &b);
    friend Long operator-(const Long &a, const Long &b);
    bool operator>(const Long &a);
    bool operator<(const Long &a);
    bool operator==(const Long &a);
    bool operator!=(const Long &a);
    bool operator>=(const Long &a);
    bool operator<=(const Long &a);
    Long &operator=(const int &a);
    void print();
    void update();
    friend std::ostream &operator<<(std::ostream &out, const Long &a);
};