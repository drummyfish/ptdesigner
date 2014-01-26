#include "colorfilldialog.h"
#include "ui_colorfilldialog.h"

ColorFillDialog:: ColorFillDialog(c_block_color_fill *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorFillDialog)
{
    ui->setupUi(this);
    this->block = block;
    this->setWindowTitle(COLOR_FILL_NAME);

    r = this->block->get_parameters()->get_int_value("red");
    g = this->block->get_parameters()->get_int_value("green");
    b = this->block->get_parameters()->get_int_value("blue");

    this->update_color();
}

ColorFillDialog::~ColorFillDialog()
{
  delete ui;
}

void ColorFillDialog::update_color()
{
  ui->frame->setStyleSheet("QFrame {background-color: rgb(" + QString::number(this->r) + "," + QString::number(this->g) + "," + QString::number(this->b) + ")}");
}

void ColorFillDialog::on_pick_clicked()
{
  QColorDialog dialog(QColor::fromRgb(this->r,this->g,this->b));
  dialog.exec();

  this->r = dialog.currentColor().red();
  this->g = dialog.currentColor().green();
  this->b = dialog.currentColor().blue();

  this->update_color();
}

void ColorFillDialog::on_buttonBox_accepted()
{
  this->block->get_parameters()->set_int_value("red",this->r);
  this->block->get_parameters()->set_int_value("green",this->g);
  this->block->get_parameters()->set_int_value("blue",this->b);
}
