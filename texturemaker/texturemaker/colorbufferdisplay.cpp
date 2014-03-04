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

#include "colorbufferdisplay.h"

//-----------------------------------------------------

ColorBufferDisplay::ColorBufferDisplay(QWidget *parent):
    QFrame(parent)

{
  this->block = NULL;
  this->is_up_to_date = false;
  this->preview_image = new QPixmap(this->width(),this->height());
}

//-----------------------------------------------------

ColorBufferDisplay::~ColorBufferDisplay()

{
  delete this->preview_image;
  this->block = NULL;
}

//-----------------------------------------------------

void ColorBufferDisplay::set_block(c_block *block)

{
  this->block = block;
  this->is_up_to_date = false;
}

//----------------------------------------------------

void ColorBufferDisplay::set_main_window(MainWindow *main_window)

{
  this->main_window = main_window;
}

//-----------------------------------------------------

void ColorBufferDisplay::invalidate()

{
  this->is_up_to_date = false;
}

//-----------------------------------------------------

void ColorBufferDisplay::paintEvent(QPaintEvent *)

{
  QPainter painter(this);
  QPen pen;
  t_color_buffer buffer;      // helper color buffer for resizing
  unsigned int i,j;
  unsigned char r,g,b;

  if (!this->main_window->get_graph_mutex()->tryLock())
    {
      painter.drawPixmap(0,0,this->width(),this->height(),*this->preview_image);
      return;
    }

  // mutex locked here

  if (this->preview_image->width() != this->width() || this->preview_image->height() != this->height())
    { // resize the image if needed
      delete this->preview_image;
      this->preview_image = new QPixmap(this->width(),this->height());
      this->is_up_to_date = false;
    }

  if (this->block == NULL || !this->block->has_image() || this->block->is_error())
    {
      painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
      painter.drawRect(0,0,this->width() - 1,this->height() - 1);
      this->main_window->get_graph_mutex()->unlock();
      return;
    }

  if (!this->is_up_to_date)
    {
      color_buffer_init(&buffer,this->width(),this->height());
      pt_resize(((c_graphic_block *) this->block)->get_color_buffer(),&buffer,INTERPOLATION_LINEAR);

      QPainter help_painter(this->preview_image);

      for (j = 0; j < buffer.height; j++)  // draw the buffer
        for (i = 0; i < buffer.width; i++)
          {
            color_buffer_get_pixel(&buffer,i,j,&r,&g,&b);
            pen.setColor(QColor::fromRgb(r,g,b));
            help_painter.setPen(pen);
            help_painter.drawPoint(i,j);
          }

      color_buffer_destroy(&buffer);
      this->is_up_to_date = true;
    }

  painter.drawPixmap(0,0,this->width(),this->height(),*this->preview_image);  // draw the buffer

  pen.setColor(QColor::fromRgb(0,0,0));
  painter.setPen(pen);
  painter.drawRect(0,0,this->width() - 1,this->height() - 1);

  this->main_window->get_graph_mutex()->unlock();
}

//-----------------------------------------------------
