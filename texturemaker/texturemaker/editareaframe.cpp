#include "editareaframe.h"

//-----------------------------------------------------

editAreaFrame::editAreaFrame(QWidget *parent) :
    QFrame(parent)
{
   this->setAcceptDrops(true);
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

      painter.drawPixmap(position->x,position->y,pixmap);
    }
}

//-----------------------------------------------------

void editAreaFrame::dropEvent(QDropEvent *event)
{
  string helpstr = event->mimeData()->text().toUtf8().constData();;
  event->acceptProposedAction();
}

//-----------------------------------------------------

void  editAreaFrame::dragEnterEvent(QDragEnterEvent *event)

{
  if (event->mimeData()->hasFormat("text/plain"))
    event->acceptProposedAction();
}

//-----------------------------------------------------
