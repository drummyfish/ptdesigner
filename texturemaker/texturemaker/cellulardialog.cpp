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

#include "cellulardialog.h"
#include "ui_cellulardialog.h"

//-----------------------------------------------------

CellularDialog::CellularDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::CellularDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->set_window_properties();

  parameters = this->block->get_parameters();

  ui->iterations->setValue(parameters->get_int_value("iterations"));
  ui->neighbourhood_size->setValue(parameters->get_int_value("neighbourhood size"));

  if (parameters->get_int_value("neighbourhood") == NEIGHBOURHOOD_VON_NEUMANN)
    ui->combo->setCurrentIndex(0);
  else
    ui->combo->setCurrentIndex(1);

  if (this->block->get_name().compare(CELLULAR_CYCLIC_NAME) == 0)  // show only relevant dialog items
    {
      ui->label_players->hide();
      ui->players->hide();
      ui->threshold->setValue(parameters->get_int_value("threshold"));
      ui->states->setValue(parameters->get_int_value("states"));
    }
  else
    {
      ui->label_threshold->hide();
      ui->threshold->hide();
      ui->label_states->hide();
      ui->states->hide();
      ui->button_set->hide();
      ui->combo_presets->hide();
      ui->players->setValue(parameters->get_int_value("players"));
    }
}

//-----------------------------------------------------

CellularDialog::~CellularDialog()

{
  delete ui;
}

//-----------------------------------------------------

void CellularDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  if (ui->combo->currentIndex() == 0)
    parameters->set_int_value("neighbourhood",NEIGHBOURHOOD_VON_NEUMANN);
  else
    parameters->set_int_value("neighbourhood",NEIGHBOURHOOD_MOORE);

  parameters->set_int_value("iterations",ui->iterations->value());
  parameters->set_int_value("neighbourhood size",ui->neighbourhood_size->value());

  if (this->block->get_name().compare(CELLULAR_CYCLIC_NAME) == 0)
    {
      parameters->set_int_value("threshold",ui->threshold->value());
      parameters->set_int_value("states",ui->states->value());
    }
  else
    {
      parameters->set_int_value("players",ui->players->value());
    }
}

//-----------------------------------------------------

void CellularDialog::on_button_set_clicked()

{
  // presets:

  switch (ui->combo_presets->currentIndex())
    {
      case 0:
        ui->combo->setCurrentIndex(0);
        ui->neighbourhood_size->setValue(2);
        ui->states->setValue(6);
        ui->threshold->setValue(2);
        ui->iterations->setValue(30);
        break;

      case 1:
        ui->combo->setCurrentIndex(1);
        ui->neighbourhood_size->setValue(3);
        ui->states->setValue(8);
        ui->threshold->setValue(5);
        ui->iterations->setValue(60);
        break;

      case 2:
       ui->combo->setCurrentIndex(0);
        ui->neighbourhood_size->setValue(2);
        ui->states->setValue(5);
        ui->threshold->setValue(4);
        ui->iterations->setValue(30);
        break;

      case 3:
        ui->combo->setCurrentIndex(0);
        ui->neighbourhood_size->setValue(3);
        ui->states->setValue(2);
        ui->threshold->setValue(10);
        ui->iterations->setValue(5);
        break;

      case 4:
        ui->combo->setCurrentIndex(0);
        ui->neighbourhood_size->setValue(2);
        ui->states->setValue(3);
        ui->threshold->setValue(5);
        ui->iterations->setValue(20);
        break;

      case 5:
        ui->combo->setCurrentIndex(1);
        ui->neighbourhood_size->setValue(2);
        ui->states->setValue(4);
        ui->threshold->setValue(9);
        ui->iterations->setValue(25);
        break;

      case 6:
        ui->combo->setCurrentIndex(1);
        ui->neighbourhood_size->setValue(1);
        ui->states->setValue(4);
        ui->threshold->setValue(2);
        ui->iterations->setValue(40);
        break;

      case 7:
        ui->combo->setCurrentIndex(0);
        ui->neighbourhood_size->setValue(3);
        ui->states->setValue(5);
        ui->threshold->setValue(4);
        ui->iterations->setValue(60);
        break;
    }
}

//-----------------------------------------------------
