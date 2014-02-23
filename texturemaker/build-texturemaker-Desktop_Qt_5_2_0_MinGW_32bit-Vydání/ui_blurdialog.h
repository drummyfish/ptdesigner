/********************************************************************************
** Form generated from reading UI file 'blurdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLURDIALOG_H
#define UI_BLURDIALOG_H

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

class Ui_BlurDialog
{
public:
    QGridLayout *gridLayout;
    QSpinBox *intensity;
    QLabel *label_2;
    QLabel *label;
    QComboBox *direction;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BlurDialog)
    {
        if (BlurDialog->objectName().isEmpty())
            BlurDialog->setObjectName(QStringLiteral("BlurDialog"));
        BlurDialog->resize(265, 117);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BlurDialog->sizePolicy().hasHeightForWidth());
        BlurDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(BlurDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        intensity = new QSpinBox(BlurDialog);
        intensity->setObjectName(QStringLiteral("intensity"));
        intensity->setMaximumSize(QSize(50, 16777215));
        intensity->setMaximum(65536);

        gridLayout->addWidget(intensity, 1, 1, 1, 1);

        label_2 = new QLabel(BlurDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(BlurDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        direction = new QComboBox(BlurDialog);
        direction->setObjectName(QStringLiteral("direction"));
        direction->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(direction, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(BlurDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(BlurDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BlurDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BlurDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BlurDialog);
    } // setupUi

    void retranslateUi(QDialog *BlurDialog)
    {
        BlurDialog->setWindowTitle(QApplication::translate("BlurDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("BlurDialog", "direction", 0));
        label->setText(QApplication::translate("BlurDialog", "intensity", 0));
        direction->clear();
        direction->insertItems(0, QStringList()
         << QApplication::translate("BlurDialog", "none", 0)
         << QApplication::translate("BlurDialog", "horizontal", 0)
         << QApplication::translate("BlurDialog", "vertical", 0)
         << QApplication::translate("BlurDialog", "diagonal (bottom left to top right)", 0)
         << QApplication::translate("BlurDialog", "diagonal (top left to bottom right)", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class BlurDialog: public Ui_BlurDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLURDIALOG_H
