#include <cstdlib>
#include <iostream>
class Row{
private: 
    size_t len;
    double* array;
public:
    Row(const size_t& len);
    Row(const Row& a);
    friend Row operator*(const Row &a, const int &b);
    friend Row operator*(const Row &a, const double &b);
    double& operator [](const int &b);
    const double& operator [](const int& a) const;
    void operator *=(const int &b);
    void operator *=(const double &b);
    bool operator ==(const Row &a);
    bool operator !=(const Row &a);
    void print();
};
class Matrix
{
private:
    size_t len, cols;
    Row* array;
public:
    Matrix(const size_t& a, const size_t& b);
    Matrix(const Matrix& a);
    friend Matrix operator*(const Matrix &a, const int &b);
    friend Matrix operator*(const Matrix &a, const double &b);
    Row& operator [](const int &a);
    const Row& operator [](const int &a) const;
    void operator *=(const int &b);
    void operator *=(const double &b);
    bool operator ==(const Matrix &a);
    bool operator !=(const Matrix &a);
    size_t getRows();
    size_t getColumns();
    void print();
};