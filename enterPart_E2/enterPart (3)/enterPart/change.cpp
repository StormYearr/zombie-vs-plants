#include "change.h"
#include "ui_change.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <Forgotten.h>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>

change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
    ui->pass->setEchoMode(QLineEdit::Password); // Set password lineEdit to show asterisks
}

change::~change()
{
    delete ui;
}

QString hashFunction4(const QString &input)
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

void change::on_buttonBox_accepted()
{
    QString username = ui->username->text();
    QString password = ui->pass->text();
    QString name = ui->name->text();
    QString email = ui->email->text();
    QString hashedPass = hashFunction4(password);
    QString number = ui->number->text();

    // Open a file named "userdata.txt" for writing
    std::ofstream file("D:/userdata6.txt", std::ios_base::app); // Using ios_base::app to append to the file

    if (file.is_open())
    {
        file << name.toStdString() << "\t";
        file << username.toStdString() << "\t";
        file << hashedPass.toStdString() << "\t";
        file << number.toStdString() << "\t";
        file << email.toStdString() << "\t";
        file << "\n";
        qDebug() << QStringLiteral("Writing has been done");
        file.close();
        accept();

    }
    else
    {
        qDebug() << QStringLiteral("File opening failed");
    }
}
