#include "createwindow.h"
#include "ui_createwindow.h"
#include <iostream>

using namespace std;

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

void CreateWindow::on_pushButton_clicked()
{
    close();
}

//Stores the information from the text box from create screen
void CreateWindow::on_reminderDescription_returnPressed()
{
    QString input = ui->reminderDescription->text();
    //description variable stores the information that the user inputed
    string description = input.toStdString();
    cout << description << endl;

}
