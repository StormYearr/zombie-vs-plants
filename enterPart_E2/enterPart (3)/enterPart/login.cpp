#include "login.h"
#include "welcome.h"
#include "ui_login.h"
#include "welcome.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <Forgotten.h>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->pass->setEchoMode(QLineEdit::Password); // Set password lineEdit to show asterisks
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
    enteredUsername = ui->Uname->text();
    enteredPassword = ui->pass->text();

    std::ifstream file("D:/userdata6.txt");
    bool found = false;

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);

            iss >> name >> username >> hashedPass >> number >> email;

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
        welcome l;
        l.setModal(true);
        l.exec();
    }
    else
    {
        qDebug() << "Login failed! 😔";
        // Deny access
    }
}

void login::on_pushButton_clicked()
{
    Forgotten l;
    l.setModal(true);
    l.exec();
}
