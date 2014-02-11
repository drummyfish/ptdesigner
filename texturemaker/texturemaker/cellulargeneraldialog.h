#ifndef CELLULARGENERALDIALOG_H
#define CELLULARGENERALDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class CellularGeneralDialog;
}

class CellularGeneralDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit CellularGeneralDialog(c_block *block, QWidget *parent);
    ~CellularGeneralDialog();

private slots:
    void on_clear_button_clicked();

    void on_game_of_life_clicked();

    void on_buttonBox_accepted();

private:
    Ui::CellularGeneralDialog *ui;
};

#endif // CELLULARGENERALDIALOG_H
