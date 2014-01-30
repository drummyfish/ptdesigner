/********************************************************************************
** Form generated from reading UI file 'convolutiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVOLUTIONDIALOG_H
#define UI_CONVOLUTIONDIALOG_H

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
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ConvolutionDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QFrame *matrix_frame;
    QGridLayout *gridLayout_2;
    QSpinBox *matrix_width;
    QSpinBox *matrix_height;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConvolutionDialog)
    {
        if (ConvolutionDialog->objectName().isEmpty())
            ConvolutionDialog->setObjectName(QStringLiteral("ConvolutionDialog"));
        ConvolutionDialog->resize(223, 264);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConvolutionDialog->sizePolicy().hasHeightForWidth());
        ConvolutionDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(ConvolutionDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(ConvolutionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(ConvolutionDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        matrix_frame = new QFrame(ConvolutionDialog);
        matrix_frame->setObjectName(QStringLiteral("matrix_frame"));
        matrix_frame->setFrameShape(QFrame::StyledPanel);
        matrix_frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(matrix_frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        gridLayout->addWidget(matrix_frame, 2, 0, 1, 2);

        matrix_width = new QSpinBox(ConvolutionDialog);
        matrix_width->setObjectName(QStringLiteral("matrix_width"));
        matrix_width->setMinimum(1);
        matrix_width->setMaximum(11);
        matrix_width->setSingleStep(2);

        gridLayout->addWidget(matrix_width, 0, 1, 1, 1);

        matrix_height = new QSpinBox(ConvolutionDialog);
        matrix_height->setObjectName(QStringLiteral("matrix_height"));
        matrix_height->setMinimum(1);
        matrix_height->setMaximum(11);
        matrix_height->setSingleStep(2);

        gridLayout->addWidget(matrix_height, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(ConvolutionDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(ConvolutionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConvolutionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConvolutionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConvolutionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConvolutionDialog)
    {
        ConvolutionDialog->setWindowTitle(QApplication::translate("ConvolutionDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("ConvolutionDialog", "height", 0));
        label->setText(QApplication::translate("ConvolutionDialog", "width", 0));
    } // retranslateUi

};

namespace Ui {
    class ConvolutionDialog: public Ui_ConvolutionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVOLUTIONDIALOG_H
