#include "Authentication.h"
#include "ui_Authentication.h"
#include "change.h"
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>

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
    QString mEnteredPassword = ui->lineEdit->text().trimmed(); // Get entered password

    std::ifstream inFile("D:/userdata6.txt");
    if (!inFile.is_open())
    {
        qDebug() << "Could not open file: D:/userdata6.txt";
        return;
    }

    std::ofstream outFile("D:/tempfile.txt"); // Temporary file to write valid lines
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
        if (hashFunction3(mEnteredPassword) == hashedPassQString)
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
        // Delete the original file
        QFile::remove("D:/userdata6.txt");

        // Rename the temporary file to original file
        QFile::rename("D:/tempfile.txt", "D:/userdata6.txt");

        qDebug() << "User data removed from file.";

        // Allow access
        change f;
        f.setModal(true);
        f.exec();
    }
    else
    {
        qDebug() << "Login failed! 😔";
        // Deny access
    }
}
