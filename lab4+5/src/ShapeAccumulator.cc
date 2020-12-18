

#include "../include/ShapeAccumulator.h"

Figure *ShapeAccumulator::get_max_area() const {
    return min_max_area_.second;
}

Figure *ShapeAccumulator::get_min_area() const {
    return min_max_area_.first;
}

Figure *ShapeAccumulator::get_max_perimeter() const {
    return min_max_perimeter_.second;
}

Figure *ShapeAccumulator::get_min_perimeter() const {
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

void ShapeAccumulator::AddAll(const std::vector<Figure *>& figures) {
    for(auto & figure : figures) {
        add(figure);
    }
}

double ShapeAccumulator::get_all_area() const{
    return all_area_;
}

double ShapeAccumulator::get_all_perimeter() const{
    return all_perimeter_;
}

void ShapeAccumulator::parse(std::string file_name) {
    std::fstream file;
    file.open(file_name,std::ios_base::out);
    if(file.fail()) {
        throw std::invalid_argument("Can't open file");
    }
    pt::ptree json_obj;
    for(auto i: figures_) {
        i->parse(&json_obj);
    }
    pt::write_json(file,json_obj);
}

void ShapeAccumulator::unparse(std::string file_name) {
    std::fstream file;
    file.open(file_name,std::ios_base::in);
    if(file.fail()) {
        throw std::invalid_argument("Can't open file");
    }
    pt::ptree objects;
    pt::read_json(file,objects);
    if(objects.empty()) {
        throw std::invalid_argument("Incorrect JSON structure");
    }
    for(pt::ptree::const_iterator iter = objects.begin();iter != objects.end(); ++iter) {
        if(iter->first == "circle") {
            Circle* circle( new Circle);
            pt::ptree a;
            a = iter->second;
            circle->unparse(&a);
            this->add(circle);
        } else if(iter->first == "triangle") {
            Triangle* triangle(new Triangle);
            pt::ptree a;
            a = iter->second;
            triangle->unparse(&a);
            this->add(triangle);
        } else if(iter->first == "rectangle") {
            Rectangle* rectangle(new Rectangle);
            pt::ptree a;
            a = iter->second;
            rectangle->unparse(&a);
            this->add(rectangle);
        } else if(iter->first == "square") {
            Square* square(new Square);
            pt::ptree a;
            a = iter->second;
            square->unparse(&a);
            this->add(square);
        } else {
            throw std::invalid_argument("Invalid figure");
        }
    }
}

std::vector<Figure*>::const_iterator ShapeAccumulator::get_iterator()

{
    std::vector<Figure*>::const_iterator iter;

    iter = figures_.begin();
    return iter;
}

std::vector<Figure*>::const_iterator ShapeAccumulator::get_end()
{
    return figures_.cend();
}

void ShapeAccumulator::remove(std::size_t index)
{
    figures_.erase(figures_.begin() + index);
}

void ShapeAccumulator::swap(std::size_t first_index, std::size_t second_index)
{
    auto elem = figures_[first_index];
    figures_[first_index] = figures_[second_index];
    figures_[second_index] = elem;
}

