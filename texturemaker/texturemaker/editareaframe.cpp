/*
 * Copyright 2013 Miloslav Číž
 *
 * This file is part of PT Designer.
 *
 * PT Designer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PT Designer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with these files. If not, see <http://www.gnu.org/licenses/>.
 */

#include "editareaframe.h"
#include "defaultblockdialog.h"
#include "colorfilldialog.h"
#include "lightdialog.h"
#include "voronoidialog.h"
#include "perlindialog.h"
#include "convolutiondialog.h"
#include "mixdialog.h"
#include "saveloaddialog.h"
#include "lsystemdialog.h"
#include "colortransitiondialog.h"
#include "blurdialog.h"
#include "colorreplacedialog.h"
#include "mosaicdialog.h"
#include "edgedetectiondialog.h"
#include "ditherdialog.h"
#include "cellulargeneraldialog.h"
#include "cellulardialog.h"
#include "substratedialog.h"
#include "woodmarbledialog.h"

//-----------------------------------------------------

EditAreaFrame::EditAreaFrame(QWidget *parent) :
    QFrame(parent)

{
   this->setAcceptDrops(true);
   this->disconnecting_mode = false;
   this->selected_id = -1;
   this->moving = false;
   this->connecting_id = -1;
   this->mouse_coordinations[0] = 0;
   this->mouse_coordinations[1] = 0;
   this->display_mouse_string = false;
   this->setMouseTracking(true);
   this->setFocusPolicy(Qt::StrongFocus);  // to accept key events

   this->pixel_buffer = new QPixmap(this->width(),this->height());
}

//-----------------------------------------------------

EditAreaFrame::~EditAreaFrame()

{
  delete this->pixel_buffer;
}

//-----------------------------------------------------

void EditAreaFrame::set_disconnecting_mode(bool value)

{
  this->disconnecting_mode = value;
}

//-----------------------------------------------------

void EditAreaFrame::set_main_window(MainWindow *main_window)

{
  this->main_window = main_window;
}

//-----------------------------------------------------

void EditAreaFrame::paintEvent(QPaintEvent *)

