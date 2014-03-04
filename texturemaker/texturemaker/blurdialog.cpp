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

#include "blurdialog.h"
#include "ui_blurdialog.h"

//-----------------------------------------------------

BlurDialog::BlurDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::BlurDialog)

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  ui->setupUi(this);
  this->set_window_properties();

  ui->intensity->setValue(parameters->get_int_value("intensity"));

  if (parameters->get_bool_value("motion"))
    {
      switch (parameters->get_int_value("direction"))
        {
          case DIRECTION_HORIZONTAL:
            ui->direction->setCurrentIndex(1);
            break;

          case DIRECTION_VERTICAL:
            ui->direction->setCurrentIndex(2);
            break;

          case DIRECTION_DIAGONAL_LD_RU:
            ui->direction->setCurrentIndex(3);
            break;

          case DIRECTION_DIAGONAL_LU_RD:
            ui->direction->setCurrentIndex(4);
            break;
        }
    }
  else
    ui->direction->setCurrentIndex(0);
}

//-----------------------------------------------------

BlurDialog::~BlurDialog()

{
  delete ui;
}

//-----------------------------------------------------

void BlurDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("intensity",ui->intensity->value());

  switch (ui->direction->currentIndex())
    {
      case 0:
        parameters->set_bool_value("motion",false);
        break;

      case 1:
        parameters->set_bool_value("motion",true);
        parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
        break;

      case 2:
        parameters->set_bool_value("motion",true);
        parameters->set_int_value("direction",DIRECTION_VERTICAL);
        break;

      case 3:
        parameters->set_bool_value("motion",true);
        parameters->set_int_value("direction",DIRECTION_DIAGONAL_LD_RU);
        break;

      case 4:
        parameters->set_bool_value("motion",true);
        parameters->set_int_value("direction",DIRECTION_DIAGONAL_LU_RD);
        break;
    }
}

//-----------------------------------------------------
