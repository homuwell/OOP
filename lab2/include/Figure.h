
#ifndef OOP_FIGURE_H
#define OOP_FIGURE_H
#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <numbers>
class Figure {
protected:
    using dot = std::pair<double,double>;
    double get_length(dot frst, dot scnd) {
        return std::sqrt(std::pow((frst.first - scnd.first),2) + std::pow((frst.second - scnd.second),2));
    }
public:
    virtual double get_perimeter() = 0;
    virtual double get_area() = 0;
};
#endif //OOP_FIGURE_H
