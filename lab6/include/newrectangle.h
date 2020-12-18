#ifndef NEWRECTANGLE_H
#define NEWRECTANGLE_H

#include <QWidget>
using dot = std::pair<double,double>;
namespace Ui {
class newRectangle;
}

class newRectangle : public QWidget
{
    Q_OBJECT

public:
    explicit newRectangle(QWidget *parent = nullptr);
    ~newRectangle();

private slots:
    void on_pushButton_clicked();
signals:
    void data_rectangle(dot first, dot second);
private:
    Ui::newRectangle *ui;
};

#endif // NEWRECTANGLE_H
