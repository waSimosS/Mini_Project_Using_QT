#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_client_b_clicked()
{
    cl= new client(this);
    cl->show();

}

void MainWindow::on_admin_b_clicked()
{
    lg= new login(this);
    lg->show();
}
