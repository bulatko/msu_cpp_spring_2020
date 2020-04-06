#include "long.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

Long::Long(int a)
    {
        if(a == 0){
        len = 1;
        arr = (int *)realloc(arr, len * sizeof(int));
        arr[0] = 0;
        sign = 0;
        }
        else {
        sign = a < 0 ? -1 : 1;
        a /= sign;
        int i = 0;
        while(a > 0){
            int c = a % 10;
            arr = (int *)realloc(arr, (i + 1) * sizeof(int));
            len = i + 1;
            arr[i] = c;
            a /= 10;
            i++;
        }
        }
    }
    Long::Long(int* a, int l)
    {
        len = l;
        arr = a;
    };
    Long::Long(int* a, int l, int s)
    {
        len = l;
        arr = a;
        sign = s;
    };
Long& Long::operator=(const int& a){
    Long b(a);
    *this = b;
    return *this;
};
Long Long::operator -() const{
    Long b(arr, len, -sign);
    return b;
};

bool Long::operator >(const Long& a){
    if(len == 1 && a.len == 1)
        return arr[0] * sign > a.arr[0] * a.sign;
    
    if(a.sign != sign)
        return sign > a.sign;
    if(len != a.len)
        return len > a.len;
    for(int i = 0; i < len; i++)
        if(arr[i] != a.arr[i])
            return arr[i] > a.arr[i];
return false;
};

bool Long::operator <(const Long& a){
    Long t1 = -a, t2(arr, len, -sign);
    return t2 > t1; 
};
bool Long::operator >=(const Long& a){
    return this > &a or this == &a;
};

bool Long::operator <=(const Long& a){
    return this < &a or this == &a;
};
bool Long::operator ==(const Long& a){
    if(len != a.len or a.sign != sign)
        return false;
    for(int i = 0; i < len; i++)
        if(arr[i] != a.arr[i])
            return false;
    return true;
};
bool Long::operator !=(const Long& a){
    return !(this == &a);
};
Long operator -(const Long& a, const Long& b){
    return a + -b;
}
Long operator +(const Long& a, const Long& b){
    if(a.sign == b.sign || a.sign * b.sign == 0){
        int min_len = a.len < b.len ? a.len : b.len;
        int max_len = a.len > b.len ? a.len : b.len;
        Long minD = a, maxD = b;
        if(a.len > b.len){
            minD = b;
            maxD = a;
        }
        int *ar = (int *)malloc(max_len * sizeof(int));
        int d = 0;
        for(int i = 0; i < min_len; i++){
            int k = d + minD.arr[i] + maxD.arr[i];
            ar[i] = k % 10;
            d = k / 10;
        }
        for(int i = min_len; i < max_len; i++){
            int k = d + maxD.arr[i];
            ar[i] = k % 10;
            d = k / 10; 
        }
        if(d){
            ar = (int *)realloc(ar, (max_len + 1) * sizeof(int));
            ar[max_len++] = d;
        }
        int sign = a.sign != 0 ? a.sign : b.sign;
        Long c(ar, max_len, sign);
        return c;
    }else{
        Long pos = a, neg = b;
        if(a.sign < 0){
            pos = b;
            neg = a;
        }
        if(pos == -neg){
            Long c(0);
            return c;
        }
        int sign = pos > -neg ? 1 : -1;
        Long big = pos, little = -neg;
        if(sign == -1){
            big = little;
            little = pos;
        }
        int d = 0;
        int *res = NULL;
        for(int i = 0; i < little.len; i++){
            res = (int *) realloc(res, (i + 1) * sizeof(int));
            int c = big.arr[i] - little.arr[i] - d;
            d = c < 0 ? 1 : 0;

            res[i] = c < 0 ? 10 + c : c;

        }
        for(int i = little.len; i < big.len; i++){
            res = (int *) realloc(res, (i + 1) * sizeof(int));
            int c = big.arr[i] - d;
            d = c < 0 ? 1 : 0;

            res[i] = c < 0 ? 10 + c : c;

        }

        Long c(res, big.len, sign);
        c.update();
        return c;

    } 

}

ostream& operator << (ostream& out, const Long& a){
    out << (a.sign >= 0 ? "" : "-");
for(int i = 0; i < a.len; i++){
    out << a.arr[a.len - i - 1];
}
    return out;
}

void Long::print(){
    cout << (sign >= 0 ? "" : "-");
for(int i = 0; i < len; i++){
    cout << arr[len - i - 1];
}
cout << endl;
}
void Long::update(){
    int l = -1;
    for(int i = 0; i < len; i++){
        if(arr[i] != 0)
            l = i;
    }
    if(l == -1){
        len = 1;
        arr = (int *)malloc(sizeof(int));
        arr[0] = 0;
        sign = 0;
        return;
    }
    len = l + 1;
    arr = (int *) realloc(arr, len * sizeof(int));
}