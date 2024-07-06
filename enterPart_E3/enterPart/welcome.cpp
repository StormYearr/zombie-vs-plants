#include "welcome.h"
#include "ui_welcome.h"
#include "Authentication.h"
#include "ui_Authentication.h"
#include "change.h"
#include "ui_change.h"
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>
#include <QPalette>
#include <QPixmap>
welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
    setWindowTitle("Welcome");
    ui->pushButton->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");
    ui->pushButton_2->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");
    ui->pushButton_3->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");
    this->setStyleSheet("background-color: #8A2BE2;");
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_pushButton_clicked()
{
    Authentication k;
    k.setModal(true);
    k.exec();
}

