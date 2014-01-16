#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "ptdesigner.h"

using namespace std;
using namespace pt_design;

//-----------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  this->graph = new c_texture_graph();

  t_block_position pos;

  this->graph->add_block(new c_block_voronoi_diagram());
  pos.block_id = 0;
  pos.x = 50;
  pos.y = 100;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->add_block(new c_block_perlin_noise());
  pos.block_id = 1;
  pos.x = 100;
  pos.y = 220;
  pos.direction = 0;
  this->set_block_position(pos);

  ui->setupUi(this);
  ui->editArea->set_main_window(this);
}

//-----------------------------------------------------

MainWindow::~MainWindow()

{
  delete this->graph;
  delete ui;
}

//-----------------------------------------------------

void MainWindow::set_block_position(t_block_position position)

{
  unsigned int i;

  for (i = 0; i < this->block_positions.size(); i++)
    if (this->block_positions.at(i).block_id == position.block_id)
      {
        this->block_positions.erase(this->block_positions.begin() + i);
      }

  this->block_positions.push_back(position);
}

//-----------------------------------------------------

void MainWindow::delete_block_position(int block_id)

{
  unsigned int i;

  for (i = 0; i < this->block_positions.size(); i++)
    if (this->block_positions.at(i).block_id == block_id)
      {
        this->block_positions.erase(this->block_positions.begin() + i);
        break;
      }
}

//-----------------------------------------------------
t_block_position *MainWindow::get_block_position(int block_id)

{
  unsigned int i;

  for (i = 0; i < this->block_positions.size(); i++)
    if (this->block_positions.at(i).block_id == block_id)
      {
        return &(this->block_positions.at(i));
      }

  return NULL;
}

//-----------------------------------------------------

void MainWindow::dropEvent(QDropEvent *de)

{
}

//-----------------------------------------------------

void MainWindow::dragMoveEvent(QDragMoveEvent *de)

{
}

//-----------------------------------------------------

void MainWindow::dragEnterEvent(QDragEnterEvent *event)

{
}

//-----------------------------------------------------

void MainWindow::on_pushButton_2_clicked()

{
}

//-----------------------------------------------------

c_texture_graph *MainWindow::get_texture_graph()

{
  return this->graph;
}

//-----------------------------------------------------
