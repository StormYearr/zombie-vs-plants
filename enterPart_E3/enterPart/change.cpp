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

QString hashFunction5(const QString &input)
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

    std::ifstream inFile("D:/userdata9.txt");
    if (!inFile.is_open())
    {
        qDebug() << "Could not open file: D:/userdata9.txt";
        return;
    }

    std::ofstream outFile("D:/tempfile4.txt"); // Temporary file to write valid lines
    if (!outFile.is_open())
    {
        qDebug() << "Could not create temporary file";
        inFile.close();
        return;
    }

    bool found = false;
    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string name, username, hashedPass, number, email;
        if (!(iss >> name >> username >> hashedPass >> number >> email)) { break; } // Error reading line

        QString hashedPassQString = QString::fromStdString(hashedPass);
        if (hashFunction5(save_pass) == hashedPassQString)
        {
            found = true;
            continue; // Skip writing this line to temporary file
        }

        // Write the line to temporary file
        outFile << name << "\t" << username << "\t" << hashedPass << "\t" << number << "\t" << email << "\n";
    }

    inFile.close();
    outFile.close();

          if (found)
          {
              qDebug() << "Login successful! 😊";
              if(!ui->username->text().isEmpty())
               {
                  username3= ui->username->text();
                  username2=username3.toStdString();
              }

              else
              {
                 username2=username;
              }
              if(!ui->pass->text().isEmpty())
              {
                   password3 = ui->pass->text();
                   password2=password3.toStdString();
              }

              else
              {
                   password2=hashedPass;
              }
              if(!ui->name->text().isEmpty())
              {
                    name3 = ui->name->text();
                    name2=name3.toStdString();
              }

              else
              {
                  name2=name;
              }
              if(!ui->email->text().isEmpty())
              {
                    email3 = ui->email->text();
                    email2=email3.toStdString();
              }
              if(!ui->pass->text().isEmpty())
              {
                    password3 = hashFunction5(ui->pass->text());
                    password2=password3.toStdString();
              }

              else
              {
                   password2=hashedPass;
              }
              if(!ui->number->text().isEmpty())
              {
                   number3 = ui->number->text();
                   number2=number3.toStdString();
              }

              // Open a file named "userdata.txt" for writing
              std::ofstream file("D:/userdata8.txt", std::ios_base::app); // Using ios_base::app to append to the file

              if (file.is_open())
              {

                  file << name2 << "\t";
                  file << username2 << "\t";
                  file <<  password2 << "\t";
                  file << number2<< "\t";
                  file << email2 << "\t";
                  file << "\n";
                  qDebug() << QStringLiteral("Writing has been done");
                  // Delete the original file
                  QFile::remove("D:/userdata8.txt");

                  // Rename the temporary file to original file
                  QFile::rename("D:/tempfile4.txt", "D:/userdata7.txt");

                  qDebug() << "User data removed from file.";

                  file.close();
                  accept();

              }
              else
              {
                  qDebug() << QStringLiteral("File opening failed");
              }
          }


          else
          {
              qDebug() << "Login failed! 😔";
              // Deny access
          }

}
