#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ShapeAccumulator.h"
#include "CreateTriangle.h"
#include "createcircle.h"
#include "createsquare.h"
#include "newrectangle.h"
#include <QStringListModel>
#include <QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::fill_figures()
{
    collection.unparse("/home/homuwell/GUI_lab/out");
    for(auto iter = collection.get_iterator(); iter < collection.get_end();iter++)
    {
        const std::vector<double> arr = (*iter)->get_all_data();
        switch(arr.size()) {
        case 3:
            put_circle(arr);
            break;
        case 5:
            put_square(arr);
            break;
        case 6:
            put_rectangle(arr);
            break;
        case 9:
            put_trirange(arr);
            break;
        }
    }
}

void MainWindow::put_trirange(std::vector<double> arr)
{
    QString str;
    str.append("Triangle: ");
    str.append("(");
    str.append(QString::number( arr[6]));
    str.append(" ");
     str.append(QString::number(arr[7]));
     str.append(" ");
     str.append(QString::number(arr[8]));
      str.append(")");
    ui->field->addItem(str);
}

void MainWindow::put_rectangle(std::vector<double> arr)
{
    QString str;
    str.append("Rectangle: ");
    str.append("(");
    str.append(QString::number( arr[4]));
    str.append(" ");
     str.append(QString::number(arr[5]));
      str.append(")");
    ui->field->addItem(str);
}

void MainWindow::put_circle(std::vector<double> arr)
{
    QString str;
    str.append("Circle: ");
    str.append("(");
    str.append(QString::number( arr[2]));
    str.append(")");
    ui->field->addItem(str);
}

void MainWindow::put_square(std::vector<double> arr)
{
    QString str;
    str.append("Square: ");
    str.append("(");
    str.append(QString::number( arr[4]));
    str.append(")");
    ui->field->addItem(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText("Do you want to save current state of collection?");
    msgBox.setWindowTitle("Save File");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No );
    msgBox.setDefaultButton(QMessageBox::No);
    int res = msgBox.exec();
    if (res == QMessageBox::Yes) {
        collection.parse("/home/homuwell/GUI_lab/out");
    }
}

void MainWindow::triangle_created(dot first, dot second, dot third)
{
   Triangle* triangle = new Triangle(first,second,third);
   put_trirange(triangle->get_all_data());
   collection.add(triangle);
}

void MainWindow::square_created(dot first, dot second)
{
    Square * square = new Square(first, second);
    put_square(square->get_all_data());
    collection.add(square);
}

void MainWindow::circle_created(dot first, double radius)
{
    Circle * circle = new Circle(first,radius);
    put_circle(circle->get_all_data());
    collection.add(circle);
}

void MainWindow::rectangle_created(dot first, dot second)
{
    Rectangle * rectangle = new Rectangle(first,second);
    put_rectangle(rectangle->get_all_data());
    collection.add(rectangle);
}


void MainWindow::on_Delete_clicked()
{
    auto elems = ui->field;
    for(auto i=0; i < elems->count();++i    )
        if(elems->item(i)->isSelected()) {
            delete elems->item(i);
            collection.remove(i);
    }
}

void MainWindow::on_Triange_clicked()
{
   createTriangle *triangle = new createTriangle();
   triangle->setWindowTitle("Add triangle");
   triangle->show();
   connect(triangle, &createTriangle::data_triangle, this, &MainWindow::triangle_created);
}

void MainWindow::on_Circle_clicked()
{
    CreateCircle * circle = new CreateCircle();
    circle->setWindowTitle("Add circle");
    circle->show();
     connect(circle, &CreateCircle::data_circle, this, &MainWindow::circle_created);
}

void MainWindow::on_Square_clicked()
{
    CreateSquare* square = new CreateSquare();
    square->setWindowTitle("Add Square");
    square->show();
    connect(square, &CreateSquare::data_square, this, &MainWindow::square_created);
}

void MainWindow::on_Rectangle_clicked()
{
    newRectangle* rectangle = new newRectangle;
    rectangle->setWindowTitle("Add Rectangle");
    rectangle->show();
    connect(rectangle, &newRectangle::data_rectangle, this, &MainWindow::rectangle_created);
}

void MainWindow::on_moveUp_clicked()
{
    int currRow = ui->field->currentRow();
     if(currRow > 0){
         QListWidgetItem tmp = *(ui->field->currentItem());
         int upRow = currRow - 1;

         *(ui->field->item(currRow)) = *(ui->field->item(upRow));
         *(ui->field->item(upRow)) = tmp;
         ui->field->setCurrentRow(upRow);
         ui->field->setCurrentItem(ui->field->item(upRow));
         ui->field->setFocus();
         collection.swap(currRow,upRow);
     }

}

void MainWindow::on_moveDown_clicked()
{
    int currRow = ui->field->currentRow();
     if(currRow < ui->field->count() - 1){
         QListWidgetItem tmp = *(ui->field->currentItem());
         int downRow = currRow + 1;

         *(ui->field->item(currRow)) = *(ui->field->item(downRow));
         *(ui->field->item(downRow)) = tmp;
         ui->field->setCurrentItem(ui->field->item(downRow));
         ui->field->setFocus();
         collection.swap(currRow,downRow);
     }
}
