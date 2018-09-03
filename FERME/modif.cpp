#include "modif.h"
#include "ui_modif.h"

modif::modif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modif)
{
    ui->setupUi(this);
}

modif::~modif()
{
    delete ui;
}

void modif::on_pushButton_clicked()
{

}
