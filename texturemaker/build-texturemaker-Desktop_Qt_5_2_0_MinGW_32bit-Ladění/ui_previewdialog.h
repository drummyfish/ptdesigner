/********************************************************************************
** Form generated from reading UI file 'previewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWDIALOG_H
#define UI_PREVIEWDIALOG_H

#include <ColorBufferDisplay.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PreviewDialog
{
public:
    QVBoxLayout *verticalLayout;
    ColorBufferDisplay *preview;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreviewDialog)
    {
        if (PreviewDialog->objectName().isEmpty())
            PreviewDialog->setObjectName(QStringLiteral("PreviewDialog"));
        PreviewDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(PreviewDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        preview = new ColorBufferDisplay(PreviewDialog);
        preview->setObjectName(QStringLiteral("preview"));
        preview->setFrameShape(QFrame::StyledPanel);
        preview->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(preview);

        buttonBox = new QDialogButtonBox(PreviewDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PreviewDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreviewDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreviewDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreviewDialog);
    } // setupUi

    void retranslateUi(QDialog *PreviewDialog)
    {
        PreviewDialog->setWindowTitle(QApplication::translate("PreviewDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class PreviewDialog: public Ui_PreviewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWDIALOG_H
