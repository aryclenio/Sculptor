#ifndef PAINTER_H
#define PAINTER_H
#include <iostream>
#include <QWidget>
#include <QWidget>
#include <QAction>
#include <QMouseEvent>
#include <QColor>
#include "vector"
#include "sculptor.h"
class Painter : public QWidget
{
    Q_OBJECT
public:
    explicit Painter(QWidget *parent = nullptr);
    ///An event that draws a matrix of blank cubes and paint then if they are ON.
    void paintEvent(QPaintEvent *event);
    ///An event that transforms a click of the mouse as an activator of the isOn property, depending of witch one of the 8 selected actions is activated.
    void mousePressEvent(QMouseEvent *event);
    ///An event to take care of actions if the mouse was released.
    void mouseReleaseEvent(QMouseEvent *event);
    ///The shape is numerated by one of the 8 actions, witch one will have your behaviour if the mouse is clicked.
    void shape(int sh);
    ///The default sculptor that is created when the application was opened for the first time.
    Sculptor *s;
    ///Shape of the draw, PutVoxel set as default.
    int sh = 1;
    ///Plane and Dimention selected by the radioButtom.
    int dim, pl;
    ///Sculptor size.
    int sx, sy, sz;
    ///Collors and transparency values.
    int r, g, b, a;
    ///Radius of the sphere and the ellipsoid.
    int rad, rx, ry,rz;
    ///Box values.
    int x,y,z;
    ///Size of the 2d matrix of blank squares.
    int h, w;
private:
    vector<vector<Voxel>> p;
    QColor lineColor;
    int cor;
    QAction *actionMudaCor;
    int cube;
    int square;
    ///Position of the click.
    int px, py, pz;
    ///Mouse is clicked = true.
    bool press;
    ///Mouse coordinates.
    int mx, my;
signals:
    void moveX(int);
    void moveY(int);
    void clickX(int);
    void clickY(int);
    void planeChosen(int);
public slots:
    void changeDimx(int size);
    void changeDimy(int size);
    void changeDimz(int size);
    void changeRad(int rd);
    void changeRx(int radx);
    void changeRy(int rady);
    void changeRz(int radz);
    void changeRed(int red);
    void changeGreen(int green);
    void changeBlue(int blue);
    void changeAlpha(int alpha);
    void changeSlice(int pln);
    void Vect();
    void Off();
};

#endif // PAINTER_H
