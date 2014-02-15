#ifndef WOODMARBLEDIALOG_H
#define WOODMARBLEDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class WoodMarbleDialog;
}

class WoodMarbleDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit WoodMarbleDialog(c_block *block, QWidget *parent);
    ~WoodMarbleDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::WoodMarbleDialog *ui;
};

#endif // WOODMARBLEDIALOG_H
