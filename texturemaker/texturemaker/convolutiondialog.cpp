#include "convolutiondialog.h"
#include "ui_convolutiondialog.h"

ConvolutionDialog::ConvolutionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConvolutionDialog)
{
    ui->setupUi(this);
}

ConvolutionDialog::~ConvolutionDialog()
{
    delete ui;
}
