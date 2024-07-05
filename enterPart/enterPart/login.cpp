#include "login.h"
#include "ground.h"
#include "ui_login.h"
#include "MainWindow.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <Forgotten.h>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
#include <QApplication>
#include "MainWindow.h"
#include <QRandomGenerator>
#include <QList>
#include <QFont>
using namespace std;
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


QString hashFunction2(const QString &input)
{
    QByteArray inputBytes = input.toUtf8();

    QByteArray hashBytes = QCryptographicHash::hash(inputBytes, QCryptographicHash::Sha256);
    QString hash = QString(hashBytes.toHex());

    // Take first 8 characters and convert to unsigned int
    bool ok;
    unsigned int hashNumber = hash.left(8).toUInt(&ok, 16);

    // If conversion to unsigned int failed, use a default value
    if (!ok) {
        hashNumber = 0;
    }

    // Convert the number to string with leading zeros if necessary
    QString result = QString::number(hashNumber).rightJustified(8, '0');

    return result;
}

void login::on_buttonBox_accepted()
{

        QString enteredUsername = ui->Uname->text();
        QString enteredPassword = ui->pass->text();

        std::ifstream file("D:/userdata5.txt");
        bool found = false;

        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string username, hashedPass, name, email, number;

                iss >>name>>username>> hashedPass >> number >> email;

                if (QString::fromStdString(username) == enteredUsername && hashFunction2(enteredPassword) == QString::fromStdString(hashedPass))
                {
                    found = true;
                    break;
                }
            }

            file.close();
        }

        if (found)
        {
            qDebug() << "Login successful! 😊";
            // Allow access
          //  ground l;
           // l.setModal(true);
           // l.exec();
//            view = new QGraphicsScene(this);
//            setScene(view);
//            setFixedSize(800,600);
//            setSceneRect(0,0,700,500);
        }
        else
        {
//            qDebug() << "Login failed! 😔";
//            // Deny access

                   QMessageBox::critical(nullptr, "Login Failed", "Try again");



        }
}


void login::on_pushButton_clicked()
{
    Forgotten l;
    l.setModal(true);
    l.exec();
}

