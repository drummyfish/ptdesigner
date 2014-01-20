#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ptdesigner.h"

using namespace pt_design;

namespace Ui {
class MainWindow;
}

//-----------------------------------------------------

/**
  Holds information about a block's position.
  */

typedef struct
{
  int block_id;
  int x;
  int y;
  unsigned char direction;   ///< 0 - up, 1 - right, 2 - down, 3 - left
} t_block_position;

//-----------------------------------------------------

/**
  Main application windows.
  */

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    c_texture_graph *graph;                   ///< global texture graph
    vector<t_block_position> block_positions; ///< keeps position information about blocks

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);

//-----------------------------------------------------

    void set_block_position(t_block_position position);

    /**<
      Sets a new information about a block position.

      @param position information to be set, if the block_id
             element of the structure already exists, it will
             be replaced with the new information, otherwise
             a new element is created
      */

//-----------------------------------------------------

    void delete_block_position(int block_id);

    /**<
      Deletes a block position information.

      @param block_id id of the block whose position will be
             deleted, if such block doesn't exist, nothing
             happens
      */

//-----------------------------------------------------

    t_block_position *get_block_position(int block_id);

    /**<
      Gets a position of a block with specified id.

      @param block_id id of the block whose position will be
             returned

      @return a pointer to a structure containing information
              about the block position, or NULL if block with
              given id doesn't exist
      */

//-----------------------------------------------------

    int get_block_by_position(int x, int y);

    /**<
      Gets block at given position.

      @param x x position
      @param y y position

      @return id of the block placed at [x,y] position
              or -1 if there is no block
      */

//-----------------------------------------------------

    void delete_block_by_id(int id);

    /**<
      Deletes a block with given id from the texture
      graph.

      @param id id of the block to be deleted
      */

//-----------------------------------------------------

    c_texture_graph *get_texture_graph();

    /**<
      Gets the global texture graph.

      @return pointer to global texture graph
      */

//-----------------------------------------------------

    void set_block_for_preview(int id);

    /**<
      Sets a block whose color buffer should be previed in
      the preview window.

      @param id id of the block to be previewed or a
             negative value if nothing should be displayed
      */

//-----------------------------------------------------

    void global_settings_changed();

    /**<
      Handles global settings change (resolution,
      supersampling or global seed).
      */

//-----------------------------------------------------

private slots:
    void on_pushButton_2_clicked();
    void on_actionDelete_triggered();
    void on_actionRotate_CW_triggered();
    void on_actionRotate_CCW_triggered();
    void on_actionExecute_triggered();
    void on_width_valueChanged(int arg1);
    void on_height_valueChanged(int arg1);
    void on_supersampling_valueChanged(int arg1);
    void on_seed_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};

//-----------------------------------------------------

#endif // MAINWINDOW_H
