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
    ~PlaneDialogo();

    int getX();
    int getY();
    int getZ();
private:
    Ui::PlaneDialogo *ui;
};

#endif // PLANEDIALOGO_H
