#ifndef COLORFILLDIALOG_H
#define COLORFILLDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "ptdesigner.h"

using namespace pt_design;

namespace Ui {
class ColorFillDialog;
}

class ColorFillDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColorFillDialog(c_block_color_fill *block, QWidget *parent);
    ~ColorFillDialog();

private slots:
    void on_pick_clicked();

    void on_buttonBox_accepted();

private:
    Ui::ColorFillDialog *ui;
    c_block_color_fill *block;
    int r,g,b;
    void update_color();
};

#endif // COLORFILLDIALOG_H
