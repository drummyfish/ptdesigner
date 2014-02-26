#include "progressdialog.h"
#include "ui_progressdialog.h"

//-----------------------------------------------------

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)

{
  ui->setupUi(this);
  this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
}

//-----------------------------------------------------

ProgressDialog::~ProgressDialog()

{
  delete ui;
}

//-----------------------------------------------------

void ProgressDialog::set_info(unsigned int percents,QString info_text)

{
  ui->progress_bar->setValue(percents);
  ui->progress_text->setText(info_text);
}

//-----------------------------------------------------
