#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_LOGIN_clicked()
{
    QString user=ui->username->text();
    QString pass=ui->password->text();
    if (user=="test" && pass=="test")
    {
        ad = new admin(this);
        ad->show();
        this->close();
    }
    else
        QMessageBox::warning(this,tr("login"),tr("password or username is inavalid !"));
}
