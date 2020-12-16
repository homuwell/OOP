//
// Created by homuwell on 12/7/20.
//

#ifndef OOP_RECTANGLE_H
#define OOP_RECTANGLE_H
#include "Figure.h"

class Rectangle : public Figure {
private:
    double first_edge_len, second_edge_len;
    std::unique_ptr<dot[]> points_;
    void fill(std:: string points);
public:
    Rectangle(std::string points);
    double get_area() override;
    double get_perimeter() override;
};


#endif //OOP_RECTANGLE_H
