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
  ~planeDialog();
  int getX();
  int getY();
  int getZ();

private:
  Ui::planeDialog *ui;
};
#endif // PLANEDIALOG_H
