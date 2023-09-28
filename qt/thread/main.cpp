#include <QCoreApplication>
#include "mythread.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    myThread thread1;
    myThread thread2;
    myThread thread3;
    thread1.name = "thread1";
    thread2.name = "thread2";
    thread3.name = "thread3";

    thread1.start(QThread::HighestPriority);
    thread2.start();
    thread3.start();
//    thread3.start(QThread::LowestPriority);
//    for(int i=0; i<100; i++)
//    {
//       qDebug() << "deneme";
//    }
//    thread1.stop = true;


    return a.exec();
}
