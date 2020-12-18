#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H
#include "Figure.h"
class Triangle : public Figure {
private:
    double FirstSecond, SecondThird, FirstThird;
    std::array<dot,3> points_;
public:
    Triangle() = default;
    Triangle(dot first,dot second, dot third);
    double get_area() override;
    double get_first_second();
    double get_second_third();
    double get_first_third();
    double get_perimeter() override;
    void parse(pt::ptree * obj) override;
    void unparse(pt::ptree *obj) override;
    const std::vector<double> get_all_data() const  override;
};
#endif //OOP_TRIANGLE_H
