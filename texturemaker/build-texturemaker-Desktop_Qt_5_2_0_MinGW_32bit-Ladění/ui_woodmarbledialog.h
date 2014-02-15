/********************************************************************************
** Form generated from reading UI file 'woodmarbledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WOODMARBLEDIALOG_H
#define UI_WOODMARBLEDIALOG_H

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

class Ui_WoodMarbleDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_hardness;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_periods;
    QSpinBox *amplitude;
    QLabel *label_circles;
    QSpinBox *periods;
    QSpinBox *hardness;
    QSpinBox *intensity;
    QDialogButtonBox *buttonBox;
    QSpinBox *circles;
    QComboBox *combo;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *WoodMarbleDialog)
    {
        if (WoodMarbleDialog->objectName().isEmpty())
            WoodMarbleDialog->setObjectName(QStringLiteral("WoodMarbleDialog"));
        WoodMarbleDialog->resize(240, 227);
        gridLayout = new QGridLayout(WoodMarbleDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_hardness = new QLabel(WoodMarbleDialog);
        label_hardness->setObjectName(QStringLiteral("label_hardness"));

        gridLayout->addWidget(label_hardness, 1, 0, 1, 1);

        label_4 = new QLabel(WoodMarbleDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label = new QLabel(WoodMarbleDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_periods = new QLabel(WoodMarbleDialog);
        label_periods->setObjectName(QStringLiteral("label_periods"));

        gridLayout->addWidget(label_periods, 3, 0, 1, 1);

        amplitude = new QSpinBox(WoodMarbleDialog);
        amplitude->setObjectName(QStringLiteral("amplitude"));
        amplitude->setMaximumSize(QSize(80, 16777215));
        amplitude->setMaximum(128);

        gridLayout->addWidget(amplitude, 4, 2, 1, 1);

        label_circles = new QLabel(WoodMarbleDialog);
        label_circles->setObjectName(QStringLiteral("label_circles"));

        gridLayout->addWidget(label_circles, 0, 0, 1, 1);

        periods = new QSpinBox(WoodMarbleDialog);
        periods->setObjectName(QStringLiteral("periods"));
        periods->setMaximumSize(QSize(80, 16777215));
        periods->setMaximum(99999);

        gridLayout->addWidget(periods, 3, 2, 1, 1);

        hardness = new QSpinBox(WoodMarbleDialog);
        hardness->setObjectName(QStringLiteral("hardness"));
        hardness->setMaximumSize(QSize(80, 16777215));
        hardness->setMaximum(99999);

        gridLayout->addWidget(hardness, 1, 2, 1, 1);

        intensity = new QSpinBox(WoodMarbleDialog);
        intensity->setObjectName(QStringLiteral("intensity"));
        intensity->setMaximumSize(QSize(80, 16777215));
        intensity->setMaximum(999999);

        gridLayout->addWidget(intensity, 2, 2, 1, 1);

        buttonBox = new QDialogButtonBox(WoodMarbleDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 2, 1, 1);

        circles = new QSpinBox(WoodMarbleDialog);
        circles->setObjectName(QStringLiteral("circles"));
        circles->setMaximumSize(QSize(80, 16777215));
        circles->setMaximum(999999);

        gridLayout->addWidget(circles, 0, 2, 1, 1);

        combo = new QComboBox(WoodMarbleDialog);
        combo->setObjectName(QStringLiteral("combo"));

        gridLayout->addWidget(combo, 5, 2, 1, 1);

        label_2 = new QLabel(WoodMarbleDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);

        label_3 = new QLabel(WoodMarbleDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 6, 0, 1, 3);


        retranslateUi(WoodMarbleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WoodMarbleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WoodMarbleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WoodMarbleDialog);
    } // setupUi

    void retranslateUi(QDialog *WoodMarbleDialog)
    {
        WoodMarbleDialog->setWindowTitle(QApplication::translate("WoodMarbleDialog", "Dialog", 0));
        label_hardness->setText(QApplication::translate("WoodMarbleDialog", "hardness", 0));
        label_4->setText(QApplication::translate("WoodMarbleDialog", "amplitude", 0));
        label->setText(QApplication::translate("WoodMarbleDialog", "intensity", 0));
        label_periods->setText(QApplication::translate("WoodMarbleDialog", "periods", 0));
        label_circles->setText(QApplication::translate("WoodMarbleDialog", "circles", 0));
        combo->clear();
        combo->insertItems(0, QStringList()
         << QApplication::translate("WoodMarbleDialog", "horizontal", 0)
         << QApplication::translate("WoodMarbleDialog", "vertical", 0)
         << QApplication::translate("WoodMarbleDialog", "diagonal (bottom left to top right)", 0)
         << QApplication::translate("WoodMarbleDialog", "diagonal (top left to bottom right)", 0)
        );
        label_2->setText(QApplication::translate("WoodMarbleDialog", "direction", 0));
        label_3->setText(QApplication::translate("WoodMarbleDialog", "For custom noise connect a block to the input.", 0));
    } // retranslateUi

};

namespace Ui {
    class WoodMarbleDialog: public Ui_WoodMarbleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WOODMARBLEDIALOG_H
