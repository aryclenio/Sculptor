#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
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

private slots:
    void on_putVoxel_clicked();

    void on_putVoxel_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};

#endif // MAINWINDOW_H
