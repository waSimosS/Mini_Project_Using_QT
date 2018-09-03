#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:


    void on_LOGIN_clicked();

private:
    Ui::login *ui;
    admin *ad;

};

#endif // LOGIN_H
