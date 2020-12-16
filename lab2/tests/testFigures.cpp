#include "../include/Circle.h"
#include "../include/Rectangle.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
using testing::Eq;

namespace {
    class testFigure : public testing::Test {
    public:
        Triangle triange{"0 0 5 5 10 0"};
        Circle circle{"0 0 10"};
        Square square{"0 0 10 10"};
        Rectangle rectangle{"0 0 5 10"};
        testFigure() {
            triange,circle,square,square;
        }
    };
}
TEST_F(testFigure, TriangeTest) {
    ASSERT_DOUBLE_EQ(triange.get_perimeter(),24.142135623730951 );
    ASSERT_DOUBLE_EQ(triange.get_area(), 25);
}
TEST_F(testFigure, CirleTest) {
    ASSERT_DOUBLE_EQ(circle.get_perimeter(),62.83185307179586);
    ASSERT_DOUBLE_EQ(circle.get_area(), 314.15926535897933);
}
TEST_F(testFigure, SquareTest) {
    ASSERT_DOUBLE_EQ(square.get_perimeter(),40);
    ASSERT_DOUBLE_EQ(square.get_area(), 100);
}
TEST_F(testFigure, rectangeTest) {
    ASSERT_DOUBLE_EQ(rectangle.get_perimeter(),30);
    ASSERT_DOUBLE_EQ(rectangle.get_area(), 50);
}