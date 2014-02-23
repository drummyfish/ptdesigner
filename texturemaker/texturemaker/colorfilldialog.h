#ifndef COLORFILLDIALOG_H
#define COLORFILLDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "ptdesigner.h"
#include "customblockdialog.h"

using namespace pt_design;

namespace Ui {
class ColorFillDialog;
}

class ColorFillDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit ColorFillDialog(c_block *block, QWidget *parent);
    ~ColorFillDialog();

private slots:
    void on_pick_clicked();
    void on_buttonBox_accepted();

private:
    Ui::ColorFillDialog *ui;
    int r,g,b;
    void update_color();
};

#endif // COLORFILLDIALOG_H
