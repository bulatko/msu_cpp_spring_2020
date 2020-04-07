#include "matrix.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Row::Row(const size_t& l){
    len = l;
    array = (double *) malloc(len * sizeof(double));
    for(int i = 0; i < len; i++)
        array[i] = 0;

}
Row::Row(const Row& a){
    len = a.len;
    array = (double *) malloc(len * sizeof(double));
    for(int i = 0; i < len; i++)
        array[i] = a.array[i];

}
double& Row::operator [](const int& a){
    if(a > 0 && a <= len)
        return array[a - 1];
    else 
        throw out_of_range("");
}
const double& Row::operator [](const int& a) const{
    if(a > 0 && a <= len)
        return array[a - 1];
    else 
        throw out_of_range("");
}

Row operator *(const Row &a, const int &b){
    Row a1 = a;
    for(int i = 0; i < a.len; i++)
        a1.array[i] *= b;
    return a1;
};

void Row::operator *=(const int &b){
    for(int i = 0; i < len; i++)
        array[i] *= b;
};
Row operator *(const Row &a, const double &b){
    Row a1(a);
    for(int i = 0; i < a.len; i++)
        a1.array[i] *= b;
    return a1;
};

void Row::operator *=(const double &b){
    for(int i = 0; i < len; i++)
        array[i] *= b;
};

bool Row::operator ==(const Row &a){
    if(len != a.len)
        return false;
    for(int i = 0; i < len; i++){
        if(array[i] != a.array[i])
            return false;
            }
    return true;
};

bool Row::operator !=(const Row &a){
    return ! (*this == a);
};



Matrix::Matrix(const size_t& rows, const size_t& c){
    len = rows;
    cols = c;
    array = (Row *) malloc(len * sizeof(Row));
    for(int i = 0; i < len; i++)
        array[i] = Row(c);

}
Matrix::Matrix(const Matrix& a){
    len = a.len;
    cols = a.cols;
    array = (Row *) malloc(len * sizeof(Row));
    for(int i = 0; i < len; i++)
        array[i] = Row(a.array[i]);

}
Row& Matrix::operator [](const int& a){
    if(a > 0 && a <= len)
        return array[a - 1];
    else 
        throw out_of_range("");
}
const Row& Matrix::operator [](const int& a) const{
    if(a > 0 && a <= len)
        return array[a - 1];
    else 
        throw out_of_range("");
}

void Row::print(){
    for(int i = 0; i < len; i++)
        cout << array[i] << " ";
    cout << endl;
}

Matrix operator *(const Matrix &a, const int &b){
    Matrix a1 = a;
    for(int i = 0; i < a.len; i++)
        a1.array[i] *= b;
    return a1;
};

void Matrix::operator *=(const int &b){
    for(int i = 0; i < len; i++)
        array[i] *= b;
};
Matrix operator *(const Matrix &a, const double &b){
    Matrix a1(a);
    for(int i = 0; i < a1.len; i++)
        a1.array[i] *= b;
    return a1;
};

void Matrix::operator *=(const double &b){
    for(int i = 0; i < len; i++)
        array[i] *= b;
};

bool Matrix::operator ==(const Matrix &a){
    if(len != a.len)
        return false;
    for(int i = 0; i < len; i++)
        if(array[i] != a.array[i])
            return false;
    return true;
};

bool Matrix::operator !=(const Matrix &a){
    return ! (*this == a);
};
size_t Matrix::getColumns(){
    return cols;
}
size_t Matrix::getRows(){
    return len;
}
void Matrix::print(){
    for(int i = 0; i < len; i++){
        array[i].print();
    }
    cout << endl;
}