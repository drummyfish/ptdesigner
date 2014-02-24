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
#include <QtWidgets/QGroupBox>
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
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *button_push;
    QPushButton *button_set_step_absolute;
    QPushButton *button_pop;
    QPushButton *button_move_forward;
    QPushButton *button_set_angle;
    QPushButton *button_turn_left;
    QPushButton *button_set_step_percent;
    QPushButton *button_draw_line;
    QPushButton *button_set_color;
    QPushButton *button_increase_step;
    QPushButton *button_set_step_pixels;
    QPushButton *button_turn_right;
    QPushButton *button_set_width_absolute;
    QPushButton *button_set_width_pixels;
    QPushButton *button_set_style_pixels;
    QPushButton *button_set_style_absolute;
    QPushButton *browse;
    QLabel *label;
    QLineEdit *path;
    QPlainTextEdit *text_edit;
    QSpinBox *iterations;
    QLabel *label_2;
    QPushButton *reload;
    QPushButton *save;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LSystemDialog)
    {
        if (LSystemDialog->objectName().isEmpty())
            LSystemDialog->setObjectName(QStringLiteral("LSystemDialog"));
        LSystemDialog->resize(723, 438);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LSystemDialog->sizePolicy().hasHeightForWidth());
        LSystemDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(LSystemDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(LSystemDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(75, 80));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        button_push = new QPushButton(groupBox);
        button_push->setObjectName(QStringLiteral("button_push"));
        button_push->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(button_push, 0, 0, 1, 1);

        button_set_step_absolute = new QPushButton(groupBox);
        button_set_step_absolute->setObjectName(QStringLiteral("button_set_step_absolute"));

        gridLayout_2->addWidget(button_set_step_absolute, 1, 4, 1, 1);

        button_pop = new QPushButton(groupBox);
        button_pop->setObjectName(QStringLiteral("button_pop"));
        button_pop->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(button_pop, 1, 0, 1, 1);

        button_move_forward = new QPushButton(groupBox);
        button_move_forward->setObjectName(QStringLiteral("button_move_forward"));

        gridLayout_2->addWidget(button_move_forward, 1, 3, 1, 1);

        button_set_angle = new QPushButton(groupBox);
        button_set_angle->setObjectName(QStringLiteral("button_set_angle"));

        gridLayout_2->addWidget(button_set_angle, 0, 1, 1, 1);

        button_turn_left = new QPushButton(groupBox);
        button_turn_left->setObjectName(QStringLiteral("button_turn_left"));
        button_turn_left->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(button_turn_left, 1, 1, 1, 1);

        button_set_step_percent = new QPushButton(groupBox);
        button_set_step_percent->setObjectName(QStringLiteral("button_set_step_percent"));
        button_set_step_percent->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(button_set_step_percent, 0, 4, 1, 1);

        button_draw_line = new QPushButton(groupBox);
        button_draw_line->setObjectName(QStringLiteral("button_draw_line"));
        button_draw_line->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(button_draw_line, 0, 3, 1, 1);

        button_set_color = new QPushButton(groupBox);
        button_set_color->setObjectName(QStringLiteral("button_set_color"));
        button_set_color->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(button_set_color, 0, 2, 1, 1);

        button_increase_step = new QPushButton(groupBox);
        button_increase_step->setObjectName(QStringLiteral("button_increase_step"));

        gridLayout_2->addWidget(button_increase_step, 3, 4, 1, 1);

        button_set_step_pixels = new QPushButton(groupBox);
        button_set_step_pixels->setObjectName(QStringLiteral("button_set_step_pixels"));

        gridLayout_2->addWidget(button_set_step_pixels, 2, 4, 1, 1);

        button_turn_right = new QPushButton(groupBox);
        button_turn_right->setObjectName(QStringLiteral("button_turn_right"));
        button_turn_right->setMaximumSize(QSize(75, 16777215));

        gridLayout_2->addWidget(button_turn_right, 2, 1, 1, 1);

        button_set_width_absolute = new QPushButton(groupBox);
        button_set_width_absolute->setObjectName(QStringLiteral("button_set_width_absolute"));
        button_set_width_absolute->setMinimumSize(QSize(100, 0));
        button_set_width_absolute->setMaximumSize(QSize(9999, 16777215));

        gridLayout_2->addWidget(button_set_width_absolute, 0, 5, 1, 1);

        button_set_width_pixels = new QPushButton(groupBox);
        button_set_width_pixels->setObjectName(QStringLiteral("button_set_width_pixels"));

        gridLayout_2->addWidget(button_set_width_pixels, 1, 5, 1, 1);

        button_set_style_pixels = new QPushButton(groupBox);
        button_set_style_pixels->setObjectName(QStringLiteral("button_set_style_pixels"));

        gridLayout_2->addWidget(button_set_style_pixels, 0, 6, 1, 1);

        button_set_style_absolute = new QPushButton(groupBox);
        button_set_style_absolute->setObjectName(QStringLiteral("button_set_style_absolute"));

        gridLayout_2->addWidget(button_set_style_absolute, 1, 6, 1, 1);


        gridLayout->addWidget(groupBox, 10, 0, 1, 6);

        browse = new QPushButton(LSystemDialog);
        browse->setObjectName(QStringLiteral("browse"));

        gridLayout->addWidget(browse, 0, 4, 1, 1);

        label = new QLabel(LSystemDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        path = new QLineEdit(LSystemDialog);
        path->setObjectName(QStringLiteral("path"));

        gridLayout->addWidget(path, 0, 2, 1, 1);

        text_edit = new QPlainTextEdit(LSystemDialog);
        text_edit->setObjectName(QStringLiteral("text_edit"));
        text_edit->setLineWrapMode(QPlainTextEdit::NoWrap);

        gridLayout->addWidget(text_edit, 2, 0, 8, 3);

        iterations = new QSpinBox(LSystemDialog);
        iterations->setObjectName(QStringLiteral("iterations"));
        iterations->setMaximumSize(QSize(50, 16777215));
        iterations->setMaximum(65536);

        gridLayout->addWidget(iterations, 1, 2, 1, 1);

        label_2 = new QLabel(LSystemDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        reload = new QPushButton(LSystemDialog);
        reload->setObjectName(QStringLiteral("reload"));

        gridLayout->addWidget(reload, 2, 4, 1, 1);

        save = new QPushButton(LSystemDialog);
        save->setObjectName(QStringLiteral("save"));

        gridLayout->addWidget(save, 3, 4, 1, 1);

        buttonBox = new QDialogButtonBox(LSystemDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setMinimumSize(QSize(0, 0));
        buttonBox->setMaximumSize(QSize(150, 16777215));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 4, 1, 1);


        retranslateUi(LSystemDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LSystemDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LSystemDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LSystemDialog);
    } // setupUi

    void retranslateUi(QDialog *LSystemDialog)
    {
        LSystemDialog->setWindowTitle(QApplication::translate("LSystemDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("LSystemDialog", "commands", 0));
        button_push->setText(QApplication::translate("LSystemDialog", "push", 0));
        button_set_step_absolute->setText(QApplication::translate("LSystemDialog", "set step (absolute)", 0));
        button_pop->setText(QApplication::translate("LSystemDialog", "pop", 0));
        button_move_forward->setText(QApplication::translate("LSystemDialog", "move forward", 0));
        button_set_angle->setText(QApplication::translate("LSystemDialog", "set angle", 0));
        button_turn_left->setText(QApplication::translate("LSystemDialog", "turn left", 0));
        button_set_step_percent->setText(QApplication::translate("LSystemDialog", "set step (% of step)", 0));
        button_draw_line->setText(QApplication::translate("LSystemDialog", "draw line", 0));
        button_set_color->setText(QApplication::translate("LSystemDialog", "set color", 0));
        button_increase_step->setText(QApplication::translate("LSystemDialog", "increase step (pixels)", 0));
        button_set_step_pixels->setText(QApplication::translate("LSystemDialog", "set step (pixels)", 0));
        button_turn_right->setText(QApplication::translate("LSystemDialog", "turn right", 0));
        button_set_width_absolute->setText(QApplication::translate("LSystemDialog", "set width (absolute)", 0));
        button_set_width_pixels->setText(QApplication::translate("LSystemDialog", "set width (pixels)", 0));
        button_set_style_pixels->setText(QApplication::translate("LSystemDialog", "set style (type, pixels)", 0));
        button_set_style_absolute->setText(QApplication::translate("LSystemDialog", "set style (type, absolute)", 0));
        browse->setText(QApplication::translate("LSystemDialog", "browse", 0));
        label->setText(QApplication::translate("LSystemDialog", "file", 0));
        label_2->setText(QApplication::translate("LSystemDialog", "iterations", 0));
        reload->setText(QApplication::translate("LSystemDialog", "reload", 0));
        save->setText(QApplication::translate("LSystemDialog", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class LSystemDialog: public Ui_LSystemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LSYSTEMDIALOG_H
