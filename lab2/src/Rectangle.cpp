//
// Created by homuwell on 12/7/20.
//

#include "../include/Rectangle.h"

void Rectangle::fill(std::string points) {
    std::stringstream ss(points);
    std::unique_ptr<dot[]> tmp;
    tmp = std::make_unique<dot[]>(2);
    double coord;
    for (auto i = 0; i < 2; ++i) {
        ss >> coord;
        tmp[i].first = coord;
        ss >> coord;
        tmp[i].second = coord;
    }
    if (tmp[1].first == tmp[0].first || tmp[1].second == tmp[2].second ) {
        throw std::invalid_argument("Can't create rectangle, invalid points");
    } else {
        points_ = std::make_unique<dot[]>(2);
        points_ = std::move(tmp);
        first_edge_len = std::abs(points_[1].first - points_[0].first );
        second_edge_len = std::abs(points_[1].second - points_[0].second );
    }
}

Rectangle::Rectangle(std::string points) {
    fill(points);
}

double Rectangle::get_area() {
    return first_edge_len * second_edge_len;
}

double Rectangle::get_perimeter() {
    return 2 * (first_edge_len + second_edge_len);
}
