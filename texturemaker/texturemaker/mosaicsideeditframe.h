#ifndef MOSAICSIDEEDITFRAME_H
#define MOSAICSIDEEDITFRAME_H

#include <QFrame>
#include <QPainter>
#include <QPen>
#include <vector>
#include <QMouseEvent>

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

protected:
    vector<t_side_point> points;  /// stores the side points

    void sort_points();

signals:

public slots:


};

#endif // MOSAICSIDEEDITFRAME_H
