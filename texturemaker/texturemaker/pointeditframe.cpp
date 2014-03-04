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

#include "pointeditframe.h"

//-----------------------------------------------------

PointEditFrame::PointEditFrame(QWidget *parent) :
    QFrame(parent)

{
  this->number_of_points = 0;
}

//-----------------------------------------------------

void PointEditFrame::mousePressEvent(QMouseEvent *event)

{
  int x,y;
  unsigned int i,j;
  bool already_exists;

  x = event->pos().x();
  y = event->pos().y();

  if (event->button() == Qt::LeftButton) // adding point
    {
      // check if the point to be added already exists:

      already_exists = false;

      for (i = 0; i < this->number_of_points; i++)
        if (this->points[i][0] == x && this->points[i][1] == y)
          {
            already_exists = true;
            break;
          }

      if (!already_exists && this->number_of_points < MAXIMUM_POINTS)
        { // add the point:
          this->points[this->number_of_points][0] = x;
          this->points[this->number_of_points][1] = y;
          this->number_of_points++;
        }
    }
  else if (event->button() == Qt::RightButton) // deleting point
    {
      for (i = 0; i < this->number_of_points; i++)
        if (this->points[i][0] <= x + 3 &&
            this->points[i][0] >= x - 3 &&
            this->points[i][1] <= y + 3 &&
            this->points[i][1] >= y - 3)
          { // delete the point:

            for (j = i; j < this->number_of_points - 1; j++) // shift all the points from i to the left by 1
              {
                this->points[j][0] = this->points[j + 1][0];
                this->points[j][1] = this->points[j + 1][1];
              }

            this->number_of_points--;

            break;
          }
    }

  this->update();
}

//-----------------------------------------------------

void PointEditFrame::clear()

{
  this->number_of_points = 0;
  this->update();
}

//-----------------------------------------------------

void PointEditFrame::paintEvent(QPaintEvent *)

{
  QPainter painter(this);
  QPen pen;
  unsigned int i;

  painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));

  pen.setColor(QColor::fromRgb(0,0,0));
  painter.setPen(pen);

  painter.drawRect(0,0,this->width() - 1,this->height() - 1);

  pen.setWidth(2);
  painter.setPen(pen);

  for (i = 0; i < this->number_of_points; i++)
    painter.drawPoint(this->points[i][0],this->points[i][1]);
}

//-----------------------------------------------------

unsigned int PointEditFrame::get_number_of_points()

{
  return this->number_of_points;
}

//-----------------------------------------------------

void PointEditFrame::set_points(string point_string)

{
  double float_points[MAXIMUM_POINTS][2];
  unsigned int length,i;

  c_texture_graph::string_to_coordinations(float_points,point_string,&length,MAXIMUM_POINTS);

  this->number_of_points = length;

  for (i = 0; i < length; i++)
    {
      this->points[i][0] = (int) (float_points[i][0] * this->width());
      this->points[i][1] = (int) (float_points[i][1] * this->height());
    }

  this->update();
}

//-----------------------------------------------------

void PointEditFrame::get_point(unsigned int index, int *x, int *y)

{
  if (index < this->number_of_points)
    {
      *x = this->points[index][0];
      *y = this->points[index][1];
    }
  else
    {
      *x = -1;
      *y = -1;
    }
}

//-----------------------------------------------------
