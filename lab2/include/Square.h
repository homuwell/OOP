#ifndef OOP_SQUARE_H
#define OOP_SQUARE_H
#include "Figure.h"

class Square : public Figure {
    double edge_len;
    std::unique_ptr<dot[]> points_;
    void fill(std:: string points);
public:
    Square(std::string points);
    double get_area() override;
    double get_perimeter() override;
    ~Square();
};


#endif //OOP_SQUARE_H
