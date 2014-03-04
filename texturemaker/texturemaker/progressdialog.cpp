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

#include "progressdialog.h"
#include "ui_progressdialog.h"

//-----------------------------------------------------

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)

{
  ui->setupUi(this);
  this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

//-----------------------------------------------------

ProgressDialog::~ProgressDialog()

{
  delete ui;
}

//-----------------------------------------------------

void ProgressDialog::set_info(unsigned int percents,QString info_text)

{
  ui->progress_bar->setValue(percents);
  ui->progress_text->setText(info_text);
}

//-----------------------------------------------------
