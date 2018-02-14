#include "createwindow.h"
#include "ui_createwindow.h"
#include <iostream>

using namespace std;

Model DataCollection;
CreateWindow::CreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateWindow)
{
    ui->setupUi(this);
}

CreateWindow::~CreateWindow()
{
    delete ui;
}

//Stores the information from the text box from create screen
void CreateWindow::on_reminderDescription_editingFinished()
{
    QString input = ui->reminderDescription->text();
    //description variable stores the information that the user inputed
    string description = input.toStdString();
    cout << description << endl;
    DataCollection.SetDesc(description);
}

//Grab the information from the title name
void CreateWindow::on_reminderTitle_editingFinished()
{
    QString titleName = ui->reminderTitle->text();

    string title = titleName.toStdString();
    cout << title << endl;
    DataCollection.SetTitle(title);
}

//Stores the time the user enters
void CreateWindow::on_timeEdit_editingFinished()
{
    QString timeInfo = ui->timeEdit->text();

    string time = timeInfo.toStdString();

    cout << time << endl;
    DataCollection.SetTime(time);
}

//cancel button to close out of everything from create window
void CreateWindow::on_pushButton_clicked()
{
    close();
}

//Stores the date information from the date that was entered
void CreateWindow::on_dateEdit_editingFinished()
{
    QString dateInfo = ui->dateEdit->text();

    string date = dateInfo.toStdString();
    cout << date << endl;

    DataCollection.SetDate(date);
}

//keeps track of when the done button was pushed
void CreateWindow::on_doneButton_clicked()
{
    QObject * senderObj = sender();
    if(senderObj->isWidgetType())
    {
        QPushButton * button = qobject_cast<QPushButton*>(senderObj);
                if (button)
                {
                    bool doneButton = 1;
                    DataCollection.SetButton(doneButton);
                    cout << "pushed button" << endl;
                }
    }
    close();
}
