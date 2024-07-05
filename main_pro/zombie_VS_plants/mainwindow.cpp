#include "mainwindow.h"
//#include "zombi2.h"
#include "cactus.h"
#include "ground.h"
#include "z1.h"
#include "brain.h"
#include <QRandomGenerator>
#include <QList>
#include <QFont>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    view = new QGraphicsScene(this);
    setScene(view);
    setFixedSize(850, 600);
    setSceneRect(0, 0, 700, 500);

    // Add image 'k' to the bottom-left corner
    QPixmap imageK(":/game/table"); // Replace with your actual path
    QGraphicsPixmapItem *itemK = new QGraphicsPixmapItem(imageK);
    int xPos = 188;
    int yPos = 400; // Calculate yPos based on scene height and image height
    itemK->setPos(xPos, yPos);
    qreal scaleFactor = 0.55; // Example scale factor (50%)
    itemK->setScale(scaleFactor);
    view->addItem(itemK);

    // Add image 'k2' to the bottom-left corner
    QPixmap imageK2(":/game/t3"); // Replace with your actual path
    QGraphicsPixmapItem *itemK2 = new QGraphicsPixmapItem(imageK2);
    int xPos2 = -80;
    int yPos2 = 400; // Calculate yPos based on scene height and image height
    itemK2->setPos(xPos2, yPos2);
    qreal scaleFactor2 = 0.62; // Example scale factor (50%)
    itemK2->setScale(scaleFactor2);
    view->addItem(itemK2);

    // Add ground to the scene
    Ground* G = new Ground();
    view->addItem(G);

    // Add brain to the scene
    brain *b = new brain();
    view->addItem(b);

    // Add time bar at the top of the scene
   timeBar = new QGraphicsRectItem(0, 0, 700, 20); // Adjust width as needed
    timeBar->setBrush(Qt::magenta); // Set color of time bar
    view->addItem(timeBar);

    // Set total time and initialize remaining time
    totalTimeInSeconds = 210; // 3 minutes and 30 seconds
    remainingTimeInSeconds = totalTimeInSeconds;

    // Create timer to update remaining time
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000); // Update every second


    Zom1 = new z1();
      view->addItem(Zom1);
      //
      Zom3 = new class z3();
      view->addItem(Zom3);

      Zom4 = new class z4();
      view->addItem(Zom4);

      Zom5 = new class z5();
      view->addItem(Zom5);

      Zom6 = new class z6();
      view->addItem(Zom6);

      // Add z2 to the scene
       Zom2 = new class z2();
       view->addItem(Zom2);

    // Add other items like Zom3, Zom4, Zom5, Zom6, Zom2 here...


}

void MainWindow::updateTime()
{
    remainingTimeInSeconds--;
    updateTimeBar();

    if (remainingTimeInSeconds <= 0)
    {
        endGame();
    }
}

void MainWindow::updateTimeBar()
{
    qreal width = (qreal)remainingTimeInSeconds / totalTimeInSeconds * 700; // 700 is the width of the scene
    timeBar->setRect(0, 0, width, 20);
}

void MainWindow::endGame()
{
    timer->stop(); // Stop the timer
    QMessageBox::information(this, "Game Over", "Time Over!"); // Show message box
    close(); // Close the main window

}

