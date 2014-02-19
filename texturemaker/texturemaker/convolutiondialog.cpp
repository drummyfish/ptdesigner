#include "convolutiondialog.h"
#include "ui_convolutiondialog.h"

//-----------------------------------------------------

ConvolutionDialog::ConvolutionDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::ConvolutionDialog)

{
  double double_buffer[256];
  unsigned int length,i,j,position;

  ui->setupUi(this);
  c_parameters *parameters;

  parameters = block->get_parameters();

  this->set_window_properties();
  ((QGridLayout *) ui->matrix_frame->layout())->setSpacing(0);

  ui->matrix_width->setValue(parameters->get_int_value("matrix width"));
  ui->matrix_height->setValue(parameters->get_int_value("matrix height"));

  // set the matrix values:

  c_texture_graph::string_to_double_array(double_buffer,parameters->get_string_value("matrix data"),&length,256);

  position = 0;

  for (j = 0; (int) j < parameters->get_int_value("matrix height"); j++)
    for (i = 0; (int) i < parameters->get_int_value("matrix width"); i++)
      {
        if (position >= length) // shouldn't happen
          break;

        ((QLineEdit *) ((QGridLayout *) ui->matrix_frame->layout())->itemAtPosition(i,j)->widget())->setText(QString::number(double_buffer[position]));
        position++;
      }

  this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

//-----------------------------------------------------

ConvolutionDialog::~ConvolutionDialog()

{
  delete ui;
}

//-----------------------------------------------------

void ConvolutionDialog::change_matrix_size(unsigned int width, unsigned int height)

{
  unsigned int i,j;
  QGridLayout *layout;
  QLayoutItem *item;
  QLineEdit *line_edit;

  layout = (QGridLayout *) ui->matrix_frame->layout();

  while ((item = layout->takeAt(0)))   // clear the previous layout
    {
      delete item->widget();
      delete item;
    }

  for (j = 0; j < height; j++)
    for (i = 0; i < width; i++)
      {
        line_edit = new QLineEdit();
        line_edit->resize(35,35);
        line_edit->setMaximumSize(35,35);
        line_edit->setMinimumSize(35,35);
        line_edit->setValidator(&this->validator);
        line_edit->setText("0");
        layout->addWidget(line_edit,i,j);
      }
}

//-----------------------------------------------------

void ConvolutionDialog::on_matrix_width_valueChanged(int arg1)

{
  this->change_matrix_size(ui->matrix_width->value(),ui->matrix_height->value());
}

//-----------------------------------------------------

void ConvolutionDialog::on_matrix_height_valueChanged(int arg1)

{
  this->change_matrix_size(ui->matrix_width->value(),ui->matrix_height->value());
}

//-----------------------------------------------------

void ConvolutionDialog::on_buttonBox_accepted()

{
  unsigned int i,j;
  string matrix_data,help_string;
  bool first;

  first = 0;

  for (j = 0; (int) j < ui->matrix_height->value(); j++)
    for (i = 0; (int) i < ui->matrix_height->value(); i++)
      {
        if (first)
          first = false;
        else
          matrix_data += " ";

        help_string = ((QLineEdit *) ((QGridLayout *) ui->matrix_frame->layout())->itemAtPosition(i,j)->widget())->text().toStdString();

        if (help_string.length() == 0)
          help_string = "0.0";

        matrix_data = matrix_data + help_string;
      }

  replace(matrix_data.begin(),matrix_data.end(),',','.'); // replace all "," with "."

  this->block->get_parameters()->set_int_value("matrix width",ui->matrix_width->value());
  this->block->get_parameters()->set_int_value("matrix height",ui->matrix_height->value());
  this->block->get_parameters()->set_string_value("matrix data",matrix_data);
}

//-----------------------------------------------------
