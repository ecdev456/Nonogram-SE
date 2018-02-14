#include "removewindow.h"
#include "ui_removewindow.h"

RemoveWindow::RemoveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveWindow)
{
    ui->setupUi(this);
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
