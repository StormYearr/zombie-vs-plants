#ifndef CACTUS_H
#define CACTUS_H
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
class Cactus:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static double speed;
    int Randomgeneration(int min,int max);
    void Camovement();
    Cactus();
private:
    QTimer* cactus_mov;
};

#endif // CACTUS_H
