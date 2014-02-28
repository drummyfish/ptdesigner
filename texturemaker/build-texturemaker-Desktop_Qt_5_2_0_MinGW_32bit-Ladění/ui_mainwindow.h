/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <addblockbutton.h>
#include <colorbufferdisplay.h>
#include <editareaframe.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_texture;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionHelp_topics;
    QAction *actionAbout;
    QAction *actionRotate_CW;
    QAction *actionRotate_CCW;
    QAction *actionDelete;
    QAction *actionExecute;
    QAction *actionDisconnect;
    QAction *actionEdit_parameters;
    QAction *actionDuplicate;
    QAction *actionDefault_parameters_dialog;
    QAction *actionInvalidate_block;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *blockArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    AddBlockButton *pushButton_19;
    AddBlockButton *pushButton_9;
    AddBlockButton *pushButton_12;
    AddBlockButton *pushButton_28;
    AddBlockButton *pushButton_17;
    AddBlockButton *pushButton_33;
    QSpacerItem *horizontalSpacer;
    AddBlockButton *pushButton_16;
    AddBlockButton *pushButton_3;
    AddBlockButton *pushButton_11;
    AddBlockButton *pushButton_10;
    AddBlockButton *pushButton_21;
    AddBlockButton *pushButton_39;
    AddBlockButton *pushButton_37;
    AddBlockButton *pushButton_36;
    AddBlockButton *pushButton_40;
    AddBlockButton *pushButton_38;
    AddBlockButton *pushButton_18;
    AddBlockButton *pushButton_14;
    AddBlockButton *pushButton_23;
    AddBlockButton *pushButton_29;
    AddBlockButton *pushButton_27;
    AddBlockButton *pushButton_34;
    AddBlockButton *pushButton_6;
    AddBlockButton *pushButton_42;
    AddBlockButton *pushButton_22;
    AddBlockButton *pushButton_25;
    AddBlockButton *pushButton_8;
    AddBlockButton *pushButton_13;
    AddBlockButton *pushButton_7;
    AddBlockButton *pushButton_5;
    AddBlockButton *pushButton_4;
    AddBlockButton *pushButton_2;
    AddBlockButton *pushButton_15;
    AddBlockButton *pushButton_43;
    AddBlockButton *pushButton_44;
    AddBlockButton *pushButton_35;
    AddBlockButton *pushButton_20;
    AddBlockButton *pushButton_24;
    AddBlockButton *pushButton_31;
    AddBlockButton *pushButton_30;
    AddBlockButton *pushButton_32;
    AddBlockButton *pushButton_41;
    AddBlockButton *pushButton_45;
    AddBlockButton *pushButton_46;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    ColorBufferDisplay *preview;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_4;
    QSpinBox *width;
    QSpinBox *seed;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QSpinBox *height;
    QSpacerItem *verticalSpacer;
    QSpinBox *supersampling;
    QLabel *label_6;
    QSpinBox *cwidth;
    QSpinBox *cheight;
    QLabel *label_7;
    QCheckBox *force;
    QGroupBox *group_block;
    QGridLayout *gridLayout_6;
    QRadioButton *radio_custom_seed;
    QLabel *label_9;
    QLineEdit *block_inputs;
    QLineEdit *block_id;
    QRadioButton *radio_global_seed;
    QLabel *label_8;
    QLabel *label_10;
    QPushButton *pushButton_26;
    QLineEdit *block_state;
    QLabel *label_13;
    QSpinBox *custom_seed;
    QLineEdit *block_name;
    QSpacerItem *verticalSpacer_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    EditAreaFrame *editArea;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *status_bar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(562, 518);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/icon64.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew_texture = new QAction(MainWindow);
        actionNew_texture->setObjectName(QStringLiteral("actionNew_texture"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resources/action save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSave_as->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp_topics = new QAction(MainWindow);
        actionHelp_topics->setObjectName(QStringLiteral("actionHelp_topics"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionRotate_CW = new QAction(MainWindow);
        actionRotate_CW->setObjectName(QStringLiteral("actionRotate_CW"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resources/action rotate cw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate_CW->setIcon(icon2);
        actionRotate_CCW = new QAction(MainWindow);
        actionRotate_CCW->setObjectName(QStringLiteral("actionRotate_CCW"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/resources/action rotate ccw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate_CCW->setIcon(icon3);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/resources/action delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon4);
        actionExecute = new QAction(MainWindow);
        actionExecute->setObjectName(QStringLiteral("actionExecute"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/resources/action execute.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExecute->setIcon(icon5);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionDisconnect->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/resources/action disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon6);
        actionEdit_parameters = new QAction(MainWindow);
        actionEdit_parameters->setObjectName(QStringLiteral("actionEdit_parameters"));
        actionDuplicate = new QAction(MainWindow);
        actionDuplicate->setObjectName(QStringLiteral("actionDuplicate"));
        actionDefault_parameters_dialog = new QAction(MainWindow);
        actionDefault_parameters_dialog->setObjectName(QStringLiteral("actionDefault_parameters_dialog"));
        actionInvalidate_block = new QAction(MainWindow);
        actionInvalidate_block->setObjectName(QStringLiteral("actionInvalidate_block"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        blockArea = new QScrollArea(centralWidget);
        blockArea->setObjectName(QStringLiteral("blockArea"));
        blockArea->setMinimumSize(QSize(0, 155));
        blockArea->setMaximumSize(QSize(16777215, 150));
        blockArea->setBaseSize(QSize(0, 0));
        blockArea->setFrameShape(QFrame::StyledPanel);
        blockArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1316, 136));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_19 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(53, 53));
        pushButton_19->setMaximumSize(QSize(53, 53));
        pushButton_19->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_19, 2, 30, 1, 1);

        pushButton_9 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(53, 53));
        pushButton_9->setMaximumSize(QSize(53, 53));
        pushButton_9->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_9, 1, 29, 1, 1);

        pushButton_12 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(53, 53));
        pushButton_12->setMaximumSize(QSize(53, 53));
        pushButton_12->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_12, 1, 30, 1, 1);

        pushButton_28 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setMinimumSize(QSize(53, 53));
        pushButton_28->setMaximumSize(QSize(53, 53));
        pushButton_28->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_28, 1, 31, 1, 1);

        pushButton_17 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(53, 53));
        pushButton_17->setMaximumSize(QSize(53, 53));
        pushButton_17->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_17, 2, 8, 1, 1);

        pushButton_33 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_33->setObjectName(QStringLiteral("pushButton_33"));
        pushButton_33->setMinimumSize(QSize(53, 53));
        pushButton_33->setMaximumSize(QSize(53, 53));
        pushButton_33->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_33, 1, 20, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 43, 1, 1);

        pushButton_16 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(53, 53));
        pushButton_16->setMaximumSize(QSize(53, 53));
        pushButton_16->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_16, 1, 24, 1, 1);

        pushButton_3 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(53, 53));
        pushButton_3->setMaximumSize(QSize(53, 53));
        pushButton_3->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_11 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(53, 53));
        pushButton_11->setMaximumSize(QSize(53, 53));
        pushButton_11->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_11, 2, 2, 1, 1);

        pushButton_10 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(53, 53));
        pushButton_10->setMaximumSize(QSize(53, 53));
        pushButton_10->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_10, 2, 1, 1, 1);

        pushButton_21 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setMinimumSize(QSize(53, 53));
        pushButton_21->setMaximumSize(QSize(53, 53));
        pushButton_21->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_21, 1, 8, 1, 1);

        pushButton_39 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_39->setObjectName(QStringLiteral("pushButton_39"));
        pushButton_39->setMinimumSize(QSize(53, 53));
        pushButton_39->setMaximumSize(QSize(53, 53));
        pushButton_39->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_39, 2, 31, 1, 1);

        pushButton_37 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_37->setObjectName(QStringLiteral("pushButton_37"));
        pushButton_37->setMinimumSize(QSize(53, 53));
        pushButton_37->setMaximumSize(QSize(53, 53));
        pushButton_37->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_37, 1, 18, 1, 1);

        pushButton_36 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_36->setObjectName(QStringLiteral("pushButton_36"));
        pushButton_36->setMinimumSize(QSize(53, 53));
        pushButton_36->setMaximumSize(QSize(53, 53));
        pushButton_36->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_36, 1, 16, 1, 1);

        pushButton_40 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_40->setObjectName(QStringLiteral("pushButton_40"));
        pushButton_40->setMinimumSize(QSize(53, 53));
        pushButton_40->setMaximumSize(QSize(53, 53));
        pushButton_40->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_40, 1, 19, 1, 1);

        pushButton_38 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_38->setObjectName(QStringLiteral("pushButton_38"));
        pushButton_38->setMinimumSize(QSize(53, 53));
        pushButton_38->setMaximumSize(QSize(53, 53));
        pushButton_38->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_38, 1, 6, 1, 1);

        pushButton_18 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(53, 53));
        pushButton_18->setMaximumSize(QSize(53, 53));
        pushButton_18->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_18, 2, 9, 1, 1);

        pushButton_14 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(53, 53));
        pushButton_14->setMaximumSize(QSize(53, 53));
        pushButton_14->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_14, 2, 7, 1, 1);

        pushButton_23 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(53, 53));
        pushButton_23->setMaximumSize(QSize(53, 53));
        pushButton_23->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_23, 2, 16, 1, 1);

        pushButton_29 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_29->setObjectName(QStringLiteral("pushButton_29"));
        pushButton_29->setMinimumSize(QSize(53, 53));
        pushButton_29->setMaximumSize(QSize(53, 53));
        pushButton_29->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_29, 1, 10, 1, 1);

        pushButton_27 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setMinimumSize(QSize(53, 53));
        pushButton_27->setMaximumSize(QSize(53, 53));
        pushButton_27->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_27, 1, 7, 1, 1);

        pushButton_34 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        pushButton_34->setMinimumSize(QSize(53, 53));
        pushButton_34->setMaximumSize(QSize(53, 53));
        pushButton_34->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_34, 1, 21, 1, 1);

        pushButton_6 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(53, 53));
        pushButton_6->setMaximumSize(QSize(53, 53));
        pushButton_6->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_6, 2, 4, 1, 1);

        pushButton_42 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_42->setObjectName(QStringLiteral("pushButton_42"));
        pushButton_42->setMinimumSize(QSize(53, 53));
        pushButton_42->setMaximumSize(QSize(53, 53));
        pushButton_42->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_42, 1, 5, 1, 1);

        pushButton_22 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(53, 53));
        pushButton_22->setMaximumSize(QSize(53, 53));
        pushButton_22->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_22, 1, 9, 1, 1);

        pushButton_25 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(53, 53));
        pushButton_25->setMaximumSize(QSize(53, 53));
        pushButton_25->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_25, 2, 0, 1, 1);

        pushButton_8 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(53, 53));
        pushButton_8->setMaximumSize(QSize(53, 53));
        pushButton_8->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_8, 2, 24, 1, 1);

        pushButton_13 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(53, 53));
        pushButton_13->setMaximumSize(QSize(53, 53));
        pushButton_13->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_13, 2, 6, 1, 1);

        pushButton_7 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(53, 53));
        pushButton_7->setMaximumSize(QSize(53, 53));
        pushButton_7->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_7, 2, 3, 1, 1);

        pushButton_5 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(53, 53));
        pushButton_5->setMaximumSize(QSize(53, 53));
        pushButton_5->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_5, 1, 4, 1, 1);

        pushButton_4 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(53, 53));
        pushButton_4->setMaximumSize(QSize(53, 53));
        pushButton_4->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_4, 1, 3, 1, 1);

        pushButton_2 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(53, 53));
        pushButton_2->setMaximumSize(QSize(53, 53));
        pushButton_2->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_15 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(53, 53));
        pushButton_15->setMaximumSize(QSize(53, 53));
        pushButton_15->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_15, 2, 5, 1, 1);

        pushButton_43 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_43->setObjectName(QStringLiteral("pushButton_43"));
        pushButton_43->setMinimumSize(QSize(53, 53));
        pushButton_43->setMaximumSize(QSize(53, 53));
        pushButton_43->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_43, 1, 0, 1, 1);

        pushButton_44 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_44->setObjectName(QStringLiteral("pushButton_44"));
        pushButton_44->setMinimumSize(QSize(53, 53));
        pushButton_44->setMaximumSize(QSize(53, 53));
        pushButton_44->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_44, 1, 25, 1, 1);

        pushButton_35 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_35->setObjectName(QStringLiteral("pushButton_35"));
        pushButton_35->setMinimumSize(QSize(53, 53));
        pushButton_35->setMaximumSize(QSize(53, 53));
        pushButton_35->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_35, 2, 21, 1, 1);

        pushButton_20 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(53, 53));
        pushButton_20->setMaximumSize(QSize(53, 53));
        pushButton_20->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_20, 2, 25, 1, 1);

        pushButton_24 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(53, 53));
        pushButton_24->setMaximumSize(QSize(53, 53));
        pushButton_24->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_24, 2, 10, 1, 1);

        pushButton_31 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_31->setObjectName(QStringLiteral("pushButton_31"));
        pushButton_31->setMinimumSize(QSize(53, 53));
        pushButton_31->setMaximumSize(QSize(53, 53));
        pushButton_31->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_31, 2, 18, 1, 1);

        pushButton_30 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_30->setObjectName(QStringLiteral("pushButton_30"));
        pushButton_30->setMinimumSize(QSize(53, 53));
        pushButton_30->setMaximumSize(QSize(53, 53));
        pushButton_30->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_30, 2, 19, 1, 1);

        pushButton_32 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        pushButton_32->setMinimumSize(QSize(53, 53));
        pushButton_32->setMaximumSize(QSize(53, 53));
        pushButton_32->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_32, 2, 20, 1, 1);

        pushButton_41 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_41->setObjectName(QStringLiteral("pushButton_41"));
        pushButton_41->setMinimumSize(QSize(53, 53));
        pushButton_41->setMaximumSize(QSize(53, 53));
        pushButton_41->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_41, 2, 29, 1, 1);

        pushButton_45 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_45->setObjectName(QStringLiteral("pushButton_45"));
        pushButton_45->setMinimumSize(QSize(53, 53));
        pushButton_45->setMaximumSize(QSize(53, 53));
        pushButton_45->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_45, 1, 42, 1, 1);

        pushButton_46 = new AddBlockButton(scrollAreaWidgetContents);
        pushButton_46->setObjectName(QStringLiteral("pushButton_46"));
        pushButton_46->setMinimumSize(QSize(53, 53));
        pushButton_46->setMaximumSize(QSize(53, 53));
        pushButton_46->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_46, 2, 42, 1, 1);

        blockArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(blockArea, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(275, 0));
        scrollArea->setMaximumSize(QSize(160, 16777215));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 256, 713));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(scrollAreaWidgetContents_2);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 200));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        preview = new ColorBufferDisplay(widget);
        preview->setObjectName(QStringLiteral("preview"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(preview->sizePolicy().hasHeightForWidth());
        preview->setSizePolicy(sizePolicy3);
        preview->setMinimumSize(QSize(140, 140));
        preview->setFrameShape(QFrame::StyledPanel);
        preview->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(preview);


        verticalLayout->addWidget(widget);

        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy4);
        groupBox_3->setMinimumSize(QSize(0, 220));
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 10, 5, 0);
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 3, 0, 1, 1);

        width = new QSpinBox(groupBox_3);
        width->setObjectName(QStringLiteral("width"));
        width->setMinimum(1);
        width->setMaximum(65536);
        width->setValue(256);

        gridLayout_3->addWidget(width, 0, 1, 1, 1);

        seed = new QSpinBox(groupBox_3);
        seed->setObjectName(QStringLiteral("seed"));
        seed->setMaximum(65536);

        gridLayout_3->addWidget(seed, 3, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 4, 0, 1, 1);

        height = new QSpinBox(groupBox_3);
        height->setObjectName(QStringLiteral("height"));
        height->setMinimum(1);
        height->setMaximum(65536);
        height->setValue(256);

        gridLayout_3->addWidget(height, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 7, 0, 1, 1);

        supersampling = new QSpinBox(groupBox_3);
        supersampling->setObjectName(QStringLiteral("supersampling"));
        supersampling->setMinimum(1);
        supersampling->setMaximum(5);

        gridLayout_3->addWidget(supersampling, 2, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 5, 0, 1, 1);

        cwidth = new QSpinBox(groupBox_3);
        cwidth->setObjectName(QStringLiteral("cwidth"));
        cwidth->setMinimum(640);
        cwidth->setMaximum(65536);
        cwidth->setValue(640);

        gridLayout_3->addWidget(cwidth, 4, 1, 1, 1);

        cheight = new QSpinBox(groupBox_3);
        cheight->setObjectName(QStringLiteral("cheight"));
        cheight->setMinimum(480);
        cheight->setMaximum(65536);
        cheight->setValue(480);

        gridLayout_3->addWidget(cheight, 5, 1, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 6, 0, 1, 1);

        force = new QCheckBox(groupBox_3);
        force->setObjectName(QStringLiteral("force"));

        gridLayout_3->addWidget(force, 6, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        group_block = new QGroupBox(scrollAreaWidgetContents_2);
        group_block->setObjectName(QStringLiteral("group_block"));
        sizePolicy4.setHeightForWidth(group_block->sizePolicy().hasHeightForWidth());
        group_block->setSizePolicy(sizePolicy4);
        group_block->setMinimumSize(QSize(0, 260));
        group_block->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        group_block->setFlat(false);
        group_block->setCheckable(false);
        gridLayout_6 = new QGridLayout(group_block);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(5, 10, 5, 0);
        radio_custom_seed = new QRadioButton(group_block);
        radio_custom_seed->setObjectName(QStringLiteral("radio_custom_seed"));

        gridLayout_6->addWidget(radio_custom_seed, 5, 0, 1, 1);

        label_9 = new QLabel(group_block);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 1, 0, 1, 1);

        block_inputs = new QLineEdit(group_block);
        block_inputs->setObjectName(QStringLiteral("block_inputs"));
        block_inputs->setReadOnly(true);

        gridLayout_6->addWidget(block_inputs, 2, 1, 1, 1);

        block_id = new QLineEdit(group_block);
        block_id->setObjectName(QStringLiteral("block_id"));
        block_id->setReadOnly(true);

        gridLayout_6->addWidget(block_id, 1, 1, 1, 1);

        radio_global_seed = new QRadioButton(group_block);
        radio_global_seed->setObjectName(QStringLiteral("radio_global_seed"));
        radio_global_seed->setChecked(true);

        gridLayout_6->addWidget(radio_global_seed, 4, 0, 1, 1);

        label_8 = new QLabel(group_block);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_6->addWidget(label_8, 0, 0, 1, 1);

        label_10 = new QLabel(group_block);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_6->addWidget(label_10, 2, 0, 1, 1);

        pushButton_26 = new QPushButton(group_block);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));

        gridLayout_6->addWidget(pushButton_26, 6, 0, 1, 2);

        block_state = new QLineEdit(group_block);
        block_state->setObjectName(QStringLiteral("block_state"));
        block_state->setReadOnly(true);

        gridLayout_6->addWidget(block_state, 3, 1, 1, 1);

        label_13 = new QLabel(group_block);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_6->addWidget(label_13, 3, 0, 1, 1);

        custom_seed = new QSpinBox(group_block);
        custom_seed->setObjectName(QStringLiteral("custom_seed"));
        custom_seed->setMaximum(9999999);

        gridLayout_6->addWidget(custom_seed, 5, 1, 1, 1);

        block_name = new QLineEdit(group_block);
        block_name->setObjectName(QStringLiteral("block_name"));
        block_name->setReadOnly(true);

        gridLayout_6->addWidget(block_name, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_3, 7, 0, 1, 1);


        verticalLayout->addWidget(group_block);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setWidgetResizable(true);
        scrollArea_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 646, 486));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy5);
        scrollAreaWidgetContents_3->setSizeIncrement(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(147, 147, 147, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        scrollAreaWidgetContents_3->setPalette(palette);
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        editArea = new EditAreaFrame(scrollAreaWidgetContents_3);
        editArea->setObjectName(QStringLiteral("editArea"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(64);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(editArea->sizePolicy().hasHeightForWidth());
        editArea->setSizePolicy(sizePolicy6);
        editArea->setMinimumSize(QSize(640, 480));
        editArea->setBaseSize(QSize(640, 480));
        editArea->setContextMenuPolicy(Qt::NoContextMenu);
        editArea->setFrameShape(QFrame::StyledPanel);
        editArea->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(editArea, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout->addWidget(scrollArea_2);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 562, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        status_bar = new QStatusBar(MainWindow);
        status_bar->setObjectName(QStringLiteral("status_bar"));
        MainWindow->setStatusBar(status_bar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        QWidget::setTabOrder(width, height);
        QWidget::setTabOrder(height, supersampling);
        QWidget::setTabOrder(supersampling, seed);
        QWidget::setTabOrder(seed, cwidth);
        QWidget::setTabOrder(cwidth, cheight);
        QWidget::setTabOrder(cheight, force);
        QWidget::setTabOrder(force, block_name);
        QWidget::setTabOrder(block_name, block_id);
        QWidget::setTabOrder(block_id, block_inputs);
        QWidget::setTabOrder(block_inputs, block_state);
        QWidget::setTabOrder(block_state, custom_seed);
        QWidget::setTabOrder(custom_seed, pushButton_39);
        QWidget::setTabOrder(pushButton_39, pushButton_37);
        QWidget::setTabOrder(pushButton_37, pushButton_36);
        QWidget::setTabOrder(pushButton_36, pushButton_40);
        QWidget::setTabOrder(pushButton_40, pushButton_38);
        QWidget::setTabOrder(pushButton_38, pushButton_18);
        QWidget::setTabOrder(pushButton_18, pushButton_14);
        QWidget::setTabOrder(pushButton_14, pushButton_23);
        QWidget::setTabOrder(pushButton_23, pushButton_29);
        QWidget::setTabOrder(pushButton_29, pushButton_27);
        QWidget::setTabOrder(pushButton_27, pushButton_34);
        QWidget::setTabOrder(pushButton_34, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_42);
        QWidget::setTabOrder(pushButton_42, pushButton_22);
        QWidget::setTabOrder(pushButton_22, pushButton_25);
        QWidget::setTabOrder(pushButton_25, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_13);
        QWidget::setTabOrder(pushButton_13, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_15);
        QWidget::setTabOrder(pushButton_15, pushButton_43);
        QWidget::setTabOrder(pushButton_43, pushButton_44);
        QWidget::setTabOrder(pushButton_44, pushButton_35);
        QWidget::setTabOrder(pushButton_35, pushButton_20);
        QWidget::setTabOrder(pushButton_20, pushButton_24);
        QWidget::setTabOrder(pushButton_24, pushButton_31);
        QWidget::setTabOrder(pushButton_31, pushButton_30);
        QWidget::setTabOrder(pushButton_30, pushButton_32);
        QWidget::setTabOrder(pushButton_32, pushButton_41);
        QWidget::setTabOrder(pushButton_41, pushButton_45);
        QWidget::setTabOrder(pushButton_45, pushButton_46);
        QWidget::setTabOrder(pushButton_46, scrollArea);
        QWidget::setTabOrder(scrollArea, pushButton);
        QWidget::setTabOrder(pushButton, blockArea);
        QWidget::setTabOrder(blockArea, pushButton_12);
        QWidget::setTabOrder(pushButton_12, pushButton_19);
        QWidget::setTabOrder(pushButton_19, pushButton_9);
        QWidget::setTabOrder(pushButton_9, pushButton_28);
        QWidget::setTabOrder(pushButton_28, pushButton_17);
        QWidget::setTabOrder(pushButton_17, pushButton_33);
        QWidget::setTabOrder(pushButton_33, radio_custom_seed);
        QWidget::setTabOrder(radio_custom_seed, pushButton_11);
        QWidget::setTabOrder(pushButton_11, pushButton_3);
        QWidget::setTabOrder(pushButton_3, radio_global_seed);
        QWidget::setTabOrder(radio_global_seed, pushButton_26);
        QWidget::setTabOrder(pushButton_26, pushButton_10);
        QWidget::setTabOrder(pushButton_10, pushButton_21);
        QWidget::setTabOrder(pushButton_21, pushButton_16);
        QWidget::setTabOrder(pushButton_16, scrollArea_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_texture);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionRotate_CW);
        menuEdit->addAction(actionRotate_CCW);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionExecute);
        menuEdit->addAction(actionDisconnect);
        menuEdit->addAction(actionEdit_parameters);
        menuEdit->addAction(actionDefault_parameters_dialog);
        menuEdit->addAction(actionDuplicate);
        menuEdit->addAction(actionInvalidate_block);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionRotate_CW);
        toolBar->addAction(actionRotate_CCW);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionExecute);
        toolBar->addAction(actionDisconnect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        actionNew_texture->setText(QApplication::translate("MainWindow", "new", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "open", 0));
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("MainWindow", "save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "save as", 0));
        actionExit->setText(QApplication::translate("MainWindow", "exit", 0));
        actionHelp_topics->setText(QApplication::translate("MainWindow", "help topics", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "about", 0));
        actionRotate_CW->setText(QApplication::translate("MainWindow", "rotate CW", 0));
        actionRotate_CCW->setText(QApplication::translate("MainWindow", "rotate CCW", 0));
        actionDelete->setText(QApplication::translate("MainWindow", "delete", 0));
        actionExecute->setText(QApplication::translate("MainWindow", "execute", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "disconnect", 0));
        actionEdit_parameters->setText(QApplication::translate("MainWindow", "edit parameters", 0));
        actionDuplicate->setText(QApplication::translate("MainWindow", "duplicate", 0));
        actionDefault_parameters_dialog->setText(QApplication::translate("MainWindow", "default parameter dialog", 0));
        actionInvalidate_block->setText(QApplication::translate("MainWindow", "invalidate block", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_19->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_19->setText(QApplication::translate("MainWindow", "square mosaic", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_9->setText(QApplication::translate("MainWindow", "color transition", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_12->setText(QApplication::translate("MainWindow", "map transition", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_28->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_28->setText(QApplication::translate("MainWindow", "crop amplitude", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_17->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_17->setText(QApplication::translate("MainWindow", "edge detection", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_33->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_33->setText(QApplication::translate("MainWindow", "sine transform", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_16->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_16->setText(QApplication::translate("MainWindow", "brightness and contrast", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "bump noise", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_11->setText(QApplication::translate("MainWindow", "load file", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_10->setText(QApplication::translate("MainWindow", "save file", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_21->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_21->setText(QApplication::translate("MainWindow", "grayscale", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_39->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_39->setText(QApplication::translate("MainWindow", "replace colors", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_37->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_37->setText(QApplication::translate("MainWindow", "marble", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_36->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_36->setText(QApplication::translate("MainWindow", "wood", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_40->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_40->setText(QApplication::translate("MainWindow", "geometric transform", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_38->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_38->setText(QApplication::translate("MainWindow", "substrate", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_18->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_18->setText(QApplication::translate("MainWindow", "convolution", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_14->setText(QApplication::translate("MainWindow", "sharpen", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_23->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_23->setText(QApplication::translate("MainWindow", "light", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_29->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_29->setText(QApplication::translate("MainWindow", "dither", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_27->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_27->setText(QApplication::translate("MainWindow", "invert", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_34->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_34->setText(QApplication::translate("MainWindow", "circle transform", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QApplication::translate("MainWindow", "mix channels", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_42->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_42->setText(QApplication::translate("MainWindow", "fault formation noise", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_22->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_22->setText(QApplication::translate("MainWindow", "glass", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_25->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_25->setText(QApplication::translate("MainWindow", "end", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QApplication::translate("MainWindow", "l-system", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_13->setText(QApplication::translate("MainWindow", "emboss", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QApplication::translate("MainWindow", "mix", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QApplication::translate("MainWindow", "simple noise", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "perlin noise", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "voronoi diagram", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_15->setText(QApplication::translate("MainWindow", "blur", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_43->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_43->setText(QApplication::translate("MainWindow", "color fill", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_44->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_44->setText(QApplication::translate("MainWindow", "radius transform", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_35->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_35->setText(QApplication::translate("MainWindow", "particles", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_20->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_20->setText(QApplication::translate("MainWindow", "turtle", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_24->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_24->setText(QApplication::translate("MainWindow", "normal map", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_31->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_31->setText(QApplication::translate("MainWindow", "cellular automaton cyclic", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_30->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_30->setText(QApplication::translate("MainWindow", "cellular automaton general", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_32->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_32->setText(QApplication::translate("MainWindow", "cellular automaton rps", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_41->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_41->setText(QApplication::translate("MainWindow", "tile", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_45->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_45->setText(QApplication::translate("MainWindow", "adjust rgb", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_46->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_46->setText(QApplication::translate("MainWindow", "adjust hsl", 0));
        pushButton->setText(QApplication::translate("MainWindow", "display full size", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "global settings", 0));
        label->setText(QApplication::translate("MainWindow", "texture width", 0));
        label_4->setText(QApplication::translate("MainWindow", "global seed", 0));
        label_2->setText(QApplication::translate("MainWindow", "texture height", 0));
        label_3->setText(QApplication::translate("MainWindow", "supersampling", 0));
        label_5->setText(QApplication::translate("MainWindow", "canvas width", 0));
        label_6->setText(QApplication::translate("MainWindow", "canvas height", 0));
        label_7->setText(QApplication::translate("MainWindow", "force compute", 0));
        force->setText(QString());
        group_block->setTitle(QApplication::translate("MainWindow", "block", 0));
        radio_custom_seed->setText(QApplication::translate("MainWindow", "use custom seed", 0));
        label_9->setText(QApplication::translate("MainWindow", "ID", 0));
        radio_global_seed->setText(QApplication::translate("MainWindow", "use global seed", 0));
        label_8->setText(QApplication::translate("MainWindow", "name", 0));
        label_10->setText(QApplication::translate("MainWindow", "inputs", 0));
        pushButton_26->setText(QApplication::translate("MainWindow", "edit parameters", 0));
        label_13->setText(QApplication::translate("MainWindow", "state", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
