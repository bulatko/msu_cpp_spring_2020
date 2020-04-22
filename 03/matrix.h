#include <cstdlib>
#include <iostream>
class Matrix
{
private:
    size_t rows, cols;
    double** array;
public:
    Matrix(const size_t& a, const size_t& b);
    Matrix(const Matrix& a);
    friend Matrix operator*(const Matrix &a, const int &b);
    friend Matrix operator*(const Matrix &a, const double &b);
    double* operator [](const size_t &a);
    const double* operator [](const size_t &a) const;
    void operator *=(const int &b);
    void operator *=(const double &b);
    bool operator ==(const Matrix &a);
    bool operator !=(const Matrix &a);
    size_t getRows();
    size_t getColumns();
    void print();
};