#ifndef LSYSTEMDIALOG_H
#define LSYSTEMDIALOG_H

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
