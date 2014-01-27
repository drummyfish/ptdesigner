#ifndef PERLINDIALOG_H
#define PERLINDIALOG_H

#include <QDialog>
#include "ptdesigner.h"

using namespace pt_design;

namespace Ui {
class PerlinDialog;
}

class PerlinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PerlinDialog(c_block_perlin_noise *block, QWidget *parent);
    ~PerlinDialog();

protected:
    c_block_perlin_noise *block;

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_amplitude_slider_valueChanged(int value);

    void on_buttonBox_accepted();

private:
    Ui::PerlinDialog *ui;
};

#endif // PERLINDIALOG_H
