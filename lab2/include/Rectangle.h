//
// Created by homuwell on 12/7/20.
//

#ifndef OOP_RECTANGLE_H
#define OOP_RECTANGLE_H
#include "Figure.h"

class Rectangle : public Figure {
private:
    double first_edge_len, second_edge_len;
    std::array<dot,2> points_;
public:
    Rectangle() = default;
    Rectangle(dot first, dot second);
    double get_area() override;
    double get_perimeter() override;
    void parse(pt::ptree * obj) override;
    void unparse(pt::ptree *obj) override;
    const std::vector<double> get_all_data() const  override;
};


#endif //OOP_RECTANGLE_H

