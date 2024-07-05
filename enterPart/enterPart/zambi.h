#ifndef ZAMBI_H
#define ZAMBI_H

#include <QDialog>

namespace Ui {
class zambi;
}

class zambi : public QDialog
{
    Q_OBJECT

public:
    explicit zambi(QWidget *parent = nullptr);
    ~zambi();

private:
    Ui::zambi *ui;
};

#endif // ZAMBI_H
