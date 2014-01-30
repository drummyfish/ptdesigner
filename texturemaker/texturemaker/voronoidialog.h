#ifndef VORONOIDIALOG_H
#define VORONOIDIALOG_H

#include <QDialog>
#include "ptdesigner.h"
#include "customblockdialog.h"
#include "general.h"

using namespace pt_design;

namespace Ui {
class VoronoiDialog;
}

class VoronoiDialog : public CustomBlockDialog
{
    Q_OBJECT

public:
    explicit VoronoiDialog(c_block *block, QWidget *parent);
    ~VoronoiDialog();

private slots:
    void on_clear_button_clicked();
    void on_buttonBox_accepted();

private:
    Ui::VoronoiDialog *ui;
};

#endif // VORONOIDIALOG_H
