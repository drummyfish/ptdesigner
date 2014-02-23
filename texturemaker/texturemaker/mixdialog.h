#ifndef MIXDIALOG_H
#define MIXDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class MixDialog;
}

class MixDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit MixDialog(c_block *block, QWidget *parent = 0);
    ~MixDialog();

private slots:
    void on_ratio_slider_valueChanged(int value);
    void on_buttonBox_accepted();

private:
    Ui::MixDialog *ui;
};

#endif // MIXDIALOG_H
