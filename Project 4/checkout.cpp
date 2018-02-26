#include "checkout.h"
#include "ui_checkout.h"
#include "string.h"
//#include "Model.h"
//#include "mainwindow.h"


QString info;
Checkout::Checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkout)
{
    ui->setupUi(this);


    info = "Student: student id needs to turn in book by .... time/n";
    ui->checkoutText->setText(info);//QString::fromStdString((info)));
    info = "";
}

Checkout::~Checkout()
{
    delete ui;
}


void Checkout::on_doneButton_clicked()
{
    close();
}
