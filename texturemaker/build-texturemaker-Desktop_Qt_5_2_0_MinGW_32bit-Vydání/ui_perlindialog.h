/********************************************************************************
** Form generated from reading UI file 'perlindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERLINDIALOG_H
#define UI_PERLINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PerlinDialog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *amplitude_value;
    QSlider *amplitude_slider;
    QLabel *label_3;
    QSpinBox *max_iterations;
    QComboBox *interpolation_combo;
    QLabel *label;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QCheckBox *smooth;
    QRadioButton *radio_unlimited;
    QRadioButton *radio_maximum;
    QLabel *label_4;
    QSpinBox *frequency;

    void setupUi(QDialog *PerlinDialog)
    {
        if (PerlinDialog->objectName().isEmpty())
            PerlinDialog->setObjectName(QStringLiteral("PerlinDialog"));
        PerlinDialog->resize(303, 182);
        gridLayout = new QGridLayout(PerlinDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        amplitude_value = new QLineEdit(PerlinDialog);
        amplitude_value->setObjectName(QStringLiteral("amplitude_value"));
        amplitude_value->setMaximumSize(QSize(60, 16777215));
        amplitude_value->setReadOnly(true);

        gridLayout->addWidget(amplitude_value, 0, 2, 1, 1);

        amplitude_slider = new QSlider(PerlinDialog);
        amplitude_slider->setObjectName(QStringLiteral("amplitude_slider"));
        amplitude_slider->setMaximum(127);
        amplitude_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(amplitude_slider, 0, 3, 1, 1);

        label_3 = new QLabel(PerlinDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        max_iterations = new QSpinBox(PerlinDialog);
        max_iterations->setObjectName(QStringLiteral("max_iterations"));
        max_iterations->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(max_iterations, 7, 3, 1, 1);

        interpolation_combo = new QComboBox(PerlinDialog);
        interpolation_combo->setObjectName(QStringLiteral("interpolation_combo"));
        interpolation_combo->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(interpolation_combo, 2, 2, 1, 2);

        label = new QLabel(PerlinDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(PerlinDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PerlinDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 10, 2, 1, 2);

        smooth = new QCheckBox(PerlinDialog);
        smooth->setObjectName(QStringLiteral("smooth"));

        gridLayout->addWidget(smooth, 4, 0, 1, 1);

        radio_unlimited = new QRadioButton(PerlinDialog);
        radio_unlimited->setObjectName(QStringLiteral("radio_unlimited"));

        gridLayout->addWidget(radio_unlimited, 7, 0, 1, 1);

        radio_maximum = new QRadioButton(PerlinDialog);
        radio_maximum->setObjectName(QStringLiteral("radio_maximum"));

        gridLayout->addWidget(radio_maximum, 7, 2, 1, 1);

        label_4 = new QLabel(PerlinDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        frequency = new QSpinBox(PerlinDialog);
        frequency->setObjectName(QStringLiteral("frequency"));
        frequency->setMinimum(1);
        frequency->setMaximum(65536);

        gridLayout->addWidget(frequency, 1, 2, 1, 1);


        retranslateUi(PerlinDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PerlinDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PerlinDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PerlinDialog);
    } // setupUi

    void retranslateUi(QDialog *PerlinDialog)
    {
        PerlinDialog->setWindowTitle(QApplication::translate("PerlinDialog", "Dialog", 0));
        label_3->setText(QApplication::translate("PerlinDialog", "iterations", 0));
        interpolation_combo->clear();
        interpolation_combo->insertItems(0, QStringList()
         << QApplication::translate("PerlinDialog", "nearest neighbour", 0)
         << QApplication::translate("PerlinDialog", "linear", 0)
         << QApplication::translate("PerlinDialog", "sine", 0)
        );
        label->setText(QApplication::translate("PerlinDialog", "amplitude", 0));
        label_2->setText(QApplication::translate("PerlinDialog", "interpolation", 0));
        smooth->setText(QApplication::translate("PerlinDialog", "smooth", 0));
        radio_unlimited->setText(QApplication::translate("PerlinDialog", "unlimited", 0));
        radio_maximum->setText(QApplication::translate("PerlinDialog", "maximum", 0));
        label_4->setText(QApplication::translate("PerlinDialog", "frequency", 0));
    } // retranslateUi

};

namespace Ui {
    class PerlinDialog: public Ui_PerlinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERLINDIALOG_H