{
  unsigned int i,j;
  int draw_from[2],draw_through1[2],draw_through2[2],draw_to[2];  // helper coordinations
  int helper,block_distance,dx,dy;
  c_block *block,*block2;
  c_texture_graph *graph;
  QPen pen;
  QFont font;
  QPainterPath path;
  QString filename;
  QPixmap pixmap;
  QPixmap pixmap_block;
  QPixmap pixmap_shadow;
  QPixmap pixmap_slot[4];                     // all four directions
  int output_position[2],input_position[2];   // position differences for drawing slots
  t_block_position *position,*position2;

  if (!this->main_window->get_graph_mutex()->tryLock())
    {
      // the texture graph isn't available, draw the previous frame

      QPainter painter(this);
      painter.drawPixmap(0,0,this->width(),this->height(),*(this->pixel_buffer));
      return;
    }

  // mutex locked here:

  // resize the canvas if needed:

  if (this->width() != this->pixel_buffer->width() || this->height() != this->pixel_buffer->height())
    {
      delete this->pixel_buffer;
      this->pixel_buffer = new QPixmap(this->width(),this->height());
    }

  QPainter painter(this->pixel_buffer);

  painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));

  graph = this->main_window->get_texture_graph();

  pixmap_block.load(":/resources/block.png");
  pixmap_shadow.load(":/resources/shadow.png");

  pixmap_slot[0].load(":/resources/slot up.png");
  pixmap_slot[1].load(":/resources/slot right.png");
  pixmap_slot[2].load(":/resources/slot down.png");
  pixmap_slot[3].load(":/resources/slot left.png");

  painter.setRenderHints(QPainter::Antialiasing,true);

  for (i = 0; i < graph->get_number_of_blocks(); i++)      // draw connections
    {
      block = graph->get_block(i);
      position = this->main_window->get_block_position(block->get_id());

      for (j = 0; j < MAX_INPUT_BLOCKS; j++)
        {
          block2 = block->get_input(j);

          if (block2 == NULL)
            continue;

          position2 = this->main_window->get_block_position(block2->get_id());

          pen.setWidth(3);
          painter.setPen(pen);

          draw_through1[0] = 0;  // so that the compiler doesn't complain
          draw_through1[1] = 0;
          draw_through2[0] = 0;
          draw_through2[1] = 0;
          draw_to[0] = 0;
          draw_to[1] = 0;

          dx = position->x - position2->x;
          dy = position->y - position2->y;

          if (dx < 0)
            dx *= -1;

          if (dy < 0)
            dy *= -1;

          block_distance = (int) sqrt(dx * dx + dy * dy);  // determines how curved the connection will be

          block_distance -= 50;

          if (block_distance < 20)   // limits
            block_distance = 20;
          else if (block_distance > 200)
            block_distance = 200;

          switch(position2->direction)   // coming from output
            {
              case 0:  // up
                draw_from[0] = position2->x + 26;
                draw_from[1] = position2->y + 5;
                draw_through1[0] = draw_from[0];
                draw_through1[1] = draw_from[1] - block_distance;
                break;

              case 1:  // right
                draw_from[0] = position2->x + 56;
                draw_from[1] = position2->y + 29;
                draw_through1[0] = draw_from[0] + block_distance;
                draw_through1[1] = draw_from[1];
                break;

              case 2:  // down
                draw_from[0] = position2->x + 26;
                draw_from[1] = position2->y + 56;
                draw_through1[0] = draw_from[0];
                draw_through1[1] = draw_from[1] + block_distance;
                break;

              case 3:  // left
                draw_from[0] = position2->x - 9;
                draw_from[1] = position2->y + 29;
                draw_through1[0] = draw_from[0] - block_distance;
                draw_through1[1] = draw_from[1];
                break;

              default:
                break;
            }

          switch(position->direction)  // coming to input slot
            {
              case 0:  // up
                draw_to[0] = position->x + 10 + j * 8;
                draw_to[1] = position->y + 58;
                draw_through2[0] = draw_to[0];
                draw_through2[1] = draw_to[1] + block_distance;
                break;

              case 1:  // right
                draw_to[0] = position->x - 9;
                draw_to[1] = position->y + 11 + j * 9;
                draw_through2[0] = draw_to[0] - block_distance;
                draw_through2[1] = draw_to[1];
                break;

              case 2:  // down
                draw_to[0] = position->x + 10 + (MAX_INPUT_BLOCKS - j - 1) * 8;
                draw_to[1] = position->y + 3;
                draw_through2[0] = draw_to[0];
                draw_through2[1] = draw_to[1] - block_distance;
                break;

              case 3:  // left
                draw_to[0] = position->x + 59;
                draw_to[1] = position->y + 11 + (MAX_INPUT_BLOCKS - j - 1) * 9;
                draw_through2[0] = draw_to[0] + block_distance;
                draw_through2[1] = draw_to[1];
                break;

              default:
                break;
            }

          path.moveTo(draw_from[0],draw_from[1]);
          path.cubicTo(draw_through1[0],draw_through1[1],draw_through2[0],draw_through2[1],draw_to[0],draw_to[1]);

          painter.drawPath(path);
        }
    }

  if (this->connecting_id >= 0)    // draw the line if connecting
    {
      pen.setWidth(3);
      painter.setPen(pen);

      position = this->main_window->get_block_position(this->connecting_id);

      switch (position->direction)
        {
          case 0: // up
            dx = 26;
            dy = 5;
            break;

          case 1: // right
            dx = 56;
            dy = 29;
            break;

          case 2: // down
            dx = 26;
            dy = 56;
            break;

          case 3: // left
            dx = -9;
            dy = 29;
            break;

          default:
            dx = 0;
            dy = 0;
            break;
        }

      painter.drawLine(position->x + dx,position->y + dy,this->mouse_coordinations[0],this->mouse_coordinations[1]);
    }

  for (i = 0; i < graph->get_number_of_blocks(); i++)      // draw blocks
    {
      block = graph->get_block(i);
      filename = QString::fromStdString(":/resources/button " + block->get_name() + ".png");
      pixmap.load(filename);

      position = this->main_window->get_block_position(block->get_id());

      if (position == NULL)
        continue;

      if (((int) block->get_id()) == this->selected_id)                        // draw selection
        {
          pen.setColor(Qt::black);
          pen.setWidth(0);
          pen.setDashOffset(2);
          pen.setStyle(Qt::DashLine);

          painter.setRenderHints(QPainter::Antialiasing,false);
          painter.setPen(pen);
          painter.drawRect(position->x - 11,position->y - 9,75,75);
          painter.setRenderHints(QPainter::Antialiasing,true);
        }

      painter.drawPixmap(position->x,position->y,pixmap);                      // draw the block
      painter.drawPixmap(position->x - 2,position->y - 1,pixmap_block);

      switch (position->direction)
        {
          case 0:  // up
            output_position[0] = 22;
            output_position[1] = -5;
            input_position[0] = 6;
            input_position[1] = 56;
            break;

          case 1:  // right
            output_position[0] = 56;
            output_position[1] = 25;
            input_position[0] = -9;
            input_position[1] = 7;
            break;

          case 2:  // down
            output_position[0] = 22;
            output_position[1] = 56;
            input_position[0] = 6;
            input_position[1] = -5;
            break;

          case 3:  // left
            output_position[0] = -9;
            output_position[1] = 25;
            input_position[0] = 56;
            input_position[1] = 7;
            break;

          default:
            output_position[0] = 0;
            output_position[1] = 0;
            input_position[0] = 10;
            input_position[1] = 56;
            break;
        }

      // draw the output:

      if (!block->is_terminal())
        painter.drawPixmap(position->x + output_position[0],position->y + output_position[1],pixmap_slot[position->direction]);

      // draw input slots:

      for (j = 0; j < block->get_max_inputs(); j++)
        if (position->direction == 0 || position->direction == 2) // up or down
          {
            if (position->direction == 2)
              helper = MAX_INPUT_BLOCKS - j - 1;  // draw slots on top in reversed order due to rotation
            else
              helper = j;

            painter.drawPixmap(position->x + input_position[0] + 8 * helper,position->y + input_position[1],pixmap_slot[(position->direction + 2) % 4]);
          }
        else   // left or right
          {
            if (position->direction == 3)
              helper = MAX_INPUT_BLOCKS - j - 1;  // draw slots in the right in reversed order due to rotation
            else
              helper = j;

            painter.drawPixmap(position->x + input_position[0],position->y + input_position[1] + 9 * helper,pixmap_slot[(position->direction + 2) % 4]);
          }

      // draw the status text:

      if (block->is_valid())
        {
          font.setPixelSize(10);
          pen.setColor(qRgb(20,200,0));
          painter.setPen(pen);
          painter.setFont(font);
          painter.drawText(position->x + 55,position->y - 3,"ok");
        }
      else if (block->is_error())
        {
          font.setPixelSize(10);
          pen.setColor(qRgb(200,20,0));
          painter.setPen(pen);
          painter.setFont(font);
          painter.drawText(position->x + 55,position->y - 3,"error");
        }
    }

  if (this->display_mouse_string)  // draw the mouse string
    {
      font.setPixelSize(10);
      pen.setColor(qRgb(50,50,50));
      painter.setPen(pen);
      painter.drawText(this->mouse_coordinations[0] + 15,this->mouse_coordinations[1] + 15,this->mouse_string);
    }

  this->main_window->get_graph_mutex()->unlock();

  painter.end();

  // now put the drawn bitmap on the widget:

  QPainter painter2(this);
  painter2.fillRect(0,0,50,50,QColor::fromRgb(255,255,255));
  painter2.drawPixmap(0,0,this->width(),this->height(),*(this->pixel_buffer));
}

