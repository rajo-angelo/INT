#include<iostream>
#include"Personne.h"
using namespace std;

void Personne::setNom(string nom){
    this->nom = nom;
}

void Personne::setPrenom(string prenom){
    this->prenoms = prenom;
}

void Personne::setDatenais(string age){
    this->datenais = age;
}

void Personne::setPoids(float poids){
    this->poids = poids;
}

string Personne::getNom(){
    return nom;
}

string Personne::getPrenom(){
    return prenoms;
}

string Personne::getDatenais(){
    return datenais;
}

float Personne::getPoids(){
    return poids;
}

void Personne::presentation(){
    cout << "=== Information Personnel  ===" << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prenoms: " << prenoms << endl;
    cout << "Date de naissance : " << datenais << endl;
    cout << "Poids : " << poids << endl;
}

Personne::Personne(string nom, string prenoms, string datenais)
{
    this->nom = nom;
    this->prenoms = prenoms;
    this->datenais = datenais;
    poids = 0.1;
}

Personne::~Personne()
{
    cout<<"Destruction du Personne\n";
}

