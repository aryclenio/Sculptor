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

    connect(ui->putVoxel,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(1)));
    connect(ui->cutVoxel,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(2)));
    connect(ui->putBox,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(3)));
    connect(ui->cutBox,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(4)));
    connect(ui->putEllipsoid,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(5)));
    connect(ui->cutEllipsoid,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(6)));
    connect(ui->putSphere,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(7)));
    connect(ui->cutSphere,
              SIGNAL(clicked(bool)),
              this,
              SLOT(shape(8)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changePlane1() //XY
{
    ui->widget->pl = 1;
    emit ui->widget->planeChosen(1);
}
void MainWindow::changePlane2() //XZ
{
    ui->widget->pl = 2;
    emit ui->widget->planeChosen(2);
}
void MainWindow::changePlane3() //YZ
{
    ui->widget->pl = 3;
    emit ui->widget->planeChosen(3);
}

void MainWindow::pVoxel() //PV
{
    ui->widget->sh = 1;
}
void MainWindow::cVoxel() //CV
{
    ui->widget->sh = 2;
}
void MainWindow::pBox() //PB
{
    ui->widget->sh = 3;
}
void MainWindow::cBox() //CB
{
    ui->widget->sh= 4;
}
void MainWindow::pShpere() //PS
{
    ui->widget->sh = 5;
}
void MainWindow::cShpere() //CS
{
    ui->widget->sh = 6;
}
void MainWindow::pEllip() //PE
{
    ui->widget->sh = 7;
}
void MainWindow::cEllip() //PS
{
    ui->widget->sh= 8;
}
