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

#include "colorfilldialog.h"
#include "ui_colorfilldialog.h"

//-----------------------------------------------------

ColorFillDialog:: ColorFillDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block, parent),
    ui(new Ui::ColorFillDialog)

{
  ui->setupUi(this);
  this->set_window_properties();

  r = this->block->get_parameters()->get_int_value("red");
  g = this->block->get_parameters()->get_int_value("green");
  b = this->block->get_parameters()->get_int_value("blue");

  this->update_color();
}

//-----------------------------------------------------

ColorFillDialog::~ColorFillDialog()

{
  delete ui;
}

//-----------------------------------------------------

void ColorFillDialog::update_color()

{
  ui->frame->setStyleSheet("QFrame {background-color: rgb(" + QString::number(this->r) + "," + QString::number(this->g) + "," + QString::number(this->b) + ")}");
}

//-----------------------------------------------------

void ColorFillDialog::on_pick_clicked()

{
  QColorDialog dialog(QColor::fromRgb(this->r,this->g,this->b));
  dialog.exec();

  this->r = dialog.currentColor().red();
  this->g = dialog.currentColor().green();
  this->b = dialog.currentColor().blue();

  this->update_color();
}

//-----------------------------------------------------

void ColorFillDialog::on_buttonBox_accepted()

{
  this->block->get_parameters()->set_int_value("red",this->r);
  this->block->get_parameters()->set_int_value("green",this->g);
  this->block->get_parameters()->set_int_value("blue",this->b);
}

//-----------------------------------------------------
