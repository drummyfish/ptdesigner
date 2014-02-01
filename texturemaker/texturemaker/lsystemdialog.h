#ifndef LSYSTEMDIALOG_H
#define LSYSTEMDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class LSystemDialog;
}

class LSystemDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit LSystemDialog(c_block *block, QWidget *parent);
    ~LSystemDialog();

private slots:
    void on_browse_clicked();

    void on_reload_clicked();

    void on_buttonBox_accepted();

    void on_save_clicked();

private:
    Ui::LSystemDialog *ui;
};

#endif // LSYSTEMDIALOG_H
