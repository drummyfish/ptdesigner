/********************************************************************************
** Form generated from reading UI file 'voronoidialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VORONOIDIALOG_H
#define UI_VORONOIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include "pointeditframe.h"

QT_BEGIN_NAMESPACE

class Ui_VoronoiDialog
{
public:
    QGridLayout *gridLayout_2;
    QRadioButton *radio_random;
    QLabel *label;
    QSpinBox *number_of_points;
    QRadioButton *radio_square;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *initial_y;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_10;
    QSpinBox *initial_angle;
    QComboBox *voronoi_type;
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_4;
    QRadioButton *radio_custom;
    QDoubleSpinBox *initial_x;
    QPushButton *clear_button;
    PointEditFrame *point_editor;
    QRadioButton *radio_cross_horizontal;
    QRadioButton *radio_cross_diagonal;
    QComboBox *voronoi_metric;
    QRadioButton *radio_circle;
    QLabel *label_13;
    QSpinBox *radius;
    QSpinBox *width;
    QSpinBox *length1;
    QSpinBox *length2;

    void setupUi(QDialog *VoronoiDialog)
    {
        if (VoronoiDialog->objectName().isEmpty())
            VoronoiDialog->setObjectName(QStringLiteral("VoronoiDialog"));
        VoronoiDialog->resize(411, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VoronoiDialog->sizePolicy().hasHeightForWidth());
        VoronoiDialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(VoronoiDialog);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        radio_random = new QRadioButton(VoronoiDialog);
        radio_random->setObjectName(QStringLiteral("radio_random"));

        gridLayout_2->addWidget(radio_random, 6, 0, 1, 1);

        label = new QLabel(VoronoiDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        number_of_points = new QSpinBox(VoronoiDialog);
        number_of_points->setObjectName(QStringLiteral("number_of_points"));
        number_of_points->setMaximum(65536);

        gridLayout_2->addWidget(number_of_points, 4, 2, 1, 1);

        radio_square = new QRadioButton(VoronoiDialog);
        radio_square->setObjectName(QStringLiteral("radio_square"));

        gridLayout_2->addWidget(radio_square, 8, 0, 1, 1);

        label_6 = new QLabel(VoronoiDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 7, 1, 1, 1);

        label_7 = new QLabel(VoronoiDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 8, 1, 1, 1);

        label_8 = new QLabel(VoronoiDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 9, 1, 1, 1);

        label_9 = new QLabel(VoronoiDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 10, 1, 1, 1);

        initial_y = new QDoubleSpinBox(VoronoiDialog);
        initial_y->setObjectName(QStringLiteral("initial_y"));
        initial_y->setMaximum(1);

        gridLayout_2->addWidget(initial_y, 16, 1, 1, 1);

        label_11 = new QLabel(VoronoiDialog);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 16, 0, 1, 1);

        label_12 = new QLabel(VoronoiDialog);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 17, 0, 1, 1);

        label_10 = new QLabel(VoronoiDialog);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 15, 0, 1, 1);

        initial_angle = new QSpinBox(VoronoiDialog);
        initial_angle->setObjectName(QStringLiteral("initial_angle"));

        gridLayout_2->addWidget(initial_angle, 17, 1, 1, 1);

        voronoi_type = new QComboBox(VoronoiDialog);
        voronoi_type->setObjectName(QStringLiteral("voronoi_type"));

        gridLayout_2->addWidget(voronoi_type, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(VoronoiDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMaximumSize(QSize(200, 16777215));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 20, 2, 1, 1);

        label_3 = new QLabel(VoronoiDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(VoronoiDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(VoronoiDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 4, 1, 1, 1);

        label_4 = new QLabel(VoronoiDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setWordWrap(true);

        gridLayout_2->addWidget(label_4, 13, 0, 1, 1);

        radio_custom = new QRadioButton(VoronoiDialog);
        radio_custom->setObjectName(QStringLiteral("radio_custom"));

        gridLayout_2->addWidget(radio_custom, 11, 0, 1, 1);

        initial_x = new QDoubleSpinBox(VoronoiDialog);
        initial_x->setObjectName(QStringLiteral("initial_x"));
        initial_x->setMaximum(1);

        gridLayout_2->addWidget(initial_x, 15, 1, 1, 1);

        clear_button = new QPushButton(VoronoiDialog);
        clear_button->setObjectName(QStringLiteral("clear_button"));

        gridLayout_2->addWidget(clear_button, 11, 2, 1, 1);

        point_editor = new PointEditFrame(VoronoiDialog);
        point_editor->setObjectName(QStringLiteral("point_editor"));
        point_editor->setMinimumSize(QSize(200, 200));
        point_editor->setMaximumSize(QSize(200, 200));
        point_editor->setFrameShape(QFrame::StyledPanel);
        point_editor->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(point_editor, 13, 2, 1, 1);

        radio_cross_horizontal = new QRadioButton(VoronoiDialog);
        radio_cross_horizontal->setObjectName(QStringLiteral("radio_cross_horizontal"));

        gridLayout_2->addWidget(radio_cross_horizontal, 9, 0, 1, 1);

        radio_cross_diagonal = new QRadioButton(VoronoiDialog);
        radio_cross_diagonal->setObjectName(QStringLiteral("radio_cross_diagonal"));

        gridLayout_2->addWidget(radio_cross_diagonal, 10, 0, 1, 1);

        voronoi_metric = new QComboBox(VoronoiDialog);
        voronoi_metric->setObjectName(QStringLiteral("voronoi_metric"));

        gridLayout_2->addWidget(voronoi_metric, 2, 2, 1, 1);

        radio_circle = new QRadioButton(VoronoiDialog);
        radio_circle->setObjectName(QStringLiteral("radio_circle"));

        gridLayout_2->addWidget(radio_circle, 7, 0, 1, 1);

        label_13 = new QLabel(VoronoiDialog);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_2->addWidget(label_13, 14, 0, 1, 1);

        radius = new QSpinBox(VoronoiDialog);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setMaximum(100);

        gridLayout_2->addWidget(radius, 7, 2, 1, 1);

        width = new QSpinBox(VoronoiDialog);
        width->setObjectName(QStringLiteral("width"));
        width->setMaximum(100);

        gridLayout_2->addWidget(width, 8, 2, 1, 1);

        length1 = new QSpinBox(VoronoiDialog);
        length1->setObjectName(QStringLiteral("length1"));
        length1->setMaximum(100);

        gridLayout_2->addWidget(length1, 9, 2, 1, 1);

        length2 = new QSpinBox(VoronoiDialog);
        length2->setObjectName(QStringLiteral("length2"));
        length2->setMaximum(100);

        gridLayout_2->addWidget(length2, 10, 2, 1, 1);


        retranslateUi(VoronoiDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VoronoiDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VoronoiDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VoronoiDialog);
    } // setupUi

    void retranslateUi(QDialog *VoronoiDialog)
    {
        VoronoiDialog->setWindowTitle(QApplication::translate("VoronoiDialog", "Dialog", 0));
        radio_random->setText(QApplication::translate("VoronoiDialog", "random", 0));
        label->setText(QApplication::translate("VoronoiDialog", "type", 0));
        radio_square->setText(QApplication::translate("VoronoiDialog", "square", 0));
        label_6->setText(QApplication::translate("VoronoiDialog", "radius (in %)", 0));
        label_7->setText(QApplication::translate("VoronoiDialog", "width (in %)", 0));
        label_8->setText(QApplication::translate("VoronoiDialog", "length (in %)", 0));
        label_9->setText(QApplication::translate("VoronoiDialog", "length (in %)", 0));
        label_11->setText(QApplication::translate("VoronoiDialog", "initial y", 0));
        label_12->setText(QApplication::translate("VoronoiDialog", "initial angle", 0));
        label_10->setText(QApplication::translate("VoronoiDialog", "initial x", 0));
        voronoi_type->clear();
        voronoi_type->insertItems(0, QStringList()
         << QApplication::translate("VoronoiDialog", "nearest distance", 0)
         << QApplication::translate("VoronoiDialog", "two nearest ratio", 0)
        );
        label_3->setText(QApplication::translate("VoronoiDialog", "point place", 0));
        label_2->setText(QApplication::translate("VoronoiDialog", "metric", 0));
        label_5->setText(QApplication::translate("VoronoiDialog", "number of points", 0));
        label_4->setText(QApplication::translate("VoronoiDialog", "connect L-system to input to use it for point placement", 0));
        radio_custom->setText(QApplication::translate("VoronoiDialog", "custom", 0));
        clear_button->setText(QApplication::translate("VoronoiDialog", "clear", 0));
        radio_cross_horizontal->setText(QApplication::translate("VoronoiDialog", "cross horizontal", 0));
        radio_cross_diagonal->setText(QApplication::translate("VoronoiDialog", "cross diagonal", 0));
        voronoi_metric->clear();
        voronoi_metric->insertItems(0, QStringList()
         << QApplication::translate("VoronoiDialog", "Euclidean", 0)
         << QApplication::translate("VoronoiDialog", "taxicab", 0)
         << QApplication::translate("VoronoiDialog", "Chebyshev", 0)
        );
        radio_circle->setText(QApplication::translate("VoronoiDialog", "circle", 0));
        label_13->setText(QApplication::translate("VoronoiDialog", "L-system", 0));
    } // retranslateUi

};

namespace Ui {
    class VoronoiDialog: public Ui_VoronoiDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VORONOIDIALOG_H
