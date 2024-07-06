#ifndef FORGOTTEN_H
#define FORGOTTEN_H
#include "change.h"
#include <QDialog>

namespace Ui {
class Forgotten;
}

class Forgotten : public QDialog
{
    Q_OBJECT

public:
    explicit Forgotten(QWidget *parent = nullptr);
    ~Forgotten();
    friend class change;
     Ui::Forgotten *ui;
private slots:
    void on_buttonBox_accepted();

private:

};

#endif // FORGOTTEN_H
