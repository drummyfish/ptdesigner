#include "addblockbutton.h"

addBlockButton::addBlockButton(QWidget *parent) :
    QPushButton(parent)
 {
 }

void addBlockButton::paintEvent(QPaintEvent *)
 {
   QPainter painter(this);
   QPixmap pixmap(":/resources/button " + this->text() + ".png");
   this->resize(53,53);
   this->setToolTip(this->text());
   painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(0,0,0));
   painter.drawPixmap(1,1,51,51,pixmap);
 }

void addBlockButton::mousePressEvent(QMouseEvent *event)
 {
   if (event->button() == Qt::LeftButton)
     {
       QDrag *drag = new QDrag(this);
       QMimeData *mimeData = new QMimeData;

       mimeData->setText(this->text());
       drag->setMimeData(mimeData);

       Qt::DropAction dropAction = drag->exec();
     }
 }
