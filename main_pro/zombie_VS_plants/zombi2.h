#ifndef ZOMBI2_H
#define ZOMBI2_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

class Cloud:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    static int count;
    Cloud(QGraphicsItem* parent=nullptr);
   // int Randomgeneration(int min,int max);
    ~Cloud();
   // void Cmovement();
   // void set_Speed(int s){
  //      speed=s;
  //  }
private:
//    int speed;
//    QTimer* cloud_mov;
};

#endif // ZOMBI2_H
