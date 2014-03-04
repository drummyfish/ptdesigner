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

#include "substratedialog.h"
#include "ui_substratedialog.h"

//-----------------------------------------------------

SubstrateDialog::SubstrateDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::SubstrateDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->set_window_properties();

  parameters = this->block->get_parameters();

  ui->grayscale->setChecked(parameters->get_bool_value("grayscale"));
  ui->iterations->setValue(parameters->get_int_value("number of iterations"));
  ui->lines->setValue(parameters->get_int_value("number of lines"));

  if (parameters->get_bool_value("iterate"))
    ui->radio_yes->setChecked(true);
  else
    ui->radio_no->setChecked(true);

  switch (parameters->get_int_value("fill type"))
    {
      case FILL_NONE:
        ui->combo->setCurrentIndex(0);
        break;

      case FILL_KEEP_BORDERS:
        ui->combo->setCurrentIndex(1);
        break;

      case FILL_NO_BORDERS:
        ui->combo->setCurrentIndex(2);
        break;
    }
}

//-----------------------------------------------------

SubstrateDialog::~SubstrateDialog()

{
  delete ui;
}

//-----------------------------------------------------

void SubstrateDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_bool_value("iterate",ui->radio_yes->isChecked());
  parameters->set_bool_value("grayscale",ui->grayscale->isChecked());
  parameters->set_int_value("number of iterations",ui->iterations->value());
  parameters->set_int_value("number of lines",ui->lines->value());

  switch (ui->combo->currentIndex())
    {
      case 0:
        parameters->set_int_value("fill type",FILL_NONE);
        break;

      case 1:
        parameters->set_int_value("fill type",FILL_KEEP_BORDERS);
        break;

      case 2:
        parameters->set_int_value("fill type",FILL_NO_BORDERS);
        break;
    }
}

//-----------------------------------------------------
