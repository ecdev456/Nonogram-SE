#include "checkout.h"
#include "ui_checkout.h"

Checkout::Checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkout)
{
    ui->setupUi(this);
}

Checkout::~Checkout()
{
    delete ui;
}


void Checkout::on_doneButton_clicked()
{
    close();
}
