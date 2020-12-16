
#include "../include/Circle.h"

double Circle::get_area() {
    return std::pow(radius,2) * std::numbers::pi;
}

double Circle::get_perimeter() {
    return radius * 2.0 * std::numbers::pi;
}

Circle::Circle(std::string points) : point_(std::make_unique<dot>()){
    fill(points);
}

void Circle::fill(std::string points) {
    std::stringstream ss(points);
    double coord;
        ss >> coord;
        point_->first = coord;
        ss >> coord;
        point_->second = coord;
        ss >> coord;
        radius = coord;
}
