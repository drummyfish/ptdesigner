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

#include "aboutdialog.h"
#include "ui_aboutdialog.h"

//-----------------------------------------------------

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)

{
  ui->setupUi(this);
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);
  this->setWindowIcon(QIcon(":/resources/nothing.png"));

  ui->label_text->setText(
    QString::fromUtf8("Author: Miloslav Číž \n") +
    QString::fromUtf8("version: ") + QString::fromUtf8(TEXTURE_MAKER_VERSION) + QString::fromUtf8("\n") +
    QString::fromUtf8("built on: ") + QString::fromUtf8(__DATE__) + QString::fromUtf8("\n") +
    QString::fromUtf8("uses PT Designer library version ") + QString::fromUtf8(PT_LIB_VERSION) + QString::fromUtf8("\n") +
    QString::fromUtf8("created with QT version ") + qVersion()
    );
}

//-----------------------------------------------------

AboutDialog::~AboutDialog()

{
  delete ui;
}

//-----------------------------------------------------
