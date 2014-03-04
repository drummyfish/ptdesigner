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

#include "mixdialog.h"
#include "ui_mixdialog.h"

//-----------------------------------------------------

MixDialog::MixDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::MixDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->set_window_properties();

  parameters = this->block->get_parameters();

  ui->ratio_slider->setValue(parameters->get_int_value("percentage"));

  switch (parameters->get_int_value("method"))
    {
      case MIX_ADD:
        ui->method_combo->setCurrentIndex(0);
        break;

      case MIX_SUBSTRACT:
        ui->method_combo->setCurrentIndex(1);
        break;

      case MIX_AVERAGE:
        ui->method_combo->setCurrentIndex(2);
        break;

      case MIX_MULTIPLY:
        ui->method_combo->setCurrentIndex(3);
        break;
    }
}

//-----------------------------------------------------

MixDialog::~MixDialog()

{
  delete ui;
}

//-----------------------------------------------------

void MixDialog::on_ratio_slider_valueChanged(int value)

{
  ui->ratio_text->setText(QString::number(value));
}

//-----------------------------------------------------

void MixDialog::on_buttonBox_accepted()

{
  this->block->get_parameters()->set_int_value("percentage",ui->ratio_slider->value());

  switch (ui->method_combo->currentIndex())
    {
      case 0:
        this->block->get_parameters()->set_int_value("method",MIX_ADD);
        break;

      case 1:
        this->block->get_parameters()->set_int_value("method",MIX_SUBSTRACT);
        break;

      case 2:
        this->block->get_parameters()->set_int_value("method",MIX_AVERAGE);
        break;

      case 3:
        this->block->get_parameters()->set_int_value("method",MIX_MULTIPLY);
        break;
    }
}

//-----------------------------------------------------
