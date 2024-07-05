#include "dinasor.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QRandomGenerator>
#include <QTimer>
Dinasor::Dinasor()

{
    qDebug()<<"Uncle Naser created!!!!!!!!!!\n";

    QPixmap imagD1("E:/programing/qt/Uncle_Naser/Images/Dinasor1.png");
    QPixmap scaled_imagD1=imagD1.scaled(50,150,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap imagD2("E:/programing/qt/Uncle_Naser/Images/Dinasor2.png");
    QPixmap scaled_imagD2=imagD2.scaled(50,150,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    QPixmap imagD3("E:/programing/qt/Uncle_Naser/Images/Dinasor3.png");
    QPixmap scaled_imagD3=imagD3.scaled(50,150,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    Frame << scaled_imagD1 << scaled_imagD2 << scaled_imagD3;

    situation="Stable";

    FHandle = new QTimer();
    connect(FHandle,&QTimer::timeout,this,&Dinasor::situationHandle);
    FHandle->start(100);

    setPixmap(scaled_imagD1);

    this->setPos(200,480);
}

int Whatimag=0;
void Dinasor::ChangeImag(){
    if(Whatimag%3==0){
        setPixmap(Frame.at(0));
    }
    else if(Whatimag%3==1){
         setPixmap(Frame.at(1));
    }
    else{
         setPixmap(Frame.at(3));
    }
    Whatimag++;
}
void Dinasor::situationHandle(){
    if(situation=="Stable"){
        ChangeImag();
        return;
    }
    else if(situation=="Up"){
        if(shetab == 0){
            situation="Down";
            return;
        }
        setPos(x(),y()+shetab);
        shetab--;
        return;
    }
    else if(situation=="Down"){
        if(shetab == 8){
            situation="Stable";
            return;
        }
        setPos(x(),y()-shetab);
        shetab++;
        return;
    }
}

