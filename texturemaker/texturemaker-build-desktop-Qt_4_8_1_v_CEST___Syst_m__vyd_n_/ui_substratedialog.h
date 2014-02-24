/********************************************************************************
** Form generated from reading UI file 'substratedialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSTRATEDIALOG_H
#define UI_SUBSTRATEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SubstrateDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QRadioButton *radio_yes;
    QLabel *label_2;
    QLabel *label;
    QRadioButton *radio_no;
    QLabel *label_4;
    QSpinBox *iterations;
    QSpinBox *lines;
    QComboBox *combo;
    QLabel *label_5;
    QCheckBox *grayscale;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SubstrateDialog)
    {
        if (SubstrateDialog->objectName().isEmpty())
            SubstrateDialog->setObjectName(QString::fromUtf8("SubstrateDialog"));
        SubstrateDialog->resize(256, 154);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SubstrateDialog->sizePolicy().hasHeightForWidth());
        SubstrateDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SubstrateDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(SubstrateDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        radio_yes = new QRadioButton(SubstrateDialog);
        radio_yes->setObjectName(QString::fromUtf8("radio_yes"));

        gridLayout->addWidget(radio_yes, 0, 1, 1, 1);

        label_2 = new QLabel(SubstrateDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label = new QLabel(SubstrateDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        radio_no = new QRadioButton(SubstrateDialog);
        radio_no->setObjectName(QString::fromUtf8("radio_no"));

        gridLayout->addWidget(radio_no, 1, 1, 1, 1);

        label_4 = new QLabel(SubstrateDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        iterations = new QSpinBox(SubstrateDialog);
        iterations->setObjectName(QString::fromUtf8("iterations"));
        iterations->setMaximum(999999);

        gridLayout->addWidget(iterations, 0, 3, 1, 1);

        lines = new QSpinBox(SubstrateDialog);
        lines->setObjectName(QString::fromUtf8("lines"));
        lines->setMaximum(9999);

        gridLayout->addWidget(lines, 1, 3, 1, 1);

        combo = new QComboBox(SubstrateDialog);
        combo->setObjectName(QString::fromUtf8("combo"));

        gridLayout->addWidget(combo, 4, 1, 1, 3);

        label_5 = new QLabel(SubstrateDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        grayscale = new QCheckBox(SubstrateDialog);
        grayscale->setObjectName(QString::fromUtf8("grayscale"));

        gridLayout->addWidget(grayscale, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(SubstrateDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 1, 1, 3);


        retranslateUi(SubstrateDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SubstrateDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SubstrateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SubstrateDialog);
    } // setupUi

    void retranslateUi(QDialog *SubstrateDialog)
    {
        SubstrateDialog->setWindowTitle(QApplication::translate("SubstrateDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SubstrateDialog", "iterate", 0, QApplication::UnicodeUTF8));
        radio_yes->setText(QApplication::translate("SubstrateDialog", "yes", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SubstrateDialog", "fill type", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SubstrateDialog", "iterations", 0, QApplication::UnicodeUTF8));
        radio_no->setText(QApplication::translate("SubstrateDialog", "no", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SubstrateDialog", "number of lines", 0, QApplication::UnicodeUTF8));
        combo->clear();
        combo->insertItems(0, QStringList()
         << QApplication::translate("SubstrateDialog", "none", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SubstrateDialog", "keep borders", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SubstrateDialog", "no borders", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("SubstrateDialog", "grayscale", 0, QApplication::UnicodeUTF8));
        grayscale->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SubstrateDialog: public Ui_SubstrateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSTRATEDIALOG_H