//-----------------------------------------------------

void EditAreaFrame::reset()

{
  this->selected_id = -1;
  this->update();
}

//-----------------------------------------------------

bool EditAreaFrame::connecting_in_progress()

{
  return this->connecting_id >= 0;
}

//-----------------------------------------------------

void EditAreaFrame::dropEvent(QDropEvent *event)

{
  string mime_string = event->mimeData()->text().toUtf8().constData();
  c_block *block;
  t_block_position position;

  if (!this->main_window->get_graph_mutex()->tryLock())
    return;

  // mutex locked here:

  block = c_block::get_block_instance(mime_string);

  if (block == NULL)
    return;

  this->main_window->get_texture_graph()->add_block(block);
  position.block_id = block->get_id();
  position.x = event->pos().x();
  position.y = event->pos().y();
  position.direction = 0;
  this->main_window->set_block_position(position);

  this->main_window->get_graph_mutex()->unlock();

  this->main_window->change_occured(); // inform the main window about the change

  this->update();    // repaint

  event->acceptProposedAction();
}

//-----------------------------------------------------

void EditAreaFrame::dragEnterEvent(QDragEnterEvent *event)

{
  if (event->mimeData()->hasFormat("text/plain"))
    event->acceptProposedAction();
}

//-----------------------------------------------------

