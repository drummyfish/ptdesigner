#ifndef MOSAICDIALOG_H
#define MOSAICDIALOG_H

#include <QDialog>
#include <QComboBox>
#include "customblockdialog.h"

namespace Ui {
class MosaicDialog;
}

class MosaicDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit MosaicDialog(c_block *block, QWidget *parent);
    ~MosaicDialog();

private slots:
    void on_clear_1_clicked();
    void on_clear_2_clicked();
    void on_clear_3_clicked();
    void on_clear_4_clicked();
    void on_buttonBox_accepted();
    void on_combo_1_currentIndexChanged(int index);
    void on_combo_2_currentIndexChanged(int index);
    void on_combo_3_currentIndexChanged(int index);
    void on_combo_4_currentIndexChanged(int index);
    void on_repeat_x_valueChanged(int arg1);
    void on_repeat_y_valueChanged(int arg1);

private:
    Ui::MosaicDialog *ui;

    void set_side_combo(QComboBox *combo, t_mosaic_transformation value);
    t_mosaic_transformation get_side_combo(QComboBox *combo);
    void check_validity();
};

#endif // MOSAICDIALOG_H
