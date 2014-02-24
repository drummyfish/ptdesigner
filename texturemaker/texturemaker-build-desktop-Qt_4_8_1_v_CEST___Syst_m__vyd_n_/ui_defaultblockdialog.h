/********************************************************************************
** Form generated from reading UI file 'defaultblockdialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTBLOCKDIALOG_H
#define UI_DEFAULTBLOCKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DefaultBlockDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DefaultBlockDialog)
    {
        if (DefaultBlockDialog->objectName().isEmpty())
            DefaultBlockDialog->setObjectName(QString::fromUtf8("DefaultBlockDialog"));
        DefaultBlockDialog->resize(400, 300);
        gridLayout = new QGridLayout(DefaultBlockDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(DefaultBlockDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 0, 1, 1);


        retranslateUi(DefaultBlockDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DefaultBlockDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DefaultBlockDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DefaultBlockDialog);
    } // setupUi

    void retranslateUi(QDialog *DefaultBlockDialog)
    {
        DefaultBlockDialog->setWindowTitle(QApplication::translate("DefaultBlockDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DefaultBlockDialog: public Ui_DefaultBlockDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTBLOCKDIALOG_H
