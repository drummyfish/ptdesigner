#ifndef COLORREPLACEDIALOG_H
#define COLORREPLACEDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class ColorReplaceDialog;
}

class ColorReplaceDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit ColorReplaceDialog(c_block *block, QWidget *parent);
    ~ColorReplaceDialog();
    void update_frames();

protected:
    QColorDialog dialog1,dialog2,dialog3,dialog4;

private slots:
    void on_edit_1_clicked();
    void on_edit_2_clicked();
    void on_edit_3_clicked();
    void on_edit_4_clicked();
    void on_buttonBox_accepted();

private:
    Ui::ColorReplaceDialog *ui;
};

#endif // COLORREPLACEDIALOG_H
