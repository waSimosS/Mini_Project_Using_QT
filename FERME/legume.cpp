#include "legume.h"
#include<QDebug>


legume::legume(string a,int b,float c,string d,string e): nom(a), qt(b), prix(c), cat(d), sai(e)
{

}

bool legume::commande(int x)
{
    if (x>qt)
        return false;
    else{
        qt=qt-x;
        return true;
    }
}

float legume::prix_total(int quant)
{
    return (quant*prix);
}

ostream& operator<< (ostream& out , legume& L)
{
    out<<setw(15)<<L.nom<<" "<<setw(15)<<L.qt<<" "<<setw(15)<<L.prix<<" "<<setw(15)<<L.cat<<" "<<setw(15)<<L.sai<<endl;
    return out;
}

istream& operator>> (istream& in, legume& L)
{
    in>>L.nom;
    in>>L.qt;
    in>>L.prix;
    in>>L.cat;
    in>>L.sai;
    return in;

}


int legume::recherche( legume& k)
{
    fstream d;
     d.open("d:\\leg.txt", ios::in | ios::out );
     legume L;
     while(1)
     {
         if (d.eof()) break;
         d>>L;
         if(L.nom==k.nom){
             k.nom=L.nom;
             k.prix=L.prix;
             k.qt=L.qt;
             k.cat=L.cat;
             k.sai=L.sai;

             return 1;}
      }
     d.close();



   return 0;
}