void EditAreaFrame::mouseDoubleClickEvent(QMouseEvent *event)

{
  int slot;

  this->selected_id = this->main_window->get_block_by_position(event->pos().x(),event->pos().y(),&slot);
  this->moving = false;
  this->connecting_id = -1;
  this->show_parameters_dialog();
}

//-----------------------------------------------------

void EditAreaFrame::show_parameters_dialog()

{
  c_block *block;
  int block_id;
  QDialog *help_dialog;

  if (this->selected_id < 0) // no block selected
    return;

  this->main_window->get_graph_mutex()->lock();

  block = this->main_window->get_texture_graph()->get_block_by_id(this->selected_id);

  if (block == NULL)
    {
      this->main_window->get_graph_mutex()->unlock();
      return;
    }

  // choose the right dialog:

  if (block->get_name().compare(COLOR_FILL_NAME) == 0)
      help_dialog = new ColorFillDialog(block,this);
    else if (block->get_name().compare(LIGHT_NAME) == 0)
      help_dialog = new LightDialog(block,this);
    else if (block->get_name().compare(PERLIN_NOISE_NAME) == 0)
      help_dialog = new PerlinDialog(block,this);
    else if (block->get_name().compare(VORONOI_DIAGRAM_NAME) == 0)
      help_dialog = new VoronoiDialog(block,this);
    else if (block->get_name().compare(CONVOLUTION_NAME) == 0)
      help_dialog = new ConvolutionDialog(block,this);
    else if (block->get_name().compare(MIX_NAME) == 0)
      help_dialog = new MixDialog(block,this);
    else if (block->get_name().compare(L_SYSTEM_NAME) == 0)
      help_dialog = new LSystemDialog(block,this);
    else if (block->get_name().compare(COLOR_TRANSITION_NAME) == 0)
      help_dialog = new ColorTransitionDialog(block,this);
    else if (block->get_name().compare(BLUR_NAME) == 0)
      help_dialog = new BlurDialog(block,this);
    else if (block->get_name().compare(REPLACE_COLORS_NAME) == 0)
      help_dialog = new ColorReplaceDialog(block,this);
    else if (block->get_name().compare(FILE_SAVE_NAME) == 0 ||
             block->get_name().compare(FILE_LOAD_NAME) == 0)
      help_dialog = new SaveLoadDialog(block,this);
    else if (block->get_name().compare(CELLULAR_CYCLIC_NAME) == 0 ||
             block->get_name().compare(CELLULAR_RPS_NAME) == 0)
      help_dialog = new CellularDialog(block,this);
    else if (block->get_name().compare(MARBLE_NAME) == 0 ||
           block->get_name().compare(WOOD_NAME) == 0)
      help_dialog = new WoodMarbleDialog(block,this);
    else if (block->get_name().compare(SQUARE_MOSAIC_NAME) == 0)
      help_dialog = new MosaicDialog(block,this);
    else if (block->get_name().compare(EDGE_DETECTION_NAME) == 0)
      help_dialog = new EdgeDetectionDialog(block,this);
    else if (block->get_name().compare(DITHER_NAME) == 0)
      help_dialog = new DitherDialog(block,this);
    else if (block->get_name().compare(CELLULAR_GENERAL_NAME) == 0)
      help_dialog = new CellularGeneralDialog(block,this);
    else if (block->get_name().compare(SUBSTRATE_NAME) == 0)
      help_dialog = new SubstrateDialog(block,this);
    else   // default dialog
      help_dialog = new DefaultBlockDialog(block);

    if (help_dialog->exec() == QDialog::Accepted)
      this->main_window->change_occured();           // changes were made => inform the main window

    delete help_dialog;

    this->main_window->get_graph_mutex()->unlock();
    this->main_window->update_graphics();
}

//-----------------------------------------------------

