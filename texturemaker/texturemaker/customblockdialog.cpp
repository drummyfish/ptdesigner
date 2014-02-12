#include "customblockdialog.h"

//-----------------------------------------------------

CustomBlockDialog::CustomBlockDialog(c_block *block, QWidget *parent) :
    QDialog(parent)

{
  this->block = block;
}

//-----------------------------------------------------

void CustomBlockDialog::set_window_properties()

{
  this->setWindowTitle(QString::fromStdString(block->get_name()));
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);
  this->setWindowIcon(QIcon(":/resources/nothing.png"));
}

//-----------------------------------------------------
