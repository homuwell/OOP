
#include "../include/Circle.h"

double Circle::get_area() {
    return std::pow(radius,2) * std::numbers::pi;
}

double Circle::get_perimeter() {
    return radius * 2.0 * std::numbers::pi;
}

Circle::Circle(Figure::dot first, double radius)
{   if (radius == 0 || radius < 0 ) {
        throw std::invalid_argument("Radius can't be negative or zero");
    } else {
        points_[0] = first;
        this->radius = radius;
    }
}

void Circle::parse(pt::ptree *obj) {
    pt::ptree circle_info;
    circle_info.put("radius",radius);
    parse_points(&circle_info,points_);
    obj->add_child("circle",circle_info);
}

void Circle::unparse(pt::ptree *obj) {
    this->radius = obj->get<double>("radius");
    unparse_points(obj,this->points_);
}

const std::vector<double> Circle::get_all_data() const
{
    std::vector<double> data;
    for(auto i: points_) {
        data.push_back(i.first);
        data.push_back(i.second);
    }
    data.push_back(radius);
    return data;
}



