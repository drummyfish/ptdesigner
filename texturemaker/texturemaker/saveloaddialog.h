#ifndef SAVELOADDIALOG_H
#define SAVELOADDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class SaveLoadDialog;
}

class SaveLoadDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit SaveLoadDialog(c_block *block, QWidget *paren);
    ~SaveLoadDialog();

private slots:
    void on_buttonBox_accepted();
    void on_browse_clicked();

private:
    Ui::SaveLoadDialog *ui;
};

#endif // SAVELOADDIALOG_H
