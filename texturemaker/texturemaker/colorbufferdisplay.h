#ifndef COLORBUFFERDISPLAY_H
#define COLORBUFFERDISPLAY_H

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
