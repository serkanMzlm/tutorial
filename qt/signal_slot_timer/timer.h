#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
#include <QtDebug>

class timer : public QObject
{
    Q_OBJECT
public:
    timer();
    QTimer* _timer;

public slots:
    void mySlot();

};



#endif // TIMER_H
