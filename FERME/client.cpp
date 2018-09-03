#include "client.h"
#include "ui_client.h"
#include <QListWidget>
#include <legume.h>
#include <QMessageBox>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}


void client::on_afficher_clicked()
{
    fstream h;
     ui->listWidget->clear();
     h.open("d:\\leg.txt",ios::in | ios::out );
     legume L;

     while(h>>L)
     {
         // if (h.eof()) break;
         // h>>L;
         QString qnom = QString::fromStdString(L.nom);
         QString qsai = QString::fromStdString(L.sai);
         QString qcat = QString::fromStdString(L.cat);
         QString cat=ui->comboBox->currentText();
         QString sai=ui->comboBox_2->currentText();
         std::string categorie=cat.toUtf8().constData();
         std::string saison=sai.toUtf8().constData();
         if (categorie==L.cat && saison==L.sai)
               ui->listWidget->addItem(qnom+"        Prix de 1 KG: "+QString::number(L.prix)+"       Quantité disponible en KG: "+QString::number(L.qt));
     }
     h.close();
}

void client::on_pushButton_clicked()
{
    fstream h,f;
    QString name=ui->lineEdit->text();
    QString qat=ui->spinBox->text();
    QString num=ui->lineEdit_2->text();
    std::string nom=name.toUtf8().constData();
    std::string no=num.toUtf8().constData();
    int quant=qat.toInt();
    legume A;
    legume L;
    A.nom=nom;
    if (legume::recherche(A)==0)
        QMessageBox::warning(this,tr("commande"),tr("Ce produit n'existe pas !"));
    else if(legume::recherche(A)==1 && A.commande(quant)==false)
        QMessageBox::warning(this,tr("commande"),tr("quantité demandé n'est pas disponible en stock !"));
    else if(legume::recherche(A)==1 && A.commande(quant)==true)
    {
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
                h<<A;
        }
        }
        f.close();
        h.close();
        string str;
        QMessageBox::information(this,"commande","commande effectué et prix totle en DT "+QString::number(A.prix_total(quant))  );
        remove("d:\\leg.txt");
        rename("d:\\supp.txt","d:\\leg.txt");

        fstream a;
        a.open("d:\\achats.txt" , ios::app | ios::out);
        a<<setw(15)<<no<<" "<<setw(15)<<nom<<" "<<setw(15)<<quant<<" "<<setw(15)<<A.prix_total(quant)<<endl;
        a.close();




    }
}
