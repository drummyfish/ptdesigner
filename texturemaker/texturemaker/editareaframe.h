#ifndef EDITAREAFRAME_H
#define EDITAREAFRAME_H

#include <QFrame>
#include <QPainter>
#include <QMouseEvent>
#include <iostream>

using namespace std;

class editAreaFrame : public QFrame
{
    Q_OBJECT
public:
    explicit editAreaFrame(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);

signals:
    
public slots:
    
};

#endif // EDITAREAFRAME_H
