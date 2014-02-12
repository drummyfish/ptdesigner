#ifndef CUSTOMBLOCKDIALOG_H
#define CUSTOMBLOCKDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include <QLineEdit>
#include <QFileDialog>
#include <QDoubleValidator>
#include <QTextStream>
#include <QMessageBox>
#include <QLayout>
#include <QIcon>
#include <iostream>
#include "ptdesigner.h"
#include "colortransition.h"

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

    void set_window_properties();

    /**
      Sets the window title and icon and makes it non-resizable.
      */

signals:

public slots:

};

#endif // CUSTOMBLOCKDIALOG_H
