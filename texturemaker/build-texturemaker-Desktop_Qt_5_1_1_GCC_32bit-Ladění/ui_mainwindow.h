/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QScrollArea *editArea;
    QWidget *scrollAreaWidgetContents_2;
    QFrame *previewFrame;
    QPushButton *fullSizeButton;
    QGroupBox *blockPropertiesBox;
    QGraphicsView *designArea;
    QScrollArea *blockArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(702, 457);
        actionNew_texture = new QAction(MainWindow);
        actionNew_texture->setObjectName(QStringLiteral("actionNew_texture"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp_topics = new QAction(MainWindow);
        actionHelp_topics->setObjectName(QStringLiteral("actionHelp_topics"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        editArea = new QScrollArea(centralWidget);
        editArea->setObjectName(QStringLiteral("editArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editArea->sizePolicy().hasHeightForWidth());
        editArea->setSizePolicy(sizePolicy);
        editArea->setMinimumSize(QSize(160, 0));
        editArea->setMaximumSize(QSize(160, 16777215));
        editArea->setSizeIncrement(QSize(0, 0));
        editArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 158, 271));
        previewFrame = new QFrame(scrollAreaWidgetContents_2);
        previewFrame->setObjectName(QStringLiteral("previewFrame"));
        previewFrame->setGeometry(QRect(10, 10, 141, 131));
        previewFrame->setFrameShape(QFrame::StyledPanel);
        previewFrame->setFrameShadow(QFrame::Raised);
        fullSizeButton = new QPushButton(scrollAreaWidgetContents_2);
        fullSizeButton->setObjectName(QStringLiteral("fullSizeButton"));
        fullSizeButton->setGeometry(QRect(10, 150, 141, 22));
        blockPropertiesBox = new QGroupBox(scrollAreaWidgetContents_2);
        blockPropertiesBox->setObjectName(QStringLiteral("blockPropertiesBox"));
        blockPropertiesBox->setGeometry(QRect(10, 180, 141, 81));
        editArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(editArea);

        designArea = new QGraphicsView(centralWidget);
        designArea->setObjectName(QStringLiteral("designArea"));

        horizontalLayout->addWidget(designArea);


        verticalLayout->addLayout(horizontalLayout);

        blockArea = new QScrollArea(centralWidget);
        blockArea->setObjectName(QStringLiteral("blockArea"));
        blockArea->setMinimumSize(QSize(0, 100));
        blockArea->setMaximumSize(QSize(16777215, 100));
        blockArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 682, 98));
        blockArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(blockArea);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 702, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew_texture);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionHelp_topics);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Texture Designer", 0));
        actionNew_texture->setText(QApplication::translate("MainWindow", "new", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "save as", 0));
        actionExit->setText(QApplication::translate("MainWindow", "exit", 0));
        actionHelp_topics->setText(QApplication::translate("MainWindow", "help topics", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "about", 0));
        fullSizeButton->setText(QApplication::translate("MainWindow", "view full size", 0));
        blockPropertiesBox->setTitle(QApplication::translate("MainWindow", "block properties", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
