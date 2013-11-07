#ifndef EDITAREAFRAME_H
#define EDITAREAFRAME_H

#include <QFrame>
#include <QPainter>

class editAreaFrame : public QFrame
{
    Q_OBJECT
public:
    explicit editAreaFrame(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

signals:
    
public slots:
    
};

#endif // EDITAREAFRAME_H
