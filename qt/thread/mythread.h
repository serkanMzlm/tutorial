#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QtCore>

class myThread: public QThread
{

public:
    myThread();
    void run();
    QString name;
    QMutex _mutex;
    bool stop;
};

#endif // MYTHREAD_H
