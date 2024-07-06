#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QString>
#include <QDialog>

namespace Ui {
class Authentication;
}

class Authentication : public QDialog
{
    Q_OBJECT

public:
    explicit Authentication(QWidget *parent = nullptr);
    ~Authentication();
     Ui::Authentication *ui;
private slots:
     void on_buttonBox_accepted();

private:

};

#endif // AUTHENTICATION_H
