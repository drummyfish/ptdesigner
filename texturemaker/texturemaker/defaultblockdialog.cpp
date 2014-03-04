/*
 * Copyright 2013 Miloslav Číž
 *
 * This file is part of PT Designer.
 *
 * PT Designer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PT Designer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with these files. If not, see <http://www.gnu.org/licenses/>.
 */

#include "defaultblockdialog.h"
#include "ui_defaultblockdialog.h"

//-----------------------------------------------------

DefaultBlockDialog::DefaultBlockDialog(c_block *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DefaultBlockDialog)

{
  unsigned int i;
  t_parameter_type parameter_type;

  this->block = block;

  ui->setupUi(this);

  this->layout()->setSizeConstraint(QLayout::SetFixedSize); // make the window non-resizeable
  this->setWindowIcon(QIcon(":/resources/nothing.png"));

  if (this->block == NULL)
    return;

  this->setWindowTitle(QString::fromStdString(block->get_name()));

  ((QGridLayout *) this->layout())->removeWidget(ui->buttonBox);

  for (i = 0; i < block->get_parameters()->number_of_parameters(); i++)
    {
      parameter_type = block->get_parameters()->get_type(i);

      ((QGridLayout *) this->layout())->addWidget(new QLabel(QString::fromStdString(block->get_parameters()->get_name(i))),i,0);

      switch (parameter_type)
        {
          case PARAMETER_INT:
            {
              QSpinBox *spin_box = new QSpinBox();
              spin_box->setMinimumWidth(75);
              spin_box->setMaximum(999999);
              spin_box->setMinimum(-999999);
              spin_box->setValue(block->get_parameters()->get_int_value(i));
              ((QGridLayout *) this->layout())->addWidget(spin_box,i,1);
              break;
            }

          case PARAMETER_DOUBLE:
            {
              QDoubleSpinBox *double_spin_box = new QDoubleSpinBox();
              double_spin_box->setMinimumWidth(75);
              double_spin_box->setMinimum(-99999999.99);
              double_spin_box->setSingleStep(0.1);
              double_spin_box->setDecimals(5);
              double_spin_box->setValue(block->get_parameters()->get_double_value(i));
              ((QGridLayout *) this->layout())->addWidget(double_spin_box,i,1);
              break;
            }

          case PARAMETER_STRING:
            {
              QLineEdit *line_edit = new QLineEdit();
              line_edit->setMinimumWidth(100);
              line_edit->setText(QString::fromStdString(block->get_parameters()->get_string_value(i)));
              ((QGridLayout *) this->layout())->addWidget(line_edit,i,1);
              break;
            }

          case PARAMETER_BOOL:
            {
              QCheckBox *check_box = new QCheckBox();
              check_box->setChecked(block->get_parameters()->get_bool_value(i));
              ((QGridLayout *) this->layout())->addWidget(check_box,i,1);
              break;
            }
        }
    }

  ((QGridLayout *) this->layout())->addWidget(ui->buttonBox,i,0);
}

//-----------------------------------------------------

DefaultBlockDialog::~DefaultBlockDialog()

{
  delete ui;
}

//-----------------------------------------------------

void DefaultBlockDialog::on_buttonBox_accepted()

{
  t_parameter_type type;
  string std_string,help_string;
  unsigned int i;
  QWidget *value_widget;

  for (i = 0; (int) i < ((QGridLayout *) this->layout())->rowCount() - 1; i++)
    {
      std_string = ((QLabel *) ((QGridLayout *) this->layout())->itemAtPosition(i,0)->widget())->text().toStdString();
      type = this->block->get_parameters()->get_type(std_string);
      value_widget = ((QGridLayout *) this->layout())->itemAtPosition(i,1)->widget();

      switch (type)
        {
          case PARAMETER_INT:
            this->block->get_parameters()->set_int_value(std_string,((QSpinBox *) value_widget)->value());
            break;

          case PARAMETER_DOUBLE:
            this->block->get_parameters()->set_double_value(std_string,((QDoubleSpinBox *) value_widget)->value());
            break;

          case PARAMETER_STRING:
            help_string = ((QLineEdit *) value_widget)->text().toStdString();
            this->block->get_parameters()->set_string_value(std_string,help_string.c_str());
            break;

          case PARAMETER_BOOL:
            this->block->get_parameters()->set_bool_value(std_string,((QCheckBox *) value_widget)->isChecked());
            break;
        }
    }
}

//-----------------------------------------------------
