#include "reminder.h"
#include "ui_reminder.h"

string reminderInfo;


Reminder::Reminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reminder)
{
    ui->setupUi(this);


    cout << "You have a Reminder!! : " << endl;

    //cout << "Title: " <<  << endl;
  //  cout << "Date/Time: " << TempR.GetDate(0)<< " " << TempR.GetTime(0) << endl;
  //  cout << "Desc: " << TempR.GetDesc(0) << endl;
    TempR.SetNumData(0);    //Reset it back to 0 spot to make it simple

    reminderInfo += "Title: " + TempR.GetTitle(0) + "\n"  + "Date: " + TempR.GetDate(0) + "\n" + "Time: " + TempR.GetTime(0)+ "\n" + "Desc: " + TempR.GetDesc(0) +"\n";


ui->printInfo->setText(QString::fromStdString((reminderInfo)));
reminderInfo = "";
    //cout <<"Title: " << TempR.tData << endl;
    //string info = infoPrint;
    //cout << DataCollection.GetDate(0) << endl;
   // cout << reminderInfo << endl;
    //int num = s.updateTime();
    //cout << "num: " << num << endl;
}

Reminder::~Reminder()
{
    delete ui;
}

void setInfo(string i)
{
    reminderInfo = i;
}
