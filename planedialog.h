#ifndef PLANEDIALOG_H
#define PLANEDIALOG_H
#include <QDialog>

namespace Ui {
class planeDialog;
}

class planeDialog : public QDialog
{
  Q_OBJECT

public:
  explicit planeDialog(QWidget *parent = 0);
  ~planeDialog(); ///Destructor of the class
  int getX(); ///Slot to get the value of the X coordinate to create a new canvas.
  int getY(); ///Slot to get the value of the Y coordinate to create a new canvas.
  int getZ(); ///Slot to get the value of the Z coordinate to create a new canvas.

private:
  Ui::planeDialog *ui;
};
#endif // PLANEDIALOG_H
