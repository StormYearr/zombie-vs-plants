#ifndef GROUND_H
#define GROUND_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Ground:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Ground();

private:

};

#endif // GROUND_H
