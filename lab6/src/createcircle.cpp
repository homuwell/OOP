#include "createcircle.h"
#include "ui_createcircle.h"

CreateCircle::CreateCircle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateCircle)
{
    ui->setupUi(this);
}

CreateCircle::~CreateCircle()
{
    delete ui;
}

void CreateCircle::on_pushButton_clicked()
{
    dot first = std::make_pair(ui->x1_circle->displayText().split(" ")[0].toDouble(),ui->y1_circle->displayText().split(" ")[0].toDouble());
    double radius = ui->radius->displayText().split(" ")[0].toDouble();
    emit data_circle(first,radius);
    this->close();
}
