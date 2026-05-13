#pragma once

#include"Vehicule.h"
#include"Moteur.h"
#include<iostream>
#include <vector>
using namespace std;

class Cammion:public Vehicule
{
    private:
        Moteur moteur;
        string marque;
        string modele;
        string immatriculation;
        float poidsAVide;
        float chargeUtile;
        float PTAC;
        int nombreEssieux;
        bool remorque;
        vector<string> categoriesPermisRequises;
    public:
        Cammion(string marque, string modele, string immatriculation, float poidsAVide, float chargeUtile, Moteur& moteur);
        ~Cammion();

        int getPuissance();
        string getNumeroSerie() ;
        string getTypeCarburant();
        int getNbCylindres();
        void setPuissance(int p) ;
        void setTypeCarburant(string type) ;
        void setMarque(string);
        string getMarque();
        void demmarerMoteur();
        void arretMoteur();
        void afficheInfo();
        bool getEtatMoteur();
};
