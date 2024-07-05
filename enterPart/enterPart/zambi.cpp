#include "zambi.h"
#include "ui_zambi.h"

zambi::zambi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zambi)
{
    ui->setupUi(this);
}

zambi::~zambi()
{
    delete ui;
}
