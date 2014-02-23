/********************************************************************************
** Form generated from reading UI file 'mosaicdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOSAICDIALOG_H
#define UI_MOSAICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include "mosaicsideeditframe.h"

QT_BEGIN_NAMESPACE

class Ui_MosaicDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_8;
    QComboBox *fill_type_combo;
    QComboBox *combo_1;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_3;
    QSpinBox *repeat_x;
    QLabel *label_2;
    QLabel *label_5;
    QSpinBox *repeat_y;
    QComboBox *combo_2;
    QDialogButtonBox *buttonBox;
    QLabel *validity;
    QLabel *label_7;
    QLineEdit *colors;
    QLabel *label_9;
    QLabel *label_6;
    QComboBox *combo_3;
    QComboBox *combo_4;
    MosaicSideEditFrame *point_edit_2;
    MosaicSideEditFrame *point_edit_3;
    MosaicSideEditFrame *point_edit_4;
    MosaicSideEditFrame *point_edit_1;
    QLabel *label_10;
    QPushButton *clear_1;
    QPushButton *clear_2;
    QPushButton *clear_3;
    QPushButton *clear_4;

    void setupUi(QDialog *MosaicDialog)
    {
        if (MosaicDialog->objectName().isEmpty())
            MosaicDialog->setObjectName(QStringLiteral("MosaicDialog"));
        MosaicDialog->resize(682, 370);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MosaicDialog->sizePolicy().hasHeightForWidth());
        MosaicDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MosaicDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_8 = new QLabel(MosaicDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 20, 0, 1, 1);

        fill_type_combo = new QComboBox(MosaicDialog);
        fill_type_combo->setObjectName(QStringLiteral("fill_type_combo"));

        gridLayout->addWidget(fill_type_combo, 21, 1, 1, 1);

        combo_1 = new QComboBox(MosaicDialog);
        combo_1->setObjectName(QStringLiteral("combo_1"));

        gridLayout->addWidget(combo_1, 7, 0, 1, 1);

        label_4 = new QLabel(MosaicDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 2);

        label = new QLabel(MosaicDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(MosaicDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        repeat_x = new QSpinBox(MosaicDialog);
        repeat_x->setObjectName(QStringLiteral("repeat_x"));
        repeat_x->setMinimumSize(QSize(50, 0));
        repeat_x->setMaximumSize(QSize(75, 16777215));
        repeat_x->setMinimum(1);

        gridLayout->addWidget(repeat_x, 17, 1, 1, 1);

        label_2 = new QLabel(MosaicDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_5 = new QLabel(MosaicDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 17, 0, 1, 1);

        repeat_y = new QSpinBox(MosaicDialog);
        repeat_y->setObjectName(QStringLiteral("repeat_y"));
        repeat_y->setMaximumSize(QSize(75, 16777215));
        repeat_y->setMinimum(1);

        gridLayout->addWidget(repeat_y, 18, 1, 1, 1);

        combo_2 = new QComboBox(MosaicDialog);
        combo_2->setObjectName(QStringLiteral("combo_2"));

        gridLayout->addWidget(combo_2, 7, 1, 1, 1);

        buttonBox = new QDialogButtonBox(MosaicDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 21, 3, 1, 1);

        validity = new QLabel(MosaicDialog);
        validity->setObjectName(QStringLiteral("validity"));

        gridLayout->addWidget(validity, 17, 3, 1, 1);

        label_7 = new QLabel(MosaicDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 17, 2, 1, 1);

        colors = new QLineEdit(MosaicDialog);
        colors->setObjectName(QStringLiteral("colors"));

        gridLayout->addWidget(colors, 20, 1, 1, 1);

        label_9 = new QLabel(MosaicDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 21, 0, 1, 1);

        label_6 = new QLabel(MosaicDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 18, 0, 1, 1);

        combo_3 = new QComboBox(MosaicDialog);
        combo_3->setObjectName(QStringLiteral("combo_3"));

        gridLayout->addWidget(combo_3, 7, 2, 1, 1);

        combo_4 = new QComboBox(MosaicDialog);
        combo_4->setObjectName(QStringLiteral("combo_4"));

        gridLayout->addWidget(combo_4, 7, 3, 1, 1);

        point_edit_2 = new MosaicSideEditFrame(MosaicDialog);
        point_edit_2->setObjectName(QStringLiteral("point_edit_2"));
        point_edit_2->setMinimumSize(QSize(160, 125));
        point_edit_2->setMaximumSize(QSize(120, 75));
        point_edit_2->setFrameShape(QFrame::StyledPanel);
        point_edit_2->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(point_edit_2, 3, 1, 1, 1);

        point_edit_3 = new MosaicSideEditFrame(MosaicDialog);
        point_edit_3->setObjectName(QStringLiteral("point_edit_3"));
        point_edit_3->setMinimumSize(QSize(160, 125));
        point_edit_3->setMaximumSize(QSize(120, 75));
        point_edit_3->setFrameShape(QFrame::StyledPanel);
        point_edit_3->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(point_edit_3, 3, 2, 1, 1);

        point_edit_4 = new MosaicSideEditFrame(MosaicDialog);
        point_edit_4->setObjectName(QStringLiteral("point_edit_4"));
        point_edit_4->setMinimumSize(QSize(160, 125));
        point_edit_4->setMaximumSize(QSize(120, 75));
        point_edit_4->setFrameShape(QFrame::StyledPanel);
        point_edit_4->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(point_edit_4, 3, 3, 1, 1);

        point_edit_1 = new MosaicSideEditFrame(MosaicDialog);
        point_edit_1->setObjectName(QStringLiteral("point_edit_1"));
        point_edit_1->setMinimumSize(QSize(160, 125));
        point_edit_1->setMaximumSize(QSize(120, 75));
        point_edit_1->setFrameShape(QFrame::StyledPanel);
        point_edit_1->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(point_edit_1, 3, 0, 1, 1);

        label_10 = new QLabel(MosaicDialog);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        clear_1 = new QPushButton(MosaicDialog);
        clear_1->setObjectName(QStringLiteral("clear_1"));

        gridLayout->addWidget(clear_1, 1, 0, 1, 1);

        clear_2 = new QPushButton(MosaicDialog);
        clear_2->setObjectName(QStringLiteral("clear_2"));

        gridLayout->addWidget(clear_2, 1, 1, 1, 1);

        clear_3 = new QPushButton(MosaicDialog);
        clear_3->setObjectName(QStringLiteral("clear_3"));

        gridLayout->addWidget(clear_3, 1, 2, 1, 1);

        clear_4 = new QPushButton(MosaicDialog);
        clear_4->setObjectName(QStringLiteral("clear_4"));

        gridLayout->addWidget(clear_4, 1, 3, 1, 1);


        retranslateUi(MosaicDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MosaicDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MosaicDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MosaicDialog);
    } // setupUi

    void retranslateUi(QDialog *MosaicDialog)
    {
        MosaicDialog->setWindowTitle(QApplication::translate("MosaicDialog", "Dialog", 0));
        label_8->setText(QApplication::translate("MosaicDialog", "fill colors", 0));
        fill_type_combo->clear();
        fill_type_combo->insertItems(0, QStringList()
         << QApplication::translate("MosaicDialog", "none", 0)
         << QApplication::translate("MosaicDialog", "keep borders", 0)
         << QApplication::translate("MosaicDialog", "no borders", 0)
        );
        combo_1->clear();
        combo_1->insertItems(0, QStringList()
         << QApplication::translate("MosaicDialog", "rotate around center", 0)
         << QApplication::translate("MosaicDialog", "rotate around vertex", 0)
         << QApplication::translate("MosaicDialog", "shift", 0)
         << QApplication::translate("MosaicDialog", "shift and flip", 0)
        );
        label_4->setText(QApplication::translate("MosaicDialog", "left", 0));
        label->setText(QApplication::translate("MosaicDialog", "top", 0));
        label_3->setText(QApplication::translate("MosaicDialog", "bottom", 0));
        label_2->setText(QApplication::translate("MosaicDialog", "right", 0));
        label_5->setText(QApplication::translate("MosaicDialog", "repeat horizontally", 0));
        combo_2->clear();
        combo_2->insertItems(0, QStringList()
         << QApplication::translate("MosaicDialog", "rotate around center", 0)
         << QApplication::translate("MosaicDialog", "rotate around vertex", 0)
         << QApplication::translate("MosaicDialog", "shift", 0)
         << QApplication::translate("MosaicDialog", "shift and flip", 0)
        );
        validity->setText(QApplication::translate("MosaicDialog", "validity", 0));
        label_7->setText(QApplication::translate("MosaicDialog", "this specification is", 0));
        label_9->setText(QApplication::translate("MosaicDialog", "fill type", 0));
        label_6->setText(QApplication::translate("MosaicDialog", "repeat vertically", 0));
        combo_3->clear();
        combo_3->insertItems(0, QStringList()
         << QApplication::translate("MosaicDialog", "rotate around center", 0)
         << QApplication::translate("MosaicDialog", "rotate around vertex", 0)
         << QApplication::translate("MosaicDialog", "shift", 0)
         << QApplication::translate("MosaicDialog", "shift and flip", 0)
        );
        combo_4->clear();
        combo_4->insertItems(0, QStringList()
         << QApplication::translate("MosaicDialog", "rotate around center", 0)
         << QApplication::translate("MosaicDialog", "rotate around vertex", 0)
         << QApplication::translate("MosaicDialog", "shift", 0)
         << QApplication::translate("MosaicDialog", "shift and flip", 0)
        );
        label_10->setText(QString());
        clear_1->setText(QApplication::translate("MosaicDialog", "clear", 0));
        clear_2->setText(QApplication::translate("MosaicDialog", "clear", 0));
        clear_3->setText(QApplication::translate("MosaicDialog", "clear", 0));
        clear_4->setText(QApplication::translate("MosaicDialog", "clear", 0));
    } // retranslateUi

};

namespace Ui {
    class MosaicDialog: public Ui_MosaicDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOSAICDIALOG_H
