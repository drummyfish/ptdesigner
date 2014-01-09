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
    c_texture_graph *graph = new c_texture_graph();

    graph->add_block(new c_block_file_save());                   // 0
    graph->add_block(new c_block_edge_detection());              // 1
    graph->add_block(new c_block_substrate());                   // 2

    graph->connect_by_id(1,0,0);
    graph->connect_by_id(2,1,0);

    graph->set_resolution(512,512);
    graph->set_supersampling(1);

    cout << "computing:" << graph->compute(false) << endl;

    graph->print_as_text();

    delete graph;

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
