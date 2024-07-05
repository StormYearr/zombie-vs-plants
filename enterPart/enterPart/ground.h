#ifndef GROUND_H
#define GROUND_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class ground:public QObject,public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    ground();
};

#endif // GROUND_H
