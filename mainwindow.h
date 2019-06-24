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
    void changeXY();
    void changeYZ();
    void changeZX();
    void pVoxel(); //PV
    void cVoxel(); //CV
    void pBox(); //PB
    void cBox(); //CB
    void pShpere(); //PS
    void cShpere(); //CS
    void pEllip(); //PE
    void cEllip(); //PS
    void selectPlane();
    void meshOpen();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};

#endif // MAINWINDOW_H
