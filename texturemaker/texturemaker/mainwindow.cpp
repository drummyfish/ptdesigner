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
  pos.x = 5;
  pos.y = 10;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->add_block(new c_block_perlin_noise());
  pos.block_id = 1;
  pos.x = 100;
  pos.y = 220;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->add_block(new c_block_mix_channels());
  pos.block_id = 2;
  pos.x = 200;
  pos.y = 300;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->add_block(new c_block_voronoi_diagram());
  pos.block_id = 3;
  pos.x = 5;
  pos.y = 10;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->add_block(new c_block_voronoi_diagram());
  pos.block_id = 4;
  pos.x = 5;
  pos.y = 10;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->add_block(new c_block_voronoi_diagram());
  pos.block_id = 5;
  pos.x = 5;
  pos.y = 10;
  pos.direction = 0;
  this->set_block_position(pos);

  this->graph->connect_by_id(0,2,0);
  this->graph->connect_by_id(1,2,1);
  this->graph->connect_by_id(3,2,2);
//  this->graph->connect_by_id(4,2,3);
//  this->graph->connect_by_id(5,2,4);

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

int MainWindow::get_block_by_position(int x, int y, int *slot)

{
  unsigned int i;
  int block_x, block_y, dx, dy, result, direction;
  bool found;
  c_block *block;

  result = -1;
  found = false;

  for (i = 0; i < this->block_positions.size(); i++)
    {
      block_x = this->block_positions.at(i).x;
      block_y = this->block_positions.at(i).y;
      direction = this->block_positions.at(i).direction;

      if (x >= block_x - 8 && x <= block_x + 64 &&
          y >= block_y - 5 && y <= block_y + 64)
        {
          result = this->block_positions.at(i).block_id;
          dx = x - block_x;
          dy = y - block_y;
          found = true;
          break;
        }
    }

  cout << found << " " << dx << " " << dy << endl;

  *slot = -1;

  if (found)
    switch (direction)
      {
        case 0: // up
          if (dx >= 24 && dy >= -4 && dx <= 34 && dy <= 1)
            *slot = MAX_INPUT_BLOCKS;
          else
            {
              for (i = 0; i < MAX_INPUT_BLOCKS; i++)
                if (dx >= (i + 1) * 7 && dy >= 58 && dx <= (i + 2) * 8 && dy <= 64)
                  {
                    *slot = i;
                    break;
                  }
            }

          break;

        case 1: // right
          if (dx >= 57 && dy >= 27 && dx <= 62 && dy <= 35)
            *slot = MAX_INPUT_BLOCKS;
          else
            {
              for (i = 0; i < MAX_INPUT_BLOCKS; i++)
                if (dx >= -8 && dy >= 9 + i * 9 && dx <= -1 && dy <= 9 + (i + 1) * 9)
                  {
                    *slot = i;
                    break;
                  }
            }

          break;

        case 2: // down
          if (dx >= 23 && dy >= 59 && dx <= 31 && dy <= 64)
            *slot = MAX_INPUT_BLOCKS;
          else
            {
              for (i = 0; i < MAX_INPUT_BLOCKS; i++)
                if (dx >= (i + 1) * 7 && dy >= -4 && dx <= (i + 2) * 8 && dy <= 1)
                  {
                    *slot = MAX_INPUT_BLOCKS - i - 1;
                    break;
                  }
            }

          break;

        case 3: // left
          if (dx >= -8 && dy >= 27 && dx <= 1 && dy <= 36)
            *slot = MAX_INPUT_BLOCKS;
          else
            {
              for (i = 0; i < MAX_INPUT_BLOCKS; i++)
                if (dx >= 56 && dy >= 9 + i * 9 && dx <= 63 && dy <= 9 + (i + 1) * 9)
                  {
                    *slot = MAX_INPUT_BLOCKS - i - 1;
                    break;
                  }
            }

          break;

        default:
          break;
      }

  if (found)
    {
      block = this->graph->get_block_by_id(result);

      if (*slot == MAX_INPUT_BLOCKS)
        {
          if (block->is_terminal())
            *slot = -1;
        }
      else if (*slot >= block->get_max_inputs())
        *slot = -1;
    }

  return result;
}

//-----------------------------------------------------

void MainWindow::delete_block_by_id(int id)

{
  if (id < 0)
    return;

  ui->preview->set_block(NULL);

  this->delete_block_position(id);
  this->graph->delete_block(id);
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

void MainWindow::on_actionDelete_triggered()
{
  this->delete_block_by_id(ui->editArea->get_selected_id());
  this->ui->editArea->update();
}

//-----------------------------------------------------

void MainWindow::on_actionRotate_CW_triggered()
{
  t_block_position *position;
  int id;

  id = ui->editArea->get_selected_id();

  if (id < 0)
    return;

  position = this->get_block_position(id);

  (position->direction)++;

  if (position->direction >= 4)
    position->direction = 0;

  ui->editArea->update();  // redraw
}

//-----------------------------------------------------

void MainWindow::set_block_for_preview(int id)

{
  if (id < 0)
    ui->preview->set_block(NULL);
  else
    ui->preview->set_block(this->graph->get_block_by_id((unsigned int) id));

  ui->preview->update();
}

//-----------------------------------------------------

void MainWindow::on_actionRotate_CCW_triggered()
{
  t_block_position *position;
  int id;

  id = ui->editArea->get_selected_id();

  if (id < 0)
    return;

  position = this->get_block_position(id);

  if (position->direction == 0)
    position->direction = 3;
  else
    position->direction--;

  ui->editArea->update();
}


//-----------------------------------------------------

void MainWindow::on_actionExecute_triggered()
{
  this->graph->compute(false);
  ui->editArea->update();
  ui->preview->update();
}

//-----------------------------------------------------

void MainWindow::global_settings_changed()

{
  if (ui->width->value() < 1)
    ui->width->setValue(1);

  if (ui->height->value() < 1)
    ui->height->setValue(1);

  if (ui->supersampling->value() < 1)
    ui->supersampling->setValue(1);

  if (ui->supersampling->value() > 5)
    ui->supersampling->setValue(5);

  if (ui->seed->value() < 0)
    ui->seed->setValue(0);

  this->graph->set_random_seed(ui->seed->value());
  this->graph->set_supersampling(ui->supersampling->value());
  this->graph->set_resolution(ui->width->value(),ui->height->value());

  ui->editArea->update();
  ui->preview->update();
}

//-----------------------------------------------------

void MainWindow::canvas_resolution_changed()

{
  ui->editArea->resize(ui->cwidth->value(),ui->cheight->value());
  ui->editArea->setMinimumSize(ui->cwidth->value(),ui->cheight->value());
  ui->editArea->setMaximumSize(ui->cwidth->value(),ui->cheight->value());
  ui->editArea->update();
}

//-----------------------------------------------------

void MainWindow::on_width_valueChanged(int arg1)
{
  this->global_settings_changed();
}

//-----------------------------------------------------

void MainWindow::on_height_valueChanged(int arg1)
{
  this->global_settings_changed();
}

//-----------------------------------------------------

void MainWindow::on_supersampling_valueChanged(int arg1)
{
  this->global_settings_changed();
}

//-----------------------------------------------------

void MainWindow::on_seed_valueChanged(int arg1)
{
  this->global_settings_changed();
}

//-----------------------------------------------------

void MainWindow::on_cwidth_valueChanged(int arg1)
{
  this->canvas_resolution_changed();
}

//----------------------------------------------------

void MainWindow::on_cheight_valueChanged(int arg1)
{
  this->canvas_resolution_changed();
}

//----------------------------------------------------
