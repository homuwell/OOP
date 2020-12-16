#include "../include/Triangle.h"
void Triangle::fill(std::string points) {
    std::stringstream ss(points);
    double coord;
    for (auto i =0; i < 3; ++i) {
        ss >> coord;
        points_[i].first = coord;
        ss >> coord;
        points_[i].second = coord;
    }
    FirstSecond = get_length(points_[0],points_[1]);
    FirstThird = get_length(points_[0],points_[2]);
    SecondThird = get_length(points_[1],points_[2]);
}

double Triangle::get_area() {
    double p = get_perimeter() / 2;
    return std::sqrt(p * (p - FirstSecond) * (p - FirstThird) * (p - SecondThird));
}

Triangle::Triangle(std::string points) : points_(std::make_unique<dot[]>(3)) {
    fill(points);
}

double Triangle::get_perimeter() {
    return FirstSecond + FirstThird + SecondThird;
}
