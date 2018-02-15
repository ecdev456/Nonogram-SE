#include "updatewindow.h"
#include "ui_updatewindow.h"

UpdateWindow::UpdateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateWindow)
{
    ui->setupUi(this);
}

UpdateWindow::~UpdateWindow()
{
    delete ui;
}

void UpdateWindow::on_pushButton_2_clicked()
{
    close();
}

void UpdateWindow::on_pushButton_clicked()
{
    close();
}
