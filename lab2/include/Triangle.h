#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H
#include "Figure.h"
class Triangle : public Figure {
private:
    double FirstSecond, SecondThird, FirstThird;
    std::unique_ptr<dot[]> points_;
    void fill(std:: string points);
public:
    Triangle(std::string points);
    double get_area() override;
    double get_perimeter() override;
};
#endif //OOP_TRIANGLE_H
