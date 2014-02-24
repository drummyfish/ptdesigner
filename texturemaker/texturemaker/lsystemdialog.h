#ifndef LSYSTEMDIALOG_H
#define LSYSTEMDIALOG_H

#include <QDialog>
#include "customblockdialog.h"
#include <fstream>

namespace Ui {
class LSystemDialog;
}

class LSystemDialog : public CustomBlockDialog

{
    Q_OBJECT

public:
    explicit LSystemDialog(c_block *block, QWidget *parent);
    ~LSystemDialog();
    void insert_string(QString what);

    /**
      Inserts given string into the text edit area at
      the cursor position.

      @param what string to be inserted
      */

private slots:
    void on_browse_clicked();
    void on_reload_clicked();
    void on_buttonBox_accepted();
    void on_save_clicked();

    void on_button_push_clicked();

    void on_button_pop_clicked();

    void on_button_set_angle_clicked();

    void on_button_turn_left_clicked();

    void on_button_turn_right_clicked();

    void on_button_set_color_clicked();

    void on_button_draw_line_clicked();

    void on_button_move_forward_clicked();

    void on_button_set_step_percent_clicked();

    void on_button_set_step_absolute_clicked();

    void on_button_set_step_pixels_clicked();

    void on_button_increase_step_clicked();

    void on_button_set_width_absolute_clicked();

    void on_button_set_width_pixels_clicked();

    void on_button_set_style_pixels_clicked();

    void on_button_set_style_absolute_clicked();

private:
    Ui::LSystemDialog *ui;
};

#endif // LSYSTEMDIALOG_H
