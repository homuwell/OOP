#include "../headers/Matrix.h"

template<class elements>
Matrix<elements>::Matrix(size_t rows, size_t columns)
: rows_(rows),
  columns_(columns),
  data_(std::make_unique<std::unique_ptr<elements []>[] > (rows))
{
    std::unique_ptr<elements []> colarr;
    for(int i = 0; i < columns; ++i) {
        colarr = std::make_unique<elements[]>(columns_);
        data_[i] = std::move(colarr);
    }
}


template <class elements>
void Matrix<elements>::read_console() {
    std::string matrixElements;
    std::cout << "Please, write elements of the matrix:\n";
    std::getline(std::cin,matrixElements);
    fill(matrixElements);
    print_console();
}
template <class elements>
void Matrix<elements>::read_file() {
    std::string path_to_file, matrix;
    std::cout << "Please, write path to file\n";
    std::cin >> path_to_file;
    std::ifstream file;
    file.open(path_to_file);
    if (!file) {
        std::cout << "file do not exist";
    } else {
        file >> matrix;
        fill(matrix);
        print_console();
    }
}
template <class elements>
void Matrix<elements>::print_console() {
    std::cout << to_string();
}
template <class elements>
void Matrix<elements>::fill(std::string matrix) {
    elements elem;
    std::stringstream ss(matrix);
    for (int row = 0; row < rows_; ++row) {
        for (int column = 0; column < columns_; ++column) {
            ss >> elem;
            data_[row][column] = elem;
        }
    }
}

template<class elements>
std::unique_ptr<elements[]>& Matrix<elements>::operator[](const size_t index) const {
    if (index > this->columns_) throw std::invalid_argument("This index is bigger that size of matrix");
    return data_[index];
}

template<class elements>
std::string Matrix<elements>::get_size()  {
    std::string s;
    std::stringstream ss(s);
    ss << rows_ << 'x' << columns_;
    ss >> s;
    return s;
}

template<class elements>
Matrix<elements>& Matrix<elements>::operator=(Matrix &&other) noexcept {
    data_ = std::move(other.data_);
    rows_ = other.rows_;
    columns_ = other.columns_;
    return *this;
}

template<class elements>
Matrix<elements>::Matrix(const Matrix &other)
: rows_(other.rows_),
  columns_(other.columns_),
  data_(std::make_unique<std::unique_ptr<elements []>[] > (other.rows_))
{
    std::unique_ptr<elements []> colarr;
    for (int row = 0; row < other.rows_; ++row) {
        colarr = std::make_unique<elements[]>(other.columns_);
        for (int column = 0; column < other.columns_; ++column) {
            colarr[column] = other.data_[row][column];
        }
        data_[row] = std::move(colarr);
    }
}

template<class elements>
Matrix<elements>::Matrix(Matrix &&other)
: data_(std::move(other.data_)),
  rows_(other.rows_),
  columns_(other.columns_)
{

}

template<class elements>
Matrix<elements> &Matrix<elements>::operator=(const Matrix &other) {
    std::unique_ptr<elements []> colarr;
    for (int row = 0; row < other.rows_; ++row) {
        colarr = std::make_unique<elements[] >(other.columns_);
        for (int column = 0; column < other.columns_; ++column) {
            colarr[column] = other.data_[row][column];
        }
        data_[row] = std::move(colarr);
    }
    rows_ = other.rows_;
    columns_ = other.columns_;
    return *this;
}

template<class elements>
Matrix<elements> Matrix<elements>::operator+(const Matrix &other) {
    if (this->rows_ != other.rows_ && this->columns_ != other.columns_) {
        throw std::invalid_argument("Sizes of matrices aren't equal");
    }
    Matrix<elements>result(other);
    for (int row = 0; row < other.rows_; ++row) {
        for (int column = 0; column < other.columns_; ++column) {
            result.data_[row][column] += this->data_[row][column];
        }
    }
    return result;
}

