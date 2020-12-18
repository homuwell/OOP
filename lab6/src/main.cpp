#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QtGui>
#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Figure Collector");
    w.fill_figures();
    w.show();
    return a.exec();
}
