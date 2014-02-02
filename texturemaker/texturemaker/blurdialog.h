#ifndef BLURDIALOG_H
#define BLURDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class BlurDialog;
}

class BlurDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit BlurDialog(c_block *block, QWidget *parent);
    ~BlurDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BlurDialog *ui;
};

#endif // BLURDIALOG_H
