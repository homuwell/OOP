#ifndef CREATECIRCLE_H
#define CREATECIRCLE_H

#include <QWidget>
using dot = std::pair<double,double>;
namespace Ui {
class CreateCircle;
}

class CreateCircle : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCircle(QWidget *parent = nullptr);
    ~CreateCircle();

private slots:
    void on_pushButton_clicked();
signals:
    void data_circle(dot first, double radius);


private:
    Ui::CreateCircle *ui;
};

#endif // CREATECIRCLE_H
