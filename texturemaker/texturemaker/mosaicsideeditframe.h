#ifndef MOSAICSIDEEDITFRAME_H
#define MOSAICSIDEEDITFRAME_H

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

#include <QFrame>
#include <QPainter>
#include <QPen>
#include <vector>
#include <string>
#include <QMouseEvent>
#include <sstream>

using namespace std;

typedef struct
{
  double x;
  double y;
} t_side_point;

/**
 * Compares two points.
 * @param p1 first operand
 * @param p2 second operand
 * @return true if the first operand is greater than
 *         the second operand, false otherwise
 */

bool compare_points(t_side_point p1, t_side_point p2);

/**
 Serves to edit side shape for teselation.
 */

class MosaicSideEditFrame : public QFrame
{
    Q_OBJECT
public:
    explicit MosaicSideEditFrame(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void clear();
    string get_shape_string();
    void set_shape(string shape_string);

protected:
    vector<t_side_point> points;  /// stores the side points

    void sort_points();

signals:

public slots:


};

#endif // MOSAICSIDEEDITFRAME_H
