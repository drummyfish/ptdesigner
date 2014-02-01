/********************************************************************************
** Form generated from reading UI file 'lsystemdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LSYSTEMDIALOG_H
#define UI_LSYSTEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_LSystemDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *browse;
    QLineEdit *path;
    QPlainTextEdit *text_edit;
    QDialogButtonBox *buttonBox;
    QPushButton *reload;
    QSpinBox *iterations;
    QLabel *label_2;
    QPushButton *save;

    void setupUi(QDialog *LSystemDialog)
    {
        if (LSystemDialog->objectName().isEmpty())
            LSystemDialog->setObjectName(QStringLiteral("LSystemDialog"));
        LSystemDialog->resize(485, 366);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LSystemDialog->sizePolicy().hasHeightForWidth());
        LSystemDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(LSystemDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(LSystemDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        browse = new QPushButton(LSystemDialog);
        browse->setObjectName(QStringLiteral("browse"));

        gridLayout->addWidget(browse, 0, 4, 1, 1);

        path = new QLineEdit(LSystemDialog);
        path->setObjectName(QStringLiteral("path"));

        gridLayout->addWidget(path, 0, 1, 1, 1);

        text_edit = new QPlainTextEdit(LSystemDialog);
        text_edit->setObjectName(QStringLiteral("text_edit"));

        gridLayout->addWidget(text_edit, 2, 0, 7, 2);

        buttonBox = new QDialogButtonBox(LSystemDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 0));
        buttonBox->setMaximumSize(QSize(150, 16777215));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 4, 1, 1);

        reload = new QPushButton(LSystemDialog);
        reload->setObjectName(QStringLiteral("reload"));

        gridLayout->addWidget(reload, 1, 4, 1, 1);

        iterations = new QSpinBox(LSystemDialog);
        iterations->setObjectName(QStringLiteral("iterations"));
        iterations->setMaximumSize(QSize(50, 16777215));
        iterations->setMaximum(65536);

        gridLayout->addWidget(iterations, 1, 1, 1, 1);

        label_2 = new QLabel(LSystemDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        save = new QPushButton(LSystemDialog);
        save->setObjectName(QStringLiteral("save"));

        gridLayout->addWidget(save, 2, 4, 1, 1);


        retranslateUi(LSystemDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LSystemDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LSystemDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LSystemDialog);
    } // setupUi

    void retranslateUi(QDialog *LSystemDialog)
    {
        LSystemDialog->setWindowTitle(QApplication::translate("LSystemDialog", "Dialog", 0));
        label->setText(QApplication::translate("LSystemDialog", "file", 0));
        browse->setText(QApplication::translate("LSystemDialog", "browse", 0));
        reload->setText(QApplication::translate("LSystemDialog", "reload", 0));
        label_2->setText(QApplication::translate("LSystemDialog", "iterations", 0));
        save->setText(QApplication::translate("LSystemDialog", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class LSystemDialog: public Ui_LSystemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LSYSTEMDIALOG_H
