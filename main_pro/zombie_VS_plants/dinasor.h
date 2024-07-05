#ifndef DINASOR_H
#define DINASOR_H
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QString>
class Dinasor:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Dinasor();
    void ChangeImag();
    void situationHandle();
private:
    QString situation;
    QList<QPixmap> Frame;
    QTimer* FHandle;
    int shetab = 8;
};

#endif // DINASOR_H
