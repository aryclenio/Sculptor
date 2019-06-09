#ifndef PAINTER_H
#define PAINTER_H
#include <iostream>
#include <QWidget>
#include <QWidget>
#include <QAction>
#include <QColor>
#include "vector"
#include "sculptor.h"
class Painter : public QWidget
{
    Q_OBJECT
public:
    explicit Painter(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void recMx(vector<vector<Voxel>> m);
    void mousePressEvent(QMouseEvent *event);
private:
    vector<vector<Voxel>> p;
    QColor lineColor;
    int cor;
    QAction *actionMudaCor;
    int sh = 1;
    int mx, my;
signals:
    void moveX(int);
    void moveY(int);
    void clickX(int);
    void clickY(int);
public slots:
    void shape(int s);
};

#endif // PAINTER_H
