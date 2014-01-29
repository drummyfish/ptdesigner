#ifndef CONVOLUTIONDIALOG_H
#define CONVOLUTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConvolutionDialog;
}

class ConvolutionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConvolutionDialog(QWidget *parent = 0);
    ~ConvolutionDialog();

private:
    Ui::ConvolutionDialog *ui;
};

#endif // CONVOLUTIONDIALOG_H
