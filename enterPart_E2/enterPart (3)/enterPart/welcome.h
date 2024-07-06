#ifndef WELCOME_H
#define WELCOME_H
#include "login.h"
#include <QDialog>

namespace Ui {
class welcome;
}

class welcome : public QDialog
{
    Q_OBJECT

public:
    explicit welcome(QWidget *parent = nullptr);
    ~welcome();

private slots:
    void on_pushButton_clicked();

private:
    Ui::welcome *ui;
    QString hashFunction2(const QString &input);
    bool checkFileCredentials(const QString &enteredPassword);
    QString mEnteredPassword;
};

#endif // WELCOME_H
