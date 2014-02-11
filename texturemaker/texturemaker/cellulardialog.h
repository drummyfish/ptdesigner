#ifndef CELLULARDIALOG_H
#define CELLULARDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class CellularDialog;
}

/**
 * A dialog for cyclic and RPS cellular automaton.
 */

class CellularDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit CellularDialog(c_block *block, QWidget *parent);
    ~CellularDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CellularDialog *ui;
};

#endif // CELLULARDIALOG_H
