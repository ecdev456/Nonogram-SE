#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "Model.h"
#include <QDialog>

extern Library Edwin;
namespace Ui {
class Checkout;
}

class Checkout : public QDialog
{
    Q_OBJECT

public:
    explicit Checkout(QWidget *parent = 0);
    ~Checkout();
void StudentInfo_CheckIn();
void BookInfo_CheckIn();
void TimeInfo_CheckIn();
private slots:

    void on_doneButton_clicked();

private:
    Ui::Checkout *ui;
};

#endif // CHECKOUT_H
