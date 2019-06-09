#include "painter.h"
#include "sculptor.h"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
vector<vector<Voxel>> a;
Painter::Painter(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
}
void Painter::recMx(vector<vector<Voxel>> m){
    a = m;

}
void Painter::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(0,0,0));
    pen.setWidth(2);
      // entregando a caneta ao pintor
    pa.setPen(pen);
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);
      // entregando o pincel ao pintor
    pa.setBrush(brush);

    int dim1 = width()/a[0].size();
    int dim2 = height()/a.size();

    for(int i =0; i<width(); i= i+dim1){
        for(int j =0; j<height(); j = j+dim2){
            pa.drawRect(i,j,dim1, dim2);
    }
}
    pa.drawPoint(mx,my);
}
void Painter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton ){
    emit clickX(event->x());
    emit clickY(event->y());
      mx = event->x();
      my = event->y();
  }
}
void Painter::shape(int s)
{
  sh = s;
  repaint();
}
