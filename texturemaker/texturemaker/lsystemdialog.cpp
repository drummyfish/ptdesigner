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
    ui->text_edit->setPlainText(read_stream.readAll());
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
}

//-----------------------------------------------------

void LSystemDialog::on_save_clicked()
{
  QFile file(ui->path->text());

  if (file.open(QIODevice::ReadWrite))
    {
      QTextStream stream(&file);
      stream << ui->text_edit->toPlainText();
      file.flush();
      file.close();
    }
}

//-----------------------------------------------------
