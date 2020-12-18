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
        Triangle triangle{std::make_pair(0,0), std::make_pair(5,5), std::make_pair(10,0)};
        Circle circle{std::make_pair(0,0), 10};
        Square square{std::make_pair(0,0), std::make_pair(10,10)};
        Rectangle rectangle{std::make_pair(0,0),std::make_pair(5,10)};
        testFigure() {
            triangle,circle,square,square;
        }
    };
}
TEST_F(testFigure, triangleTest) {
    ASSERT_DOUBLE_EQ(triangle.get_perimeter(),24.142135623730951 );
    ASSERT_DOUBLE_EQ(triangle.get_area(), 25);
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
TEST_F(testFigure, ArrayTest) {
    std::vector<Figure*> figures;
    figures.push_back(&triangle);
    figures.push_back(&circle);
    figures.push_back(&square);
    figures.push_back(&rectangle);
    Figure* max_area;
    Figure* max_perimeter;
    double all_area = 0;
    double tmp_area = 0;
    double tmp_per = 0;
    for(auto i : figures) {
        all_area += i->get_area();
        if(i->get_area() > tmp_area) {
            tmp_area = i->get_area();
            max_area = i;
        }
        if(i->get_perimeter() > tmp_per) {
            tmp_per = i->get_perimeter();
            max_perimeter = i;
        }
        }
        ASSERT_DOUBLE_EQ(all_area,489.15926535897933);
        ASSERT_EQ(max_perimeter,&circle);
        ASSERT_EQ(max_area,&circle);
}