#include "saveloaddialog.h"
#include "ui_saveloaddialog.h"

//-----------------------------------------------------

SaveLoadDialog::SaveLoadDialog(c_block *block, QWidget *parent) :
    CustomBlockDialog(block,parent),
    ui(new Ui::SaveLoadDialog)

{
  ui->setupUi(this);
  this->set_window_properties();

  ui->path_text->setText(QString::fromStdString(this->block->get_parameters()->get_string_value("path")));
}

//-----------------------------------------------------

SaveLoadDialog::~SaveLoadDialog()

{
  delete ui;
}

//-----------------------------------------------------

void SaveLoadDialog::on_buttonBox_accepted()

{
  this->block->get_parameters()->set_string_value("path",ui->path_text->text().toStdString());
}

//-----------------------------------------------------

void SaveLoadDialog::on_browse_clicked()

{
  QFileDialog dialog;

  if (this->block->get_name().compare(FILE_SAVE_NAME) == 0)
    dialog.setAcceptMode(QFileDialog::AcceptSave);
  else
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setDefaultSuffix("png");
  dialog.setNameFilter(tr("png files (*.png)"));

  if (dialog.exec() == QDialog::Accepted)
    {
      ui->path_text->setText(dialog.selectedFiles().at(0));
    }
}

//-----------------------------------------------------
