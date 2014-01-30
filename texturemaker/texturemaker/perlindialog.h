#ifndef PERLINDIALOG_H
#define PERLINDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class PerlinDialog;
}

class PerlinDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit PerlinDialog(c_block *block, QWidget *parent);
    ~PerlinDialog();

private slots:
    void on_amplitude_slider_valueChanged(int value);
    void on_buttonBox_accepted();

private:
    Ui::PerlinDialog *ui;
};

#endif // PERLINDIALOG_H
