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

#include "ditherdialog.h"
#include "ui_ditherdialog.h"

//-----------------------------------------------------

DitherDialog::DitherDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::DitherDialog)

{
  ui->setupUi(this);
  this->set_window_properties();

  ui->levels->setValue(this->block->get_parameters()->get_int_value("levels"));

  switch (this->block->get_parameters()->get_int_value("method"))
    {
      case DITHERING_THRESHOLD:
        ui->method->setCurrentIndex(0);
        break;

      case DITHERING_RANDOM:
        ui->method->setCurrentIndex(1);
        break;

      case DITHERING_ERROR_PROPAGATION:
        ui->method->setCurrentIndex(2);
        break;

      case DITHERING_ORDERED:
        ui->method->setCurrentIndex(3);
        break;
    }
}

//-----------------------------------------------------

DitherDialog::~DitherDialog()

{
  delete ui;
}

//-----------------------------------------------------

void DitherDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("levels",ui->levels->value());

  switch (ui->method->currentIndex())
    {
      case 0:
        parameters->set_int_value("method",DITHERING_THRESHOLD);
        break;

      case 1:
        parameters->set_int_value("method",DITHERING_RANDOM);
        break;

      case 2:
        parameters->set_int_value("method",DITHERING_ERROR_PROPAGATION);
        break;

      case 3:
        parameters->set_int_value("method",DITHERING_ORDERED);
        break;
    }
}

//-----------------------------------------------------
