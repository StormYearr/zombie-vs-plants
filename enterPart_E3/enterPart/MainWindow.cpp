#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "login.h"
#include "signUp.h"
#include <QFont>
#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("let's play");
    QFont font("Arail",20);
    ui->login->setFont(font);
    ui->login->setStyleSheet("background-color: #4169E1"); // رنگ نارنجی
    QFont font2("Arail",20);
    ui->register_2->setFont(font2);
    ui->register_2->setStyleSheet("background-color:#008000"); // رنگ آبی
    QFont font3("Arail",20);
    ui->label_2->setFont(font);
    ui->label_2->setStyleSheet("color:#FF0000"); // رنگ آبی
    show();




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{

    login l;
    l.setModal(true);
    l.exec();
}


void MainWindow::on_register_2_clicked()
{
    signUp l;
    l.setModal(true);
    l.exec();
}

