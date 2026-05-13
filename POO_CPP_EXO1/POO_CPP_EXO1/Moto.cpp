#include<iostream>
#include"Moto.h"
using namespace std;

void Moto::demmarerMoteur()
{
    moteur.demarrer();
}
void Moto::arretMoteur()
{
    moteur.arreter();
}

int Moto::getPuissance() { 
    return moteur.getPuissance();
}

string Moto::getNumeroSerie() { 
    return moteur.getNumeroSerie();
}

string Moto::getTypeCarburant() 
{ 
    return moteur.getTypeCarburant();
}

int Moto::getNbCylindres() 
{ 
    return moteur.getNbCylindres();
}

void Moto::setMarque(string marque){
    this->marque = marque;
}

void Moto::setPuissance(int p) 
{ 
    moteur.setPuissance(p); 
}
void Moto::setTypeCarburant(string type) 
{ 
    moteur.setTypeCarburant(type); 
}

string Moto::getMarque()
{
    return marque;
}

void Moto::afficheInfo()
{
    cout<<"\n== Info Moto == \n";
    cout << "Marque : " <<marque<< endl;
    cout << "Model : " <<modele<< endl;
    cout << "Numero matricule : " <<immatriculation<< endl;
    moteur.afficherInfos();
}

bool Moto::getEtatMoteur()
{
    return moteur.getEstDemarre();
}

Moto::Moto(string marque, string modele, string immatriculation, Moteur& moteurs)
    :moteur(moteurs.getPuissance(),moteurs.getNumeroSerie(),moteurs.getTypeCarburant(),moteurs.getNbCylindres())
{   
    this->marque = marque;
    this->modele = modele;
    this->immatriculation = immatriculation;
}

Moto::~Moto()
{
    cout << "Moto detruit" << endl;
}