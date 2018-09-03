#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "login.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_client_b_clicked();

    void on_admin_b_clicked();

private:
    Ui::MainWindow *ui;
    client *cl;
    login *lg;


};

#endif // MAINWINDOW_H
