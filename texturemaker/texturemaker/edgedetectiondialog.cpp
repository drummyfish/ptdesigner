#include "edgedetectiondialog.h"
#include "ui_edgedetectiondialog.h"

//-----------------------------------------------------

EdgeDetectionDialog::EdgeDetectionDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::EdgeDetectionDialog)

{
  ui->setupUi(this);
  this->set_window_properties();
  ui->intensity->setValue(this->block->get_parameters()->get_int_value("intensity"));

  switch (this->block->get_parameters()->get_int_value("type"))
    {
      case DETECTION_BOTH:
        ui->type->setCurrentIndex(0);
        break;

      case DETECTION_HORIZONTAL:
        ui->type->setCurrentIndex(1);
        break;

      case DETECTION_VERTICAL:
        ui->type->setCurrentIndex(2);
        break;
    }
}

//-----------------------------------------------------

EdgeDetectionDialog::~EdgeDetectionDialog()

{
  delete ui;
}

//-----------------------------------------------------

void EdgeDetectionDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("intensity",ui->intensity->value());

  switch (ui->type->currentIndex())
    {
      case 0:
        parameters->set_int_value("type",DETECTION_BOTH);
        break;

      case 1:
        parameters->set_int_value("type",DETECTION_HORIZONTAL);
        break;

      case 2:
        parameters->set_int_value("type",DETECTION_VERTICAL);
        break;
    }
}

//-----------------------------------------------------
