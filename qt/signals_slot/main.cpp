#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <iostream>

#include "radio.h"
#include "station.h"

#define SIZE 5

bool is_connect = false;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Radio radio;
    Station* channels[SIZE];

    channels[0] = new Station(&radio, 45, "One");
    channels[1] = new Station(&radio, 48, "Apple");
    channels[2] = new Station(&radio, 96, "Shutdown");
    channels[3] = new Station(&radio, 95, "Top");
    channels[4] = new Station(&radio, 55, "Back");

    radio.connect(&radio, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);

    std::string input;
    do{
        qInfo() << "Enter \"on, off, quit, test\"";
        std::cin >> input;
        QString line =  QString::fromStdString(input).toUpper();
        qInfo() << line;
        if(line == "ON" && !is_connect){
            qInfo() << "Turning the radio on";
            for(int i = 0; i < SIZE; i++){
                Station* channel = channels[i];
                radio.connect(channel, &Station::send, &radio, &Radio::listen);
            }
            is_connect = true;
        }else if(line == "OFF" && is_connect){
            qInfo() << "Turning the radio off";
            for(int i = 0; i < SIZE; i++){
                Station* channel = channels[i];
                radio.disconnect(channel, &Station::send, &radio, &Radio::listen);
            }
            is_connect = false;
        }else if(line == "TEST"){
            qInfo() << "Test";
            for(int i = 0; i < SIZE; i++){
                channels[i]->broadcast("Broadcasting...");
            }
        }else if(line == "QUIT"){
            qInfo() << "Quitting";
            emit radio.quit();
            break;
        }else{
            qInfo() << "Try Again";
        }
    }while(true);

    return a.exec();
}
