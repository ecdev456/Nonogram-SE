#include "reminder.h"
#include "ui_reminder.h"
#include "Model.h"


std::string reminderInfo;
//Library TopLayer;

Reminder::Reminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reminder)
{
    ui->setupUi(this);

    reminderInfo += "Title: " + TopLayer.GetBookInfo(TopLayer.GetIndex()) + "\n"  + "Book Due Date Arrived" + "\n" + "Time: " + TopLayer.GetTimeDue(TopLayer.GetIndex())+ "\n" + "Desc: " + "Thank You, Book checked back in!" +"\n";


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
