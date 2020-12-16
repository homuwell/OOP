
#include "../include/Square.h"

void Square::fill(std::string points) {
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
    if (std::abs(tmp[1].first - tmp[0].first ) != std::abs(tmp[1].second - tmp[0].second ) ) {
        throw std::invalid_argument("Can't create square, invalid points");
    } else {
        points_ = std::make_unique<dot[]>(2);
        points_ = std::move(tmp);
        edge_len = std::abs(points_[1].first - points_[0].first );
    }
}

Square::Square(std::string points) {
    fill(points);
}

double Square::get_area() {
    return edge_len * edge_len;
}

double Square::get_perimeter() {
    return 4.0 * edge_len;
}

Square::~Square() {
    points_.reset();
}
