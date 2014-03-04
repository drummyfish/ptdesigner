#ifndef CONVOLUTIONDIALOG_H
#define CONVOLUTIONDIALOG_H

/*
 * Copyright 2013 Miloslav Číž
 *
 * This file is part of PT Designer.
 *
 * PT Designer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PT Designer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with these files. If not, see <http://www.gnu.org/licenses/>.
 */

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
