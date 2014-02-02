#ifndef TRANSITIONPREVIEWFRAME_H
#define TRANSITIONPREVIEWFRAME_H

#include <QFrame>
#include <QPainter>
#include <QPen>
#include "colortransition.h"
#include "ptdesigner.h"
#include "colorbuffer.h"

using namespace pt_design;

class TransitionPreviewFrame : public QFrame

{
  Q_OBJECT
public:
  explicit TransitionPreviewFrame(QWidget *parent = 0);
  void set_transition(t_color_transition *transition);
  void paintEvent(QPaintEvent *);

protected:
  t_color_transition *transition;  /// transition being previewed

signals:

public slots:

};

#endif // TRANSITIONPREVIEWFRAME_H
