#ifndef POINTEDITFRAME_H
#define POINTEDITFRAME_H

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

#include <QObject>
#include <QFrame>
#include <QMouseEvent>
#include <iostream>
#include <QPainter>
#include "ptdesigner.h"

#define MAXIMUM_POINTS 512

/**
 A frame that allows user to define points
 in two dimensional space.
 */

using namespace std;
using namespace pt_design;

class PointEditFrame : public QFrame
{
    Q_OBJECT
public:
    explicit PointEditFrame(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);
    void clear();
    void set_points(string point_string);
    unsigned int get_number_of_points();
    void get_point(unsigned int index, int *x, int *y);

protected:
    int points[MAXIMUM_POINTS][2];   /// points
    unsigned int number_of_points;

signals:

public slots:

};

#endif // POINTEDITFRAME_H
