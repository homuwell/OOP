#include "createsquare.h"
#include "ui_createsquare.h"
using dot = std::pair<double,double>;
CreateSquare::CreateSquare(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateSquare)
{
    ui->setupUi(this);
}

CreateSquare::~CreateSquare()
{
    delete ui;
}

void CreateSquare::on_pushButton_clicked()
{
    dot first = std::make_pair(ui->x1_square->displayText().split(" ")[0].toDouble(),ui->y1_square->displayText().split(" ")[0].toDouble());
     dot second = std::make_pair(ui->x2_square->displayText().split(" ")[0].toDouble(),ui->y2_square->displayText().split(" ")[0].toDouble());
    emit data_square(first,second);
    this->close();
}
