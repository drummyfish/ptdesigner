#include "mixdialog.h"
#include "ui_mixdialog.h"

MixDialog::MixDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::MixDialog)
{
  ui->setupUi(this);
}

MixDialog::~MixDialog()
{
  delete ui;
}
