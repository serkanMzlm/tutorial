#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

QString str = "ilk konsol uygulmasi";

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << str;
    w.show();
    return a.exec();
}
