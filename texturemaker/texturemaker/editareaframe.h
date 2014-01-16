#ifndef EDITAREAFRAME_H
#define EDITAREAFRAME_H

#include <QFrame>
#include <QPainter>
#include <QMouseEvent>
#include <iostream>
#include "mainwindow.h"

using namespace std;

//-----------------------------------------------------

class editAreaFrame : public QFrame
{
    Q_OBJECT

protected:
    MainWindow *main_window;

public:
    explicit editAreaFrame(QWidget *parent = 0);

//-----------------------------------------------------

    void set_main_window(MainWindow *main_window);

    /**
      Sets a pointer to main window for this edit area,
      the main windows provides access to global texture
      graph that is being drawn by this edit area.

      @param main_window pointer to a window to be set
             as the main window for this object
      */

//-----------------------------------------------------

    void paintEvent(QPaintEvent *);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);

signals:
    
public slots:
    
};

//-----------------------------------------------------

#endif // EDITAREAFRAME_H
