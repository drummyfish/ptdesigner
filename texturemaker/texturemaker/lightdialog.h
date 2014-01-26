#ifndef LIGHTDIALOG_H
#define LIGHTDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "ptdesigner.h"

using namespace pt_design;

namespace Ui {
class LightDialog;
}

class LightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LightDialog(c_block_light *block, QWidget *parent);
    ~LightDialog();

private slots:
    void on_pick_ambient_clicked();

    void on_pick_diffuse_clicked();

    void on_pick_specular_clicked();

    void on_curve_selection_currentIndexChanged(int index);

    void on_buttonBox_accepted();

private:
    Ui::LightDialog *ui;
    c_block_light *block;
    QColorDialog dialog_ambient;
    QColorDialog dialog_diffuse;
    QColorDialog dialog_specular;

    void update_graphics();
};

#endif // LIGHTDIALOG_H
