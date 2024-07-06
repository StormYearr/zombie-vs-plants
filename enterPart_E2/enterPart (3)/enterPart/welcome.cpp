#include "welcome.h"
#include "ui_welcome.h"
#include "Authentication.h"
#include "ui_Authentication.h"
#include "change.h"
#include "ui_change.h"
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>

welcome::welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_pushButton_clicked()
{
    Authentication k;
    k.setModal(true);
    k.exec();
}
