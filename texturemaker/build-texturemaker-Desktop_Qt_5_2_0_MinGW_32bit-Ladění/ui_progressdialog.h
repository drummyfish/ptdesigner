/********************************************************************************
** Form generated from reading UI file 'progressdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_ProgressDialog
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progress_bar;
    QLabel *progress_text;

    void setupUi(QDialog *ProgressDialog)
    {
        if (ProgressDialog->objectName().isEmpty())
            ProgressDialog->setObjectName(QStringLiteral("ProgressDialog"));
        ProgressDialog->resize(320, 75);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProgressDialog->sizePolicy().hasHeightForWidth());
        ProgressDialog->setSizePolicy(sizePolicy);
        ProgressDialog->setMinimumSize(QSize(320, 75));
        ProgressDialog->setMaximumSize(QSize(320, 75));
        ProgressDialog->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/nothing.png"), QSize(), QIcon::Normal, QIcon::Off);
        ProgressDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ProgressDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progress_bar = new QProgressBar(ProgressDialog);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setValue(24);

        gridLayout->addWidget(progress_bar, 0, 0, 1, 1);

        progress_text = new QLabel(ProgressDialog);
        progress_text->setObjectName(QStringLiteral("progress_text"));

        gridLayout->addWidget(progress_text, 1, 0, 1, 1);


        retranslateUi(ProgressDialog);

        QMetaObject::connectSlotsByName(ProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *ProgressDialog)
    {
        ProgressDialog->setWindowTitle(QApplication::translate("ProgressDialog", "computing", 0));
        progress_text->setText(QApplication::translate("ProgressDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgressDialog: public Ui_ProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
