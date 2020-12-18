#include "../../lab2/include/Circle.h"
#include "../../lab2/include/Rectangle.h"
#include "../../lab2/include/Triangle.h"
#include "../../lab2/include/Square.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <fstream>
#include "../include/ShapeAccumulator.h"
using testing::Eq;

namespace {
    class testShapeAccumulator : public testing::Test {
    public:
        Triangle triange{std::make_pair(0,0), std::make_pair(5,5), std::make_pair(10,0)};
        Circle circle{std::make_pair(0,0), 10};
        Square square{std::make_pair(0,0), std::make_pair(10,10)};
        Rectangle rectangle{std::make_pair(0,0),std::make_pair(5,10)};
        ShapeAccumulator collection;
        testShapeAccumulator() {
        triange,circle,square,square;collection;
        }
    };
}
TEST_F(testShapeAccumulator, addTest) {
    collection.add(&square);
    ASSERT_EQ(collection.get_max_area()->get_area(),square.get_area() );
    ASSERT_EQ(collection.get_min_perimeter()->get_perimeter(), square.get_perimeter());
}

TEST_F(testShapeAccumulator, addAllTest) {
    std::vector<Figure *> shapes;
    shapes.push_back(&triange);
    shapes.push_back(&rectangle);
    shapes.push_back(&square);
    shapes.push_back(&circle);
    collection.AddAll(shapes);
    ASSERT_DOUBLE_EQ(collection.get_min_area()->get_area(),25);
    ASSERT_DOUBLE_EQ(collection.get_max_area()->get_area(),314.15926535897933);
    ASSERT_DOUBLE_EQ(collection.get_min_perimeter()->get_perimeter(),24.142135623730951 );
    ASSERT_DOUBLE_EQ(collection.get_max_perimeter()->get_perimeter(),62.83185307179586);
}
TEST_F(testShapeAccumulator, GetAllTest) {
    std::vector<Figure *> shapes;
    shapes.push_back(&triange);
    shapes.push_back(&rectangle);
    shapes.push_back(&square);
    shapes.push_back(&circle);
    collection.AddAll(shapes);
    ASSERT_DOUBLE_EQ(collection.get_all_perimeter(),156.97398869552683);
    ASSERT_DOUBLE_EQ(collection.get_all_area(), 489.15926535897933);
}
TEST_F(testShapeAccumulator, ParseTest) {
    std::vector<Figure *> shapes;
    shapes.push_back(&triange);
    shapes.push_back(&rectangle);
    shapes.push_back(&square);
    shapes.push_back(&circle);
    collection.AddAll(shapes);
    collection.parse("/home/homuwell/CLionProjects/OOP/lab4/out");
    std::fstream file;
    file.open("/home/homuwell/CLionProjects/OOP/lab4/out",std::ios::in);
    ASSERT_NE(file.peek(),std::ifstream::traits_type::eof());
    file.close();
}
TEST_F(testShapeAccumulator, UnparseTest) {
    ShapeAccumulator test_coll;
    test_coll.unparse("/home/homuwell/CLionProjects/OOP/lab4/out");
    ASSERT_DOUBLE_EQ(test_coll.get_min_area()->get_area(),25);
    ASSERT_DOUBLE_EQ(test_coll.get_max_area()->get_area(),314.15926535897933);
    ASSERT_DOUBLE_EQ(test_coll.get_min_perimeter()->get_perimeter(),24.142135623730951 );
    ASSERT_DOUBLE_EQ(test_coll.get_max_perimeter()->get_perimeter(),62.83185307179586);
}