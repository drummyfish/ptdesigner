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

class EditAreaFrame : public QFrame
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
    bool disconnecting_mode;    /// whether the disconnecting state is on
    QPixmap *pixel_buffer;      /// serves as a canvas for painting the widget

public:
    explicit EditAreaFrame(QWidget *parent = 0);
    ~EditAreaFrame();
    void paintEvent(QPaintEvent *);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
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

    void show_parameters_dialog();

    /**
      Shows a parameter edit dialog for currently
      selected block. If no block is selected, nothing
      happens. The method locks the graph mutex.
      */

//-----------------------------------------------------

    void reset();

    /**
      Resets the area's state variables to default stat
      (i.e. clears selected block etc.).
      */

//-----------------------------------------------------

    void set_disconnecting_mode(bool value);

    /**
      Turns disconnecting mode on or off. In this mode
      the user can delete block connections.

      @param value true to turn the mode on, false to
             turn it off
      */

//-----------------------------------------------------

    int get_selected_id();

    /**
      Returns an id of the currently selected block.

      @return id of the selected block or -1 if none
              is selected
      */

//-----------------------------------------------------

    void open_block_setting(c_block *block);

    /**


      */

//-----------------------------------------------------

signals:
    
public slots:
    
};

//-----------------------------------------------------

#endif // EDITAREAFRAME_H
