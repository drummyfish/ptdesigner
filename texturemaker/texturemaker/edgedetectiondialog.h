#ifndef EDGEDETECTIONDIALOG_H
#define EDGEDETECTIONDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class EdgeDetectionDialog;
}

class EdgeDetectionDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit EdgeDetectionDialog(c_block *block, QWidget *parent);
    ~EdgeDetectionDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::EdgeDetectionDialog *ui;
};

#endif // EDGEDETECTIONDIALOG_H
