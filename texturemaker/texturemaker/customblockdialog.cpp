#include "customblockdialog.h"

//-----------------------------------------------------

CustomBlockDialog::CustomBlockDialog(c_block *block, QWidget *parent) :
    QDialog(parent)

{
  this->block = block;
  this->setWindowTitle(QString::fromStdString(block->get_name()));
}

//-----------------------------------------------------
