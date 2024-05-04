#include "station.h"

Station::Station(QObject *parent, int channel ,QString name):
    QObject{parent}, channel{channel}, name(name)
{

}

void Station::broadcast(QString message)
{
    emit send(channel, name, message);
}

