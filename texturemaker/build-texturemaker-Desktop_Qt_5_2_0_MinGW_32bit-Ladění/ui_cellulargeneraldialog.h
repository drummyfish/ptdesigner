/********************************************************************************
** Form generated from reading UI file 'cellulargeneraldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLULARGENERALDIALOG_H
#define UI_CELLULARGENERALDIALOG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CellularGeneralDialog
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;
    QTableWidget *rules;
    QPushButton *game_of_life;
    QLabel *label;
    QPushButton *clear_button;
    QSpinBox *iterations;
    QLabel *label_3;
    QSpinBox *states;

    void setupUi(QDialog *CellularGeneralDialog)
    {
        if (CellularGeneralDialog->objectName().isEmpty())
            CellularGeneralDialog->setObjectName(QStringLiteral("CellularGeneralDialog"));
        CellularGeneralDialog->resize(580, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CellularGeneralDialog->sizePolicy().hasHeightForWidth());
        CellularGeneralDialog->setSizePolicy(sizePolicy);
        CellularGeneralDialog->setMinimumSize(QSize(580, 400));
        CellularGeneralDialog->setMaximumSize(QSize(580, 400));
        gridLayout = new QGridLayout(CellularGeneralDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        frame = new QFrame(CellularGeneralDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(69, 69));
        frame->setMaximumSize(QSize(69, 69));
        frame->setStyleSheet(QStringLiteral("background-image: url(:/resources/cellular_general.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(frame, 0, 1, 1, 1);

        label_2 = new QLabel(CellularGeneralDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CellularGeneralDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 8, 1, 1, 1);

        rules = new QTableWidget(CellularGeneralDialog);
        if (rules->columnCount() < 9)
            rules->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        rules->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        rules->setObjectName(QStringLiteral("rules"));
        rules->horizontalHeader()->setVisible(true);
        rules->horizontalHeader()->setCascadingSectionResizes(false);
        rules->horizontalHeader()->setDefaultSectionSize(40);

        gridLayout->addWidget(rules, 0, 0, 9, 1);

        game_of_life = new QPushButton(CellularGeneralDialog);
        game_of_life->setObjectName(QStringLiteral("game_of_life"));

        gridLayout->addWidget(game_of_life, 1, 1, 1, 1);

        label = new QLabel(CellularGeneralDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 7, 1, 1, 1);

        clear_button = new QPushButton(CellularGeneralDialog);
        clear_button->setObjectName(QStringLiteral("clear_button"));

        gridLayout->addWidget(clear_button, 2, 1, 1, 1);

        iterations = new QSpinBox(CellularGeneralDialog);
        iterations->setObjectName(QStringLiteral("iterations"));
        iterations->setMaximum(9999999);

        gridLayout->addWidget(iterations, 4, 1, 1, 1);

        label_3 = new QLabel(CellularGeneralDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 5, 1, 1, 1);

        states = new QSpinBox(CellularGeneralDialog);
        states->setObjectName(QStringLiteral("states"));
        states->setMaximum(256);

        gridLayout->addWidget(states, 6, 1, 1, 1);


        retranslateUi(CellularGeneralDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CellularGeneralDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CellularGeneralDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CellularGeneralDialog);
    } // setupUi

    void retranslateUi(QDialog *CellularGeneralDialog)
    {
        CellularGeneralDialog->setWindowTitle(QApplication::translate("CellularGeneralDialog", "Dialog", 0));
        label_2->setText(QApplication::translate("CellularGeneralDialog", "iterations", 0));
        QTableWidgetItem *___qtablewidgetitem = rules->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CellularGeneralDialog", "a", 0));
        QTableWidgetItem *___qtablewidgetitem1 = rules->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CellularGeneralDialog", "b", 0));
        QTableWidgetItem *___qtablewidgetitem2 = rules->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CellularGeneralDialog", "c", 0));
        QTableWidgetItem *___qtablewidgetitem3 = rules->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CellularGeneralDialog", "d", 0));
        QTableWidgetItem *___qtablewidgetitem4 = rules->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("CellularGeneralDialog", "e", 0));
        QTableWidgetItem *___qtablewidgetitem5 = rules->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("CellularGeneralDialog", "f", 0));
        QTableWidgetItem *___qtablewidgetitem6 = rules->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("CellularGeneralDialog", "g", 0));
        QTableWidgetItem *___qtablewidgetitem7 = rules->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("CellularGeneralDialog", "h", 0));
        QTableWidgetItem *___qtablewidgetitem8 = rules->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("CellularGeneralDialog", "y", 0));
        game_of_life->setText(QApplication::translate("CellularGeneralDialog", "game of life", 0));
        label->setText(QApplication::translate("CellularGeneralDialog", "<html><head/><body><p>y:</p><p>1 - cell is born</p><p>0 - nothing happens</p><p>-1 - cell dies</p></body></html>", 0));
        clear_button->setText(QApplication::translate("CellularGeneralDialog", "clear", 0));
        label_3->setText(QApplication::translate("CellularGeneralDialog", "states", 0));
    } // retranslateUi

};

namespace Ui {
    class CellularGeneralDialog: public Ui_CellularGeneralDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLULARGENERALDIALOG_H
