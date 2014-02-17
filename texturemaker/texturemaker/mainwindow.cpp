#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "ptdesigner.h"
#include "aboutdialog.h"

using namespace std;
using namespace pt_design;

//-----------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
  this->graph = new c_texture_graph();
  ui->setupUi(this);
  ui->editArea->set_main_window(this);
  ui->preview->set_main_window(this);
  ui->group_block->hide();
  this->update_title();
  this->filename = "";
  this->change_happened = false;
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
                if ((int) dx >= -8 && dy >= 9 + i * 9 && (int) dx <= -1 && dy <= 9 + (i + 1) * 9)
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
                if ((int) dx >= (i + 1) * 7 && (int) dy >= -4 && (int) dx <= (i + 2) * 8 && (int) dy <= 1)
                  {
                    *slot = MAX_INPUT_BLOCKS - i - 1;
                    break;
                  }
            }

          break;

        case 3: // left
          if ((int) dx >= -8 && (int) dy >= 27 && (int) dx <= 1 && dy <= 36)
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
      else if ((unsigned int) *slot >= block->get_max_inputs())
        *slot = -1;
    }

  return result;
}

//-----------------------------------------------------

void MainWindow::change_occured()

{
  this->change_happened = true;
}

//-----------------------------------------------------

bool MainWindow::save_positions(QString filename)

{
  ofstream output_file(filename.toStdString().c_str());
  unsigned int i;
  t_block_position position;

  if (output_file.is_open())
    {
      output_file << ui->editArea->width() << ":" << ui->editArea->height() << "\n"; // canvas size

      for (i = 0; i < this->block_positions.size(); i++)
        {
          position = this->block_positions.at(i);

          output_file << position.block_id << ";";     // id
          output_file << position.x << ";";            // x
          output_file << position.y << ";";            // y
          output_file << ((int) position.direction) << "\n"; // direction
      }

    output_file.close();
      return true;
    }

  return false;
}

//-----------------------------------------------------

void MainWindow::delete_block_by_id(int id)

{
  if (id < 0)
    return;

  this->graph_mutex.lock();

  ui->preview->set_block(NULL);
  this->delete_block_position(id);
  this->graph->delete_block_with_id(id);

  this->graph_mutex.unlock();
}

//-----------------------------------------------------

QMutex *MainWindow::get_graph_mutex()

