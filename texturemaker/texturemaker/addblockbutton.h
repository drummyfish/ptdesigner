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

#endif // ADDBLOCKBUTTON_H
