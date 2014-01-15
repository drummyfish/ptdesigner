#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "ptdesigner.h"

using namespace std;
using namespace pt_design;

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

void MainWindow::on_pushButton_2_clicked()
{

}
