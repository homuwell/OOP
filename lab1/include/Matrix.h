#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#ifndef OOP_MATRIX_H
#define OOP_MATRIX_H
template <class elements>
class Matrix {
    size_t rows_, columns_;
    std::unique_ptr<std::unique_ptr<elements[]>[]> data_;
    elements determinant(const Matrix &matrix);
public:
    Matrix& operator=(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix &other);
    std::string get_size();
    Matrix(size_t rows, size_t columns);
    Matrix(size_t rows, size_t columns, std::initializer_list<elements> elems);
    Matrix(const Matrix &other);
    Matrix(Matrix&& other);
    void print_console();
    std::string to_string();
    std::unique_ptr<elements[]>& operator[] (const size_t index) const;
    Matrix operator +(const Matrix &other);
    Matrix operator -(const Matrix &other);
    Matrix operator *(const Matrix &other);
    Matrix operator *(const elements scalar);
    bool operator ==(const Matrix &other);
    bool operator !=(const Matrix &other);
    elements get_determinant();
    ~Matrix();
};
#include "../src/Matrix.cc"
#endif //OOP_MATRIX_H
