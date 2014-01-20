/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Jan 20 11:06:32 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
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
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    colorBufferDisplay *preview;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_2;
    editAreaFrame *editArea;
    QScrollArea *blockArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    addBlockButton *pushButton_33;
    QSpacerItem *horizontalSpacer;
    addBlockButton *pushButton_16;
    addBlockButton *pushButton_3;
    addBlockButton *pushButton_11;
    addBlockButton *pushButton_10;
    addBlockButton *pushButton_21;
    addBlockButton *pushButton_39;
    addBlockButton *pushButton_17;
    addBlockButton *pushButton_37;
    addBlockButton *pushButton_36;
    addBlockButton *pushButton_40;
    addBlockButton *pushButton_38;
    addBlockButton *pushButton_18;
    addBlockButton *pushButton_14;
    addBlockButton *pushButton_23;
    addBlockButton *pushButton_29;
    addBlockButton *pushButton_27;
    addBlockButton *pushButton_34;
    addBlockButton *pushButton_6;
    addBlockButton *pushButton_42;
    addBlockButton *pushButton_22;
    addBlockButton *pushButton_25;
    addBlockButton *pushButton_8;
    addBlockButton *pushButton_13;
    addBlockButton *pushButton_7;
    addBlockButton *pushButton_5;
    addBlockButton *pushButton_4;
    addBlockButton *pushButton_2;
    addBlockButton *pushButton_15;
    addBlockButton *pushButton_43;
    addBlockButton *pushButton_44;
    addBlockButton *pushButton_35;
    addBlockButton *pushButton_20;
    addBlockButton *pushButton_24;
    addBlockButton *pushButton_31;
    addBlockButton *pushButton_30;
    addBlockButton *pushButton_32;
    addBlockButton *pushButton_41;
    addBlockButton *pushButton_19;
    addBlockButton *pushButton_9;
    addBlockButton *pushButton_12;
    addBlockButton *pushButton_28;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(562, 518);
        actionNew_texture = new QAction(MainWindow);
        actionNew_texture->setObjectName(QString::fromUtf8("actionNew_texture"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/action save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHelp_topics = new QAction(MainWindow);
        actionHelp_topics->setObjectName(QString::fromUtf8("actionHelp_topics"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionRotate_CW = new QAction(MainWindow);
        actionRotate_CW->setObjectName(QString::fromUtf8("actionRotate_CW"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/action rotate cw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate_CW->setIcon(icon1);
        actionRotate_CCW = new QAction(MainWindow);
        actionRotate_CCW->setObjectName(QString::fromUtf8("actionRotate_CCW"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/action rotate ccw.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate_CCW->setIcon(icon2);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/action delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon3);
        actionExecute = new QAction(MainWindow);
        actionExecute->setObjectName(QString::fromUtf8("actionExecute"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/action execute.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExecute->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(180, 0));
        scrollArea->setMaximumSize(QSize(160, 16777215));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 178, 262));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(scrollAreaWidgetContents_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        preview = new colorBufferDisplay(widget);
        preview->setObjectName(QString::fromUtf8("preview"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(preview->sizePolicy().hasHeightForWidth());
        preview->setSizePolicy(sizePolicy2);
        preview->setMinimumSize(QSize(140, 140));
        preview->setFrameShape(QFrame::StyledPanel);
        preview->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(preview);


        verticalLayout->addWidget(widget);

        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(0, 50));
        groupBox->setSizeIncrement(QSize(0, 0));

        verticalLayout->addWidget(groupBox);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea);

        scrollArea_2 = new QScrollArea(centralWidget);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 373, 262));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy4);
        scrollAreaWidgetContents_3->setSizeIncrement(QSize(0, 0));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        editArea = new editAreaFrame(scrollAreaWidgetContents_3);
        editArea->setObjectName(QString::fromUtf8("editArea"));
        sizePolicy4.setHeightForWidth(editArea->sizePolicy().hasHeightForWidth());
        editArea->setSizePolicy(sizePolicy4);
        editArea->setMinimumSize(QSize(0, 0));
        editArea->setFrameShape(QFrame::StyledPanel);
        editArea->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(editArea);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout->addWidget(scrollArea_2);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        blockArea = new QScrollArea(centralWidget);
        blockArea->setObjectName(QString::fromUtf8("blockArea"));
        blockArea->setMinimumSize(QSize(0, 155));
        blockArea->setMaximumSize(QSize(16777215, 150));
        blockArea->setBaseSize(QSize(0, 0));
        blockArea->setFrameShape(QFrame::StyledPanel);
        blockArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(-701, 0, 1257, 137));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_33 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));
        pushButton_33->setMinimumSize(QSize(53, 53));
        pushButton_33->setMaximumSize(QSize(53, 53));
        pushButton_33->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_33, 1, 20, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 42, 1, 1);

        pushButton_16 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setMinimumSize(QSize(53, 53));
        pushButton_16->setMaximumSize(QSize(53, 53));
        pushButton_16->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_16, 1, 24, 1, 1);

        pushButton_3 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(53, 53));
        pushButton_3->setMaximumSize(QSize(53, 53));
        pushButton_3->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_11 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(53, 53));
        pushButton_11->setMaximumSize(QSize(53, 53));
        pushButton_11->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_11, 2, 2, 1, 1);

        pushButton_10 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(53, 53));
        pushButton_10->setMaximumSize(QSize(53, 53));
        pushButton_10->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_10, 2, 1, 1, 1);

        pushButton_21 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));
        pushButton_21->setMinimumSize(QSize(53, 53));
        pushButton_21->setMaximumSize(QSize(53, 53));
        pushButton_21->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_21, 1, 8, 1, 1);

        pushButton_39 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));
        pushButton_39->setMinimumSize(QSize(53, 53));
        pushButton_39->setMaximumSize(QSize(53, 53));
        pushButton_39->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_39, 2, 31, 1, 1);

        pushButton_17 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setMinimumSize(QSize(53, 53));
        pushButton_17->setMaximumSize(QSize(53, 53));
        pushButton_17->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_17, 2, 8, 1, 1);

        pushButton_37 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));
        pushButton_37->setMinimumSize(QSize(53, 53));
        pushButton_37->setMaximumSize(QSize(53, 53));
        pushButton_37->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_37, 1, 18, 1, 1);

        pushButton_36 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));
        pushButton_36->setMinimumSize(QSize(53, 53));
        pushButton_36->setMaximumSize(QSize(53, 53));
        pushButton_36->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_36, 1, 16, 1, 1);

        pushButton_40 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_40->setObjectName(QString::fromUtf8("pushButton_40"));
        pushButton_40->setMinimumSize(QSize(53, 53));
        pushButton_40->setMaximumSize(QSize(53, 53));
        pushButton_40->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_40, 1, 19, 1, 1);

        pushButton_38 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_38->setObjectName(QString::fromUtf8("pushButton_38"));
        pushButton_38->setMinimumSize(QSize(53, 53));
        pushButton_38->setMaximumSize(QSize(53, 53));
        pushButton_38->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_38, 1, 6, 1, 1);

        pushButton_18 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setMinimumSize(QSize(53, 53));
        pushButton_18->setMaximumSize(QSize(53, 53));
        pushButton_18->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_18, 2, 9, 1, 1);

        pushButton_14 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMinimumSize(QSize(53, 53));
        pushButton_14->setMaximumSize(QSize(53, 53));
        pushButton_14->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_14, 2, 7, 1, 1);

        pushButton_23 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));
        pushButton_23->setMinimumSize(QSize(53, 53));
        pushButton_23->setMaximumSize(QSize(53, 53));
        pushButton_23->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_23, 2, 16, 1, 1);

        pushButton_29 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));
        pushButton_29->setMinimumSize(QSize(53, 53));
        pushButton_29->setMaximumSize(QSize(53, 53));
        pushButton_29->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_29, 1, 10, 1, 1);

        pushButton_27 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));
        pushButton_27->setMinimumSize(QSize(53, 53));
        pushButton_27->setMaximumSize(QSize(53, 53));
        pushButton_27->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_27, 1, 7, 1, 1);

        pushButton_34 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));
        pushButton_34->setMinimumSize(QSize(53, 53));
        pushButton_34->setMaximumSize(QSize(53, 53));
        pushButton_34->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_34, 1, 21, 1, 1);

        pushButton_6 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(53, 53));
        pushButton_6->setMaximumSize(QSize(53, 53));
        pushButton_6->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_6, 2, 4, 1, 1);

        pushButton_42 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_42->setObjectName(QString::fromUtf8("pushButton_42"));
        pushButton_42->setMinimumSize(QSize(53, 53));
        pushButton_42->setMaximumSize(QSize(53, 53));
        pushButton_42->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_42, 1, 5, 1, 1);

        pushButton_22 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));
        pushButton_22->setMinimumSize(QSize(53, 53));
        pushButton_22->setMaximumSize(QSize(53, 53));
        pushButton_22->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_22, 1, 9, 1, 1);

        pushButton_25 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));
        pushButton_25->setMinimumSize(QSize(53, 53));
        pushButton_25->setMaximumSize(QSize(53, 53));
        pushButton_25->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_25, 2, 0, 1, 1);

        pushButton_8 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(53, 53));
        pushButton_8->setMaximumSize(QSize(53, 53));
        pushButton_8->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_8, 2, 24, 1, 1);

        pushButton_13 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setMinimumSize(QSize(53, 53));
        pushButton_13->setMaximumSize(QSize(53, 53));
        pushButton_13->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_13, 2, 6, 1, 1);

        pushButton_7 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(53, 53));
        pushButton_7->setMaximumSize(QSize(53, 53));
        pushButton_7->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_7, 2, 3, 1, 1);

        pushButton_5 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(53, 53));
        pushButton_5->setMaximumSize(QSize(53, 53));
        pushButton_5->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_5, 1, 4, 1, 1);

        pushButton_4 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(53, 53));
        pushButton_4->setMaximumSize(QSize(53, 53));
        pushButton_4->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_4, 1, 3, 1, 1);

        pushButton_2 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(53, 53));
        pushButton_2->setMaximumSize(QSize(53, 53));
        pushButton_2->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_15 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMinimumSize(QSize(53, 53));
        pushButton_15->setMaximumSize(QSize(53, 53));
        pushButton_15->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_15, 2, 5, 1, 1);

        pushButton_43 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_43->setObjectName(QString::fromUtf8("pushButton_43"));
        pushButton_43->setMinimumSize(QSize(53, 53));
        pushButton_43->setMaximumSize(QSize(53, 53));
        pushButton_43->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_43, 1, 0, 1, 1);

        pushButton_44 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_44->setObjectName(QString::fromUtf8("pushButton_44"));
        pushButton_44->setMinimumSize(QSize(53, 53));
        pushButton_44->setMaximumSize(QSize(53, 53));
        pushButton_44->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_44, 1, 25, 1, 1);

        pushButton_35 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));
        pushButton_35->setMinimumSize(QSize(53, 53));
        pushButton_35->setMaximumSize(QSize(53, 53));
        pushButton_35->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_35, 2, 21, 1, 1);

        pushButton_20 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setMinimumSize(QSize(53, 53));
        pushButton_20->setMaximumSize(QSize(53, 53));
        pushButton_20->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_20, 2, 25, 1, 1);

        pushButton_24 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));
        pushButton_24->setMinimumSize(QSize(53, 53));
        pushButton_24->setMaximumSize(QSize(53, 53));
        pushButton_24->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_24, 2, 10, 1, 1);

        pushButton_31 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));
        pushButton_31->setMinimumSize(QSize(53, 53));
        pushButton_31->setMaximumSize(QSize(53, 53));
        pushButton_31->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_31, 2, 18, 1, 1);

        pushButton_30 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));
        pushButton_30->setMinimumSize(QSize(53, 53));
        pushButton_30->setMaximumSize(QSize(53, 53));
        pushButton_30->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_30, 2, 19, 1, 1);

        pushButton_32 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));
        pushButton_32->setMinimumSize(QSize(53, 53));
        pushButton_32->setMaximumSize(QSize(53, 53));
        pushButton_32->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_32, 2, 20, 1, 1);

        pushButton_41 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_41->setObjectName(QString::fromUtf8("pushButton_41"));
        pushButton_41->setMinimumSize(QSize(53, 53));
        pushButton_41->setMaximumSize(QSize(53, 53));
        pushButton_41->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_41, 2, 29, 1, 1);

        pushButton_19 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setMinimumSize(QSize(53, 53));
        pushButton_19->setMaximumSize(QSize(53, 53));
        pushButton_19->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_19, 2, 30, 1, 1);

        pushButton_9 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(53, 53));
        pushButton_9->setMaximumSize(QSize(53, 53));
        pushButton_9->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_9, 1, 29, 1, 1);

        pushButton_12 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setMinimumSize(QSize(53, 53));
        pushButton_12->setMaximumSize(QSize(53, 53));
        pushButton_12->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_12, 1, 30, 1, 1);

        pushButton_28 = new addBlockButton(scrollAreaWidgetContents);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));
        pushButton_28->setMinimumSize(QSize(53, 53));
        pushButton_28->setMaximumSize(QSize(53, 53));
        pushButton_28->setBaseSize(QSize(53, 53));

        gridLayout_2->addWidget(pushButton_28, 1, 31, 1, 1);

        blockArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(blockArea, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 562, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

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
        menuHelp->addAction(actionHelp_topics);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionRotate_CW);
        toolBar->addAction(actionRotate_CCW);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionExecute);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Texture Designer", 0, QApplication::UnicodeUTF8));
        actionNew_texture->setText(QApplication::translate("MainWindow", "new", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "save", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("MainWindow", "save as", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "exit", 0, QApplication::UnicodeUTF8));
        actionHelp_topics->setText(QApplication::translate("MainWindow", "help topics", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "about", 0, QApplication::UnicodeUTF8));
        actionRotate_CW->setText(QApplication::translate("MainWindow", "rotate CW", 0, QApplication::UnicodeUTF8));
        actionRotate_CCW->setText(QApplication::translate("MainWindow", "rotate CCW", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "delete", 0, QApplication::UnicodeUTF8));
        actionExecute->setText(QApplication::translate("MainWindow", "execute", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "display full size", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "block", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_33->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_33->setText(QApplication::translate("MainWindow", "sine transform", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_16->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_16->setText(QApplication::translate("MainWindow", "brightness and contrast", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("MainWindow", "bump noise", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_11->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_11->setText(QApplication::translate("MainWindow", "load file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_10->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_10->setText(QApplication::translate("MainWindow", "save file", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_21->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_21->setText(QApplication::translate("MainWindow", "grayscale", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_39->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_39->setText(QApplication::translate("MainWindow", "replace colors", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_17->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_17->setText(QApplication::translate("MainWindow", "edge detection", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_37->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_37->setText(QApplication::translate("MainWindow", "marble", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_36->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_36->setText(QApplication::translate("MainWindow", "wood", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_40->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_40->setText(QApplication::translate("MainWindow", "geometric transform", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_38->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_38->setText(QApplication::translate("MainWindow", "substrate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_18->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_18->setText(QApplication::translate("MainWindow", "convolution", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_14->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_14->setText(QApplication::translate("MainWindow", "sharpen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_23->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_23->setText(QApplication::translate("MainWindow", "light", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_29->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_29->setText(QApplication::translate("MainWindow", "dither", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_27->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_27->setText(QApplication::translate("MainWindow", "invert", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_34->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_34->setText(QApplication::translate("MainWindow", "circle transform", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_6->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_6->setText(QApplication::translate("MainWindow", "mix channels", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_42->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_42->setText(QApplication::translate("MainWindow", "fault formation noise", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_22->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_22->setText(QApplication::translate("MainWindow", "glass", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_25->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_25->setText(QApplication::translate("MainWindow", "end", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_8->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_8->setText(QApplication::translate("MainWindow", "l-system", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_13->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_13->setText(QApplication::translate("MainWindow", "emboss", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_7->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_7->setText(QApplication::translate("MainWindow", "mix", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_5->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_5->setText(QApplication::translate("MainWindow", "simple noise", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "perlin noise", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("MainWindow", "voronoi diagram", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_15->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_15->setText(QApplication::translate("MainWindow", "blur", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_43->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_43->setText(QApplication::translate("MainWindow", "color fill", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_44->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_44->setText(QApplication::translate("MainWindow", "radius transform", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_35->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_35->setText(QApplication::translate("MainWindow", "particles", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_20->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_20->setText(QApplication::translate("MainWindow", "turtle", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_24->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_24->setText(QApplication::translate("MainWindow", "normal map", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_31->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_31->setText(QApplication::translate("MainWindow", "cellular automaton cyclic", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_30->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_30->setText(QApplication::translate("MainWindow", "cellular automaton general", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_32->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_32->setText(QApplication::translate("MainWindow", "cellular automaton rps", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_41->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_41->setText(QApplication::translate("MainWindow", "tile", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_19->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_19->setText(QApplication::translate("MainWindow", "square mosaic", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_9->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_9->setText(QApplication::translate("MainWindow", "color transition", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_12->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_12->setText(QApplication::translate("MainWindow", "map transition", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_28->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButton_28->setText(QApplication::translate("MainWindow", "crop amplitude", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
