#ifndef CUSTOMBLOCKDIALOG_H
#define CUSTOMBLOCKDIALOG_H

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
#include <QColorDialog>
#include <QLineEdit>
#include <QFileDialog>
#include <QDoubleValidator>
#include <QTextStream>
#include <QMessageBox>
#include <QLayout>
#include <QIcon>
#include <iostream>
#include "ptdesigner.h"
#include "colortransition.h"

using namespace pt_design;
using namespace std;

/**
 Serves as a base class for dialogs for modifying
 parameters of concrete blocks.
 */

class CustomBlockDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CustomBlockDialog(c_block *block, QWidget *parent);

protected:
    c_block *block;   /// block being modified

    void set_window_properties();

    /**
      Sets the window title and icon and makes it non-resizable.
      */

signals:

public slots:

};

#endif // CUSTOMBLOCKDIALOG_H
