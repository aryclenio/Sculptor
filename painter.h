#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include "vector"
#include "sculptor.h"
class Painter : public QWidget
{
    Q_OBJECT
public:
    explicit Painter(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *event);
    void recMx(std::vector<std::vector<Voxel>> m);
private:
    std::vector<std::vector<Voxel>> p;
signals:

public slots:
};

#endif // PAINTER_H
