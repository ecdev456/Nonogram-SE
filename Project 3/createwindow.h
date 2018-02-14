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

private slots:

    void on_reminderDescription_editingFinished();

    void on_reminderTitle_editingFinished();

    void on_dateEdit_editingFinished();

    void on_timeEdit_editingFinished();

    void on_pushButton_clicked();

    void on_doneButton_clicked();

private:
    Ui::CreateWindow *ui;


};



#endif // CREATEWINDOW_H
