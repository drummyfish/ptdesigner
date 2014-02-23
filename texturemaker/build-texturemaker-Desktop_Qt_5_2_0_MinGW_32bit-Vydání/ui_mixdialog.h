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
    QComboBox *method_combo;
    QSlider *ratio_slider;
    QLineEdit *ratio_text;
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

        method_combo = new QComboBox(MixDialog);
        method_combo->setObjectName(QStringLiteral("method_combo"));

        gridLayout->addWidget(method_combo, 4, 3, 1, 1);

        ratio_slider = new QSlider(MixDialog);
        ratio_slider->setObjectName(QStringLiteral("ratio_slider"));
        ratio_slider->setMaximum(100);
        ratio_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ratio_slider, 3, 3, 1, 1);

        ratio_text = new QLineEdit(MixDialog);
        ratio_text->setObjectName(QStringLiteral("ratio_text"));
        ratio_text->setMaximumSize(QSize(50, 16777215));
        ratio_text->setReadOnly(true);

        gridLayout->addWidget(ratio_text, 3, 1, 1, 1);

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
        method_combo->clear();
        method_combo->insertItems(0, QStringList()
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
