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

#include "addblockbutton.h"

//-----------------------------------------------------

AddBlockButton::AddBlockButton(QWidget *parent) :
    QPushButton(parent)

 {
 }

//-----------------------------------------------------

void AddBlockButton::paintEvent(QPaintEvent *)

 {
   QPainter painter(this);
   QPixmap pixmap(":/resources/button " + this->text() + ".png");
   this->resize(53,53);
   this->setToolTip(this->text());
   painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(0,0,0));
   painter.drawPixmap(1,1,51,51,pixmap);
 }

//-----------------------------------------------------

void AddBlockButton::mousePressEvent(QMouseEvent *event)

 {
   if (event->button() == Qt::LeftButton)
     {
       QDrag *drag = new QDrag(this);
       QMimeData *mimeData = new QMimeData;

       mimeData->setText(this->text());
       drag->setMimeData(mimeData);

       Qt::DropAction dropAction = drag->exec();
     }
 }

//-----------------------------------------------------
