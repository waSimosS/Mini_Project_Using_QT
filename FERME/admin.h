#ifndef ADMIN_H
#define ADMIN_H
#include<modif.h>
#include <QDialog>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();

private slots:
    void on_Ajout_L_clicked();
    
    void on_pushButton_clicked();

    void on_Rech_l_clicked();

    void on_delete_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::admin *ui;
    modif *mod;

};

#endif // ADMIN_H
