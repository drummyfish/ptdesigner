#include "mixdialog.h"
#include "ui_mixdialog.h"

//-----------------------------------------------------

MixDialog::MixDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::MixDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->setWindowTitle(QString::fromStdString(block->get_name()));
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);

  parameters = this->block->get_parameters();

  ui->ratio_slider->setValue(parameters->get_int_value("percentage"));

  switch (parameters->get_int_value("method"))
    {
      case MIX_ADD:
        ui->method_combo->setCurrentIndex(0);
        break;

      case MIX_SUBSTRACT:
        ui->method_combo->setCurrentIndex(1);
        break;

      case MIX_AVERAGE:
        ui->method_combo->setCurrentIndex(2);
        break;

      case MIX_MULTIPLY:
        ui->method_combo->setCurrentIndex(3);
        break;
    }
}

//-----------------------------------------------------

MixDialog::~MixDialog()

{
  delete ui;
}

//-----------------------------------------------------

void MixDialog::on_ratio_slider_valueChanged(int value)

{
  ui->ratio_text->setText(QString::number(value));
}

//-----------------------------------------------------

void MixDialog::on_buttonBox_accepted()

{
  this->block->get_parameters()->set_int_value("percentage",ui->ratio_slider->value());

  switch (ui->method_combo->currentIndex())
    {
      case 0:
        this->block->get_parameters()->set_int_value("method",MIX_ADD);
        break;

      case 1:
        this->block->get_parameters()->set_int_value("method",MIX_SUBSTRACT);
        break;

      case 2:
        this->block->get_parameters()->set_int_value("method",MIX_AVERAGE);
        break;

      case 3:
        this->block->get_parameters()->set_int_value("method",MIX_MULTIPLY);
        break;
    }
}

//-----------------------------------------------------
