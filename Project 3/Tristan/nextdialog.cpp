#include "nextdialog.h"
#include "ui_nextdialog.h"

NextDialog::NextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NextDialog)
{
    ui->setupUi(this);
}

NextDialog::~NextDialog()
{
    delete ui;
}
