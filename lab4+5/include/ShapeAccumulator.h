#ifndef OOP_SHAPEACCUMULATOR_H
#define OOP_SHAPEACCUMULATOR_H
#include "../../lab2/include/Figure.h"
#include "../../lab2/include/Circle.h"
#include "../../lab2/include/Triangle.h"
#include "../../lab2/include/Square.h"
#include "../../lab2/include/Rectangle.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
namespace pt = boost::property_tree;
using pair_fig = std::pair<Figure*, Figure*>;
class ShapeAccumulator {
    std::vector<Figure*> figures_;
    pair_fig min_max_area_;
    pair_fig min_max_perimeter_;
    double all_area_;
    double all_perimeter_;
public:
    ShapeAccumulator() : all_perimeter_(0), all_area_(0) {};
    Figure* get_max_area() const;
    Figure* get_min_area() const;
    Figure* get_max_perimeter() const;
    Figure* get_min_perimeter() const;
    void add(Figure* figure);
    void AddAll(const std::vector<Figure*>& figures);
    double get_all_area() const;
    double get_all_perimeter() const;
    void parse(std::string file_name);
    void unparse(std::string file_name);
    std::vector<Figure*>::const_iterator get_iterator();
    std::vector<Figure*>::const_iterator get_end();
    void remove(std::size_t index);
    void swap(std::size_t first_index, std::size_t second_index);

};


#endif //OOP_SHAPEACCUMULATOR_H