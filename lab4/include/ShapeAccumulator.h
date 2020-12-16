

#ifndef OOP_SHAPEACCUMULATOR_H
#define OOP_SHAPEACCUMULATOR_H
#include "../../lab2/include/Figure.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
using pair_fig = std::pair<Figure*, Figure*>;
class ShapeAccumulator {
    std::vector<Figure*> figures_;
    pair_fig min_max_area_;
    pair_fig min_max_perimeter_;
    double all_area_;
    double all_perimeter_;
public:
    ShapeAccumulator() : all_perimeter_(0), all_area_(0) {};
    Figure* get_max_area();
    Figure* get_min_area();
    Figure* get_max_perimeter();
    Figure* get_min_perimeter();
    void add(Figure* figure);
    void AddAll(std::vector<Figure*> figures);
    double get_all_area();
    double get_all_perimeter();
};


#endif //OOP_SHAPEACCUMULATOR_H
