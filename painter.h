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
private:
    vector<vector<Voxel>> p;
    QColor lineColor;
    int cor;
    QAction *actionMudaCor;
signals:

public slots:
};

#endif // PAINTER_H
