#include "CreateRectangle.h"
#include "ui_CreateRectangle.h"
using dot = std::pair<double,double>;
CreateRectangle::CreateRectangle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateRectangle)
{
    ui->setupUi(this);
}

CreateRectangle::~CreateRectangle()
{
    delete ui;
}

void CreateRectangle::on_pushButton_clicked()
{
    dot first = std::make_pair(ui->x1_rectangle->displayText().split(" ")[0].toDouble(),ui->y1_rectangle->displayText().split(" ")[0].toDouble());
     dot second = std::make_pair(ui->x2_rectangle->displayText().split(" ")[0].toDouble(),ui->y2_rectangle->displayText().split(" ")[0].toDouble());
    emit data_rectangle(first,second);
    this->close();
}
