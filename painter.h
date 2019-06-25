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
    void paintEvent(QPaintEvent *event); ///An event that draws a matrix of blank cubes and paint then if they are ON. 
    void mousePressEvent(QMouseEvent *event); ///An event that transforms a click of the mouse as an activator of the isOn property, depending of witch one of the 8 selected actions is activated.
    void mouseReleaseEvent(QMouseEvent *event); ///An event to take care of actions if the mouse was released
    void shape(int sh); ///The shape is numerated by one of the 8 actions, witch one will have your behaviour if the mouse is clicked.
    Sculptor *s; ///The default sculptor that is created when the application was opened for the first time.
    int sh = 1; ///Shape of the draw, PutVoxel set as default.
    int dim, pl; ///Plane and Dimention selected by the radioButtom
    int sx, sy, sz; ///Sculptor size.
    int r, g, b, a; ///Collors and transparency values.
    int rad, rx, ry,rz; ///Radius of the sphere and the ellipsoid.
    int x,y,z; ///Box values.
    int h, w; ///Size of the 2d matrix of blank squares.
private:
    vector<vector<Voxel>> p;
    QColor lineColor;
    int cor;
    QAction *actionMudaCor;
    int cube;
    int px, py, pz; ///Position of the click.
    bool press; ///Mouse is clicked = true.
    int mx, my; ///Mouse coordinates
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
