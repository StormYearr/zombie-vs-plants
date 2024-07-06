#ifndef FORGOTTEN_H
#define FORGOTTEN_H

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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Forgotten *ui;
};

#endif // FORGOTTEN_H
