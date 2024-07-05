#include "ground.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QMutex>

ground::ground()
{
    qDebug()<<"Ground created\n";

    QPixmap imagG (":/Game/Ground");
    QPixmap scaled_imagG = imagG.scaled(1000,100,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(scaled_imagG);
    this->setPos(-100,480);

}
