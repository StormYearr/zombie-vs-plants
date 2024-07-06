#ifndef CHANGE_H
#define CHANGE_H

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
private slots:
     void on_buttonBox_accepted();

private:

};

#endif // CHANGE_H
