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
    void changeXY(); ///Slot to change the plane currently ON.
    void changeYZ(); ///Slot to change the plane currently ON.
    void changeZX(); ///Slot to change the plane currently ON.
    void pVoxel(); ///PutVoxel slot, called by the pushbuttom.
    void cVoxel(); ///CutVoxel slot, called by the pushbuttom.
    void pBox(); ///PutBox slot, called by the pushbuttom.
    void cBox(); ///CutBox slot, called by the pushbuttom.
    void pShpere(); ///PutSphere slot, called by the pushbuttom.
    void cShpere(); ///CutSphere slot, called by the pushbuttom.
    void pEllip(); ///PutEllipsoid slot, called by the pushbuttom.
    void cEllip(); ///CutEllipsoid slot, called by the pushbuttom.
    void selectPlane(); ///Slot to select a plane

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};

#endif // MAINWINDOW_H
