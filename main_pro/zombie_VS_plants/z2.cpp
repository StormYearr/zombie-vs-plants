#include "z2.h"
#include "qcursor.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QEvent>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QRectF> // Added QRectF header for rectangle handling
#include "ground.h"

z2::z2()
{
    QPixmap imagDI2(":/game/hiar");
    QPixmap scaled_imagDI2=imagDI2.scaled(60,110,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    setPixmap(scaled_imagDI2);
    this->setPos(578,460);
    setAcceptHoverEvents(true);

    // Start moving the item automatically
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &z2::moveItem);
    timer->start(60); // Adjust interval as needed (milliseconds)
}

void z2::moveItem()
{

    // Check if score is greater than 100 and initial position is set
    if (score > 100 && !initialMoveStarted)
    {
        // Check if initial position is within specified coordinates
        if (x() >= 650 && x() <= 670 && y() <= 280 && y() >= -27)
        {
            // Set initial move started flag
            initialMoveStarted = true;
            canMove=false;
        }
    }

    // Check if initial move has started
    if (initialMoveStarted)
    {
        // Check if colliding with z3 item
        QList<QGraphicsItem*> collidingItems = this->collidingItems();
        bool isColliding = false;

        for (auto item : collidingItems)
        {
            if (dynamic_cast<Ground*>(item)) // Check if colliding item is z3
            {
                isColliding = true;
                break;
            }
        }

        if (isColliding)
        {
            // Calculate new position (move item to the left)
            QPointF newPos = pos();
            newPos.setX(newPos.x() - 1); // Adjust speed and direction here

            // Set the new position
            setPos(newPos);
        }
    }
}

void z2::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // Capture the position of the cursor relative to the item
    if (score > 100 && canMove)
    {
        offset = event->pos();
    }
}

void z2::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Calculate the new position of the item
    if (score > 100 && canMove)
    {
        QPointF newPos = event->scenePos() - offset;
        setPos(newPos);
    }
}

void z2::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // Change cursor to indicate item is movable
    if (score > 100 && canMove)
    {
        QCursor cursor(Qt::OpenHandCursor);
        setCursor(cursor);
    }
}

void z2::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // Restore default cursor when leaving the item
    if (score > 100 && canMove)
    {
        unsetCursor();
    }
}

void z2::increaseScore(int amount)
{
    score += amount;
    if (score > 100)
    {
        // Disable further movement once initial move has started
        canMove = false;
    }
}
