#ifndef ADDBLOCKBUTTON_H
#define ADDBLOCKBUTTON_H

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QMouseEvent>

using namespace std;

//-----------------------------------------------------

/**
  Button that represents a block and can be dragged over
  to the edit area to add that block to the graph. Cannot
  be clicked.
  */

class addBlockButton : public QPushButton
{
    Q_OBJECT
public:
    explicit addBlockButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

//-----------------------------------------------------

#endif // ADDBLOCKBUTTON_H
