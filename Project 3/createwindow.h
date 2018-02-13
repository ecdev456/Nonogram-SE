#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QDialog>
#include "model.h"
#include "ui_createwindow.h"

namespace Ui {
class CreateWindow;
}

class CreateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateWindow(QWidget *parent = 0);

    ~CreateWindow();

   /* CreateWindow(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::CreateWindow)
    {
        ui->setupUi(this);
    }

   ~CreateWindow()
    {
        delete ui;
    }*/
private slots:
    void on_pushButton_clicked();

    void on_reminderDescription_returnPressed();

private:
    Ui::CreateWindow *ui;


};



#endif // CREATEWINDOW_H
