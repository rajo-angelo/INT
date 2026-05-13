#include<iostream>
#include"Cammion.h"
using namespace std;

void Cammion::demmarerMoteur()
{
    moteur.demarrer();
}

void Cammion::arretMoteur()
{
    moteur.arreter();
}

void Cammion::setMarque(string marque)
{
    this->marque = marque;
}

int Cammion::getPuissance() { 
    return moteur.getPuissance();
}

string Cammion::getNumeroSerie() { 
    return moteur.getNumeroSerie();
}

string Cammion::getTypeCarburant() 
{ 
    return moteur.getTypeCarburant();
}

int Cammion::getNbCylindres() 
{ 
    return moteur.getNbCylindres();
}


void Cammion::setPuissance(int p) 
{ 
    moteur.setPuissance(p); 
}
void Cammion::setTypeCarburant(string type) 
{ 
    moteur.setTypeCarburant(type); 
}

string Cammion::getMarque()
{
    return marque;
}

void Cammion::afficheInfo(){
    cout<<"\n==== Information du cammion ===\n";
    cout << "marque : " << marque  << endl;
    cout << "modele: " << modele << endl;
    cout << "immatriculation : " << immatriculation << endl;
    cout << "poidsAVide : " << poidsAVide << endl;
    cout << "chargeUtile : " << chargeUtile << endl;
    cout << "PTAC: " << PTAC << endl;
    cout << "nombreEssieux : " << nombreEssieux << endl;
    cout << "poidsAVide : " << poidsAVide << endl;
    moteur.afficherInfos();
}

bool Cammion::getEtatMoteur()
{
    return moteur.getEstDemarre();
}


Cammion::Cammion(string marque, string modele, string immatriculation, float poidsAVide, float chargeUtile, Moteur& moteurs)
    :moteur(moteurs.getPuissance(),moteurs.getNumeroSerie(),moteurs.getTypeCarburant(),moteurs.getNbCylindres())
{   
    cout<<"Cammion bien construit\n";
    this->marque = marque;
    this->modele = modele;
    this->immatriculation = immatriculation;
    this->poidsAVide = poidsAVide;
    this->chargeUtile = chargeUtile;
}

Cammion::~Cammion()
{
    cout<<"Cammion detruit\n";
};