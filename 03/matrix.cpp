#include "matrix.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Matrix::Matrix(const size_t& r, const size_t& c){
    rows = r;
    cols = c;
    array = new double*[rows];
    for(size_t i= 0; i < rows; i++)
        array[i] = new double[c];

}
Matrix::Matrix(const Matrix& a){
    rows = a.rows;
    cols = a.cols;
    array = new double*[rows];
    for(size_t i = 0; i < rows; i++){
        array[i] = new double[cols];
        for(size_t j = 0; j < cols; j++)
            array[i][j] = a[i][j];
    }
}
double* Matrix::operator [](const size_t& a){
    if(a > 0 && a <= rows)
        return array[a - 1];
    else 
        throw out_of_range("");
}
const double* Matrix::operator [](const size_t& a) const{
    if(a > 0 && a <= rows)
        return array[a - 1];
    else 
        throw out_of_range("");
}


Matrix operator *(const Matrix &a, const int &b){
    Matrix a1(a);
    for(size_t i = 0; i < a.rows; i++)
        for(size_t j = 0; i < a.cols; j++)
            a1.array[i][j] *= b;
    return a1;
};

void Matrix::operator *=(const int &b){
    for(size_t i= 0; i < rows; i++)
        for(size_t j = 0; j < cols; j++)
            array[i][j] *= b;
};
Matrix operator *(const Matrix &a, const double &b){
    Matrix a1(a);
    cout << "s";
    for(size_t i = 0; i < a.rows; i++){
        for(size_t j = 0; j < a.cols; j++){
            cout << "i = " << i << "; j = " << j << " a[i][j] = " << a1.array[i][i] << " ";
            a1.array[i][j] *= b;
            }
            cout << endl;
            }
    return a1;
};

void Matrix::operator *=(const double &b){
    for(size_t i= 0; i < rows; i++)
        for(size_t j = 0; j < cols; j++)
            array[i][j] *= b;
};

bool Matrix::operator ==(const Matrix &a){
    if(this == &a)
        return true;
    if(rows != a.rows || cols != a.cols)
        return false;
    for(size_t i= 0; i < rows; i++)
        for(size_t j = 0; j < cols; j++)
            if(array[i][j] != a.array[i][j])
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
    return rows;
}
void Matrix::print(){
    for(size_t i= 0; i < rows; i++){
        for(size_t j= 0; j < rows; j++)
            cout << array[i][j] << " ";
    cout << endl;
    }
    cout << endl;
}