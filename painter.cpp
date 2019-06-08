#include "painter.h"
#include "sculptor.h"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <QBrush>
vector<vector<Voxel>> a;
Painter::Painter(QWidget *parent) : QWidget(parent)
{

}
void Painter::recMx(vector<vector<Voxel>> m){
    a = m;

}
void Painter::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(255,255,255));
    pen.setWidth(2);
      // entregando a caneta ao pintor
    pa.setPen(pen);
    brush.setColor(QColor(0,0,0));
    brush.setStyle(Qt::SolidPattern);
      // entregando o pincel ao pintor
    pa.setBrush(brush);

    float dim1 = width()/10;
    float dim2 = height()/10;

    for(int i =0; i<width(); i++){
        for(int j =0; j<height(); j++){
            pa.drawRect(i,j,dim1, dim2);

    }

}
}
