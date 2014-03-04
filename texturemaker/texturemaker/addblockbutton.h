#ifndef ADDBLOCKBUTTON_H
#define ADDBLOCKBUTTON_H

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

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>

using namespace std;

//-----------------------------------------------------

/**
  Button that represents a block and can be dragged over
  to the edit area to add that block to the graph. Cannot
  be clicked.
  */

class AddBlockButton : public QPushButton
{
    Q_OBJECT
public:
    explicit AddBlockButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

//-----------------------------------------------------

#endif // ADDBLOCKBUTTON_H
