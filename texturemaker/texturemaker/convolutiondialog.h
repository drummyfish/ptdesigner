#ifndef CONVOLUTIONDIALOG_H
#define CONVOLUTIONDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class ConvolutionDialog;
}

class ConvolutionDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
  explicit ConvolutionDialog(c_block *block, QWidget *parent);
  ~ConvolutionDialog();
  void change_matrix_size(unsigned int width, unsigned int height);

private:
  QDoubleValidator validator;

private slots:
  void on_matrix_width_valueChanged(int arg1);
  void on_matrix_height_valueChanged(int arg1);

  void on_buttonBox_accepted();

private:
  Ui::ConvolutionDialog *ui;
};

#endif // CONVOLUTIONDIALOG_H
