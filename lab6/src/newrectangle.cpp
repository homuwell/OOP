#include "newrectangle.h"
#include "ui_newrectangle.h"

newRectangle::newRectangle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newRectangle)
{
    ui->setupUi(this);
}

newRectangle::~newRectangle()
{
    delete ui;
}

void newRectangle::on_pushButton_clicked()
{
    dot first = std::make_pair(ui->x1_rectangle->displayText().split(" ")[0].toDouble(),ui->y1_rectangle->displayText().split(" ")[0].toDouble());
     dot second = std::make_pair(ui->x2_rectangle->displayText().split(" ")[0].toDouble(),ui->y2_rectangle->displayText().split(" ")[0].toDouble());
    emit data_rectangle(first,second);
    this->close();
}
