#ifndef COLORBUFFERDISPLAY_H
#define COLORBUFFERDISPLAY_H

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

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <QPen>
#include <QMutex>
#include <QPixmap>
#include "ptdesigner.h"
#include "proctextures.h"
#include "mainwindow.h"
#include "general.h"

using namespace pt_design;

//-----------------------------------------------------

  /**
    Displays content of given color buffer, serves
    as a preview.
    */

class ColorBufferDisplay : public QFrame
{
    Q_OBJECT

private:
    c_block *block;          /// block being displayed
    QPixmap *preview_image;
    bool is_up_to_date;
    MainWindow *main_window; /// pointer to the main window

public:
    explicit ColorBufferDisplay(QWidget *parent = 0);
    ~ColorBufferDisplay();
    void paintEvent(QPaintEvent *);

//-----------------------------------------------------

    void set_main_window(MainWindow *main_window);

    /**
      Sets a main window for this object.

      @param main_window main window to be set
      */

//-----------------------------------------------------

    void invalidate();

    /**
      Invalidates the preview so it is forced to
      access its previewed block next time it is
      repainted.
      */

//-----------------------------------------------------

    void set_block(c_block *block);

    /**
      Sets a block whose color buffer will be displayed.

      @param block block to be displayed or NULL if
             nothing should be displayed
      */
    
//-----------------------------------------------------

signals:
    
public slots:
    
};

#endif // COLORBUFFERDISPLAY_H
