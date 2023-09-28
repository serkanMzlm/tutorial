#ifndef PROJECT_TYPE_H
#define PROJECT_TYPE_H

#include <QtQml>
#include <QtCore>
#include <QColor>
#include <QDebug>
#include <QObject>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

enum { ST_X, ST_Y, ST_ALL};
typedef union{
    struct{
      int x;
      int y;
    };
    int state[ST_ALL];
}Pos_t;

#endif // PROJECT_TYPE_H
