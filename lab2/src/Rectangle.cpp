#include "../include/Rectangle.h"

Rectangle::Rectangle(Figure::dot first, Figure::dot second)
{
    if (second.first == first.first || second.second == first.second || first == second ) {
        throw std::invalid_argument("Can't create rectangle, invalid points");
    } else {
        points_[0] = first;
        points_[1] = second;
        first_edge_len = std::abs(points_[1].first - points_[0].first );
        second_edge_len = std::abs(points_[1].second - points_[0].second );
    }
}

double Rectangle::get_area() {
    return first_edge_len * second_edge_len;
}

double Rectangle::get_perimeter() {
    return 2 * (first_edge_len + second_edge_len);
}

void Rectangle::parse(pt::ptree *obj) {
    pt::ptree rectanlge_info;
    rectanlge_info.put("first_edge_len",first_edge_len);
    rectanlge_info.put("second_edge_len",second_edge_len);
    parse_points(&rectanlge_info,points_);
    obj->add_child("rectangle",rectanlge_info);
}

void Rectangle::unparse(pt::ptree *obj) {
    this->first_edge_len = obj->get<double>("first_edge_len");
    this->second_edge_len = obj->get<double>("second_edge_len");
    unparse_points(obj,this->points_);
}

const std::vector<double> Rectangle::get_all_data() const
{
    std::vector<double> data;
    for(auto i: points_) {
        data.push_back(i.first);
        data.push_back(i.second);
    }
    data.push_back(first_edge_len);
    data.push_back(second_edge_len);
    return data;
}
