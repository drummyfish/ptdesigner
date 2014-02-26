#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>

namespace Ui {
class ProgressDialog;
}

/**
 * Shows the progress bar and text during computation.
 */

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = 0);
    ~ProgressDialog();
    int blocks_total;      /// total number of blocks to be computed
    void set_info(unsigned int percents,QString info_text);

private:
    Ui::ProgressDialog *ui;
};

#endif // PROGRESSDIALOG_H