template<class elements>
Matrix<elements> Matrix<elements>::operator-(const Matrix &other) {
    if (this->rows_ != other.rows_ && this->columns_ != other.columns_) {
        throw std::invalid_argument("Sizes of matrices aren't equal");
    }
    Matrix<elements>result(*this);
    for (int row = 0; row < other.rows_; ++row) {
        for (int column = 0; column < other.columns_; ++column) {
            result.data_[row][column] -= other.data_[row][column];
        }
    }
    return result;
}

template<class elements>
Matrix<elements> Matrix<elements>::operator*(const Matrix &other) {
    if (this->rows_ != other.columns_) throw std::invalid_argument("Numbers of columns of first matrix doesn't equal to number of rows of second matrix");
    Matrix<elements>result(this->rows_,other.columns_);
    #pragma omp parallel for
    for(int i = 0; i < result.rows_; ++i) {
        for (int j = 0; j  < result.columns_;++j) {
            for (int k = 0; k < this->columns_; ++k) {
                    result.data_[i][j] += this->data_[i][k] * other.data_[k][j];
            }
        }
    }
    return result;
}

template<class elements>
elements Matrix<elements>::determinant(const Matrix &matrix) {
    elements det = 0;
    if (matrix.rows_ == 2) {
        return matrix.data_[0][0] * matrix.data_[1][1] - matrix.data_[0][1] * matrix.data_[1][0];
    } else {
        Matrix<elements> minor(matrix.rows_ - 1,matrix.columns_ - 1);
        for (int i = 0; i < matrix.columns_; i++)
        {
            int numbersDone = 0;
            for (int j = 1; j < matrix.rows_; j++)
                for (int k = 0; k < matrix.columns_; k++)
                    if (k != i)
                    {
                        numbersDone++;
                        minor.data_[(numbersDone - 1) / (matrix.rows_ - 1)][(numbersDone - 1) % (matrix.rows_ - 1)] = matrix.data_[j][k];
                    }

            det += std::pow(-1, i + 2) * matrix.data_[0][i] * determinant(minor);
        }
        return det;
    }
}

template<class elements>
bool Matrix<elements>::operator==(const Matrix &other) {
    if (this->rows_ != other.rows_ || this->columns_ != other.columns_) {
        return false;
    } else {
        for(auto i = 0; i < this->rows_; ++i) {
            for(auto j = 0; j < this->columns_;++j) {
                if (this->data_[i][j] != other.data_[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
}

template<class elements>
Matrix<elements> Matrix<elements>::operator*(const elements scalar) {
    Matrix<elements> temp(*this);
    for (int i = 0; i < temp.rows_; i++)
        for (int j = 0; j < temp.columns_; j++)
            temp.data_[i][j] *= scalar;
    return temp;
}

template<class elements>
std::string Matrix<elements>::to_string() {
    std::ostringstream result;
    for (int row = 0; row < rows_; ++row) {
        for (int column = 0; column < columns_; ++column) {
            result << data_[row][column] << ' ';
        }
        result << '\n';
    }
    return result.str().erase(result.str().size() - 1,1);
}

template<class elements>
bool Matrix<elements>::operator!=(const Matrix &other) {
    return !(this == other);
}

template<class elements>
void Matrix<elements>::read_string(std::string matrix) {
    fill(std::move(matrix));
}

template<class elements>
Matrix<elements>::Matrix(size_t rows, size_t columns, std::string elems)
: rows_(rows),
  columns_(columns),
  data_(std::make_unique<std::unique_ptr<elements []>[] > (rows))
  {
    std::unique_ptr<elements []> colarr;
    for(int i = 0; i < rows; ++i) {
        colarr = std::make_unique<elements[]>(columns_);
        data_[i] = std::move(colarr);
    }
    fill(std::move(elems));
  }

template<class elements>
Matrix<elements>::~Matrix() {
    data_.reset(nullptr);
}

template<class elements>
elements Matrix<elements>::get_determinant() {
    return determinant(*this);
}




