#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <QFuture>
#include <QTimer>
#include <QtConcurrent/QtConcurrent>
#include "ptdesigner.h"
#include "defaultblockdialog.h"
#include "previewdialog.h"

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
    QMutex graph_mutex;                       ///< protexts the texture graph from race conditions

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void dropEvent(QDropEvent *de);
    void dragMoveEvent(QDragMoveEvent *de);
    void dragEnterEvent(QDragEnterEvent *event);

//-----------------------------------------------------

    static void compute_thread(MainWindow *window, bool force);

    /**<
      This method contains a code for recomputing the
      texture graph and should be run in separate thread.
      It executes the recomputation and when it's done,
      updates the texture preview and the edit area.
      The function locks the graph mutext itself.

      @param window window whose texture graph will be
             recomputed
      @param force if true, every block will be forced
             to recompute, otherwise only necessary
             computations will be done
      */

//-----------------------------------------------------

    void update_graphics();

    /**<
     Updates all graphics elements.
     */

//-----------------------------------------------------

    QMutex *get_graph_mutex();

    /**<
      Gets the mutex sddociated to the texture graph.

      @return texture graph mutex
      */

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

    int get_block_by_position(int x, int y, int *slot);

    /**<
      Gets block (and its slot) at given position.

      @param x x position
      @param y y position
      @param slot in this variable the slot number at given
             position will be returned, numbers 0 to
             MAX_INPT_BLOCKS - 1 are input slots, MAX_INPT_BLOCKS
             is the output slot and -1 is no slot

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

    void canvas_resolution_changed();

    /**<
      Handles canvas resolution change.
      */

//-----------------------------------------------------

    void block_selected(int block_id);

    /**<
       Updates the block info.

       @param block_id id of the selected block or -1
              if no block is selected (the info will be
              cleared)
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
    void on_cwidth_valueChanged(int arg1);
    void on_cheight_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_radio_global_seed_toggled(bool checked);

    void on_radio_custom_seed_toggled(bool checked);

    void on_custom_seed_valueChanged(int arg1);

    void on_actionDisconnect_changed();

private:
    Ui::MainWindow *ui;
};

//-----------------------------------------------------

#endif // MAINWINDOW_H
