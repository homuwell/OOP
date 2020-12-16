

#ifndef OOP_CIRCLE_H
#define OOP_CIRCLE_H
#include "Figure.h"

class Circle : public Figure{
private:
    double radius;
    std::unique_ptr<dot> point_;
    void fill(std::string points);
public:
    Circle(std::string points);
    double get_area() override;
    double get_perimeter() override;
};


#endif //OOP_CIRCLE_H
