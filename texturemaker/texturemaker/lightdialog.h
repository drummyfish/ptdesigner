#ifndef LIGHTDIALOG_H
#define LIGHTDIALOG_H

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
class LightDialog;
}

class LightDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit LightDialog(c_block *block, QWidget *parent);
    ~LightDialog();

private slots:
    void on_pick_ambient_clicked();
    void on_pick_diffuse_clicked();
    void on_pick_specular_clicked();
    void on_curve_selection_currentIndexChanged(int index);
    void on_buttonBox_accepted();
    void on_set_preset_clicked();

private:
    Ui::LightDialog *ui;
    QColorDialog dialog_ambient;
    QColorDialog dialog_diffuse;
    QColorDialog dialog_specular;

    void update_graphics();
};

#endif // LIGHTDIALOG_H
