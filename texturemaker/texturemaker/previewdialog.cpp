#include "previewdialog.h"
#include "ui_previewdialog.h"

//-----------------------------------------------------

PreviewDialog::PreviewDialog(c_block *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreviewDialog)

{
  unsigned int width,height;
  this->block = block;
  ui->setupUi(this);

  ui->preview->set_main_window((MainWindow *) parent);

  if (this->block != NULL && this->block->has_image())
    {
      width = ((c_graphic_block *) this->block)->get_color_buffer()->width;
      height = ((c_graphic_block *) this->block)->get_color_buffer()->height;
      ui->preview->setMinimumSize(width,height);

      ui->preview->resize(width,height);

      width += 50;
      height += 60;

      width = width > this->maximumWidth() ? this->maximumWidth() : width;
      height = height > this->maximumHeight() ? this->maximumHeight() : height;

      this->resize(width,height);
    }

  ui->preview->set_block(this->block);

  ui->preview->update();
}

//-----------------------------------------------------

PreviewDialog::~PreviewDialog()

{
  delete ui;
}

//-----------------------------------------------------
