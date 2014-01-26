/********************************************************************************
** Form generated from reading UI file 'lightdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIGHTDIALOG_H
#define UI_LIGHTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LightDialog
{
public:
    QGridLayout *gridLayout;
    QDoubleSpinBox *direction_y;
    QLabel *label_7;
    QLabel *label_2;
    QDoubleSpinBox *direction_x;
    QComboBox *curve_selection;
    QDoubleSpinBox *viewer_height;
    QLabel *label_6;
    QDoubleSpinBox *phong_exponent;
    QLabel *label_5;
    QLabel *label_3;
    QFrame *frame_ambient;
    QFrame *frame_curve;
    QFrame *frame_specular;
    QFrame *frame_diffuse;
    QPushButton *pick_specular;
    QDialogButtonBox *buttonBox;
    QPushButton *pick_diffuse;
    QPushButton *pick_ambient;
    QLabel *label;
    QLabel *label_4;

    void setupUi(QDialog *LightDialog)
    {
        if (LightDialog->objectName().isEmpty())
            LightDialog->setObjectName(QStringLiteral("LightDialog"));
        LightDialog->resize(356, 194);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LightDialog->sizePolicy().hasHeightForWidth());
        LightDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(LightDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        direction_y = new QDoubleSpinBox(LightDialog);
        direction_y->setObjectName(QStringLiteral("direction_y"));

        gridLayout->addWidget(direction_y, 7, 4, 1, 1);

        label_7 = new QLabel(LightDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(64, 16777215));
        label_7->setWordWrap(true);

        gridLayout->addWidget(label_7, 7, 2, 1, 1);

        label_2 = new QLabel(LightDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(label_2, 3, 3, 1, 1);

        direction_x = new QDoubleSpinBox(LightDialog);
        direction_x->setObjectName(QStringLiteral("direction_x"));

        gridLayout->addWidget(direction_x, 7, 3, 1, 1);

        curve_selection = new QComboBox(LightDialog);
        curve_selection->setObjectName(QStringLiteral("curve_selection"));
        curve_selection->setMaximumSize(QSize(128, 16777215));

        gridLayout->addWidget(curve_selection, 5, 8, 1, 1);

        viewer_height = new QDoubleSpinBox(LightDialog);
        viewer_height->setObjectName(QStringLiteral("viewer_height"));
        viewer_height->setMaximumSize(QSize(64, 16777215));
        viewer_height->setMaximum(50);

        gridLayout->addWidget(viewer_height, 6, 8, 1, 1);

        label_6 = new QLabel(LightDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(64, 16777215));
        label_6->setWordWrap(true);

        gridLayout->addWidget(label_6, 6, 4, 1, 1);

        phong_exponent = new QDoubleSpinBox(LightDialog);
        phong_exponent->setObjectName(QStringLiteral("phong_exponent"));
        phong_exponent->setMinimum(-10);
        phong_exponent->setMaximum(10);

        gridLayout->addWidget(phong_exponent, 6, 3, 1, 1);

        label_5 = new QLabel(LightDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(64, 16777215));
        label_5->setScaledContents(false);
        label_5->setWordWrap(true);

        gridLayout->addWidget(label_5, 6, 2, 1, 1);

        label_3 = new QLabel(LightDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(label_3, 3, 4, 1, 1);

        frame_ambient = new QFrame(LightDialog);
        frame_ambient->setObjectName(QStringLiteral("frame_ambient"));
        frame_ambient->setMinimumSize(QSize(64, 64));
        frame_ambient->setMaximumSize(QSize(64, 64));
        frame_ambient->setFrameShape(QFrame::StyledPanel);
        frame_ambient->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_ambient, 4, 2, 1, 1);

        frame_curve = new QFrame(LightDialog);
        frame_curve->setObjectName(QStringLiteral("frame_curve"));
        frame_curve->setMinimumSize(QSize(128, 64));
        frame_curve->setMaximumSize(QSize(128, 64));
        frame_curve->setFrameShape(QFrame::StyledPanel);
        frame_curve->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_curve, 4, 8, 1, 1);

        frame_specular = new QFrame(LightDialog);
        frame_specular->setObjectName(QStringLiteral("frame_specular"));
        frame_specular->setMinimumSize(QSize(64, 64));
        frame_specular->setMaximumSize(QSize(64, 64));
        frame_specular->setFrameShape(QFrame::StyledPanel);
        frame_specular->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_specular, 4, 4, 1, 1);

        frame_diffuse = new QFrame(LightDialog);
        frame_diffuse->setObjectName(QStringLiteral("frame_diffuse"));
        frame_diffuse->setMinimumSize(QSize(64, 64));
        frame_diffuse->setMaximumSize(QSize(64, 64));
        frame_diffuse->setFrameShape(QFrame::StyledPanel);
        frame_diffuse->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(frame_diffuse, 4, 3, 1, 1);

        pick_specular = new QPushButton(LightDialog);
        pick_specular->setObjectName(QStringLiteral("pick_specular"));
        pick_specular->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(pick_specular, 5, 4, 1, 1);

        buttonBox = new QDialogButtonBox(LightDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMaximumSize(QSize(128, 16777215));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 7, 8, 1, 1);

        pick_diffuse = new QPushButton(LightDialog);
        pick_diffuse->setObjectName(QStringLiteral("pick_diffuse"));
        pick_diffuse->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(pick_diffuse, 5, 3, 1, 1);

        pick_ambient = new QPushButton(LightDialog);
        pick_ambient->setObjectName(QStringLiteral("pick_ambient"));
        pick_ambient->setMaximumSize(QSize(64, 16777215));

        gridLayout->addWidget(pick_ambient, 5, 2, 1, 1);

        label = new QLabel(LightDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 3, 2, 1, 1);

        label_4 = new QLabel(LightDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 8, 1, 1);


        retranslateUi(LightDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LightDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LightDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LightDialog);
    } // setupUi

    void retranslateUi(QDialog *LightDialog)
    {
        LightDialog->setWindowTitle(QApplication::translate("LightDialog", "Dialog", 0));
        label_7->setText(QApplication::translate("LightDialog", "direction vector", 0));
        label_2->setText(QApplication::translate("LightDialog", "diffuse", 0));
        curve_selection->clear();
        curve_selection->insertItems(0, QStringList()
         << QApplication::translate("LightDialog", "cos smooth", 0)
         << QApplication::translate("LightDialog", "cos absolute value", 0)
         << QApplication::translate("LightDialog", "linear half", 0)
         << QApplication::translate("LightDialog", "linear full", 0)
        );
        label_6->setText(QApplication::translate("LightDialog", "viewer height", 0));
        label_5->setText(QApplication::translate("LightDialog", "Phong exponent", 0));
        label_3->setText(QApplication::translate("LightDialog", "specular", 0));
        pick_specular->setText(QApplication::translate("LightDialog", "pick", 0));
        pick_diffuse->setText(QApplication::translate("LightDialog", "pick", 0));
        pick_ambient->setText(QApplication::translate("LightDialog", "pick", 0));
        label->setText(QApplication::translate("LightDialog", "ambient", 0));
        label_4->setText(QApplication::translate("LightDialog", "reflection curve", 0));
    } // retranslateUi

};

namespace Ui {
    class LightDialog: public Ui_LightDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIGHTDIALOG_H