{
  return &this->graph_mutex;
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
        this->change_occured();
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
  this->update_graphics();
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

void MainWindow::update_graphics()

{
  ui->editArea->update();
  ui->preview->invalidate();
  ui->preview->update();
}

//-----------------------------------------------------

void MainWindow::compute_thread(MainWindow *window, bool force)

{
  window->get_graph_mutex()->lock();
  window->graph->compute(force);
  window->get_graph_mutex()->unlock();
  window->update_graphics();
}

//-----------------------------------------------------

void MainWindow::on_actionExecute_triggered()

{
  QFuture<void> future;

  future = QtConcurrent::run(MainWindow::compute_thread,this,ui->force->isChecked());   // run the computation in separate thread with one parameter
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

//-----------------------------------------------------

void MainWindow::block_selected(int block_id)

{
  c_block *block;

  if (block_id >= 0)
    {
      ui->group_block->show();

      block = this->graph->get_block_by_id(block_id);

      if (block == NULL)
        return;

      ui->block_name->setText(QString::fromStdString(block->get_name()));
      ui->block_id->setText(QString::number(block->get_id()));
      ui->block_inputs->setText(QString::number(block->get_min_inputs()) + " - " + QString::number(block->get_max_inputs()));

      if (block->is_error())
        ui->block_state->setText("error");
      else if (block->is_valid())
        ui->block_state->setText("valid");
      else
        ui->block_state->setText("invalid");

      if (block->is_using_global_seed())
        {
          ui->custom_seed->setValue(block->get_random_seed());
          ui->radio_global_seed->setChecked(true);
          ui->radio_custom_seed->setChecked(false);          
        }
      else
        {
          ui->custom_seed->setValue(block->get_random_seed());
          ui->radio_global_seed->setChecked(false);
          ui->radio_custom_seed->setChecked(true);
        }
    }
  else
    {
      ui->group_block->hide();
    }
}

//-----------------------------------------------------

bool MainWindow::closing_file()

{
  if (!this->change_happened)
    return true;

  QMessageBox::StandardButton reply;

  reply = QMessageBox::question(this,"Confirmation", "Close the file without saving?",QMessageBox::Yes|QMessageBox::No);

  return reply == QMessageBox::Yes;
}

//-----------------------------------------------------

void MainWindow::on_pushButton_clicked()

{
  int selected_id;
  c_block *block;

  selected_id = ui->editArea->get_selected_id();

  if (selected_id < 0)
    return;                   // no block selected

  block = this->graph->get_block_by_id(selected_id);

  if (block == NULL || !block->has_image() || !block->is_valid() || block->is_error())
    return;

  PreviewDialog dialog(block,this);
  dialog.exec();
}

//-----------------------------------------------------

void MainWindow::on_radio_global_seed_toggled(bool checked)

{
  c_block *block;

  if (!this->graph_mutex.tryLock())
    return;

  // mutex locked here:

  block = this->graph->get_block_by_id(ui->editArea->get_selected_id());

  if (block != NULL)
    block->use_global_seed();

  this->graph_mutex.unlock();
  this->update_graphics();
}

//-----------------------------------------------------

void MainWindow::on_radio_custom_seed_toggled(bool checked)

{
  c_block *block;

  this->graph_mutex.lock();

  // mutex locked here:

  block = this->graph->get_block_by_id(ui->editArea->get_selected_id());

  if (block != NULL)
    block->use_custom_seed(ui->custom_seed->value());

  this->graph_mutex.unlock();
  this->update_graphics();
}

//-----------------------------------------------------

void MainWindow::on_custom_seed_valueChanged(int arg1)

{
  c_block *block;

  if (ui->radio_custom_seed->isChecked())
    {
      this->graph_mutex.lock();

      block = this->graph->get_block_by_id(ui->editArea->get_selected_id());

      if (block != NULL)
        block->use_custom_seed(ui->custom_seed->value());

      this->graph_mutex.unlock();
      this->update_graphics();
    }
}

//-----------------------------------------------------

void MainWindow::on_actionDisconnect_changed()

{
  ui->editArea->set_disconnecting_mode(ui->actionDisconnect->isChecked());
}

//-----------------------------------------------------

void MainWindow::on_actionAbout_triggered()

{
  AboutDialog dialog;

  dialog.exec();
}

//-----------------------------------------------------

bool MainWindow::load(QString filename)

{
  bool success;
  unsigned int i,j,x,y;
  int id;
  string line;
  QString q_line;
  QStringList string_list;
  QString positions_filename;
  t_block_position position, *position_ptr;

  positions_filename = filename.left(filename.size() - 4) + "_positions";
  ifstream input_file(positions_filename.toStdString().c_str());

  ui->editArea->reset();
  this->set_block_for_preview(-1);
  ui->preview->set_block(NULL);
  this->graph_mutex.lock();
  this->block_positions.clear();

  if (input_file.is_open())    // load the positions from the file
    {
      getline(input_file,line);   // load the canvas size first
      q_line = QString::fromStdString(line);
      string_list = q_line.split(':');

      if (string_list.length() == 2)
        {
          ui->cwidth->setValue(string_list.at(0).toInt());
          ui->cheight->setValue(string_list.at(1).toInt());

          while (getline(input_file,line))
            {
              q_line = QString::fromStdString(line);

              string_list = q_line.split(';');

              if (string_list.length() < 4)  // invalid entry
                continue;

              position.block_id = string_list.at(0).toInt();
              position.x = string_list.at(1).toInt();
              position.y = string_list.at(2).toInt();
              position.direction = string_list.at(3).toInt();

              this->set_block_position(position);
            }
        }

      input_file.close();
    }

  ui->preview->set_block(NULL);
  this->set_block_for_preview(-10);

  this->graph->clear();

  success = this->graph->load_from_file(filename.toStdString());

  if (!success)
    {
      this->graph_mutex.unlock();
      this->block_positions.clear();
      return false;
    }

  this->graph->get_resolution(&x,&y);

  ui->width->setValue(x);
  ui->height->setValue(y);
  ui->supersampling->setValue(this->graph->get_supersampling());
  ui->seed->setValue(this->graph->get_random_seed());

  for (i = 0; i < this->graph->get_number_of_blocks(); i++)  // make up positions that don't exist
    {
      id = this->graph->get_block(i)->get_id();

      position_ptr = this->get_block_position(id);

      if (position_ptr == NULL)
        {
          position.block_id = id;
          position.x = rand() % (ui->editArea->width() - 100);
          position.y = rand() % (ui->editArea->height() - 100);
          position.direction = 0; // up

          this->set_block_position(position);
        }
    }

  this->graph_mutex.unlock();

  this->filename = filename;
  this->update_title();
  this->change_happened = false;

  return true;
}

//-----------------------------------------------------

void MainWindow::update_title()

{
  if (this->filename.length() == 0)
    this->setWindowTitle(MAIN_WINDOW_TITLE);
  else
    this->setWindowTitle(QString::fromLocal8Bit(MAIN_WINDOW_TITLE) + QString::fromLocal8Bit(" - ") + this->filename);
}

//-----------------------------------------------------

bool MainWindow::save(QString filename)

{
  bool success;
  QString positions_filename;

  success = this->graph->save_to_file(filename.toStdString());

  if (success)
    {
      positions_filename = filename.left(filename.length() - 4) + "_positions";
      this->save_positions(positions_filename);
    }

  return success;
}

//-----------------------------------------------------

void MainWindow::save_as()

{
  QFileDialog dialog;

  dialog.setAcceptMode(QFileDialog::AcceptSave);
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setDefaultSuffix("xml");
  dialog.setNameFilter(tr("xml files (*.xml)"));

  if (dialog.exec() == QDialog::Accepted)
    {
      this->filename = dialog.selectedFiles().at(0);

      if (!this->save(this->filename))
        {
          this->filename = "";

          QMessageBox message;

          message.setText("Could not save the file.");
          message.exec();
        }
      else  // set the new window title
        {
          this->update_title();
          this->change_happened = false; // reset the change watcher
        }
    }
}

//-----------------------------------------------------

void MainWindow::on_actionSave_triggered()

{
  if (this->filename.length() == 0)  // unsaved file => save as
    this->save_as();
  else
    {
      this->save(this->filename);
      this->change_happened = false; // reset the change watcher
    }
}

//-----------------------------------------------------

void MainWindow::on_actionSave_as_triggered()

{
  this->save_as();
}

//-----------------------------------------------------

void MainWindow::on_actionExit_triggered()

{
  if (this->closing_file())
    QApplication::quit();
}

//-----------------------------------------------------

void MainWindow::on_actionOpen_triggered()
{
  QFileDialog dialog;
  QString selected_file;

  dialog.setAcceptMode(QFileDialog::AcceptOpen);
  dialog.setFileMode(QFileDialog::AnyFile);
  dialog.setDefaultSuffix("xml");
  dialog.setNameFilter(tr("xml files (*.xml)"));

  if (dialog.exec() == QDialog::Accepted)
    {
      selected_file = dialog.selectedFiles().at(0);

      if (!this->closing_file())   // prompt the user
        return;

      this->load(selected_file);
      this->update_graphics();
    }
}

//-----------------------------------------------------

void MainWindow::on_pushButton_26_clicked()

{
  ui->editArea->show_parameters_dialog();
}

//-----------------------------------------------------

void MainWindow::on_actionEdit_parameters_triggered()

{
  ui->editArea->show_parameters_dialog();
}

//-----------------------------------------------------

void MainWindow::on_actionDuplicate_triggered()

{
  c_block *block,*new_block;
  c_parameters *parameters,*new_parameters;
  t_block_position *position,new_position;
  string parameter_name;
  unsigned int i;

  if (ui->editArea->get_selected_id() < 0)
    return;

  this->graph_mutex.lock();

  block = this->graph->get_block_by_id(ui->editArea->get_selected_id());
  position = this->get_block_position(ui->editArea->get_selected_id());

  if (block == NULL || position == NULL)
    {
      this->graph_mutex.unlock();
      return;
    }

  // duplicate the block:

  new_block = c_block::get_block_instance(block->get_name());
  this->graph->add_block(new_block);

  new_position.block_id = new_block->get_id();
  new_position.x = position->x < ui->editArea->width() - 150 ? position->x + 50 : position->x - 50;
  new_position.y = position->y < ui->editArea->height() - 150 ? position->y + 50 : position->y - 50;
  new_position.direction = position->direction;

  // copy parameter values:

  parameters = block->get_parameters();
  new_parameters = new_block->get_parameters();

  for (i = 0; i < parameters->number_of_parameters(); i++)
    {
      parameter_name = parameters->get_name(i);

      switch (parameters->get_type(i))
        {
          case PARAMETER_INT:
            new_parameters->set_int_value(parameter_name,parameters->get_int_value(parameter_name));
            break;

          case PARAMETER_DOUBLE:
            new_parameters->set_double_value(parameter_name,parameters->get_double_value(parameter_name));
            break;

          case PARAMETER_BOOL:
            new_parameters->set_bool_value(parameter_name,parameters->get_bool_value(parameter_name));
            break;

          case PARAMETER_STRING:
            new_parameters->set_string_value(parameter_name,parameters->get_string_value(parameter_name));
            break;
        }
    }

  this->set_block_position(new_position);

  this->graph_mutex.unlock();
  this->update_graphics();
}

//-----------------------------------------------------

void MainWindow::on_actionNew_texture_triggered()

{
  if (this->closing_file())
    {
      this->graph_mutex.lock();
      this->graph->clear();
      this->block_positions.clear();
      this->graph_mutex.unlock();
      ui->cwidth->setValue(800);
      ui->cheight->setValue(600);
      this->update_graphics();
      this->set_block_for_preview(-1);
      ui->editArea->reset();
      this->change_happened = false;
    }
}

//-----------------------------------------------------

void MainWindow::on_actionDefault_parameters_dialog_triggered()

{
  c_block *block;

  block = this->graph->get_block_by_id(ui->editArea->get_selected_id());

  if (block == NULL)
    return;

  DefaultBlockDialog dialog(block,this);
  dialog.exec();
}

//-----------------------------------------------------

void MainWindow::on_actionInvalidate_block_triggered()

{
  c_block *block;

  block = this->graph->get_block_by_id(ui->editArea->get_selected_id());

  if (block == NULL)
    return;

  block->invalidate();

  this->update_graphics();
}

//-----------------------------------------------------
