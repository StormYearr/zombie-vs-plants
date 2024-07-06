#include "signUp.h"
#include "ui_signUp.h"
#include <fstream>
#include <QCryptographicHash>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <regex>

signUp::signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signUp)
{
     ui->setupUi(this);
     setWindowTitle("Registration section");
     ui->pass->setEchoMode(QLineEdit::Password); // Set password lineEdit to show asterisks

    // Set background color and font for username QLineEdit
    ui->username->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");

    // Set border and background color for name QLineEdit
    ui->name->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");

    // Set background color and font for email QLineEdit
    ui->email->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");

    // Set background color and font for number QLineEdit
    ui->number->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");
    ui->pass->setStyleSheet("border: 2px solid #cccccc; background-color: #f9f9f9; font-family: Arial; font-size: 12px;");

    // Set button background color and text color
    ui->buttonBox->setStyleSheet("background-color: #4CAF50; color: white;");
  // this->setStyleSheet("background-image: url(:/path_to_image/image.jpg);");
    this->setStyleSheet("background-color: #90EE90;");
}

signUp::~signUp()
{
    delete ui;
}

QString hashFunction(const QString &input)
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

void signUp::on_buttonBox_accepted()
{
    QString username = ui->username->text();
    QString password = ui->pass->text();
    QString name = ui->name->text();
    QString email = ui->email->text();
    QString hashedPass = hashFunction(password);
    QString number = ui->number->text();

    // Open a file named "userdata.txt" for writing
    std::ofstream file("D:/userdata9.txt", std::ios_base::app); // Using ios_base::app to append to the file

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
    }
    else
    {
        qDebug() << QStringLiteral("File opening failed");
    }
}
