/********************************************************************************
** Form generated from reading UI file 'colorfilldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORFILLDIALOG_H
#define UI_COLORFILLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ColorFillDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QPushButton *pick;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ColorFillDialog)
    {
        if (ColorFillDialog->objectName().isEmpty())
            ColorFillDialog->setObjectName(QStringLiteral("ColorFillDialog"));
        ColorFillDialog->resize(174, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorFillDialog->sizePolicy().hasHeightForWidth());
        ColorFillDialog->setSizePolicy(sizePolicy);
        ColorFillDialog->setMaximumSize(QSize(200, 200));
        verticalLayout = new QVBoxLayout(ColorFillDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(ColorFillDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(64, 64));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(frame);

        pick = new QPushButton(ColorFillDialog);
        pick->setObjectName(QStringLiteral("pick"));

        verticalLayout->addWidget(pick);

        buttonBox = new QDialogButtonBox(ColorFillDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ColorFillDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorFillDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorFillDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorFillDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorFillDialog)
    {
        ColorFillDialog->setWindowTitle(QApplication::translate("ColorFillDialog", "Dialog", 0));
        pick->setText(QApplication::translate("ColorFillDialog", "pick color", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorFillDialog: public Ui_ColorFillDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORFILLDIALOG_H
