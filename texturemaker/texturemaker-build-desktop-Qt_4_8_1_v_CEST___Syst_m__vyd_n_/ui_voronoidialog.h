/********************************************************************************
** Form generated from reading UI file 'voronoidialog.ui'
**
** Created: Sat Feb 8 15:28:37 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VORONOIDIALOG_H
#define UI_VORONOIDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
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
            VoronoiDialog->setObjectName(QString::fromUtf8("VoronoiDialog"));
        VoronoiDialog->resize(411, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VoronoiDialog->sizePolicy().hasHeightForWidth());
        VoronoiDialog->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(VoronoiDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        radio_random = new QRadioButton(VoronoiDialog);
        radio_random->setObjectName(QString::fromUtf8("radio_random"));

        gridLayout_2->addWidget(radio_random, 6, 0, 1, 1);

        label = new QLabel(VoronoiDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        number_of_points = new QSpinBox(VoronoiDialog);
        number_of_points->setObjectName(QString::fromUtf8("number_of_points"));
        number_of_points->setMaximum(65536);

        gridLayout_2->addWidget(number_of_points, 4, 2, 1, 1);

        radio_square = new QRadioButton(VoronoiDialog);
        radio_square->setObjectName(QString::fromUtf8("radio_square"));

        gridLayout_2->addWidget(radio_square, 8, 0, 1, 1);

        label_6 = new QLabel(VoronoiDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 7, 1, 1, 1);

        label_7 = new QLabel(VoronoiDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 8, 1, 1, 1);

        label_8 = new QLabel(VoronoiDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 9, 1, 1, 1);

        label_9 = new QLabel(VoronoiDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 10, 1, 1, 1);

        initial_y = new QDoubleSpinBox(VoronoiDialog);
        initial_y->setObjectName(QString::fromUtf8("initial_y"));
        initial_y->setMaximum(1);

        gridLayout_2->addWidget(initial_y, 16, 1, 1, 1);

        label_11 = new QLabel(VoronoiDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 16, 0, 1, 1);

        label_12 = new QLabel(VoronoiDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 17, 0, 1, 1);

        label_10 = new QLabel(VoronoiDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 15, 0, 1, 1);

        initial_angle = new QSpinBox(VoronoiDialog);
        initial_angle->setObjectName(QString::fromUtf8("initial_angle"));

        gridLayout_2->addWidget(initial_angle, 17, 1, 1, 1);

        voronoi_type = new QComboBox(VoronoiDialog);
        voronoi_type->setObjectName(QString::fromUtf8("voronoi_type"));

        gridLayout_2->addWidget(voronoi_type, 1, 2, 1, 1);

        buttonBox = new QDialogButtonBox(VoronoiDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setMaximumSize(QSize(200, 16777215));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 20, 2, 1, 1);

        label_3 = new QLabel(VoronoiDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(VoronoiDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(VoronoiDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 1, 1, 1);

        label_4 = new QLabel(VoronoiDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMaximumSize(QSize(100, 16777215));
        label_4->setWordWrap(true);

        gridLayout_2->addWidget(label_4, 13, 0, 1, 1);

        radio_custom = new QRadioButton(VoronoiDialog);
        radio_custom->setObjectName(QString::fromUtf8("radio_custom"));

        gridLayout_2->addWidget(radio_custom, 11, 0, 1, 1);

        initial_x = new QDoubleSpinBox(VoronoiDialog);
        initial_x->setObjectName(QString::fromUtf8("initial_x"));
        initial_x->setMaximum(1);

        gridLayout_2->addWidget(initial_x, 15, 1, 1, 1);

        clear_button = new QPushButton(VoronoiDialog);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));

        gridLayout_2->addWidget(clear_button, 11, 2, 1, 1);

        point_editor = new PointEditFrame(VoronoiDialog);
        point_editor->setObjectName(QString::fromUtf8("point_editor"));
        point_editor->setMinimumSize(QSize(200, 200));
        point_editor->setMaximumSize(QSize(200, 200));
        point_editor->setFrameShape(QFrame::StyledPanel);
        point_editor->setFrameShadow(QFrame::Plain);

        gridLayout_2->addWidget(point_editor, 13, 2, 1, 1);

        radio_cross_horizontal = new QRadioButton(VoronoiDialog);
        radio_cross_horizontal->setObjectName(QString::fromUtf8("radio_cross_horizontal"));

        gridLayout_2->addWidget(radio_cross_horizontal, 9, 0, 1, 1);

        radio_cross_diagonal = new QRadioButton(VoronoiDialog);
        radio_cross_diagonal->setObjectName(QString::fromUtf8("radio_cross_diagonal"));

        gridLayout_2->addWidget(radio_cross_diagonal, 10, 0, 1, 1);

        voronoi_metric = new QComboBox(VoronoiDialog);
        voronoi_metric->setObjectName(QString::fromUtf8("voronoi_metric"));

        gridLayout_2->addWidget(voronoi_metric, 2, 2, 1, 1);

        radio_circle = new QRadioButton(VoronoiDialog);
        radio_circle->setObjectName(QString::fromUtf8("radio_circle"));

        gridLayout_2->addWidget(radio_circle, 7, 0, 1, 1);

        label_13 = new QLabel(VoronoiDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 14, 0, 1, 1);

        radius = new QSpinBox(VoronoiDialog);
        radius->setObjectName(QString::fromUtf8("radius"));
        radius->setMaximum(100);

        gridLayout_2->addWidget(radius, 7, 2, 1, 1);

        width = new QSpinBox(VoronoiDialog);
        width->setObjectName(QString::fromUtf8("width"));
        width->setMaximum(100);

        gridLayout_2->addWidget(width, 8, 2, 1, 1);

        length1 = new QSpinBox(VoronoiDialog);
        length1->setObjectName(QString::fromUtf8("length1"));
        length1->setMaximum(100);

        gridLayout_2->addWidget(length1, 9, 2, 1, 1);

        length2 = new QSpinBox(VoronoiDialog);
        length2->setObjectName(QString::fromUtf8("length2"));
        length2->setMaximum(100);

        gridLayout_2->addWidget(length2, 10, 2, 1, 1);


        retranslateUi(VoronoiDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), VoronoiDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VoronoiDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(VoronoiDialog);
    } // setupUi

    void retranslateUi(QDialog *VoronoiDialog)
    {
        VoronoiDialog->setWindowTitle(QApplication::translate("VoronoiDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        radio_random->setText(QApplication::translate("VoronoiDialog", "random", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("VoronoiDialog", "type", 0, QApplication::UnicodeUTF8));
        radio_square->setText(QApplication::translate("VoronoiDialog", "square", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("VoronoiDialog", "radius (in %)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("VoronoiDialog", "width (in %)", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("VoronoiDialog", "length (in %)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("VoronoiDialog", "length (in %)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("VoronoiDialog", "initial y", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("VoronoiDialog", "initial angle", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("VoronoiDialog", "initial x", 0, QApplication::UnicodeUTF8));
        voronoi_type->clear();
        voronoi_type->insertItems(0, QStringList()
         << QApplication::translate("VoronoiDialog", "nearest distance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VoronoiDialog", "two nearest ratio", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("VoronoiDialog", "point place", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("VoronoiDialog", "metric", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("VoronoiDialog", "number of points", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("VoronoiDialog", "connect L-system to input to use it for point placement", 0, QApplication::UnicodeUTF8));
        radio_custom->setText(QApplication::translate("VoronoiDialog", "custom", 0, QApplication::UnicodeUTF8));
        clear_button->setText(QApplication::translate("VoronoiDialog", "clear", 0, QApplication::UnicodeUTF8));
        radio_cross_horizontal->setText(QApplication::translate("VoronoiDialog", "cross horizontal", 0, QApplication::UnicodeUTF8));
        radio_cross_diagonal->setText(QApplication::translate("VoronoiDialog", "cross diagonal", 0, QApplication::UnicodeUTF8));
        voronoi_metric->clear();
        voronoi_metric->insertItems(0, QStringList()
         << QApplication::translate("VoronoiDialog", "Euclidean", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VoronoiDialog", "taxicab", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("VoronoiDialog", "Chebyshev", 0, QApplication::UnicodeUTF8)
        );
        radio_circle->setText(QApplication::translate("VoronoiDialog", "circle", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("VoronoiDialog", "L-system", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VoronoiDialog: public Ui_VoronoiDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VORONOIDIALOG_H
