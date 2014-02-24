/********************************************************************************
** Form generated from reading UI file 'mixdialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIXDIALOG_H
#define UI_MIXDIALOG_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>

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
            MixDialog->setObjectName(QString::fromUtf8("MixDialog"));
        MixDialog->resize(272, 121);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MixDialog->sizePolicy().hasHeightForWidth());
        MixDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(MixDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(MixDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(MixDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 3, 1, 1);

        method_combo = new QComboBox(MixDialog);
        method_combo->setObjectName(QString::fromUtf8("method_combo"));

        gridLayout->addWidget(method_combo, 4, 3, 1, 1);

        ratio_slider = new QSlider(MixDialog);
        ratio_slider->setObjectName(QString::fromUtf8("ratio_slider"));
        ratio_slider->setMaximum(100);
        ratio_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ratio_slider, 3, 3, 1, 1);

        ratio_text = new QLineEdit(MixDialog);
        ratio_text->setObjectName(QString::fromUtf8("ratio_text"));
        ratio_text->setMaximumSize(QSize(50, 16777215));
        ratio_text->setReadOnly(true);

        gridLayout->addWidget(ratio_text, 3, 1, 1, 1);

        label = new QLabel(MixDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);


        retranslateUi(MixDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MixDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MixDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MixDialog);
    } // setupUi

    void retranslateUi(QDialog *MixDialog)
    {
        MixDialog->setWindowTitle(QApplication::translate("MixDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MixDialog", "method", 0, QApplication::UnicodeUTF8));
        method_combo->clear();
        method_combo->insertItems(0, QStringList()
         << QApplication::translate("MixDialog", "add", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixDialog", "substract", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixDialog", "average", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MixDialog", "multiply", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("MixDialog", "ratio", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MixDialog: public Ui_MixDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIXDIALOG_H
