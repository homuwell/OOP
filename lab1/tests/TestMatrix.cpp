#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../headers/Matrix.h"

using testing::Eq;

namespace {
    class testMatrix : public testing::Test {
    public:
        Matrix<int> intMatrix{3,3, "1 2 3"
                                   " 4 5 6"
                                   " 7 8 9"};
        Matrix<double> doubleMatrix{2,2, "1.5 2.5"
                                        " 3.5 4.5"};
        testMatrix() {
            intMatrix;
            doubleMatrix;
        }
    };
}
TEST_F(testMatrix, accessTest) {
    ASSERT_EQ(5, intMatrix[1][1]);
}
TEST_F(testMatrix, multiplicationTestWithDiffrentSizes) {
    Matrix<int>second{3,3,"10 11 12"
                                            " 13 14 15"
                                            " 16 17 18"};
    auto c = intMatrix * second;
    Matrix<int>result{3,3,"84 90 96 "
                                            "201 216 231 "
                                            " 318 342 366"};
    ASSERT_EQ(c.to_string(), result.to_string());
}
TEST_F(testMatrix, multiplicationTestWithDoubleEqualSizes) {
    Matrix<double>second{2,2, "5.5 6.5"
                             " 7.5 8.5"};
    auto c = doubleMatrix * second;
    Matrix<double>result{2,2,"27 31"
                             " 53 61"};
    ASSERT_EQ(c.to_string(), result.to_string());
}
TEST_F(testMatrix, multiplicationTestInvalidArgument) {
    Matrix<int>second{3,2,"10 11"
                          " 12 13"
                          " 14 15"};
    try {
        auto c = intMatrix * second;
        FAIL();
    }
    catch (const std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Numbers of columns of first matrix doesn't equal to number of rows of second matrix");
    }
}
TEST_F(testMatrix, accessTestInvalidArgument)  {
    try {
        intMatrix[500][500];
        FAIL();
    }
    catch (const std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "This index is bigger that size of matrix");
    }
}
TEST_F(testMatrix, subtractionTestInt) {
    Matrix<int>second{3,3, "7 8 9"
                              " 10 11 12"
                              " 13 14 15"};
    auto c = second - intMatrix;
    Matrix<int>result{3,3,"6 6 6"
                             " 6 6 6"
                             " 6 6 6"};
    ASSERT_EQ(c.to_string(), result.to_string());
}

TEST_F(testMatrix, subtractionTestInvalidArgument)  {
    try {
        Matrix<int>second{2,2, "7 8"
                               " 10 11"};
        auto c = second - intMatrix;
        FAIL();
    }
    catch (const std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Sizes of matrices aren't equal");
    }
}
TEST_F(testMatrix, subtractionTestDouble) {
    Matrix<double>second{2,2, "7 8"
                           " 9 10"};
    auto c = second - doubleMatrix;
    Matrix<double>result{2,2,"5.5 5.5"
                             " 5.5 5.5"};
    ASSERT_EQ(c.to_string(), result.to_string());
}
TEST_F(testMatrix, additionTestInt) {
    Matrix<int>second{3,3, "7 8 9"
                           " 10 11 12"
                           " 13 14 15"};
    auto c = second + intMatrix;
    Matrix<int>result{3,3,"8 10 12"
                          " 14 16 18"
                          " 20 22 24"};
    ASSERT_EQ(c.to_string(), result.to_string());
}

TEST_F(testMatrix, additionTestInvalidArgument)  {
    try {
        Matrix<int>second{2,2, "7 8"
                               " 10 11"};
        auto c = second + intMatrix;
        FAIL();
    }
    catch (const std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Sizes of matrices aren't equal");
    }
}
TEST_F(testMatrix, additionTestDouble) {
    Matrix<double>second{2,2, "7 8"
                              " 9 10"};
    auto c = second + doubleMatrix;
    Matrix<double>result{2,2,"8.5 10.5"
                             " 12.5 14.5"};
    ASSERT_EQ(c.to_string(), result.to_string());
}
TEST_F(testMatrix, determinantTestIntZero) {

    ASSERT_EQ(intMatrix.get_determinant(), 0);
}
TEST_F(testMatrix, determinantTestDouble) {

    ASSERT_EQ(doubleMatrix.get_determinant(), -2);
}
TEST_F(testMatrix, determinantTestInt) {
    Matrix<int>second{3,3, "5 2 8"
                           " 8 4 5"
                           " 1 3 7"};
    ASSERT_EQ(second.get_determinant(), 123);
}