#include "mosaicdialog.h"
#include "ui_mosaicdialog.h"

//-----------------------------------------------------

MosaicDialog::MosaicDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::MosaicDialog)

{
  ui->setupUi(this);
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

//-----------------------------------------------------

MosaicDialog::~MosaicDialog()

{
  delete ui;
}

//-----------------------------------------------------

void MosaicDialog::on_clear_1_clicked()

{
  ui->point_edit_1->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_clear_2_clicked()

{
  ui->point_edit_2->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_clear_3_clicked()

{
  ui->point_edit_3->clear();
}

//-----------------------------------------------------

void MosaicDialog::on_clear_4_clicked()

{
  ui->point_edit_4->clear();
}

//-----------------------------------------------------
