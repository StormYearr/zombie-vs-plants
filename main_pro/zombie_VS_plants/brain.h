#ifndef BRAIN_H
#define BRAIN_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QRectF>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>

class brain : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    brain();

    void setBrainSize(const QSize &size);

private slots:
    void showRandomPosition();
    void hideBrain();
   // void mousePressEvent(QGraphicsSceneMouseEvent *event);
  //  void increaseScore();

private:
    QGraphicsPixmapItem *brainPixmapItem;
    QTimer *timerShow;
    QTimer *timerHide;
    QSize brainSize;
    int score;
    QGraphicsTextItem *scoreText;
};

#endif // BRAIN_H
