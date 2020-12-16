

#include "../include/ShapeAccumulator.h"

Figure *ShapeAccumulator::get_max_area() {
    return min_max_area_.second;
}

Figure *ShapeAccumulator::get_min_area() {
    return min_max_area_.first;
}

Figure *ShapeAccumulator::get_max_perimeter() {
    return min_max_perimeter_.second;
}

Figure *ShapeAccumulator::get_min_perimeter() {
    return min_max_area_.first;
}

void ShapeAccumulator::add(Figure *figure) {
    all_area_ += figure->get_area();
    all_perimeter_ += figure->get_perimeter();
    if (figures_.empty()) {
        min_max_area_ = std::make_pair(figure,figure);
        min_max_perimeter_ = std::make_pair(figure,figure);
        figures_.push_back(figure);
        return;
    }
    if (figure->get_perimeter() < min_max_area_.first->get_perimeter()) {
        min_max_area_.first = figure;
    } else if (figure->get_perimeter() > min_max_area_.second->get_perimeter()) {
        min_max_area_.second = figure;
    }
    if (figure->get_perimeter() < min_max_perimeter_.first->get_perimeter()) {
        min_max_perimeter_.first = figure;
    } else if (figure->get_perimeter() > min_max_perimeter_.second->get_perimeter()) {
        min_max_perimeter_.second = figure;
    }
    figures_.push_back(figure);
}

void ShapeAccumulator::AddAll(std::vector<Figure *> figures) {
    for(auto i = 0; i < figures.size(); i++) {
        add(figures[i]);
    }
}

double ShapeAccumulator::get_all_area() {
    return all_area_;
}

double ShapeAccumulator::get_all_perimeter() {
    return all_perimeter_;
}
