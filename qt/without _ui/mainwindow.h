#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QWidget* window   = new QWidget(this);
    QPushButton* button1 = new QPushButton("button1", this);
    QHBoxLayout* h_box   = new QHBoxLayout;
    QGridLayout* layout   = new QGridLayout(this);
    QLabel* label = new QLabel;
    QLineEdit* line = new QLineEdit;
};
#endif // MAINWINDOW_H
