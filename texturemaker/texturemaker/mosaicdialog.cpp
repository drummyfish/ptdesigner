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

#include "mosaicdialog.h"
#include "ui_mosaicdialog.h"
#include <iostream>

using namespace std;

//-----------------------------------------------------

MosaicDialog::MosaicDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::MosaicDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->set_window_properties();

  parameters = this->block->get_parameters();

  ui->repeat_x->setValue(parameters->get_int_value("tiles x"));
  ui->repeat_y->setValue(parameters->get_int_value("tiles y"));

  this->set_side_combo(ui->combo_1,(t_mosaic_transformation) parameters->get_int_value("transformation 1"));
  this->set_side_combo(ui->combo_2,(t_mosaic_transformation) parameters->get_int_value("transformation 2"));
  this->set_side_combo(ui->combo_3,(t_mosaic_transformation) parameters->get_int_value("transformation 3"));
  this->set_side_combo(ui->combo_4,(t_mosaic_transformation) parameters->get_int_value("transformation 4"));

  ui->point_edit_1->set_shape(parameters->get_string_value("side 1"));
  ui->point_edit_2->set_shape(parameters->get_string_value("side 2"));
  ui->point_edit_3->set_shape(parameters->get_string_value("side 3"));
  ui->point_edit_4->set_shape(parameters->get_string_value("side 4"));

  ui->colors->setText(QString::fromStdString(parameters->get_string_value("fill colors")));

  switch (parameters->get_int_value("fill type"))
    {
      case FILL_NONE:
        ui->fill_type_combo->setCurrentIndex(0);
        break;

      case FILL_KEEP_BORDERS:
        ui->fill_type_combo->setCurrentIndex(1);
        break;

      case FILL_NO_BORDERS:
        ui->fill_type_combo->setCurrentIndex(2);
        break;
    }
}

//-----------------------------------------------------

void MosaicDialog::set_side_combo(QComboBox *combo, t_mosaic_transformation value)

{
  switch (value)
    {
      case MOSAIC_TRANSFORM_ROTATE_SIDE:
        combo->setCurrentIndex(0);
        break;

      case MOSAIC_TRANSFORM_ROTATE_VERTEX:
        combo->setCurrentIndex(1);
        break;

      case MOSAIC_TRANSFORM_SHIFT:
        combo->setCurrentIndex(2);
        break;

      case MOSAIC_TRANSFORM_SHIFT_MIRROR:
        combo->setCurrentIndex(3);
        break;
    }
}

//-----------------------------------------------------

t_mosaic_transformation MosaicDialog::get_side_combo(QComboBox *combo)

{
  switch (combo->currentIndex())
    {
      case 0:
        return MOSAIC_TRANSFORM_ROTATE_SIDE;
        break;

      case 1:
        return MOSAIC_TRANSFORM_ROTATE_VERTEX;
        break;

      case 2:
        return MOSAIC_TRANSFORM_SHIFT;
        break;

      case 3:
        return MOSAIC_TRANSFORM_SHIFT_MIRROR;
        break;
    }

  return MOSAIC_TRANSFORM_SHIFT_MIRROR;
}

//-----------------------------------------------------

MosaicDialog::~MosaicDialog()

{
  delete ui;
}

//-----------------------------------------------------

void MosaicDialog::on_clear_1_clicked()

{
  ui->point_edit_1->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_clear_2_clicked()

{
  ui->point_edit_2->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_clear_3_clicked()

{
  ui->point_edit_3->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_clear_4_clicked()

{
  ui->point_edit_4->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("tiles x",ui->repeat_x->value());
  parameters->set_int_value("tiles y",ui->repeat_y->value());

  parameters->set_int_value("transformation 1",this->get_side_combo(ui->combo_1));
  parameters->set_int_value("transformation 2",this->get_side_combo(ui->combo_2));
  parameters->set_int_value("transformation 3",this->get_side_combo(ui->combo_3));
  parameters->set_int_value("transformation 4",this->get_side_combo(ui->combo_4));

  parameters->set_string_value("side 1",ui->point_edit_1->get_shape_string());
  parameters->set_string_value("side 2",ui->point_edit_2->get_shape_string());
  parameters->set_string_value("side 3",ui->point_edit_3->get_shape_string());
  parameters->set_string_value("side 4",ui->point_edit_4->get_shape_string());

  parameters->set_string_value("fill colors",ui->colors->text().toStdString());

  switch (ui->fill_type_combo->currentIndex())
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

void MosaicDialog::check_validity()

{
  t_square_mosaic mosaic;

  mosaic.side_shape[0] = (char *) "";  // sides are not important for validity
  mosaic.side_shape[1] = (char *) "";
  mosaic.side_shape[2] = (char *) "";
  mosaic.side_shape[3] = (char *) "";

  mosaic.tiles_x = ui->repeat_x->value();
  mosaic.tiles_y = ui->repeat_y->value();

  mosaic.transformation[0] = this->get_side_combo(ui->combo_1);
  mosaic.transformation[1] = this->get_side_combo(ui->combo_2);
  mosaic.transformation[2] = this->get_side_combo(ui->combo_3);
  mosaic.transformation[3] = this->get_side_combo(ui->combo_4);

  if (square_mosaic_is_valid(&mosaic))
    {
      ui->validity->setStyleSheet("color: green");
      ui->validity->setText("valid");
    }
  else
    {
      ui->validity->setStyleSheet("color: red");
      ui->validity->setText("invalid");
    }
}

//-----------------------------------------------------

void MosaicDialog::on_combo_1_currentIndexChanged(int index)

{
  this->check_validity();
}

//-----------------------------------------------------

void MosaicDialog::on_combo_2_currentIndexChanged(int index)

{
  this->check_validity();
}

//-----------------------------------------------------

void MosaicDialog::on_combo_3_currentIndexChanged(int index)

{
  this->check_validity();
}

//-----------------------------------------------------

void MosaicDialog::on_combo_4_currentIndexChanged(int index)

{
  this->check_validity();
}

//-----------------------------------------------------

void MosaicDialog::on_repeat_x_valueChanged(int arg1)

{
  this->check_validity();
}

//-----------------------------------------------------

void MosaicDialog::on_repeat_y_valueChanged(int arg1)
{
  this->check_validity();
}

//----------------------------------------------------
