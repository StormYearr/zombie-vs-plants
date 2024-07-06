#include "Forgotten.h"
#include "ui_Forgotten.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QString>
Forgotten::Forgotten(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Forgotten)
{
    ui->setupUi(this);
}

Forgotten::~Forgotten()
{
    delete ui;
}

void Forgotten::on_buttonBox_accepted()
{

    QString ph = ui->phoneNum->text();
    //QString enteredPassword = ui->pass->text();

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

            if (QString::fromStdString(number) ==ph)
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
    }
    else
    {
        qDebug() << "Login failed! 😔";
        // Deny access
    }
}

