#ifndef LIGHTDIALOG_H
#define LIGHTDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class LightDialog;
}

class LightDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit LightDialog(c_block *block, QWidget *parent);
    ~LightDialog();

private slots:
    void on_pick_ambient_clicked();
    void on_pick_diffuse_clicked();
    void on_pick_specular_clicked();
    void on_curve_selection_currentIndexChanged(int index);
    void on_buttonBox_accepted();

private:
    Ui::LightDialog *ui;
    QColorDialog dialog_ambient;
    QColorDialog dialog_diffuse;
    QColorDialog dialog_specular;

    void update_graphics();
};

#endif // LIGHTDIALOG_H
