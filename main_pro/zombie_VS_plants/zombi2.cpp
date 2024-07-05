#include "zombi2.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QRandomGenerator>
#include <QTimer>


//int Cloud::count=0;


//int Cloud:: Randomgeneration (int min,int max){

//    return QRandomGenerator::global()->bounded(min,max+1);
//}
Cloud::Cloud(QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent)
{
//    qDebug()<<"New cloud created!\n";

//    QPixmap imagCl(":/Images/cloud2.png");
//    QPixmap scaled_imagCl=imagCl.scaled(150,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
//    setPixmap(scaled_imagCl);

//    this->setPos(800,Randomgeneration(-50,50));

//    speed=Randomgeneration(1,10);

//    cloud_mov =new QTimer();

//    connect(cloud_mov,&QTimer::timeout,this,&Cloud::Cmovement);
//    cloud_mov->start(40);
//    count++;
//    QPixmap imagDI1(":/game/regular");
//    QPixmap scaled_imagDI1=imagDI1.scaled(60,110,Qt::KeepAspectRatio,Qt::SmoothTransformation);

//    QPixmap imagDI2(":/game/bucket");
//    QPixmap scaled_imagDI2=imagDI2.scaled(70,250,Qt::KeepAspectRatio,Qt::SmoothTransformation);

//    QPixmap imagDI3(":/game/leaf");
//    QPixmap scaled_imagDI3=imagDI3.scaled(70,250,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    //
   // Frame << scaled_imagDI1 << scaled_imagDI2 << scaled_imagDI3;

//    setPixmap(scaled_imagDI1);
//    this->setPos(55,443);

//    setPixmap(scaled_imagDI3);
//    this->setPos(50,440);

//    setPixmap(scaled_imagDI3);
//    this->setPos(40,400);
}


//void Cloud::Cmovement(){
//    QPointF cloudPos = this->pos();
//    if(cloudPos.x()<-80){
//        qDebug()<<"cloud Deleted!!\n";
//        scene()->removeItem(this);
//        delete(this);
//        return;
//    }
//    setPos(x()-speed,y());
//}


Cloud::~Cloud(){
    count--;
}
