/********************************************************************************
** Form generated from reading UI file 'edgedetectiondialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDGEDETECTIONDIALOG_H
#define UI_EDGEDETECTIONDIALOG_H

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

class Ui_EdgeDetectionDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *intensity;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QComboBox *type;

    void setupUi(QDialog *EdgeDetectionDialog)
    {
        if (EdgeDetectionDialog->objectName().isEmpty())
            EdgeDetectionDialog->setObjectName(QString::fromUtf8("EdgeDetectionDialog"));
        EdgeDetectionDialog->resize(221, 119);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EdgeDetectionDialog->sizePolicy().hasHeightForWidth());
        EdgeDetectionDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(EdgeDetectionDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(EdgeDetectionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        intensity = new QSpinBox(EdgeDetectionDialog);
        intensity->setObjectName(QString::fromUtf8("intensity"));
        intensity->setMaximumSize(QSize(80, 16777215));
        intensity->setMaximum(1000);

        gridLayout->addWidget(intensity, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(EdgeDetectionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);

        label_2 = new QLabel(EdgeDetectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        type = new QComboBox(EdgeDetectionDialog);
        type->setObjectName(QString::fromUtf8("type"));

        gridLayout->addWidget(type, 1, 1, 1, 1);


        retranslateUi(EdgeDetectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EdgeDetectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EdgeDetectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EdgeDetectionDialog);
    } // setupUi

    void retranslateUi(QDialog *EdgeDetectionDialog)
    {
        EdgeDetectionDialog->setWindowTitle(QApplication::translate("EdgeDetectionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EdgeDetectionDialog", "intensity", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("EdgeDetectionDialog", "direction", 0, QApplication::UnicodeUTF8));
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("EdgeDetectionDialog", "both", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EdgeDetectionDialog", "horizontal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EdgeDetectionDialog", "vertical", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class EdgeDetectionDialog: public Ui_EdgeDetectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDGEDETECTIONDIALOG_H
