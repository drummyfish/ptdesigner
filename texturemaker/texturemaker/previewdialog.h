#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

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
#include <QWidget>
#include <QMutex>
#include "ptdesigner.h"

using namespace pt_design;

namespace Ui {
class PreviewDialog;
}

/**
 A dialog that serves as a full size texture preview.
 */

class PreviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewDialog(c_block *block, QWidget *parent);

    /**
      Class constructor.

      @param block block to be previewed
      @param parent parent of the dialog, must be set to
             the main window that holds the texture graph
             and its mutex
      */

    ~PreviewDialog();

private:
    c_block *block;          /// block being previewed
    Ui::PreviewDialog *ui;
};

#endif // PREVIEWDIALOG_H
