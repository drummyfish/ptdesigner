/********************************************************************************
** Form generated from reading UI file 'ditherdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DITHERDIALOG_H
#define UI_DITHERDIALOG_H

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
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DitherDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *levels;
    QLabel *label_2;
    QComboBox *method;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DitherDialog)
    {
        if (DitherDialog->objectName().isEmpty())
            DitherDialog->setObjectName(QStringLiteral("DitherDialog"));
        DitherDialog->resize(216, 122);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DitherDialog->sizePolicy().hasHeightForWidth());
        DitherDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(DitherDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DitherDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        levels = new QSpinBox(DitherDialog);
        levels->setObjectName(QStringLiteral("levels"));
        levels->setMaximumSize(QSize(80, 16777215));
        levels->setMaximum(999999999);

        gridLayout->addWidget(levels, 0, 1, 1, 1);

        label_2 = new QLabel(DitherDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        method = new QComboBox(DitherDialog);
        method->setObjectName(QStringLiteral("method"));

        gridLayout->addWidget(method, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DitherDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);


        retranslateUi(DitherDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DitherDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DitherDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DitherDialog);
    } // setupUi

    void retranslateUi(QDialog *DitherDialog)
    {
        DitherDialog->setWindowTitle(QApplication::translate("DitherDialog", "Dialog", 0));
        label->setText(QApplication::translate("DitherDialog", "levels", 0));
        label_2->setText(QApplication::translate("DitherDialog", "method", 0));
        method->clear();
        method->insertItems(0, QStringList()
         << QApplication::translate("DitherDialog", "threshold", 0)
         << QApplication::translate("DitherDialog", "random", 0)
         << QApplication::translate("DitherDialog", "error propagation", 0)
         << QApplication::translate("DitherDialog", "ordered", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class DitherDialog: public Ui_DitherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DITHERDIALOG_H
