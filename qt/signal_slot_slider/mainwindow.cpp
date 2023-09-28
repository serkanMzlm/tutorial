#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("close");

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
        ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

