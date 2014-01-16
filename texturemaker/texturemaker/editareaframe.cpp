#include "editareaframe.h"

//-----------------------------------------------------

editAreaFrame::editAreaFrame(QWidget *parent) :
    QFrame(parent)
{
   this->setAcceptDrops(true);
   this->selected_id = -1;
   this->moving = false;
   this->setFocusPolicy(Qt::StrongFocus);  // to accept key events
}

//-----------------------------------------------------

void editAreaFrame::set_main_window(MainWindow *main_window)

{
  this->main_window = main_window;
}

//-----------------------------------------------------

void editAreaFrame::paintEvent(QPaintEvent *)
{
  unsigned int i;
  c_block *block;
  c_texture_graph *graph;
  QString filename;
  QPixmap pixmap;
  t_block_position *position;

  QPainter painter(this);
  painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));

  graph = this->main_window->get_texture_graph();

  for (i = 0; i < graph->get_number_of_blocks(); i++)
    {
      block = graph->get_block(i);
      filename = QString::fromStdString(":/resources/button " + block->get_name() + ".png");
      pixmap.load(filename);

      position = this->main_window->get_block_position(block->get_id());

      if (position == NULL)
        continue;

      if (((int) block->get_id()) == this->selected_id)  // selection
        {
          QPen pen;

          pen.setColor(Qt::black);
          pen.setStyle(Qt::DashLine);

          painter.setPen(pen);
          painter.drawRect(position->x - 10,position->y - 10,70,70);
        }

      painter.drawPixmap(position->x,position->y,pixmap);
    }
}

//-----------------------------------------------------

void editAreaFrame::dropEvent(QDropEvent *event)
{
  string mime_string = event->mimeData()->text().toUtf8().constData();
  c_block *block;
  t_block_position position;

  block = c_block::get_block_instance(mime_string);

  if (block == NULL)
    return;

  this->main_window->get_texture_graph()->add_block(block);
  position.block_id = block->get_id();
  position.x = event->pos().x();
  position.y = event->pos().y();
  this->main_window->set_block_position(position);

  this->update();    // repaint

  event->acceptProposedAction();
}

//-----------------------------------------------------

void editAreaFrame::dragEnterEvent(QDragEnterEvent *event)

{
  if (event->mimeData()->hasFormat("text/plain"))
    event->acceptProposedAction();
}

//-----------------------------------------------------

void editAreaFrame::mousePressEvent(QMouseEvent *event)

{
  int x, y;

  x = event->pos().x();
  y = event->pos().y();

  this->selected_id = this->main_window->get_block_by_position(x,y);

  if (this->selected_id >= 0)
    this->moving = true;

  this->update();
}

//-----------------------------------------------------

void editAreaFrame::keyPressEvent(QKeyEvent *event)

{
  if (this->selected_id < 0)
    return;

  if (event->key() == Qt::Key_Delete)
    this->main_window->delete_block_by_id(this->selected_id);

  this->update();
  this->selected_id = -1;
}

//-----------------------------------------------------

void editAreaFrame::mouseReleaseEvent(QMouseEvent *event)

{
  this->moving = false;
}

//-----------------------------------------------------

void editAreaFrame::mouseMoveEvent(QMouseEvent *event)

{
  if (this->moving)
    {
      t_block_position *position;

      position = this->main_window->get_block_position(this->selected_id);

      if (position == NULL)
        return;

      position->x = event->pos().x() - 25;
      position->y = event->pos().y() - 25;

      this->update();
    }
}

//-----------------------------------------------------

int editAreaFrame::get_selected_id()

{
  return this->selected_id;
}

//-----------------------------------------------------
