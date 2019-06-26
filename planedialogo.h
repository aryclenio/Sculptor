#ifndef PLANEDIALOGO_H
#define PLANEDIALOGO_H

#include <QDialog>

namespace Ui {
class PlaneDialogo;
}

class PlaneDialogo : public QDialog
{
    Q_OBJECT

public:
    explicit PlaneDialogo(QWidget *parent = 0);
    ///Destructor of the class.
    ~PlaneDialogo();

    ///Slot to get the value of the X coordinate to create a new canvas.
    int getX();
    ///Slot to get the value of the Y coordinate to create a new canvas.
    int getY();
    ///Slot to get the value of the Z coordinate to create a new canvas.
    int getZ();
private:
    Ui::PlaneDialogo *ui;
};

#endif // PLANEDIALOGO_H
