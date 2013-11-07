#ifndef TEXTUREDESIGNVIEW_H
#define TEXTUREDESIGNVIEW_H

#include <QObject>
#include <QtWidgets>
#include <QGraphicsView>

class textureDesignView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit textureDesignView(QWidget *parent = 0);

signals:

public slots:

};

#endif // TEXTUREDESIGNVIEW_H
