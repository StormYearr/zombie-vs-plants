#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_buttonBox_accepted();
    void on_pushButton_clicked();

private:
    Ui::login *ui;
    QGraphicsScene *view; // Added QGraphicsScene pointer for view management
};

#endif // LOGIN_H
