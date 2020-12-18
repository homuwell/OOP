
#ifndef OOP_FIGURE_H
#define OOP_FIGURE_H
#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <numbers>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
namespace pt = boost::property_tree;
class Figure {
protected:
#include <vector>
    using dot = std::pair<double,double>;
    template<size_t N>
    void parse_points(pt::ptree *obj,std::array<dot,N> arr);
    template<size_t N>
    void unparse_points(pt::ptree *obj,std::array<dot,N>& arr);
    double get_length(dot frst, dot scnd) {
        return std::sqrt(std::pow((frst.first - scnd.first),2) + std::pow((frst.second - scnd.second),2));
    }
public:
    virtual double get_perimeter() = 0;
    virtual double get_area() = 0;
    virtual void parse(pt::ptree *obj) = 0;
    virtual  void unparse(pt::ptree *obj) = 0;
    virtual const std::vector<double> get_all_data() const = 0;
};


template<size_t N>
void Figure::parse_points(pt::ptree *obj, std::array<dot,N> arr) {
    pt::ptree all_arr;
    for(auto i = 0; i <N; ++i) {
        pt::ptree points_arr;
        for(auto j = 0; j < 2; ++j) {
            pt::ptree point_arr;
            j == 0 ? point_arr.put_value(arr[i].first) : point_arr.put_value(arr[i].second);
            points_arr.push_back(std::make_pair("",point_arr));
        }
        all_arr.push_back(std::make_pair("",points_arr));
    }
    obj->add_child("points_arr",all_arr);
}

template<size_t N>
void Figure::unparse_points(pt::ptree *obj, std::array<dot, N>& arr) {
    auto i = 0, j = 0;
    for(pt::ptree::value_type &point : obj->get_child("points_arr")) {
        for(pt::ptree::value_type &dot : point.second) {
            j == 0 ? arr[i].first = dot.second.get_value<double>() : arr[i].second = dot.second.get_value<double>();
            ++j;
        }
        j = 0;
        ++i;
    }
}

#endif //OOP_FIGURE_H
