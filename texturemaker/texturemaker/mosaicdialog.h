#ifndef MOSAICDIALOG_H
#define MOSAICDIALOG_H

#include <QDialog>
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

private:
    Ui::MosaicDialog *ui;
};

#endif // MOSAICDIALOG_H
