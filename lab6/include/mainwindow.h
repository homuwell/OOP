#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<ShapeAccumulator.h>
#include <QMainWindow>
#include <QMessageBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using dot = std::pair<double,double>;
class MainWindow : public QMainWindow
{
    Q_OBJECT
     ShapeAccumulator collection;

public:
     MainWindow(QWidget *parent = nullptr);
    void fill_figures();
    void put_trirange(std::vector<double> arr);
      void put_rectangle(std::vector<double> arr);
    void put_circle(std::vector<double> arr);
      void put_square(std::vector<double> arr);
    ~MainWindow();
      void closeEvent(QCloseEvent *event);
public slots:
    void triangle_created(dot first,dot second, dot third);
    void square_created(dot first, dot second);
    void circle_created(dot first, double radius);
    void rectangle_created(dot first, dot second);

private slots:
    void on_Delete_clicked();

    void on_Triange_clicked();

    void on_Circle_clicked();

    void on_Square_clicked();

    void on_Rectangle_clicked();

    void on_moveUp_clicked();
    
    void on_moveDown_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
