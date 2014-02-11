#include "cellulardialog.h"
#include "ui_cellulardialog.h"

//-----------------------------------------------------

CellularDialog::CellularDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::CellularDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->setWindowTitle(QString::fromStdString(block->get_name()));

  parameters = this->block->get_parameters();

  ui->iterations->setValue(parameters->get_int_value("iterations"));
  ui->neighbourhood_size->setValue(parameters->get_int_value("neighbourhood size"));

  if (parameters->get_int_value("neighbourhood") == NEIGHBOURHOOD_VON_NEUMANN)
    ui->combo->setCurrentIndex(0);
  else
    ui->combo->setCurrentIndex(1);

  if (this->block->get_name().compare(CELLULAR_CYCLIC_NAME) == 0)  // show only relevant dialog items
    {
      ui->label_players->hide();
      ui->players->hide();
      ui->threshold->setValue(parameters->get_int_value("threshold"));
      ui->states->setValue(parameters->get_int_value("states"));
    }
  else
    {
      ui->label_threshold->hide();
      ui->threshold->hide();
      ui->label_states->hide();
      ui->states->hide();
      ui->players->setValue(parameters->get_int_value("players"));
    }
}

//-----------------------------------------------------

CellularDialog::~CellularDialog()
{
  delete ui;
}

//-----------------------------------------------------

void CellularDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  if (ui->combo->currentIndex() == 0)
    parameters->set_int_value("neighbourhood",NEIGHBOURHOOD_VON_NEUMANN);
  else
    parameters->set_int_value("neighbourhood",NEIGHBOURHOOD_MOORE);

  parameters->set_int_value("iterations",ui->iterations->value());
  parameters->set_int_value("neighbourhood size",ui->neighbourhood_size->value());

  if (this->block->get_name().compare(CELLULAR_CYCLIC_NAME) == 0)
    {
      parameters->set_int_value("threshold",ui->threshold->value());
      parameters->set_int_value("states",ui->states->value());
    }
  else
    {
      parameters->set_int_value("players",ui->players->value());
    }
}

//-----------------------------------------------------
