/********************************************************************************
** Form generated from reading UI file 'mixdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIXDIALOG_H
#define UI_MIXDIALOG_H

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
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_MixDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *MixDialog)
    {
        if (MixDialog->objectName().isEmpty())
            MixDialog->setObjectName(QStringLiteral("MixDialog"));
        MixDialog->resize(272, 121);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MixDialog->sizePolicy().hasHeightForWidth());
        MixDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MixDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(MixDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MixDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 3, 1, 1);

        comboBox = new QComboBox(MixDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 4, 3, 1, 1);

        horizontalSlider = new QSlider(MixDialog);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 3, 3, 1, 1);

        lineEdit = new QLineEdit(MixDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaximumSize(QSize(50, 16777215));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 3, 1, 1, 1);

        label = new QLabel(MixDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);


        retranslateUi(MixDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MixDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MixDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MixDialog);
    } // setupUi

    void retranslateUi(QDialog *MixDialog)
    {
        MixDialog->setWindowTitle(QApplication::translate("MixDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("MixDialog", "method", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MixDialog", "add", 0)
         << QApplication::translate("MixDialog", "substract", 0)
         << QApplication::translate("MixDialog", "average", 0)
         << QApplication::translate("MixDialog", "multiply", 0)
        );
        label->setText(QApplication::translate("MixDialog", "ratio", 0));
    } // retranslateUi

};

namespace Ui {
    class MixDialog: public Ui_MixDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIXDIALOG_H
