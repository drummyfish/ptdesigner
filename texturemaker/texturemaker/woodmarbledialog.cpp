#include "woodmarbledialog.h"
#include "ui_woodmarbledialog.h"

//-----------------------------------------------------

WoodMarbleDialog::WoodMarbleDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::WoodMarbleDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->set_window_properties();

  parameters = this->block->get_parameters();

  if (this->block->get_name().compare(MARBLE_NAME) == 0)
    {
      ui->circles->hide();
      ui->label_circles->hide();
      ui->hardness->hide();
      ui->label_hardness->hide();

      ui->periods->setValue(parameters->get_int_value("periods"));
    }
  else
    {
      ui->periods->hide();
      ui->label_periods->hide();

      ui->circles->setValue(parameters->get_int_value("circles"));
      ui->hardness->setValue(parameters->get_int_value("hardness"));
    }

  ui->intensity->setValue(parameters->get_int_value("intensity"));
  ui->amplitude->setValue(parameters->get_int_value("amplitude"));

  switch (parameters->get_int_value("direction"))
    {
      case DIRECTION_HORIZONTAL:
        ui->combo->setCurrentIndex(0);
        break;

      case DIRECTION_VERTICAL:
        ui->combo->setCurrentIndex(1);
        break;

      case DIRECTION_DIAGONAL_LD_RU:
        ui->combo->setCurrentIndex(2);
        break;

      case DIRECTION_DIAGONAL_LU_RD:
        ui->combo->setCurrentIndex(3);
        break;
    }
}

//-----------------------------------------------------

WoodMarbleDialog::~WoodMarbleDialog()

{
  delete ui;
}

//-----------------------------------------------------

void WoodMarbleDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("intensity",ui->intensity->value());
  parameters->set_int_value("amplitude",ui->amplitude->value());

  if (this->block->get_name().compare(MARBLE_NAME) == 0)
    {
      parameters->set_int_value("periods",ui->periods->value());
    }
  else
    {
      parameters->set_int_value("circles",ui->circles->value());
      parameters->set_int_value("hardness",ui->hardness->value());
    }

  switch (ui->combo->currentIndex())
    {
      case 0:
        parameters->set_int_value("direction",DIRECTION_HORIZONTAL);
        break;

      case 1:
        parameters->set_int_value("direction",DIRECTION_VERTICAL);
        break;

      case 2:
        parameters->set_int_value("direction",DIRECTION_DIAGONAL_LD_RU);
        break;

      case 3:
        parameters->set_int_value("direction",DIRECTION_DIAGONAL_LU_RD);
        break;
    }
}

//-----------------------------------------------------
