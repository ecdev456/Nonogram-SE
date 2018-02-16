#include "reminder.h"
#include "ui_reminder.h"

string reminderInfo;


Reminder::Reminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reminder)
{
    ui->setupUi(this);


    TempR.SetNumData(0);    //Reset it back to 0 spot to make it simple

    reminderInfo += "Title: " + TempR.GetTitle(0) + "\n"  + "Date: " + TempR.GetDate(0) + "\n" + "Time: " + TempR.GetTime(0)+ "\n" + "Desc: " + TempR.GetDesc(0) +"\n";


ui->printInfo->setText(QString::fromStdString((reminderInfo)));
reminderInfo = "";

}

Reminder::~Reminder()
{
    delete ui;
}

void setInfo(string i)
{
    reminderInfo = i;
}
