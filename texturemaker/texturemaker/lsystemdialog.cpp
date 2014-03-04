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

#include "lsystemdialog.h"
#include "ui_lsystemdialog.h"

//-----------------------------------------------------

LSystemDialog::LSystemDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::LSystemDialog)

{
  ui->setupUi(this);
  this->set_window_properties();

  ui->path->setText(QString::fromStdString(this->block->get_parameters()->get_string_value("path")));
  ui->iterations->setValue(this->block->get_parameters()->get_int_value("iterations"));

  QFile file(ui->path->text());
  QTextStream read_stream(&file);
  file.open(QFile::ReadOnly | QFile::Text);

  if (file.isOpen())
    ui->text_edit->setPlainText(read_stream.readAll());
}

//-----------------------------------------------------

LSystemDialog::~LSystemDialog()

{
  delete ui;
}

//-----------------------------------------------------

void LSystemDialog::on_browse_clicked()

{
  QFileDialog dialog;

  dialog.setAcceptMode(QFileDialog::AcceptOpen);
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setDefaultSuffix("txt");
  dialog.setNameFilter(tr("text files (*.txt)"));

  if (dialog.exec() == QDialog::Accepted)
    {
      ui->path->setText(dialog.selectedFiles().at(0));

      this->on_reload_clicked();
    }
}

//-----------------------------------------------------

void LSystemDialog::on_reload_clicked()

{
  QFile file(ui->path->text());
  QTextStream read_stream(&file);
  file.open(QFile::ReadOnly | QFile::Text);

  if (file.isOpen())
    {
      ui->text_edit->clear();
      ui->text_edit->setPlainText(read_stream.readAll());
    }
  else
    {
      QMessageBox message;

      message.setText("Could not open the file.");
      message.exec();
    }
}

//-----------------------------------------------------

void LSystemDialog::on_buttonBox_accepted()

{
  this->block->get_parameters()->set_string_value("path",ui->path->text().toStdString());
  this->block->get_parameters()->set_int_value("iterations",ui->iterations->value());
  this->block->invalidate();
}

//-----------------------------------------------------

void LSystemDialog::on_save_clicked()

{
  ofstream file;
  QStringList list;
  unsigned int i;

  file.open(ui->path->text().toStdString().c_str());

  if (file.is_open())
    {
      list = ui->text_edit->toPlainText().split('\n');

      for (i = 0; i < list.length(); i++)
        file << list.at(i).toStdString() << endl;

      file.close();
    }
  else
    {
      QMessageBox message;

      message.setText("Could not open the file.");
      message.exec();
    }
}

//-----------------------------------------------------

void LSystemDialog::insert_string(QString what)

{
  ui->text_edit->insertPlainText(what);
}

//-----------------------------------------------------

void LSystemDialog::on_button_push_clicked()

{
  this->insert_string("[");
}

//-----------------------------------------------------

void LSystemDialog::on_button_pop_clicked()

{
  this->insert_string("]");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_angle_clicked()

{
  this->insert_string("A(0)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_turn_left_clicked()

{
  this->insert_string("L(90)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_turn_right_clicked()

{
  this->insert_string("R(90)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_color_clicked()

{
  this->insert_string("C(0,0,0)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_draw_line_clicked()

{
  this->insert_string("D");
}

//-----------------------------------------------------

void LSystemDialog::on_button_move_forward_clicked()

{
  this->insert_string("G");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_step_percent_clicked()

{
  this->insert_string("P(150)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_step_absolute_clicked()

{
  this->insert_string("B(100)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_step_pixels_clicked()

{
  this->insert_string("M(100)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_increase_step_clicked()

{
  this->insert_string("I(50)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_width_absolute_clicked()

{
  this->insert_string("W(10)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_width_pixels_clicked()

{
  this->insert_string("F(1)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_style_pixels_clicked()

{
  this->insert_string("T(0,0)");
}

//-----------------------------------------------------

void LSystemDialog::on_button_set_style_absolute_clicked()

{
  this->insert_string("S(0,0)");
}

//-----------------------------------------------------
