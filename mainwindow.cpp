#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "planedialogo.h"
#include "sculptor.h"
#include "painter.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->redSlider->setMaximum(255);
    ui->BlueSlider->setMaximum(255);
    ui->greenSlider->setMaximum(255);
    ui->aSlider->setMaximum(255);
    ui->sliderX->setMaximum(ui->widget->sx-1);
    ui->sliderY->setMaximum(ui->widget->sy-1);
    ui->sliderZ->setMaximum(ui->widget->sz-1);
    ui->sphereSlider->setMaximum(ui->widget->sx/2 -1);
    ui->xSlider->setMaximum(ui->widget->sx/2 -1);
    ui->ySlider->setMaximum(ui->widget->sy/2 -1);
    ui->zSlider->setMaximum(ui->widget->sz/2 -1);
    ui->sliderSlice->setMaximum(ui->widget->sz -1);
    connect(ui->sliderSlice,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeSlice(int)));
    connect(ui->putVoxel,
            SIGNAL(clicked(bool)),
            this,
            SLOT(pVoxel()));
    connect(ui->cutVoxel,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cVoxel()));
    connect(ui->putBox,
            SIGNAL(clicked(bool)),
            this,
            SLOT(pBox()));
    connect(ui->cutBox,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cBox()));
    connect(ui->putEllipsoid,
            SIGNAL(clicked(bool)),
            this,
            SLOT(pShpere()));
    connect(ui->cutEllipsoid,
            SIGNAL(clicked(bool)),
            this,
            SLOT(cShpere()));
    connect(ui->putSphere,
            SIGNAL(clicked(bool)),
            this,
            SLOT(pEllip()));
    connect(ui->cutSphere,
            SIGNAL(clicked(bool)),
            this, //esta this porque eu estou falando da mainwindow
            SLOT(cEllip()));
    connect(ui->redSlider,
            SIGNAL(valueChanged(int)),
            ui->widget, //aqui é onde eu vou mandar
            SLOT(changeRed(int)));
    connect(ui->BlueSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeBlue(int)));
    connect(ui->greenSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeGreen(int)));
    connect(ui->aSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeAlpha(int)));
    connect(ui->sliderX,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeDimx(int)));
    connect(ui->sliderY,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeDimy(int)));
    connect(ui->sliderZ,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeDimz(int)));
    connect(ui->sphereSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeRad(int)));
    connect(ui->xSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeRx(int)));
    connect(ui->ySlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeRy(int)));
    connect(ui->zSlider,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(changeRz(int)));
    connect(ui->btXY,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeXY()));

    connect(ui->btYZ,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeYZ()));

    connect(ui->btZX,
            SIGNAL(clicked(bool)),
            this,
            SLOT(changeZX()));
    connect(ui->actionExport_off_File,
            SIGNAL(triggered(bool)),
            ui->widget,
            SLOT(Off()));
    connect(ui->actionExport_vect_File,
            SIGNAL(triggered(bool)),
            ui->widget,
            SLOT(Vect()));
    connect(ui->actionCreate_Plane,
            SIGNAL(triggered(bool)),
            this,
            SLOT(selectPlane()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::selectPlane(){
      QMessageBox box;
      QString msg;
      PlaneDialogo dialog;

      if(dialog.exec() == QDialog::Accepted){
        msg = "r = <b>"+QString::number(dialog.getX())+
            "</b> <br>"+
            "g = <b>"+QString::number(dialog.getY())+
            "</b> <br>"+
            "b = <b>"+QString::number(dialog.getZ())+
            "</b>";
        box.setText(msg);
        box.exec();
      }
      ui->widget->s->~Sculptor();
      ui->widget->sx = dialog.getX();
      ui->widget->sy = dialog.getY();
      ui->widget->sz = dialog.getZ();
      ui->widget->s = new Sculptor(ui->widget->sx,ui->widget->sy,ui->widget->sz);
      ui->widget->repaint();
}
void MainWindow::changeXY() //XY
{
    ui->widget->pl = XY;
    emit ui->widget->planeChosen(XY);
    ui->widget->dim = ui->widget->sz/2;
    ui->sliderSlice->setMaximum(ui->widget->sz -1);
    ui->widget->repaint();
}
void MainWindow::changeYZ() //YZ
{
    ui->widget->pl = YZ;
    emit ui->widget->planeChosen(YZ);
    ui->widget->dim = ui->widget->sx/2;
    ui->sliderSlice->setMaximum(ui->widget->sx -1);
    ui->widget->repaint();
}
void MainWindow::changeZX()
{
    ui->widget->pl = ZX;
    emit ui->widget->planeChosen(ZX);
    ui->widget->dim = ui->widget->sy/2;
    ui->sliderSlice->setMaximum(ui->widget->sy -1);
    ui->widget->repaint();
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
