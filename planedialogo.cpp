#include "planedialogo.h"
#include "ui_planedialogo.h"

PlaneDialogo::PlaneDialogo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlaneDialogo)
{
    ui->setupUi(this);
}

PlaneDialogo::~PlaneDialogo()
{
    delete ui;
}

int PlaneDialogo::getX()
{
  return ui->xSlider->value();
}

int PlaneDialogo::getY()
{
  return ui->ySlider->value();
}

int PlaneDialogo::getZ()
{
  return ui->zSlider->value();
}
