#ifndef CREATERECTANGLE_H
#define CREATERECTANGLE_H

#include <QWidget>
using dot = std::pair<double,double>;
namespace Ui {
class CreateTriangle;
}

class createTriangle : public QWidget
{
    Q_OBJECT

public:
    explicit createTriangle(QWidget *parent = nullptr);
    ~createTriangle();

private slots:
    void on_pushButton_clicked();
signals:
    void data_triangle(dot first,dot second, dot third);

private:
    Ui::CreateTriangle *ui;
};

#endif // CREATERECTANGLE_H
