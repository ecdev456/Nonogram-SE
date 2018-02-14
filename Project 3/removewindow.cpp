#include "removewindow.h"
#include "ui_removewindow.h"
//#include "model.h"

RemoveWindow::RemoveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveWindow)
{
    ui->setupUi(this);


    TitleArray[0] = "first";//this is just a test

    string info = TitleArray[0];
    ui->textEdit_2->setText(QString::fromStdString((info)));

}

RemoveWindow::~RemoveWindow()
{
    delete ui;
}

//when cancel button has been clicked
void RemoveWindow::on_cancelRemove_clicked()
{
    close();
}

//done button has been pressed
void RemoveWindow::on_doneRemove_clicked()
{
    close();
}
