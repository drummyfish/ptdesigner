#ifndef SUBSTRATEDIALOG_H
#define SUBSTRATEDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class SubstrateDialog;
}

class SubstrateDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit SubstrateDialog(c_block *block, QWidget *parent);
    ~SubstrateDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SubstrateDialog *ui;
};

#endif // SUBSTRATEDIALOG_H
