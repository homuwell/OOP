#ifndef OOP_SQUARE_H
#define OOP_SQUARE_H
#include "Figure.h"

class Square : public Figure {
    double edge_len;
    std::array<dot,2> points_;
public:
    Square() = default;
    Square(dot first, dot second);
    double get_area() override;
    double get_perimeter() override;
    void parse(pt::ptree *obj) override;
    void unparse(pt::ptree *obj) override;
    const std::vector<double> get_all_data() const  override;
};


#endif //OOP_SQUARE_H
