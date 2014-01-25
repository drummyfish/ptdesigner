#include "editareaframe.h"
#include "defaultblockdialog.h"

//-----------------------------------------------------

EditAreaFrame::EditAreaFrame(QWidget *parent) :
    QFrame(parent)
{
   this->setAcceptDrops(true);
   this->selected_id = -1;
   this->moving = false;
   this->connecting_id = -1;
   this->mouse_coordinations[0] = 0;
   this->mouse_coordinations[1] = 0;
   this->display_mouse_string = false;
   this->setMouseTracking(true);
   this->setFocusPolicy(Qt::StrongFocus);  // to accept key events
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
      QPainter painter(this);
      painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
      return;
    }

  // mutex locked here:

  QPainter painter(this);
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

          if (block_distance < 50)   // limits
            block_distance = 50;
          else if (block_distance > 150)
            block_distance = 150;

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
          pen.setStyle(Qt::DashLine);

          painter.setPen(pen);
          painter.drawRect(position->x - 11,position->y - 9,75,75);
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
  c_block *block;
  int slot,block_id;

  block_id = this->main_window->get_block_by_position(event->pos().x(),event->pos().y(),&slot);

  if (block_id < 0)
    return;

  block = this->main_window->get_texture_graph()->get_block_by_id(block_id);

  if (block == NULL)
    return;

  {
    DefaultBlockDialog dialog(block);
    dialog.exec();
  }

  this->moving = false;      // so that double click doesn't trigger block move
  this->connecting_id = -1;
  this->main_window->update_graphics();
}

//-----------------------------------------------------

void EditAreaFrame::mousePressEvent(QMouseEvent *event)

{
  int x, y;
  int slot;

  if (!this->main_window->get_graph_mutex()->tryLock())
    return;

  // mutex locked here:

  x = event->pos().x();
  y = event->pos().y();

  this->selected_id = this->main_window->get_block_by_position(x,y,&slot);

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

  this->update();
}

//-----------------------------------------------------

void EditAreaFrame::keyPressEvent(QKeyEvent *event)

{
  if (this->selected_id < 0)
    return;

  if (event->key() == Qt::Key_Delete)
    this->main_window->delete_block_by_id(this->selected_id);

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
          this->mouse_string = "slot " + QString::number(slot);

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
