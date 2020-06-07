
#include <cstddef>

class Matrix
{
public:
    Matrix(size_t rows, size_t columns);
    size_t getRows() const;
    size_t getColumns() const;
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;
    Matrix& operator*=(int arg);
    ~Matrix();
    class Row {
    public:
        Row(const Matrix &m, size_t i)
        {
            columns = m.columns;
            data = m.data + i * columns;
        }
        const int& operator[](size_t j) const
        {
            if (j >= columns) {
                throw std::out_of_range("");
            }
            return data[j];
        }
        int& operator[](size_t j)
        {
            if (j >= columns) {
                throw std::out_of_range("");
            }
            return data[j];
        }
    private:
        size_t columns;
        int *data;
    };
    const Row operator[](size_t i) const;
    Row operator[](size_t i);
private:
    size_t rows;
    size_t columns;
    int *data;
};
