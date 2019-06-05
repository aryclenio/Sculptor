#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Sculptor *s;
    s = new Sculptor(10,10,10);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

