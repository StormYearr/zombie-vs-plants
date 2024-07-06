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

    setWindowTitle("صفحه UI با دکمه های رنگی");
    QFont font("Arail",20);
    ui->login->setFont(font);
    ui->login->setStyleSheet("background-color: #FF5733"); // رنگ نارنجی
    QFont font2("Arail",20);
    ui->register_2->setFont(font2);
    ui->register_2->setStyleSheet("background-color: #3498DB"); // رنگ آبی
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

