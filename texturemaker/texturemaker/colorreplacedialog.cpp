#include "colorreplacedialog.h"
#include "ui_colorreplacedialog.h"

//-----------------------------------------------------

ColorReplaceDialog::ColorReplaceDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::ColorReplaceDialog)

{
  c_parameters *parameters;

  ui->setupUi(this);
  this->setWindowTitle(QString::fromStdString(block->get_name()));
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);

  parameters = this->block->get_parameters();

  this->dialog1.setCurrentColor(QColor::fromRgb(
    parameters->get_int_value("color 1 red"),
    parameters->get_int_value("color 1 green"),
    parameters->get_int_value("color 1 blue")));

  this->dialog2.setCurrentColor(QColor::fromRgb(
    parameters->get_int_value("color 2 red"),
    parameters->get_int_value("color 2 green"),
    parameters->get_int_value("color 2 blue")));

  this->dialog3.setCurrentColor(QColor::fromRgb(
    parameters->get_int_value("color 3 red"),
    parameters->get_int_value("color 3 green"),
    parameters->get_int_value("color 3 blue")));

  this->dialog4.setCurrentColor(QColor::fromRgb(
    parameters->get_int_value("color 4 red"),
    parameters->get_int_value("color 4 green"),
    parameters->get_int_value("color 4 blue")));

  this->update_frames();
}

//-----------------------------------------------------

void ColorReplaceDialog::update_frames()

{
  ui->frame_1->setStyleSheet("QFrame {background-color: rgb(" +
    QString::number(this->dialog1.currentColor().red()) + "," +
    QString::number(this->dialog1.currentColor().green()) + "," +
    QString::number(this->dialog1.currentColor().blue()) + ")}");

  ui->frame_2->setStyleSheet("QFrame {background-color: rgb(" +
    QString::number(this->dialog2.currentColor().red()) + "," +
    QString::number(this->dialog2.currentColor().green()) + "," +
    QString::number(this->dialog2.currentColor().blue()) + ")}");

  ui->frame_3->setStyleSheet("QFrame {background-color: rgb(" +
    QString::number(this->dialog3.currentColor().red()) + "," +
    QString::number(this->dialog3.currentColor().green())+ "," +
    QString::number(this->dialog3.currentColor().blue()) + ")}");

  ui->frame_4->setStyleSheet("QFrame {background-color: rgb(" +
    QString::number(this->dialog4.currentColor().red()) + "," +
    QString::number(this->dialog4.currentColor().green())+ "," +
    QString::number(this->dialog4.currentColor().blue()) + ")}");
}

//-----------------------------------------------------

ColorReplaceDialog::~ColorReplaceDialog()

{
  delete ui;
}

//-----------------------------------------------------

void ColorReplaceDialog::on_edit_1_clicked()

{
  this->dialog1.exec();
  this->update_frames();
}

//-----------------------------------------------------

void ColorReplaceDialog::on_edit_2_clicked()

{
  this->dialog2.exec();
  this->update_frames();
}

//-----------------------------------------------------

void ColorReplaceDialog::on_edit_3_clicked()

{
  this->dialog3.exec();
  this->update_frames();
}

//-----------------------------------------------------

void ColorReplaceDialog::on_edit_4_clicked()

{
  this->dialog4.exec();
  this->update_frames();
}

//-----------------------------------------------------

void ColorReplaceDialog::on_buttonBox_accepted()

{
  c_parameters *parameters;

  parameters = this->block->get_parameters();

  parameters->set_int_value("color 1 red",this->dialog1.currentColor().red());
  parameters->set_int_value("color 1 green",this->dialog1.currentColor().green());
  parameters->set_int_value("color 1 blue",this->dialog1.currentColor().blue());

  parameters->set_int_value("color 2 red",this->dialog2.currentColor().red());
  parameters->set_int_value("color 2 green",this->dialog2.currentColor().green());
  parameters->set_int_value("color 2 blue",this->dialog2.currentColor().blue());

  parameters->set_int_value("color 3 red",this->dialog3.currentColor().red());
  parameters->set_int_value("color 3 green",this->dialog3.currentColor().green());
  parameters->set_int_value("color 3 blue",this->dialog3.currentColor().blue());

  parameters->set_int_value("color 4 red",this->dialog4.currentColor().red());
  parameters->set_int_value("color 4 green",this->dialog4.currentColor().green());
  parameters->set_int_value("color 4 blue",this->dialog4.currentColor().blue());
}

//-----------------------------------------------------