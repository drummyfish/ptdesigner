/********************************************************************************
** Form generated from reading UI file 'defaultblockdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEFAULTBLOCKDIALOG_H
#define UI_DEFAULTBLOCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DefaultBlockDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DefaultBlockDialog)
    {
        if (DefaultBlockDialog->objectName().isEmpty())
            DefaultBlockDialog->setObjectName(QStringLiteral("DefaultBlockDialog"));
        DefaultBlockDialog->resize(400, 300);
        gridLayout = new QGridLayout(DefaultBlockDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(DefaultBlockDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        DefaultBlockDialog->setWindowTitle(QApplication::translate("DefaultBlockDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DefaultBlockDialog: public Ui_DefaultBlockDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEFAULTBLOCKDIALOG_H
