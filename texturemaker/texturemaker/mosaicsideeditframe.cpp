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

#include "mosaicsideeditframe.h"

//-----------------------------------------------------

bool compare_points(t_side_point p1, t_side_point p2)

{
  return p1.x > p2.x;
}

//-----------------------------------------------------

MosaicSideEditFrame::MosaicSideEditFrame(QWidget *parent):
    QFrame(parent)

{
  this->clear();
}

//-----------------------------------------------------

void MosaicSideEditFrame::sort_points()

{
  sort(this->points.begin(),this->points.end(),compare_points);
}

//-----------------------------------------------------

void MosaicSideEditFrame::clear()

{
  t_side_point point;

  this->points.clear();

  point.x = 0.0;                   // initial points
  point.y = 0.0;

  this->points.push_back(point);

  point.x = 1.0;
  point.y = 0.0;

  this->points.push_back(point);

  this->update();
}

//-----------------------------------------------------

void MosaicSideEditFrame::paintEvent(QPaintEvent *event)

{
  unsigned int i,half_height;
  double x1,y1,x2,y2,paint_x1,paint_y1,paint_x2,paint_y2;
  QPainter painter(this);
  QPen pen;

  painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));

  half_height = this->height() / 2;

  for (i = 0; i < this->points.size() - 1; i++)
    {
      x1 = this->points.at(i).x;
      y1 = this->points.at(i).y;
      x2 = this->points.at(i + 1).x;
      y2 = this->points.at(i + 1).y;

      paint_x1 = (int) (x1 * this->width());
      paint_y1 = (int) (-1 * y1 * half_height + half_height);
      paint_x2 = (int) (x2 * this->width());
      paint_y2 = (int) (-1 * y2 * half_height + half_height);

      pen.setColor(QColor::fromRgb(0,0,0));
      pen.setWidth(0);
      painter.setPen(pen);

      painter.drawLine(paint_x1,paint_y1,paint_x2,paint_y2);

      pen.setColor(QColor::fromRgb(255,0,0));
      pen.setWidth(2);
      painter.setPen(pen);

      painter.drawPoint(paint_x1,paint_y1);
      painter.drawPoint(paint_x2,paint_y2);
    }
}

//-----------------------------------------------------

void MosaicSideEditFrame::mousePressEvent(QMouseEvent *event)

{
  t_side_point point;
  unsigned int i;

  point.x = event->pos().x() / ((double) this->width());
  point.y = (this->height() - event->pos().y() - this->height() / 2) / ((double) this->height() / 2);

  if (event->button() == Qt::LeftButton) // adding point
    {
      this->points.push_back(point);
      this->sort_points();
    }
  else                                   // right button - removing point
    {
      for (i = 1; i < this->points.size() - 1; i++)   // never delete the first and the last point
        if (point.x < this->points.at(i).x + 0.05 &&
            point.x > this->points.at(i).x - 0.05 &&
            point.y < this->points.at(i).y + 0.05 &&
            point.y > this->points.at(i).y - 0.05)
          {
            this->points.erase(this->points.begin() + i);
            break;
          }
    }

  this->update();
}

//-----------------------------------------------------

string MosaicSideEditFrame::get_shape_string()

{
  QString help_string;
  unsigned int i;
  bool first;

  help_string = "";
  first = true;

  for (i = 0; i < this->points.size(); i++)
    {
      if (first)
        first = false;
      else
        help_string += " ";

      help_string += QString::number(this->points.at(i).x) + " " + QString::number(this->points.at(i).y);
    }

  return help_string.toStdString();
}

//-----------------------------------------------------

void MosaicSideEditFrame::set_shape(string shape_string)

{
  stringstream str_stream;
  unsigned int position;
  double value_x, value_y;
  t_side_point point;

  this->clear();

  str_stream.str(shape_string);

  position = 0;

  if (!str_stream.eof())
    do
      {
        str_stream >> value_x;
        str_stream >> value_y;

        point.x = value_x;
        point.y = value_y;

        this->points.push_back(point);

        position++;
      } while (!str_stream.eof());

  this->sort_points();
  this->update();
}

//-----------------------------------------------------
