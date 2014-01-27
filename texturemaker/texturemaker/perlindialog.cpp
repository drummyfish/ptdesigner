#include "perlindialog.h"
#include "ui_perlindialog.h"

//-----------------------------------------------------

PerlinDialog::PerlinDialog(c_block_perlin_noise *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PerlinDialog)
{
    c_parameters *parameters;

    ui->setupUi(this);
    this->setWindowTitle(PERLIN_NOISE_NAME);
    this->block = block;

    parameters = block->get_parameters();

    ui->amplitude_slider->setValue(parameters->get_int_value("amplitude"));
    ui->frequency->setValue(parameters->get_int_value("frequency"));

    switch (parameters->get_int_value("interpolation"))
      {
        case INTERPOLATION_NEAREST:
          ui->interpolation_combo->setCurrentIndex(0);
          break;

        case INTERPOLATION_LINEAR:
          ui->interpolation_combo->setCurrentIndex(1);
          break;

        case INTERPOLATION_SINE:
          ui->interpolation_combo->setCurrentIndex(2);
          break;
      }

    if (parameters->get_int_value("max iterations") == -1)
      {
        ui->max_iterations->setValue(10);
        ui->radio_unlimited->setChecked(true);
      }
    else
      {
        ui->max_iterations->setValue(parameters->get_int_value("max iterations"));
        ui->radio_maximum->setChecked(true);
      }

    ui->smooth->setChecked(parameters->get_bool_value("smooth"));
}

//-----------------------------------------------------

PerlinDialog::~PerlinDialog()
{
  delete ui;
}

//-----------------------------------------------------

void PerlinDialog::on_amplitude_slider_valueChanged(int value)
{
  ui->amplitude_value->setText(QString::number(ui->amplitude_slider->value()));
}

//-----------------------------------------------------

void PerlinDialog::on_buttonBox_accepted()
{
  c_parameters *parameters;

  parameters = block->get_parameters();

  parameters->set_bool_value("smooth",ui->smooth->isChecked());
  parameters->set_int_value("amplitude",ui->amplitude_slider->value());
  parameters->set_int_value("frequency",ui->frequency->value());

  switch (ui->interpolation_combo->currentIndex())
    {
      case 0:
        parameters->set_int_value("interpolation",INTERPOLATION_NEAREST);
        break;

      case 1:
        parameters->set_int_value("interpolation",INTERPOLATION_LINEAR);
        break;

      case 2:
        parameters->set_int_value("interpolation",INTERPOLATION_SINE);
        break;
    }

  if (ui->radio_unlimited->isChecked())
    parameters->set_int_value("max iterations",-1);
  else
    parameters->set_int_value("max iterations",ui->max_iterations->value());
}

//-----------------------------------------------------
