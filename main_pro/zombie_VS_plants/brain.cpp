#include "brain.h"
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator> // For random number generation
#include "ground.h"

brain::brain()
{
    // Set the default size of the brain
    brainSize = QSize(40, 40); // Default size is 40x40

    // Start timer to show brain on different positions
    timerShow = new QTimer(this);
    connect(timerShow, &QTimer::timeout, this, &brain::showRandomPosition);
    timerShow->start(7000); // Timer interval: 7 seconds

    // Timer to hide brain after 3 seconds
    timerHide = new QTimer(this);
    connect(timerHide, &QTimer::timeout, this, &brain::hideBrain);
}

void brain::setBrainSize(const QSize &size)
{
    brainSize = size; // Set the new size for the brain
}

void brain::showRandomPosition()
{
    // List of 5 specific positions
    QList<QPointF> positions = {
        QPointF(430, 220),
        QPointF(490, 280),
        QPointF(370, 280),
        QPointF(490, 100),
        QPointF(550, 220)
    };

    // Get a random index to choose a position
    int randomIndex = QRandomGenerator::global()->bounded(positions.size());
    QPointF randomPosition = positions[randomIndex];

    // Create a new instance of QGraphicsPixmapItem for brain
    QGraphicsPixmapItem *newBrainItem = new QGraphicsPixmapItem(QPixmap(":/game/br").scaled(brainSize));
    newBrainItem->setPos(randomPosition);

    // Add brain item to the scene (assuming you have access to the scene)
    if (scene()) {
        scene()->addItem(newBrainItem);

        // Start the timer to hide brain after 3 seconds
        QTimer *timerHideCurrent = new QTimer(this);
        connect(timerHideCurrent, &QTimer::timeout, [newBrainItem, timerHideCurrent]() {
            if (newBrainItem->scene()) {
                newBrainItem->scene()->removeItem(newBrainItem);
                delete newBrainItem;
            }
            timerHideCurrent->deleteLater();
        });
        timerHideCurrent->start(7000); // Timer interval: 7 seconds

        // Stop the hide timer for the current brain
        timerHide->stop();
        timerHide = timerHideCurrent; // Update timerHide to point to the current timer
    }
}

void brain::hideBrain()
{
    // No need to implement anything here since hiding is handled in showRandomPosition()
}
