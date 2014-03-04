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

#include "previewdialog.h"
#include "ui_previewdialog.h"

//-----------------------------------------------------

PreviewDialog::PreviewDialog(c_block *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewDialog)

{
  unsigned int width,height;
  this->block = block;
  ui->setupUi(this);

  ui->preview->set_main_window((MainWindow *) parent);

  if (this->block != NULL && this->block->has_image())
    {
      width = ((c_graphic_block *) this->block)->get_color_buffer()->width;
      height = ((c_graphic_block *) this->block)->get_color_buffer()->height;
      ui->preview->setMinimumSize(width,height);

      ui->preview->resize(width,height);

      width += 50;
      height += 60;

      width = (int) width > this->maximumWidth() ? this->maximumWidth() : width;
      height = (int) height > this->maximumHeight() ? this->maximumHeight() : height;

      this->resize(width,height);
    }

  ui->preview->set_block(this->block);

  ui->preview->update();
}

//-----------------------------------------------------

PreviewDialog::~PreviewDialog()

{
  delete ui;
}

//-----------------------------------------------------
