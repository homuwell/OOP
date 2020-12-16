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
    void fill(std::string matrix);
    elements determinant(const Matrix &matrix);
public:
    Matrix& operator=(Matrix&& other) noexcept;
    Matrix& operator=(const Matrix &other);
    std::string get_size();
    void read_console();
    void read_file();
    Matrix(size_t rows, size_t columns);
    Matrix(size_t rows, size_t columns, std::string elems);
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
    void read_string(std::string matrix);
    ~Matrix();
};
#include "../classes/Matrix.cc"
#endif //OOP_MATRIX_H
