/********************************************************************************
** Form generated from reading UI file 'blurdialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLURDIALOG_H
#define UI_BLURDIALOG_H

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
            BlurDialog->setObjectName(QString::fromUtf8("BlurDialog"));
        BlurDialog->resize(265, 117);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BlurDialog->sizePolicy().hasHeightForWidth());
        BlurDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(BlurDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        intensity = new QSpinBox(BlurDialog);
        intensity->setObjectName(QString::fromUtf8("intensity"));
        intensity->setMaximumSize(QSize(50, 16777215));
        intensity->setMaximum(65536);

        gridLayout->addWidget(intensity, 1, 1, 1, 1);

        label_2 = new QLabel(BlurDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(BlurDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        direction = new QComboBox(BlurDialog);
        direction->setObjectName(QString::fromUtf8("direction"));
        direction->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(direction, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(BlurDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
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
        BlurDialog->setWindowTitle(QApplication::translate("BlurDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BlurDialog", "direction", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BlurDialog", "intensity", 0, QApplication::UnicodeUTF8));
        direction->clear();
        direction->insertItems(0, QStringList()
         << QApplication::translate("BlurDialog", "none", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BlurDialog", "horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BlurDialog", "vertical", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BlurDialog", "diagonal (bottom left to top right)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BlurDialog", "diagonal (top left to bottom right)", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class BlurDialog: public Ui_BlurDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLURDIALOG_H
