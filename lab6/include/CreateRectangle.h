#ifndef CREATERECTANGLE_H
#define CREATERECTANGLE_H

#include <QWidget>
using dot = std::pair<double,double>;
namespace Ui {
class CreateRectangle;
}

class CreateRectangle : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRectangle(QWidget *parent = nullptr);
    ~CreateRectangle();

private slots:
    void on_pushButton_clicked();
signals:
    void data_rectangle(dot first,dot second);
private:
    Ui::CreateRectangle *ui;
};

#endif // CREATERECTANGLE_H
