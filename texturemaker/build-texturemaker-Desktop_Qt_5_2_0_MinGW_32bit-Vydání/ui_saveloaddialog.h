/********************************************************************************
** Form generated from reading UI file 'saveloaddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVELOADDIALOG_H
#define UI_SAVELOADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SaveLoadDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *path_text;
    QPushButton *browse;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SaveLoadDialog)
    {
        if (SaveLoadDialog->objectName().isEmpty())
            SaveLoadDialog->setObjectName(QStringLiteral("SaveLoadDialog"));
        SaveLoadDialog->resize(285, 115);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SaveLoadDialog->sizePolicy().hasHeightForWidth());
        SaveLoadDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SaveLoadDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SaveLoadDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        path_text = new QLineEdit(SaveLoadDialog);
        path_text->setObjectName(QStringLiteral("path_text"));

        verticalLayout->addWidget(path_text);

        browse = new QPushButton(SaveLoadDialog);
        browse->setObjectName(QStringLiteral("browse"));
        browse->setMinimumSize(QSize(100, 0));
        browse->setMaximumSize(QSize(100, 16777215));

        verticalLayout->addWidget(browse);

        buttonBox = new QDialogButtonBox(SaveLoadDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SaveLoadDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SaveLoadDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SaveLoadDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SaveLoadDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveLoadDialog)
    {
        SaveLoadDialog->setWindowTitle(QApplication::translate("SaveLoadDialog", "Dialog", 0));
        label->setText(QApplication::translate("SaveLoadDialog", "path", 0));
        browse->setText(QApplication::translate("SaveLoadDialog", "browse", 0));
    } // retranslateUi

};

namespace Ui {
    class SaveLoadDialog: public Ui_SaveLoadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVELOADDIALOG_H
