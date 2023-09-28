#include "timer.h"


timer::timer()
{
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(mySlot()));
    _timer->start(1000);
}

void timer::mySlot()
{
    qDebug()<<"timer ...";

}
