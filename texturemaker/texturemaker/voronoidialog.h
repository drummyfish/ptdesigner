#ifndef VORONOIDIALOG_H
#define VORONOIDIALOG_H

#include <QDialog>
#include "ptdesigner.h"
#include "general.h"

using namespace pt_design;

namespace Ui {
class VoronoiDialog;
}

class VoronoiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VoronoiDialog(c_block_voronoi_diagram *block, QWidget *parent);
    ~VoronoiDialog();

private slots:
    void on_clear_button_clicked();

    void on_buttonBox_accepted();

private:
    Ui::VoronoiDialog *ui;
    c_block_voronoi_diagram *block;
};

#endif // VORONOIDIALOG_H
