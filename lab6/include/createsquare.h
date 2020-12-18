#ifndef CREATESQUARE_H
#define CREATESQUARE_H

#include <QWidget>
using dot = std::pair<double,double>;
namespace Ui {
class CreateSquare;
}

class CreateSquare : public QWidget
{
    Q_OBJECT

public:
    explicit CreateSquare(QWidget *parent = nullptr);
    ~CreateSquare();

private slots:
    void on_pushButton_clicked();
signals:
    void data_square(dot first,dot second);
private:
    Ui::CreateSquare *ui;
};

#endif // CREATESQUARE_H
