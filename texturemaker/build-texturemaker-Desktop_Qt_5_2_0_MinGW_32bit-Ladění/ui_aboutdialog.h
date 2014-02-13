/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLabel *label;
    QFrame *frame;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(356, 261);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        AboutDialog->setStyleSheet(QStringLiteral("background-color: rgb(255,255,255)"));
        gridLayout = new QGridLayout(AboutDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMaximumSize(QSize(16777215, 25));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 1);

        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(AboutDialog);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        frame = new QFrame(AboutDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(170, 175));
        frame->setMaximumSize(QSize(170, 175));
        frame->setStyleSheet(QStringLiteral("background-image: url(\":/resources/icon original.png\")"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(0);

        gridLayout->addWidget(frame, 1, 1, 1, 1);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("AboutDialog", "<html><head/><body><p>Miloslav \304\214\303\255\305\276, 2014</p><p>version: 1.0</p></body></html>", 0));
        label->setText(QApplication::translate("AboutDialog", "Texturemaker", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
