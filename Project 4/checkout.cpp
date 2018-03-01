#include "checkout.h"
#include "ui_checkout.h"
#include "string.h"
#include "Model.h"
#include "mainwindow.h"


#include <iostream>
using namespace std;

//Library library;

Checkout::Checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkout)
{
    ui->setupUi(this);

    StudentInfo_CheckIn();
    BookInfo_CheckIn();
    TimeInfo_CheckIn();
}

void Checkout::StudentInfo_CheckIn()
{
    string student = Edwin.GetTempName();
    //QString Student = Edwin.GetTempName();
          ui->StudentInfo->setText(QString::fromStdString(student));
}

void Checkout::BookInfo_CheckIn()
{
    string book = Edwin.GetTempBook();
     ui->BookInfo->setText(QString::fromStdString(book));
}


void Checkout::TimeInfo_CheckIn()
{
        //cout << "Check: " << Edwin.GetTempTime() << endl;
    string timeCheck = Edwin.GetTempTime();
     ui->TimeInfo->setText(QString::fromStdString(timeCheck));
}

Checkout::~Checkout()
{
    delete ui;
}


void Checkout::on_doneButton_clicked()
{
    //Update Code goes here where we put setters.

    close();
}
