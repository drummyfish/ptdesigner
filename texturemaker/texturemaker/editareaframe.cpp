#include "editareaframe.h"

editAreaFrame::editAreaFrame(QWidget *parent) :
    QFrame(parent)
{
}

void editAreaFrame::paintEvent(QPaintEvent *)
 {
     QPainter painter(this);
     painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
 }
