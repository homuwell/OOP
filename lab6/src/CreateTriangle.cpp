#include "CreateTriangle.h"
#include "ui_CreateTriangle.h"
#include <QString>
createTriangle::createTriangle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTriangle)
{
    ui->setupUi(this);
}

createTriangle::~createTriangle()
{
    delete ui;
}

void createTriangle::on_pushButton_clicked()
{
    dot first = std::make_pair(ui->x1->displayText().split(" ")[0].toDouble(),ui->y1->displayText().split(" ")[0].toDouble());
    dot second = std::make_pair(ui->x2->displayText().split(" ")[0].toDouble(),ui->y2->displayText().split(" ")[0].toDouble());
    dot third = std::make_pair(ui->x3->displayText().split(" ")[0].toDouble(),ui->y3->displayText().split(" ")[0].toDouble());
    emit data_triangle(first, second, third);
    this->close();
}
