#include "checkout.h"
#include "ui_checkout.h"
#include "string.h"
#include "Model.h"
#include "mainwindow.h"

Library library;

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
    QString Student = "ib7348"; //Example display
    //string student

    cout << library.getIndex() << endl;
     ui->StudentInfo->setText(QString::fromStdString(library.GetStudentInfo(library.getIndex())));
}

void Checkout::BookInfo_CheckIn()
{
    QString book = "Raiders of the Lost Ark"; //Example display
            ui->BookInfo->setText(book);
}


void Checkout::TimeInfo_CheckIn()
{
    QString timeCheck = "8:30 pm"; //Example Display
            ui->TimeInfo->setText(timeCheck);
}

Checkout::~Checkout()
{
    delete ui;
}


void Checkout::on_doneButton_clicked()
{
    close();
}
