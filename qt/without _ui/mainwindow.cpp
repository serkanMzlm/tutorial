#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    h_box->addWidget(button1);
    layout->addWidget(label, 0,0);
    layout->addWidget(line, 0,1);
    window->setLayout(layout);
}

MainWindow::~MainWindow(){
    delete window;
    delete button1;
    delete h_box;
    delete layout;
    delete label;
    delete line;
}

