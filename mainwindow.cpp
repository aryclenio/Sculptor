#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include "painter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Sculptor *s;
    s = new Sculptor(10,10,10);
    m = s->readMx();
    ui->widget->recMx(m);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

