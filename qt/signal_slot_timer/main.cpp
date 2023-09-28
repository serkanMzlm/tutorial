#include <QCoreApplication>
#include "timer.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    timer __timer;
    return a.exec();
}
