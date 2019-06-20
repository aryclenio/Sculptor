#include "setsize.h"
#include "ui_setsize.h"

Setsize::Setsize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setsize)
{
    ui->setupUi(this);
}

Setsize::~Setsize()
{
    delete ui;
}
