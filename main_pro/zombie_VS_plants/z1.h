#ifndef Z1_H
#define Z1_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QRectF>

class z1 : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    z1();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    int getScore() const { return score; }
       void increaseScore(int amount);
    void moveItem();
private:
    int score = 101; // Score variable
    QPointF offset; // Offset for mouse move
    bool initialMoveStarted=false;
    bool canMove=true;
};
#endif // Z1_H


