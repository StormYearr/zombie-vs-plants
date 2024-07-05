#include "ground.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QMutex>

Ground::Ground()
{
    QPixmap imagG (":/game/gr");
    QPixmap scaled_imagG = imagG.scaled(849,600,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(scaled_imagG);
    this->setPos(-100,7);

}
