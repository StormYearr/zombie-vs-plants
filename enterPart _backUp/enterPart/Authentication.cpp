#include "Authentication.h"
#include "ui_Authentication.h"
#include "change.h"
#include "welcome.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <Forgotten.h>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>

Authentication::Authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentication)
{
    ui->setupUi(this);
}

Authentication::~Authentication()
{
    delete ui;
}


QString hashFunction3(const QString &input)
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

void Authentication::on_buttonBox_accepted()
{
      QString mEnteredPassword;
    mEnteredPassword = ui->lineEdit->text();

   std::ifstream file("D:/userdata9.txt");
   bool found = false;

   if (file.is_open())
   {
       std::string line;
       while (std::getline(file, line))
       {
           std::istringstream iss(line);
             std::string username, hashedPass, name, email, number;
           iss >>name>>username>> hashedPass >> number >> email;

           if (hashFunction3(mEnteredPassword) == QString::fromStdString(hashedPass))
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

        change f;
        f.save_Pass(mEnteredPassword);
        f.setModal(true);
        f.exec();
   }
   else
   {
       qDebug() << "Login failed! 😔";
       // Deny access
   }
}
