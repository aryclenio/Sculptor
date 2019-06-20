#include "painter.h"
#include "sculptor.h"
#include <iostream>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QDebug>
#include <QColor>
Painter::Painter(QWidget *parent) : QWidget(parent)
{
    sx = 10; sy = 10; sz=10;
    s = new Sculptor(sx,sy,sz);
        dim=0; pl=XY;
        x=0; y=0; z=0; rad=0; rx=0;ry=0;rz=0;

        r = 0; g=0; b=0; a = 255;

        sh=1;
}

void Painter::paintEvent(QPaintEvent *event)
{
    QPainter pa(this);
    QPen pen;
    QBrush brush;
    pen.setColor(QColor(0,0,0));
    pen.setWidth(1);
    pa.setPen(pen);
    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);
    pa.setBrush(brush);
    p.clear();
    p = s->readMx(dim,pl);
    int dim1 = width()/p[0].size();
    int dim2 = height()/p.size();

    w = dim1;
    h = dim2;
    for(int i =0; i<width(); i= i+dim1){
        for(int j =0; j<height(); j = j+dim2){
            pa.drawRect(i,j,dim1,dim2);
    }
}

    for(int i=0; i<p.size();i++){
           for(int j=0; j<p[0].size();j++){
                if(p[i][j].isOn){
                    brush.setColor(QColor(p[i][j].r,p[i][j].g,p[i][j].b,p[i][j].a));
                    brush.setStyle(Qt::SolidPattern);
                    pa.setBrush(brush);
                    qDebug() << p[i][j].r <<p[i][j].g <<p[i][j].b;
                    int xcenter =i*dim1;
                    int ycenter =j*dim2;
                    pa.drawEllipse(xcenter,ycenter,dim1,dim2);
                }
           }
        }

}
void Painter::mouseReleaseEvent(QMouseEvent *event)
{
    if(!(event->button() == Qt::LeftButton)){
    press = false;
    }
}
void Painter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton ){
    emit clickX(event->x());
    emit clickY(event->y());
    press = true;
      mx = (event->x())/w;
      my = (event->y())/h;
    emit moveX(mx);
    emit moveY(my);

      if(pl == XY)
          {
              px=mx;
              py=my;
              pz=dim;
          }

          else if(pl == YZ)
          {
              py=mx;
              pz=my;
              px=dim;
          }

          else if(pl== ZX)
          {
              pz=mx;
              px=my;
              py=dim;
          }
      Painter::shape(sh);
  }
}
void Painter::shape(int sh)
{
    if(sh == 1)
    {
       s->setColor(r,g,b,a);
       s->putVoxel(px,py,pz);
    }
    if(sh == 2)
    {
       s->cutVoxel(px,py,pz);
    }
    if(sh == 3)
    {
        s->setColor(r,g,b,a);
        s->putBox(px,(px+x),py,(py+y),pz,(pz+z));

    }
    if(sh == 4)
    {
       s->cutBox(px,(px+x),py,(py+y),pz,(pz+z));
    }
    if(sh == 5)
    {
        s->setColor(r,g,b,a);
        s->putSphere(px,py,pz,rad);

    }
    if(sh == 6)
    {
       s->cutSphere(px,py,pz,rad);;
    }
    if(sh == 7)
    {
        s->setColor(r,g,b,a);
        s->putEllipsoid(px,py,pz,rx,ry,rz);

    }
    if(sh == 8)
    {
       s->cutEllipsoid(px,py,pz,rx,ry,rz);
    }
    repaint();
}

void Painter::changeRed(int red)
{
    r = red;
}
void Painter::changeGreen(int green)
{
    g = green;
}
void Painter::changeBlue(int blue)
{
    b= blue;
}
void Painter::changeAlpha(int alpha)
{
    a = alpha;
}


void Painter::changeDimx(int size)
{
    x=size;
}
void Painter::changeDimy(int size)
{
    y=size;
}
void Painter::changeDimz(int size)
{
    z=size;
}
void Painter::changeRad(int rd)
{
    rad=rd;
}
void Painter::changeRx(int radx)
{
    rx=radx;
}
void Painter::changeRy(int rady)
{
    ry=rady;
}
void Painter::changeRz(int radz)
{
    rz=radz;
}
void Painter::changeSlice(int pln)
{
    dim = pln;
    repaint();
}
void Painter::Vect(){
    s->writeVECT("C:/Users/ARY/Documents/GitHub/Sculptor/sculptor.vect");
}
void Painter::Off(){
    s->writeOFF("C:/Users/ARY/Documents/GitHub/Sculptor/sculptor.off");
}
