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

#include "transitionpreviewframe.h"

//-----------------------------------------------------

TransitionPreviewFrame::TransitionPreviewFrame(QWidget *parent) :
    QFrame(parent)

{
  this->transition = NULL;
}

//-----------------------------------------------------

void TransitionPreviewFrame::set_transition(t_color_transition *transition)

{
  this->transition = transition;
}

//-----------------------------------------------------

void TransitionPreviewFrame::paintEvent(QPaintEvent *)

{
  if (this->transition == NULL)
    return;

  unsigned int i,j;
  t_color_buffer buffer;
  unsigned char r,g,b;
  QPainter painter(this);
  QPen pen;

  color_buffer_init(&buffer,256,50);

  for (j = 0; j < buffer.height; j++)
    for (i = 0; i < buffer.width; i++)
      color_buffer_set_pixel(&buffer,i,j,i,i,i);

  pt_map_to_transition(&buffer,this->transition);

  painter.setRenderHints(QPainter::Antialiasing,false);

  for (j = 0; j < buffer.height; j++)
    for (i = 0; i < buffer.width; i++)
      {
        color_buffer_get_pixel(&buffer,i,j,&r,&g,&b);
        pen.setColor(QColor::fromRgb(r,g,b));
        painter.setPen(pen);
        painter.drawPoint(i,j);
      }

  color_buffer_destroy(&buffer);
}

//-----------------------------------------------------
