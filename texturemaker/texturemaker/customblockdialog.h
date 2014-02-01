#ifndef CUSTOMBLOCKDIALOG_H
#define CUSTOMBLOCKDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QLineEdit>
#include <QFileDialog>
#include <QDoubleValidator>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include "ptdesigner.h"

using namespace pt_design;
using namespace std;

/**
 Serves as a base class for dialogs for modifying
 parameters of concrete blocks.
 */

class CustomBlockDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CustomBlockDialog(c_block *block, QWidget *parent);

protected:
    c_block *block;   /// block being modified

signals:

public slots:

};

#endif // CUSTOMBLOCKDIALOG_H
