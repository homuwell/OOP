#ifndef CREATERECTANGLE_H
#define CREATERECTANGLE_H

#include <QWidget>

namespace Ui {
class createRectangle;
}

class createRectangle : public QWidget
{
    Q_OBJECT

public:
    explicit createRectangle(QWidget *parent = nullptr);
    ~createRectangle();

private:
    Ui::createRectangle *ui;
};

#endif // CREATERECTANGLE_H
