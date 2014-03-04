#ifndef DEFAULTBLOCKDIALOG_H
#define DEFAULTBLOCKDIALOG_H

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
#include <QLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSizePolicy>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include "ptdesigner.h"

namespace Ui {
class DefaultBlockDialog;
}

using namespace pt_design;

/**
 Default dialog used for editing block parameters.
 It displays all parameters and it's values and
 enables the user to edit them.
 */

class DefaultBlockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DefaultBlockDialog(c_block *block, QWidget *parent = 0);
    ~DefaultBlockDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DefaultBlockDialog *ui;
    c_block *block;              /// block whose parameters are being edited
};

#endif // DEFAULTBLOCKDIALOG_H
