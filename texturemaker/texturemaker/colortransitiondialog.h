#ifndef COLORTRANSITIONDIALOG_H
#define COLORTRANSITIONDIALOG_H

#include <QDialog>
#include "customblockdialog.h"

namespace Ui {
class ColorTransitionDialog;
}

class ColorTransitionDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit ColorTransitionDialog(c_block *block, QWidget *parent);
    ~ColorTransitionDialog();

private slots:
    void on_delete_button_clicked();

    void on_add_button_clicked();

    void on_edit_button_clicked();

    void on_buttonBox_accepted();

private:
    Ui::ColorTransitionDialog *ui;
    t_color_transition transition;
    void update_items();
    int selected_point();

    /**<
     Returns currently selected point.

     @return number of currently selected point (its coordination)
             or -1 if no point is selected
     */
};

#endif // COLORTRANSITIONDIALOG_H
