
#ifndef OOP_CIRCLE_H
#define OOP_CIRCLE_H
#include "Figure.h"

class Circle : public Figure{
private:
    double radius;
    std::array<dot,1> points_;
public:
    Circle() = default;
    Circle(dot first, double radius);
    double get_area() override;
    double get_perimeter() override;
    void parse(pt::ptree *obj) override;
    void unparse(pt::ptree *obj) override;
    const std::vector<double> get_all_data() const  override;
};


#endif //OOP_CIRCLE_H
