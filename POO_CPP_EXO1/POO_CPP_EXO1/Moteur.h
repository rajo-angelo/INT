#pragma once

#include <iostream>
#include <string>
using namespace std;

class Moteur {
    protected:
        int puissance;                
        string numeroSerie;
        string typeCarburant; 
        int nbCylindres;
        bool estDemarre;

    public:
        Moteur(int puissance, string numeroSerie, string typeCarburant, int nbCylindres);
        ~Moteur();

        void demarrer();
        void arreter();
        void afficherInfos();

        int getPuissance();
        string getNumeroSerie();
        string getTypeCarburant();
        int getNbCylindres();
        bool getEstDemarre();

        void setPuissance(int p);
        void setTypeCarburant(string type);
};
