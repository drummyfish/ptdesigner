#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dropEvent(QDropEvent *de)
{
}

void MainWindow::dragMoveEvent(QDragMoveEvent *de)
{
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
}
