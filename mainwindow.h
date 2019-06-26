#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
#include "painter.h"
#include "vector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    ///Slot to change the plane currently ON.
    void changeXY();
    ///Slot to change the plane currently ON.
    void changeYZ();
    ///Slot to change the plane currently ON.
    void changeZX();
    ///PutVoxel slot, called by the pushbuttom.
    void pVoxel();
    ///CutVoxel slot, called by the pushbuttom.
    void cVoxel();
    ///PutBox slot, called by the pushbuttom.
    void pBox();
    ///CutBox slot, called by the pushbuttom.
    void cBox();
    ///PutSphere slot, called by the pushbuttom.
    void pShpere();
    ///CutSphere slot, called by the pushbuttom.
    void cShpere();
    ///PutEllipsoid slot, called by the pushbuttom.
    void pEllip();
    ///CutEllipsoid slot, called by the pushbuttom.
    void cEllip();
    ///Slot to select a plane.
    void selectPlane();
     ///Slot to open the .off file in Meshlab, called by the pushbuttom.
    void meshOpen();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};

#endif // MAINWINDOW_H
