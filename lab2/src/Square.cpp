
#include "../include/Square.h"

Square::Square(dot first, dot second)
{
    if (std::abs(second.first - first.first ) != std::abs(second.second - first.second ) ) {
        throw std::invalid_argument("Can't create square, invalid points");
    } else {
        points_[0] = first;;
        points_[1] = second;
        edge_len = points_[1].first - points_[0].first;
    }
}

double Square::get_area() {
    return edge_len * edge_len;
}

double Square::get_perimeter() {
    return 4.0 * edge_len;
}

void Square::parse(pt::ptree *obj) {
    pt::ptree square_info;
    pt::ptree all_arr;
    square_info.put("edge_len",edge_len);
    parse_points(&square_info,points_);
    obj->add_child("square",square_info);
}

void Square::unparse(pt::ptree *obj) {
    this->edge_len = obj->get<double>("edge_len");
    unparse_points(obj,this->points_);
}

const std::vector<double> Square::get_all_data() const
{
    std::vector<double> data;
    for(auto i: points_) {
        data.push_back(i.first);
        data.push_back(i.second);
    }
    data.push_back(edge_len);
    return data;

}
