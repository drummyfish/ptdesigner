#ifndef DITHERDIALOG_H
#define DITHERDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class DitherDialog;
}

class DitherDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit DitherDialog(c_block *block, QWidget *parent);
    ~DitherDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DitherDialog *ui;
};

#endif // DITHERDIALOG_H
