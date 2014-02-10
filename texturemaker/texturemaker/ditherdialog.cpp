#include "ditherdialog.h"
#include "ui_ditherdialog.h"

//-----------------------------------------------------

DitherDialog::DitherDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::DitherDialog)

{
  ui->setupUi(this);
  this->setWindowTitle(QString::fromStdString(block->get_name()));
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);

  ui->levels->setValue(this->block->get_parameters()->get_int_value("levels"));

  switch (this->block->get_parameters()->get_int_value("method"))
    {
      case DITHERING_THRESHOLD:
        ui->method->setCurrentIndex(0);
        break;

      case DITHERING_RANDOM:
        ui->method->setCurrentIndex(1);
        break;

      case DITHERING_ERROR_PROPAGATION:
        ui->method->setCurrentIndex(2);
        break;

      case DITHERING_ORDERED:
        ui->method->setCurrentIndex(3);
        break;
    }
}

//-----------------------------------------------------

DitherDialog::~DitherDialog()

{
  delete ui;
}

//-----------------------------------------------------

void DitherDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("levels",ui->levels->value());

  switch (ui->method->currentIndex())
    {
      case 0:
        parameters->set_int_value("method",DITHERING_THRESHOLD);
        break;

      case 1:
        parameters->set_int_value("method",DITHERING_RANDOM);
        break;

      case 2:
        parameters->set_int_value("method",DITHERING_ERROR_PROPAGATION);
        break;

      case 3:
        parameters->set_int_value("method",DITHERING_ORDERED);
        break;
    }
}

//-----------------------------------------------------
