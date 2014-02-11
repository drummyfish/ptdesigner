/********************************************************************************
** Form generated from reading UI file 'cellulardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLULARDIALOG_H
#define UI_CELLULARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CellularDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_threshold;
    QSpinBox *threshold;
    QSpinBox *states;
    QSpinBox *neighbourhood_size;
    QSpinBox *players;
    QLabel *label_2;
    QLabel *label_players;
    QLabel *label_states;
    QDialogButtonBox *buttonBox;
    QComboBox *combo;
    QLabel *label_4;
    QSpinBox *iterations;

    void setupUi(QDialog *CellularDialog)
    {
        if (CellularDialog->objectName().isEmpty())
            CellularDialog->setObjectName(QStringLiteral("CellularDialog"));
        CellularDialog->resize(277, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CellularDialog->sizePolicy().hasHeightForWidth());
        CellularDialog->setSizePolicy(sizePolicy);
        CellularDialog->setMinimumSize(QSize(277, 200));
        CellularDialog->setMaximumSize(QSize(277, 200));
        gridLayout = new QGridLayout(CellularDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CellularDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_threshold = new QLabel(CellularDialog);
        label_threshold->setObjectName(QStringLiteral("label_threshold"));

        gridLayout->addWidget(label_threshold, 3, 0, 1, 1);

        threshold = new QSpinBox(CellularDialog);
        threshold->setObjectName(QStringLiteral("threshold"));
        threshold->setMaximumSize(QSize(80, 16777215));
        threshold->setMaximum(9999999);

        gridLayout->addWidget(threshold, 3, 1, 1, 1);

        states = new QSpinBox(CellularDialog);
        states->setObjectName(QStringLiteral("states"));
        states->setMaximumSize(QSize(80, 16777215));
        states->setMaximum(256);

        gridLayout->addWidget(states, 2, 1, 1, 1);

        neighbourhood_size = new QSpinBox(CellularDialog);
        neighbourhood_size->setObjectName(QStringLiteral("neighbourhood_size"));
        neighbourhood_size->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(neighbourhood_size, 1, 1, 1, 1);

        players = new QSpinBox(CellularDialog);
        players->setObjectName(QStringLiteral("players"));
        players->setMaximumSize(QSize(80, 16777215));
        players->setMinimum(1);
        players->setMaximum(9999999);
        players->setSingleStep(2);

        gridLayout->addWidget(players, 4, 1, 1, 1);

        label_2 = new QLabel(CellularDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_players = new QLabel(CellularDialog);
        label_players->setObjectName(QStringLiteral("label_players"));

        gridLayout->addWidget(label_players, 4, 0, 1, 1);

        label_states = new QLabel(CellularDialog);
        label_states->setObjectName(QStringLiteral("label_states"));

        gridLayout->addWidget(label_states, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(CellularDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 1, 1, 1);

        combo = new QComboBox(CellularDialog);
        combo->setObjectName(QStringLiteral("combo"));

        gridLayout->addWidget(combo, 0, 1, 1, 1);

        label_4 = new QLabel(CellularDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        iterations = new QSpinBox(CellularDialog);
        iterations->setObjectName(QStringLiteral("iterations"));
        iterations->setMaximumSize(QSize(80, 16777215));
        iterations->setMaximum(999999);

        gridLayout->addWidget(iterations, 5, 1, 1, 1);


        retranslateUi(CellularDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CellularDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CellularDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CellularDialog);
    } // setupUi

    void retranslateUi(QDialog *CellularDialog)
    {
        CellularDialog->setWindowTitle(QApplication::translate("CellularDialog", "Dialog", 0));
        label->setText(QApplication::translate("CellularDialog", "neighbourhood type", 0));
        label_threshold->setText(QApplication::translate("CellularDialog", "threshold", 0));
        label_2->setText(QApplication::translate("CellularDialog", "neighbourhood size", 0));
        label_players->setText(QApplication::translate("CellularDialog", "players", 0));
        label_states->setText(QApplication::translate("CellularDialog", "states", 0));
        combo->clear();
        combo->insertItems(0, QStringList()
         << QApplication::translate("CellularDialog", "von Neumann", 0)
         << QApplication::translate("CellularDialog", "Moore", 0)
        );
        label_4->setText(QApplication::translate("CellularDialog", "iterations", 0));
    } // retranslateUi

};

namespace Ui {
    class CellularDialog: public Ui_CellularDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLULARDIALOG_H
