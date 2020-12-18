#include "../include/Triangle.h"

Triangle::Triangle(dot first,dot second, dot third)
{
    if(first == second || first == third || second == third) {
        throw std::invalid_argument("Points can't be equal");
    }
    auto side1 = get_length(first,second);
    auto side2 = get_length(first,third);
    auto side3 = get_length(second,third);
    if (side1 + side2 < side3 || side2 + side3 < side1 || side3+side1 < side2) {
        throw std::invalid_argument("These points do not define a triangle");
    }
    points_[0] = first;
    points_[1] = second;
    points_[2] = third;
    FirstSecond = side1;
    FirstThird = side2;
    SecondThird = side3;
}

double Triangle::get_area() {
    double p = get_perimeter() / 2;
    return std::sqrt(p * (p - FirstSecond) * (p - FirstThird) * (p - SecondThird));
}

double Triangle::get_first_second()
{
    return FirstSecond;
}

double Triangle::get_second_third()
{
    return SecondThird;
}

double Triangle::get_first_third()
{
    return FirstThird;
}



double Triangle::get_perimeter() {
    return FirstSecond + FirstThird + SecondThird;
}

void Triangle::parse(pt::ptree *obj) {
    pt::ptree triangle_info;
    triangle_info.put("FirstSecond",FirstSecond);
    triangle_info.put("FirstThird",FirstThird);
    triangle_info.put("SecondThird",SecondThird);
    parse_points(&triangle_info,points_);
    obj->add_child("triangle",triangle_info);

}

void Triangle::unparse(pt::ptree *obj) {
    this->FirstSecond = obj->get<double>("FirstSecond");
    this->FirstThird = obj->get<double>("FirstThird");
    this->SecondThird = obj->get<double>("SecondThird");
    unparse_points(obj,this->points_);
}

const std::vector<double> Triangle::get_all_data() const
{
    std::vector<double> data;
    for(auto i: points_) {
        data.push_back(i.first);
        data.push_back(i.second);
    }
    data.push_back(FirstSecond);
    data.push_back(FirstThird);
    data.push_back(SecondThird);
    return data;
}