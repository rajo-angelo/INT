#pragma once

#include"Moteur.h"
#include"Vehicule.h"
#include<iostream>
using namespace std;

class Moto:public Vehicule
{
    private:
        Moteur moteur;
        string marque;
        string modele;
        string immatriculation;

    public:
        int getPuissance();
        string getNumeroSerie() ;
        string getTypeCarburant();
        string getMarque();
        int getNbCylindres();
        void setPuissance(int p) ;
        void setTypeCarburant(string type) ;
        void setMarque(string);
        bool getEtatMoteur();
        void demmarerMoteur();
        void arretMoteur();
        void afficheInfo();
        Moto(string marque, string modele, string immatriculation, Moteur& moteurs);
        ~Moto();
};





