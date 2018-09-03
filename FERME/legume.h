#ifndef LEGUME_H
#define LEGUME_H
#include <string>
#include <iomanip>
#include<iostream>
#include<fstream>
using namespace std;
class legume
{
public:
    string nom;
    int qt;
    float prix;
    string cat;
    string sai;

public:
    legume(){}
    legume(string,int,float,string,string);
    ~legume(){}
    float prix_total (int );
    bool commande(int);
    static int recherche(legume&);
    friend ostream& operator<< (ostream&, legume&);
    friend istream& operator>> (istream&, legume&);

};

#endif // LEGUME_H
