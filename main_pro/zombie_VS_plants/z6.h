#ifndef Z6_H
#define Z6_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QRectF>

class z6 : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    z6();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    int getScore() const { return score; }
    void increaseScore(int amount);
    void moveItem();
private:
    int score = 0; // Score variable
    QPointF offset; // Offset for mouse move
    bool initialMoveStarted=false;
    bool canMove=true;
};
#endif // Z6_H
