#ifndef STATION_H
#define STATION_H

#include <QObject>

class Station : public QObject
{
    Q_OBJECT
private:
    int channel;
    QString name;
public:
    explicit Station(QObject *parent = nullptr, int channel = 0 ,QString name = "unknown");

signals:
    void send(int channel, QString name, QString message);

public slots:
    void broadcast(QString message);
};

#endif // STATION_H
