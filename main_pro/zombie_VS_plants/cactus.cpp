#include "cactus.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRandomGenerator>
#include <QTimer>
double Cactus::speed=3;

int Cactus:: Randomgeneration (int min,int max){

    return QRandomGenerator::global()->bounded(min,max+1);
}
Cactus::Cactus()
{
    qDebug()<<"New cactus created!!!\n";

    QPixmap imagCa (":/game/br");
    QPixmap scaled_imagCa = imagCa.scaled(50,150,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(scaled_imagCa);

    this->setPos(800,450);

    cactus_mov = new QTimer();

    connect(cactus_mov,&QTimer::timeout,this,&Cactus::Camovement);
    cactus_mov->start(10);
}
void Cactus::Camovement(){
    QPointF cactusPos = this->pos();
    if(cactusPos.x()<-80){
        qDebug()<<"cactus Deleted!!!\n";
        scene()->removeItem(this);
        delete(this);
        return;
    }
    setPos(x()-speed,y());
}
