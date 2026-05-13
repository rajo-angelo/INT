
#include "Moteur.h"

Moteur::Moteur(int puissance,  string numeroSerie, string typeCarburant, int nbCylindres) {
    
    this->puissance = puissance;
    this->numeroSerie = numeroSerie;
    this->typeCarburant = typeCarburant;
    this->nbCylindres = nbCylindres;
    estDemarre = false;
}

Moteur::~Moteur() {
    cout << "Moteur détruit" << endl;
}

void Moteur::demarrer() {
    if (!estDemarre) {
        estDemarre = true;
        cout << "Moteur démarré" << endl;
    } else {
        cout << "Moteur déjà en marche" << endl;
    }
}

void Moteur::arreter() {
    if (estDemarre) {
        estDemarre = false;
        cout << "Moteur arrêté" << endl;
    }
    else cout<<"Moteur n'est pas deja machee\n";
}

void Moteur::afficherInfos() {
    cout << "=== Infos Moteur ===" << endl;
    cout << "Puissance : " << puissance << " CV" << endl;
    cout << "Numéro série : " << numeroSerie << endl;
    cout << "Carburant : " << typeCarburant << endl;
    cout << "Nombre cylindres : " << nbCylindres << endl;
    cout << "État : " << (estDemarre ? "Démarré" : "Arrêté") << endl;

}


int Moteur::getPuissance() { 
    return puissance; 
}

string Moteur::getNumeroSerie() { 
    return numeroSerie; 
}

string Moteur::getTypeCarburant() 
{ 
    return typeCarburant; 
}

int Moteur::getNbCylindres() 
{ 
    return nbCylindres; 
}

bool Moteur::getEstDemarre() 
{ 
    return estDemarre; 
}

void Moteur::setPuissance(int p) 
{ 
    puissance = p; 
}

void Moteur::setTypeCarburant(string type) 
{ 
    typeCarburant = type; 
}
