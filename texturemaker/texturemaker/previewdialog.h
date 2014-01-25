#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

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
