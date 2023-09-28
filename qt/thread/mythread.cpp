#include "mythread.h"

myThread::myThread()
{

}

void myThread::run()
{
    for(int i=0; i<10; i++)
    {
        _mutex.lock();
        if( this->stop )
        {
            break;
        }
//        this->sleep(1);
        _mutex.unlock();
        qDebug() << this->name << i << " running...";
    }

}
