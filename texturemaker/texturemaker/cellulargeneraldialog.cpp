#include "cellulargeneraldialog.h"
#include "ui_cellulargeneraldialog.h"

//-----------------------------------------------------

CellularGeneralDialog::CellularGeneralDialog(c_block *block, QWidget *parent):
    CustomBlockDialog(block,parent),
    ui(new Ui::CellularGeneralDialog)

{
  unsigned int i,j,number,remainder;
  QTableWidgetItem *item;
  unsigned char current_rules[256];
  unsigned int length;
  QString help_string;

  ui->setupUi(this);
  this->set_window_properties();

  ui->iterations->setValue(this->block->get_parameters()->get_int_value("iterations"));
  ui->states->setValue(this->block->get_parameters()->get_int_value("states"));

  c_texture_graph::string_to_char_array(current_rules,this->block->get_parameters()->get_string_value("rules"),&length,256);

  for (i = 0; i < 256; i++) // insert table rows
    {
      ui->rules->insertRow(i);

      number = i;

      for (j = 0; j < 8; j++)
        {
          remainder = number % 2;
          number = number / 2;

          item = new QTableWidgetItem(QString::number(remainder));
          item->setFlags(item->flags() ^ Qt::ItemIsEditable);  // read only

          ui->rules->setItem(i,j,item);
        }

      if (current_rules[i] == 1)
        help_string = "1";
      else if (current_rules[i] == 255)
        help_string = "-1";
      else
        help_string = "0";

      item = new QTableWidgetItem(help_string);
      ui->rules->setItem(i,8,item);
    }
}

//-----------------------------------------------------

CellularGeneralDialog::~CellularGeneralDialog()

{
  delete ui;
}

//-----------------------------------------------------

void CellularGeneralDialog::on_clear_button_clicked()

{
  unsigned int i;

  for (i = 0; i < 256; i++)
    ui->rules->item(i,8)->setText("0");
}

//-----------------------------------------------------

void CellularGeneralDialog::on_game_of_life_clicked()

{
  int rule_array[256];
  unsigned int i;

  make_game_of_life_rules(rule_array);

  for (i = 0; i < 256; i++)
    ui->rules->item(i,8)->setText(QString::number(rule_array[i]));
}

//-----------------------------------------------------

void CellularGeneralDialog::on_buttonBox_accepted()

{
  unsigned int i;
  unsigned char rules[256];
  unsigned char help_char;
  QString help_string;

  for (i = 0; i < 256; i++)
    {
      help_string = ui->rules->item(i,8)->text();

      if (help_string == "1")
        help_char = 1;
      else if (help_string == "-1")
        help_char = 255;
      else
        help_char = 0;

      rules[i] = help_char;
    }

  this->block->get_parameters()->set_string_value("rules",c_texture_graph::char_array_to_string(rules,256));
  this->block->get_parameters()->set_int_value("iterations",ui->iterations->value());
  this->block->get_parameters()->set_int_value("states",ui->states->value());
}

//-----------------------------------------------------
