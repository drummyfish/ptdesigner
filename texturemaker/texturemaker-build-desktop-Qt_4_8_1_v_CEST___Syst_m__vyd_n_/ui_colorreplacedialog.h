/********************************************************************************
** Form generated from reading UI file 'colorreplacedialog.ui'
**
** Created: Mon Feb 24 13:33:44 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORREPLACEDIALOG_H
#define UI_COLORREPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ColorReplaceDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame_1;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QDialogButtonBox *buttonBox;
    QPushButton *edit_1;
    QLabel *label;
    QPushButton *edit_2;
    QPushButton *edit_3;
    QPushButton *edit_4;

    void setupUi(QDialog *ColorReplaceDialog)
    {
        if (ColorReplaceDialog->objectName().isEmpty())
            ColorReplaceDialog->setObjectName(QString::fromUtf8("ColorReplaceDialog"));
        ColorReplaceDialog->resize(317, 122);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorReplaceDialog->sizePolicy().hasHeightForWidth());
        ColorReplaceDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ColorReplaceDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame_1 = new QFrame(ColorReplaceDialog);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        frame_1->setMinimumSize(QSize(50, 50));
        frame_1->setMaximumSize(QSize(50, 50));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_1, 2, 0, 1, 1);

        frame_2 = new QFrame(ColorReplaceDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(50, 50));
        frame_2->setMaximumSize(QSize(50, 50));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_2, 2, 1, 1, 1);

        frame_3 = new QFrame(ColorReplaceDialog);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(50, 50));
        frame_3->setMaximumSize(QSize(50, 50));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_3, 2, 2, 1, 1);

        frame_4 = new QFrame(ColorReplaceDialog);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setMinimumSize(QSize(50, 50));
        frame_4->setMaximumSize(QSize(50, 50));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_4, 2, 3, 1, 1);

        label_3 = new QLabel(ColorReplaceDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_2 = new QLabel(ColorReplaceDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_4 = new QLabel(ColorReplaceDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        buttonBox = new QDialogButtonBox(ColorReplaceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 4, 3, 1);

        edit_1 = new QPushButton(ColorReplaceDialog);
        edit_1->setObjectName(QString::fromUtf8("edit_1"));
        edit_1->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(edit_1, 3, 0, 1, 1);

        label = new QLabel(ColorReplaceDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        edit_2 = new QPushButton(ColorReplaceDialog);
        edit_2->setObjectName(QString::fromUtf8("edit_2"));
        edit_2->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(edit_2, 3, 1, 1, 1);

        edit_3 = new QPushButton(ColorReplaceDialog);
        edit_3->setObjectName(QString::fromUtf8("edit_3"));
        edit_3->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(edit_3, 3, 2, 1, 1);

        edit_4 = new QPushButton(ColorReplaceDialog);
        edit_4->setObjectName(QString::fromUtf8("edit_4"));
        edit_4->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(edit_4, 3, 3, 1, 1);


        retranslateUi(ColorReplaceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorReplaceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorReplaceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorReplaceDialog)
    {
        ColorReplaceDialog->setWindowTitle(QApplication::translate("ColorReplaceDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ColorReplaceDialog", "color 3", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ColorReplaceDialog", "color 2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ColorReplaceDialog", "color 4", 0, QApplication::UnicodeUTF8));
        edit_1->setText(QApplication::translate("ColorReplaceDialog", "edit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ColorReplaceDialog", "color 1", 0, QApplication::UnicodeUTF8));
        edit_2->setText(QApplication::translate("ColorReplaceDialog", "edit", 0, QApplication::UnicodeUTF8));
        edit_3->setText(QApplication::translate("ColorReplaceDialog", "edit", 0, QApplication::UnicodeUTF8));
        edit_4->setText(QApplication::translate("ColorReplaceDialog", "edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorReplaceDialog: public Ui_ColorReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORREPLACEDIALOG_H
