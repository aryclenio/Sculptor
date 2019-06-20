#include "planedialog.h"
#include "ui_planedialog.h"

planeDialog::planeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::planeDialog)
{
  ui->setupUi(this);
}

planeDialog::~planeDialog()
{
  delete ui;
}

int planeDialog::getX()
{
  return ui->horizontalSliderR->value();
}

int planeDialog::getY()
{
  return ui->horizontalSliderG->value();
}

int planeDialog::getZ()
{
  return ui->horizontalSliderB->value();
}
