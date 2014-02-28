#include "aboutdialog.h"
#include "ui_aboutdialog.h"

//-----------------------------------------------------

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)

{
  ui->setupUi(this);
  this->layout()->setSizeConstraint(QLayout::SetFixedSize);
  this->setWindowIcon(QIcon(":/resources/nothing.png"));

  ui->label_text->setText(
    QString::fromUtf8("Author: Miloslav Číž \n") +
    QString::fromUtf8("version: ") + QString::fromUtf8(TEXTURE_MAKER_VERSION) + QString::fromUtf8("\n") +
    QString::fromUtf8("built on: ") + QString::fromUtf8(__DATE__) + QString::fromUtf8("\n") +
    QString::fromUtf8("uses PT Designer library version ") + QString::fromUtf8(PT_LIB_VERSION) + QString::fromUtf8("\n") +
    QString::fromUtf8("created with QT version ") + qVersion()
    );
}

//-----------------------------------------------------

AboutDialog::~AboutDialog()

{
  delete ui;
}

//-----------------------------------------------------
