#ifndef CLIENT_H
#define CLIENT_H
#include<fstream>

#include <QDialog>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

private slots:

    void on_afficher_clicked();

    void on_pushButton_clicked();

private:
    Ui::client *ui;

};

#endif // CLIENT_H
