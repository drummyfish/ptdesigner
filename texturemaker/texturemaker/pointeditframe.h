#ifndef POINTEDITFRAME_H
#define POINTEDITFRAME_H

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
