#ifndef ADDBLOCKBUTTON_H
#define ADDBLOCKBUTTON_H

#include <iostream>
#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QIcon>

using namespace std;

class addBlockButton : public QPushButton
{
    Q_OBJECT
public:
    explicit addBlockButton(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // ADDBLOCKBUTTON_H
