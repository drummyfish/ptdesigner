/********************************************************************************
** Form generated from reading UI file 'colortransitiondialog.ui'
**
** Created: Sat Feb 8 15:28:37 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORTRANSITIONDIALOG_H
#define UI_COLORTRANSITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include "transitionpreviewframe.h"

QT_BEGIN_NAMESPACE

class Ui_ColorTransitionDialog
{
public:
    QGridLayout *gridLayout;
    QListWidget *points;
    TransitionPreviewFrame *transition_preview;
    QDialogButtonBox *buttonBox;
    QSpinBox *coordination;
    QPushButton *add_button;
    QPushButton *edit_button;
    QPushButton *delete_button;

    void setupUi(QDialog *ColorTransitionDialog)
    {
        if (ColorTransitionDialog->objectName().isEmpty())
            ColorTransitionDialog->setObjectName(QString::fromUtf8("ColorTransitionDialog"));
        ColorTransitionDialog->resize(355, 271);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorTransitionDialog->sizePolicy().hasHeightForWidth());
        ColorTransitionDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ColorTransitionDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        points = new QListWidget(ColorTransitionDialog);
        points->setObjectName(QString::fromUtf8("points"));

        gridLayout->addWidget(points, 6, 2, 5, 1);

        transition_preview = new TransitionPreviewFrame(ColorTransitionDialog);
        transition_preview->setObjectName(QString::fromUtf8("transition_preview"));
        transition_preview->setMinimumSize(QSize(256, 50));
        transition_preview->setMaximumSize(QSize(256, 50));
        transition_preview->setFrameShape(QFrame::StyledPanel);
        transition_preview->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(transition_preview, 2, 2, 1, 1);

        buttonBox = new QDialogButtonBox(ColorTransitionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 3, 1, 1);

        coordination = new QSpinBox(ColorTransitionDialog);
        coordination->setObjectName(QString::fromUtf8("coordination"));
        coordination->setMaximumSize(QSize(75, 16777215));
        coordination->setMaximum(255);

        gridLayout->addWidget(coordination, 10, 3, 1, 1);

        add_button = new QPushButton(ColorTransitionDialog);
        add_button->setObjectName(QString::fromUtf8("add_button"));

        gridLayout->addWidget(add_button, 9, 3, 1, 1);

        edit_button = new QPushButton(ColorTransitionDialog);
        edit_button->setObjectName(QString::fromUtf8("edit_button"));

        gridLayout->addWidget(edit_button, 8, 3, 1, 1);

        delete_button = new QPushButton(ColorTransitionDialog);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));

        gridLayout->addWidget(delete_button, 7, 3, 1, 1);


        retranslateUi(ColorTransitionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorTransitionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorTransitionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorTransitionDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorTransitionDialog)
    {
        ColorTransitionDialog->setWindowTitle(QApplication::translate("ColorTransitionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        add_button->setText(QApplication::translate("ColorTransitionDialog", "add point", 0, QApplication::UnicodeUTF8));
        edit_button->setText(QApplication::translate("ColorTransitionDialog", "edit color", 0, QApplication::UnicodeUTF8));
        delete_button->setText(QApplication::translate("ColorTransitionDialog", "delete", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorTransitionDialog: public Ui_ColorTransitionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORTRANSITIONDIALOG_H
