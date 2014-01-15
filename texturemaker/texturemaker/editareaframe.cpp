#include "editareaframe.h"

editAreaFrame::editAreaFrame(QWidget *parent) :
    QFrame(parent)
{
   this->setAcceptDrops(true);
}

void editAreaFrame::paintEvent(QPaintEvent *)
 {
   QPainter painter(this);
   painter.fillRect(0,0,this->width(),this->height(),QColor::fromRgb(255,255,255));
 }

void editAreaFrame::dropEvent(QDropEvent *event)
{
    string helpstr = event->mimeData()->text().toUtf8().constData();;

    cout << "haha" << helpstr << endl;

    event->acceptProposedAction();
}

void  editAreaFrame::dragEnterEvent(QDragEnterEvent *event)

{
    if (event->mimeData()->hasFormat("text/plain"))
      event->acceptProposedAction();
}
