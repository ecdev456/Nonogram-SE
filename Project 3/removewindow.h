#ifndef REMOVEWINDOW_H
#define REMOVEWINDOW_H

#include <QDialog>
#include "model.h"
#include <iostream>


extern Model TempE;

namespace Ui {
class RemoveWindow;
}

class RemoveWindow : public QDialog, public Model
{

    Q_OBJECT

public:
    explicit RemoveWindow(QWidget *parent = 0);
    ~RemoveWindow();

private slots:
    void on_cancelRemove_clicked();

    void on_doneRemove_clicked();

    void on_removeChoice_editingFinished();

private:
    Ui::RemoveWindow *ui;
};
#endif // REMOVEWINDOW_H

