#include "colorbufferdisplay.h"

//-----------------------------------------------------

colorBufferDisplay::colorBufferDisplay(QWidget *parent):
    QFrame(parent)
{
  this->block = NULL;
}

//-----------------------------------------------------

void colorBufferDisplay::set_block(c_block *block)

{
  this->block = block;
}

//-----------------------------------------------------

void colorBufferDisplay::paintEvent(QPaintEvent *)

{
  QPainter painter(this);
  QPen pen;
  t_color_buffer buffer;   // help buffer for resizing the image
  unsigned int i,j;
  unsigned char r,g,b;

  if (this->block == NULL || !this->block->has_image() || this->block->is_error())
    {
      painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
      painter.drawRect(0,0,this->width() - 1,this->height() - 1);
      return;
    }

  if (!color_buffer_init(&buffer,this->width(),this->height()))
    return;

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
}

//-----------------------------------------------------
