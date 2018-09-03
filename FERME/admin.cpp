#include "admin.h"
#include "ui_admin.h"
#include <fstream>
#include <QMessageBox>
#include <legume.h>
#include <QtDebug>
#include <stdio.h>

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}


void admin::on_pushButton_clicked()
{
  fstream f;

   QString user=ui->lineEdit->text();
   QString qat=ui->spinBox->text();
   QString pri=ui->doubleSpinBox->text();
   QString cat=ui->comboBox->currentText();
   QString sai=ui->comboBox_2->currentText();
   std::string nom=user.toUtf8().constData();
   int quant=qat.toInt();
   float prix=ui->doubleSpinBox->value();
   std::string categorie=cat.toUtf8().constData();
   std::string saison=sai.toUtf8().constData();
   legume L(nom,quant,prix,categorie,saison);

   if (legume::recherche(L)==0)
   {
        f.open("d:\\leg.txt",ios::app | ios::out );
        f<<L<<endl;
        QMessageBox::information(this,tr("ajout"),tr("le legume est ajouté !"));
   }
   else{
        QMessageBox::warning(this,tr("ajout"),tr("le legume existe deja !"));
   }

   f.close();
}

void admin::on_Rech_l_clicked()
{   fstream f,h;

    QString user=ui->lineEdit_2->text();
    std::string name=user.toUtf8().constData();
    QString qat=ui->spinBox_2->text();

    int quant=qat.toInt();
    float prix=ui->doubleSpinBox_2->value();
    legume A;
    legume L;
    A.nom=name;
     if (legume::recherche(A)==0)
         QMessageBox::warning(this,tr("MODIF"),tr("Ce produit n'existe pas !"));
     else{
         h.open("d:\\supp.txt",  ios::app | ios::out);
         f.open("d:\\leg.txt", ios::in | ios::out );
         f.seekg(0);
         h.seekg(0);
         while(f>>L)
             {
             if (L.nom!=A.nom)
             {
                 h<<L;
             }
          else {
                 L.prix=prix;
                 L.qt=quant;
                 h<<L;
         }}
         f.close();
         h.close();
         QMessageBox::information(this,tr("SUPP"),tr("le legume est modifié!"));
         remove("d:\\leg.txt");
         rename("d:\\supp.txt","d:\\leg.txt");}

}

void admin::on_delete_2_clicked()
{
    fstream f,h;

       QString user=ui->lineEdit_3->text();
       std::string name=user.toUtf8().constData();
       legume A;
       legume L;
       A.nom=name;
        if (legume::recherche(A)==0)
            QMessageBox::warning(this,tr("SUPP"),tr("Ce produit n'existe pas !"));
        else{
            h.open("d:\\supp.txt",  ios::app | ios::out);
            f.open("d:\\leg.txt", ios::in | ios::out );
            f.seekg(0);
            h.seekg(0);
            while(f>>L)
            {
                //if (f.eof()) break;
                //f>>L;
                if (L.nom!=A.nom)
                {
                    h<<L;
                }
            }
            f.close();
            h.close();
            QMessageBox::information(this,tr("SUPP"),tr("le legume est Supprimé !"));
            remove("d:\\leg.txt");
            rename("d:\\supp.txt","d:\\leg.txt");
            //d.rename("leg.txt");

       }
}

void admin::on_pushButton_2_clicked()
{
    fstream a;
    char ch[100];
    a.open("d:\\achats.txt" , ios::in| ios::out);
    ui->listWidget->clear();
    while(1){
        if (a.eof()) break;
        a.getline(ch,100,'\n');
         QString qnom = QString::fromStdString(ch);
         ui->listWidget->addItem(qnom);
        }

}
