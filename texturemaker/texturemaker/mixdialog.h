#ifndef MIXDIALOG_H
#define MIXDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class MixDialog;
}

class MixDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit MixDialog(c_block *block, QWidget *parent = 0);
    ~MixDialog();

private:
    Ui::MixDialog *ui;
};

#endif // MIXDIALOG_H
