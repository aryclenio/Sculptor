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
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void shape(int sh);
    Sculptor *s;
    int sh = 1; //Forma  de desenho, putvoxel default
    int dim, pl; //Dimensão e plano selecionado, setado em sculptor::readMx
    int sx, sy, sz; //Medidas do Plano
    int r, g, b, a; //cores a serem modificadas
    int rad, rx, ry,rz;
    int x,y,z; //variaveis que recebem os valores de dimensão, dependendo do formato (XY, YZ, ZX)
    int h, w; //altura e largura do cubo, segundo o tamanho setado pelo sculptor
private:
    vector<vector<Voxel>> p;
    QColor lineColor;
    int cor;
    QAction *actionMudaCor;
    int cube;
    int square;
    int px, py, pz; //posições setadas pelas funções em sculptor
    bool press; //Identifica o pressionamento ou soltura do mouse.
    int mx, my; //Captura o movimento do mouse em abmas coordenadas.
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
