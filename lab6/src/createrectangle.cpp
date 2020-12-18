#include "createrectangle.h"
#include "ui_createrectangle.h"

createRectangle::createRectangle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createRectangle)
{
    ui->setupUi(this);
}

createRectangle::~createRectangle()
{
    delete ui;
}
