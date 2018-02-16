#ifndef UPDATEWINDOW_H
#define UPDATEWINDOW_H
#include "model.h"

#include <QDialog>

extern Model updateModel;
namespace Ui {
class UpdateWindow;
}

class UpdateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateWindow(QWidget *parent = 0);
    ~UpdateWindow();

private slots:

    void on_cancelUpdate_clicked();

    void on_doneUpdate_clicked();

    void on_updateChoice_editingFinished();

    void on_reminderDone_clicked();

    void on_updateCancel_clicked();

private:
    Ui::UpdateWindow *ui;
};

#endif // UPDATEWINDOW_H
