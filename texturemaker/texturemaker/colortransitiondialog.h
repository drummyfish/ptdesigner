#ifndef COLORTRANSITIONDIALOG_H
#define COLORTRANSITIONDIALOG_H

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

namespace Ui {
class ColorTransitionDialog;
}

class ColorTransitionDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit ColorTransitionDialog(c_block *block, QWidget *parent);
    ~ColorTransitionDialog();

private slots:
    void on_delete_button_clicked();
    void on_add_button_clicked();
    void on_edit_button_clicked();
    void on_buttonBox_accepted();

    void on_change_position_clicked();

private:
    Ui::ColorTransitionDialog *ui;
    t_color_transition transition;
    void update_items();
    int selected_point();

    /**<
     Returns currently selected point.

     @return number of currently selected point (its coordination)
             or -1 if no point is selected
     */
};

#endif // COLORTRANSITIONDIALOG_H
