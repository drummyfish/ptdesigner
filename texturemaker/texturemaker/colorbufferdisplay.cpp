#include "colorbufferdisplay.h"

//-----------------------------------------------------

ColorBufferDisplay::ColorBufferDisplay(QWidget *parent):
    QFrame(parent)
{
  this->block = NULL;
}

//-----------------------------------------------------

void ColorBufferDisplay::set_block(c_block *block)

{
  this->block = block;
}

//----------------------------------------------------

void ColorBufferDisplay::set_main_window(MainWindow *main_window)
{
  this->main_window = main_window;
}

//-----------------------------------------------------

void ColorBufferDisplay::paintEvent(QPaintEvent *)

{
  QPainter painter(this);
  QPen pen;
  t_color_buffer buffer;   // help buffer for resizing the image
  unsigned int i,j;
  unsigned char r,g,b;

  if (!this->main_window->get_graph_mutex()->tryLock())
    {
      QPixmap hourglass(":/resources/hourglass3.png");

      painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
      painter.drawRect(0,0,this->width() - 1,this->height() - 1);
      painter.drawPixmap(this->width() / 2 - 30,this->height() / 2 - 30,hourglass);

      return;
    }

  // mutex locked here

  if (this->block == NULL || !this->block->has_image() || this->block->is_error())
    {
      painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
      painter.drawRect(0,0,this->width() - 1,this->height() - 1);
      this->main_window->get_graph_mutex()->unlock();
      return;
    }

  if (!color_buffer_init(&buffer,this->width(),this->height()))
    {
      this->main_window->get_graph_mutex()->unlock();
      return;
    }

  pt_resize(((c_graphic_block *) this->block)->get_color_buffer(),&buffer,INTERPOLATION_LINEAR);

  for (j = 0; j < buffer.height; j++)  // draw the buffer
    for (i = 0; i < buffer.width; i++)
      {
        color_buffer_get_pixel(&buffer,i,j,&r,&g,&b);
        pen.setColor(QColor::fromRgb(r,g,b));
        painter.setPen(pen);
        painter.drawPoint(i,j);
      }

  pen.setColor(QColor::fromRgb(0,0,0));
  painter.setPen(pen);
  painter.drawRect(0,0,this->width() - 1,this->height() - 1);

  color_buffer_destroy(&buffer);

  this->main_window->get_graph_mutex()->unlock();
}

//-----------------------------------------------------
