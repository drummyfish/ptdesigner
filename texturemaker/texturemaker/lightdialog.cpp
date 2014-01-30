#include "lightdialog.h"
#include "ui_lightdialog.h"

//-----------------------------------------------------

LightDialog::LightDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::LightDialog)
{
  ui->setupUi(this);
  this->setWindowTitle(QString::fromStdString(block->get_name()));

  this->dialog_ambient.setCurrentColor(QColor::fromRgb(
    block->get_parameters()->get_int_value("ambient red"),
    block->get_parameters()->get_int_value("ambient green"),
    block->get_parameters()->get_int_value("ambient blue")));

  this->dialog_diffuse.setCurrentColor(QColor::fromRgb(
    block->get_parameters()->get_int_value("diffuse red"),
    block->get_parameters()->get_int_value("diffuse green"),
    block->get_parameters()->get_int_value("diffuse blue")));

  this->dialog_specular.setCurrentColor(QColor::fromRgb(
    block->get_parameters()->get_int_value("specular red"),
    block->get_parameters()->get_int_value("specular green"),
    block->get_parameters()->get_int_value("specular blue")));

  ui->direction_x->setValue(this->block->get_parameters()->get_double_value("direction vector x"));
  ui->direction_y->setValue(this->block->get_parameters()->get_double_value("direction vector y"));
  ui->phong_exponent->setValue(this->block->get_parameters()->get_double_value("phong exponent"));
  ui->viewer_height->setValue(this->block->get_parameters()->get_double_value("viewer height"));

  this->update_graphics();
}

//-----------------------------------------------------

void LightDialog::update_graphics()
{
  QString curve_image;

  ui->frame_ambient->setStyleSheet("QFrame {background-color: rgb("
    + QString::number(this->dialog_ambient.currentColor().red()) + ","
    + QString::number(this->dialog_ambient.currentColor().green()) + ","
    + QString::number(this->dialog_ambient.currentColor().blue()) + ")}");

  ui->frame_diffuse->setStyleSheet("QFrame {background-color: rgb("
    + QString::number(this->dialog_diffuse.currentColor().red()) + ","
    + QString::number(this->dialog_diffuse.currentColor().green()) + ","
    + QString::number(this->dialog_diffuse.currentColor().blue()) + ")}");

  ui->frame_specular->setStyleSheet("QFrame {background-color: rgb("
    + QString::number(this->dialog_specular.currentColor().red()) + ","
    + QString::number(this->dialog_specular.currentColor().green()) + ","
    + QString::number(this->dialog_specular.currentColor().blue()) + ")}");

  switch (ui->curve_selection->currentIndex())
    {
      case 0:
        curve_image = "cos smooth";
        break;

      case 1:
        curve_image = "cos abs";
        break;

      case 2:
        curve_image = "linear half";
        break;

      case 3:
        curve_image = "linear full";
        break;
    }

  ui->frame_curve->setStyleSheet("QFrame {background-image: url(:/resources/curve " + curve_image + ".png)}");
}

//-----------------------------------------------------

LightDialog::~LightDialog()
{
  delete ui;
}

//-----------------------------------------------------

void LightDialog::on_pick_ambient_clicked()
{
  this->dialog_ambient.exec();
  this->update_graphics();
}

//-----------------------------------------------------

void LightDialog::on_pick_diffuse_clicked()
{
  this->dialog_diffuse.exec();
  this->update_graphics();
}

//-----------------------------------------------------

void LightDialog::on_pick_specular_clicked()
{
  this->dialog_specular.exec();
  this->update_graphics();
}

//-----------------------------------------------------

void LightDialog::on_curve_selection_currentIndexChanged(int index)
{
  this->update_graphics();
}

//-----------------------------------------------------

void LightDialog::on_buttonBox_accepted()
{
  this->block->get_parameters()->set_int_value("ambient red",this->dialog_ambient.currentColor().red());
  this->block->get_parameters()->set_int_value("ambient green",this->dialog_ambient.currentColor().green());
  this->block->get_parameters()->set_int_value("ambient blue",this->dialog_ambient.currentColor().blue());

  this->block->get_parameters()->set_int_value("diffuse red",this->dialog_diffuse.currentColor().red());
  this->block->get_parameters()->set_int_value("diffuse green",this->dialog_diffuse.currentColor().green());
  this->block->get_parameters()->set_int_value("diffuse blue",this->dialog_diffuse.currentColor().blue());

  this->block->get_parameters()->set_int_value("specular red",this->dialog_specular.currentColor().red());
  this->block->get_parameters()->set_int_value("specular green",this->dialog_specular.currentColor().green());
  this->block->get_parameters()->set_int_value("specular blue",this->dialog_specular.currentColor().blue());

  this->block->get_parameters()->set_double_value("phong exponent",ui->phong_exponent->value());
  this->block->get_parameters()->set_double_value("viewer height",ui->viewer_height->value());
  this->block->get_parameters()->set_double_value("direction vector x",ui->direction_x->value());
  this->block->get_parameters()->set_double_value("direction vector y",ui->direction_y->value());

  switch (ui->curve_selection->currentIndex())
    {
      case 0:
        this->block->get_parameters()->set_int_value("reflection curve",REFLECTION_CURVE_COSINE_SMOOTH);
        break;

      case 1:
        this->block->get_parameters()->set_int_value("reflection curve",REFLECTION_CURVE_COSINE_ABS);
        break;

      case 2:
        this->block->get_parameters()->set_int_value("reflection curve",REFLECTION_CURVE_LINEAR_HALF);
        break;

      case 3:
        this->block->get_parameters()->set_int_value("reflection curve",REFLECTION_CURVE_LINEAR_FULL);
        break;
    }
}

//-----------------------------------------------------
