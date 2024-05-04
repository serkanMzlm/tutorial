#ifndef RADIO_H
#define RADIO_H

#include <QObject>
#include <QDebug>

class Radio : public QObject
{
    Q_OBJECT
public:
    explicit Radio(QObject *parent = nullptr);

public slots:
    void listen(int channel, QString name, QString message);

signals:
    void quit();
};

#endif // RADIO_H
