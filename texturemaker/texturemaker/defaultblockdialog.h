#ifndef DEFAULTBLOCKDIALOG_H
#define DEFAULTBLOCKDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSizePolicy>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include "ptdesigner.h"

namespace Ui {
class DefaultBlockDialog;
}

using namespace pt_design;

/**
 Default dialog used for editing block parameters.
 It displays all parameters and it's values and
 enables the user to edit them.
 */

class DefaultBlockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DefaultBlockDialog(c_block *block, QWidget *parent = 0);
    ~DefaultBlockDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DefaultBlockDialog *ui;
    c_block *block;              /// block whose parameters are being edited
};

#endif // DEFAULTBLOCKDIALOG_H
