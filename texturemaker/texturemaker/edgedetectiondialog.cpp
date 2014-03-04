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

#include "edgedetectiondialog.h"
#include "ui_edgedetectiondialog.h"

//-----------------------------------------------------

EdgeDetectionDialog::EdgeDetectionDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::EdgeDetectionDialog)

{
  ui->setupUi(this);
  this->set_window_properties();
  ui->intensity->setValue(this->block->get_parameters()->get_int_value("intensity"));

  switch (this->block->get_parameters()->get_int_value("type"))
    {
      case DETECTION_BOTH:
        ui->type->setCurrentIndex(0);
        break;

      case DETECTION_HORIZONTAL:
        ui->type->setCurrentIndex(1);
        break;

      case DETECTION_VERTICAL:
        ui->type->setCurrentIndex(2);
        break;
    }
}

//-----------------------------------------------------

EdgeDetectionDialog::~EdgeDetectionDialog()

{
  delete ui;
}

//-----------------------------------------------------

void EdgeDetectionDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("intensity",ui->intensity->value());

  switch (ui->type->currentIndex())
    {
      case 0:
        parameters->set_int_value("type",DETECTION_BOTH);
        break;

      case 1:
        parameters->set_int_value("type",DETECTION_HORIZONTAL);
        break;

      case 2:
        parameters->set_int_value("type",DETECTION_VERTICAL);
        break;
    }
}

//-----------------------------------------------------
