#ifndef EDITAREAFRAME_H
#define EDITAREAFRAME_H

#include <QFrame>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <QMutex>
#include <iostream>
#include <QMimeData>
#include "math.h"
#include "mainwindow.h"

using namespace std;

//-----------------------------------------------------

  /**
    Edit area of the application, displays the texture graph
    and allows its editing.
    */

class editAreaFrame : public QFrame
{
    Q_OBJECT

protected:
    MainWindow *main_window;
    int selected_id;            /// id of currently selected block, negative = none
    bool moving;                /// whether the block moving state is on
    int connecting_id;          /// id of the block being currently connected
    int mouse_coordinations[2]; /// stores mouse coordinations when needed
    QString mouse_string;       /// string displayed by the mouse pointer
    bool display_mouse_string;  /// whether to display the mouse string

public:
    explicit editAreaFrame(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

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

    int get_selected_id();

    /**
      Returns an id of the currently selected block.

      @return id of the selected block or -1 if none
              is selected
      */

//-----------------------------------------------------

signals:
    
public slots:
    
};

//-----------------------------------------------------

#endif // EDITAREAFRAME_H
