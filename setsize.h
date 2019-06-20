#ifndef SETSIZE_H
#define SETSIZE_H

#include <QDialog>

namespace Ui {
class Setsize;
}

class Setsize : public QDialog
{
    Q_OBJECT

public:
    explicit Setsize(QWidget *parent = 0);
    ~Setsize();

private:
    Ui::Setsize *ui;
};

#endif // SETSIZE_H
