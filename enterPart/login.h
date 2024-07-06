#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    std::string username, hashedPass, name, email, number;
    Ui::login *ui;
    QString enteredUsername ;
    QString enteredPassword ;
private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:

};

#endif // LOGIN_H
