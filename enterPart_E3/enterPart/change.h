#ifndef CHANGE_H
#define CHANGE_H
#include <QString>
#include <QDialog>

namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = nullptr);
    ~change();
     Ui::change *ui;
     QString  save_pass;
      std::string username, hashedPass, name, email, number;
     std::string username2,  password2, name2, email2, number2;
     QString username3,  password3, name3, email3, number3;
     void save_Pass(QString s)
     {
          save_pass=s;
     }
private slots:
     void on_buttonBox_accepted();

private:

};

#endif // CHANGE_H
