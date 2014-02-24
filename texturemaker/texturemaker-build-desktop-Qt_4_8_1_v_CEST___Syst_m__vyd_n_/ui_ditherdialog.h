/********************************************************************************
** Form generated from reading UI file 'ditherdialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DITHERDIALOG_H
#define UI_DITHERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>

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
            DitherDialog->setObjectName(QString::fromUtf8("DitherDialog"));
        DitherDialog->resize(216, 122);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DitherDialog->sizePolicy().hasHeightForWidth());
        DitherDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(DitherDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DitherDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        levels = new QSpinBox(DitherDialog);
        levels->setObjectName(QString::fromUtf8("levels"));
        levels->setMaximumSize(QSize(80, 16777215));
        levels->setMaximum(999999999);

        gridLayout->addWidget(levels, 0, 1, 1, 1);

        label_2 = new QLabel(DitherDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        method = new QComboBox(DitherDialog);
        method->setObjectName(QString::fromUtf8("method"));

        gridLayout->addWidget(method, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DitherDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        DitherDialog->setWindowTitle(QApplication::translate("DitherDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DitherDialog", "levels", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DitherDialog", "method", 0, QApplication::UnicodeUTF8));
        method->clear();
        method->insertItems(0, QStringList()
         << QApplication::translate("DitherDialog", "threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DitherDialog", "random", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DitherDialog", "error propagation", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DitherDialog", "ordered", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class DitherDialog: public Ui_DitherDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DITHERDIALOG_H
