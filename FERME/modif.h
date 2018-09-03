#ifndef MODIF_H
#define MODIF_H

#include <QDialog>

namespace Ui {
class modif;
}

class modif : public QDialog
{
    Q_OBJECT

public:
    explicit modif(QWidget *parent = 0);
    ~modif();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modif *ui;
};

#endif // MODIF_H