void EditAreaFrame::mousePressEvent(QMouseEvent *event)

{
  int x, y;
  int slot;
  c_block *block;

  if (!this->main_window->get_graph_mutex()->tryLock())
    return;

  // mutex locked here:

  x = event->pos().x();
  y = event->pos().y();

  this->selected_id = this->main_window->get_block_by_position(x,y,&slot);

  if (this->disconnecting_mode || event->button() == Qt::RightButton)
    {
      if (this->selected_id >= 0 && slot < MAX_INPUT_BLOCKS && slot >= 0)
        {
          block = this->main_window->get_texture_graph()->get_block_by_id(this->selected_id);
          block->disconnect(slot);
        }

      this->main_window->get_graph_mutex()->unlock();
      this->update();
      return;
    }

  this->main_window->set_block_for_preview(this->selected_id);

  if (this->selected_id >= 0)  // a block was clicked
    {
      if (slot < 0)            // no slot clicked => moving the block
        this->moving = true;
      else if (this->connecting_id < 0 && slot == MAX_INPUT_BLOCKS)  // starting connecting blocks
        this->connecting_id = this->selected_id;
      else if (this->connecting_id >= 0 && slot < MAX_INPUT_BLOCKS && slot >= 0) // connection in progres
        {
          this->main_window->get_texture_graph()->connect_by_id(this->connecting_id,this->selected_id,slot);
          this->connecting_id = -1;
        }
    }
  else
    this->connecting_id = -1;

  this->main_window->get_graph_mutex()->unlock();

  this->main_window->change_occured();

  this->update();

  this->main_window->block_selected(this->selected_id);
}

//-----------------------------------------------------

void EditAreaFrame::keyPressEvent(QKeyEvent *event)

{
  if (this->selected_id < 0)
    return;

  if (event->key() == Qt::Key_Delete)
    {
      if (this->connecting_in_progress())
        return;

      this->main_window->delete_block_by_id(this->selected_id);
    }

  this->update();
  this->selected_id = -1;
}

//-----------------------------------------------------

void EditAreaFrame::mouseReleaseEvent(QMouseEvent *event)

{
  this->moving = false;
}

//-----------------------------------------------------

void EditAreaFrame::mouseMoveEvent(QMouseEvent *event)

{
  int slot,id;
  c_block *block;

  if (!this->main_window->get_graph_mutex()->tryLock())
    return;

  // mutex locked here:

  if (this->connecting_id >= 0)
    {
      this->mouse_coordinations[0] = event->pos().x();
      this->mouse_coordinations[1] = event->pos().y();
      this->update();
    }
  else if (this->moving)
    {
      t_block_position *position;

      this->display_mouse_string = false;

      position = this->main_window->get_block_position(this->selected_id);

      if (position == NULL)
        {
          this->main_window->get_graph_mutex()->unlock();
          return;
        }

      position->x = event->pos().x() - 25;
      position->y = event->pos().y() - 25;

      if (position->x < 0)
        position->x = 0;
      else if (position->x >= this->width() - 25)
        position->x = this->width() - 25;

      if (position->y < 0)
        position->y = 0;
      else if (position->y >= this->height() - 25)
        position->y = this->height() - 25;

      this->update();
    }

    id = this->main_window->get_block_by_position(event->pos().x(),event->pos().y(),&slot);

    if (id >= 0 && slot >= 0)
      {
        this->mouse_coordinations[0] = event->pos().x();  // update the mouse coordinations
        this->mouse_coordinations[1] = event->pos().y();

        this->display_mouse_string = true;

        if (slot == MAX_INPUT_BLOCKS)
          this->mouse_string = "output";
        else
          {
            this->mouse_string = "slot " + QString::number(slot);

            block = this->main_window->get_texture_graph()->get_block_by_id(id);

            if (block != NULL)
              {
                if (slot >= block->get_min_inputs())
                  this->mouse_string += " (optional)";
              }
          }

        this->update();
      }
    else if (this->display_mouse_string)
      {
        this->display_mouse_string = false;
        this->update();
      }

   this->main_window->get_graph_mutex()->unlock();
}

//-----------------------------------------------------

int EditAreaFrame::get_selected_id()

{
  return this->selected_id;
}

//-----------------------------------------------------
