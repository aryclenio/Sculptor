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

