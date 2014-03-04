#ifndef TRANSITIONPREVIEWFRAME_H
#define TRANSITIONPREVIEWFRAME_H

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
