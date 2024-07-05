#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "z1.h"
#include "z2.h"
#include "z3.h"
#include "z4.h"
#include "z5.h"
#include "z6.h"
#include "brain.h"
class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    z1 * Zom1;
    z2 *Zom2;
    z3 *Zom3;
    z4 *Zom4;
    z5 *Zom5;
    z6 *Zom6;
    brain *b;
private:
    QGraphicsScene *view;
    QGraphicsRectItem *timeBar;
    QTimer *timer;
    int totalTimeInSeconds; // Total time in seconds
    int remainingTimeInSeconds; // Remaining time in seconds

    void updateTimeBar(); // Update time bar based on remaining time
    void endGame(); // End the game when time is over

private slots:
    void updateTime(); // Update remaining time slot

};
#endif // MAINWINDOW_H


