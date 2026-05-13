#include"Permi.h"
#include<iostream>
#include<vector>
using namespace std;

void Permi::setnumeroPermis(string numeroPermis)
{
    this->numeroPermis = numeroPermis;
}

void Permi::setdateDelivrance(string dateDelivrance)
{
    this->dateDelivrance = dateDelivrance;
}

void Permi::setdateExpiration(string dateExpiration)
{
    this->dateExpiration = dateExpiration;
}

void Permi::setCategorie(vector<string> categories)
{
    this->categorie = categories;
}

string Permi::getnumeroPermis()
{
    return numeroPermis;
}

string Permi::getdateDelivrance()
{
    return dateDelivrance;
}

string Permi::getdateExpiration()
{
    return dateExpiration;
}

vector<string> Permi::getCategorie()
{
    return categorie;
}

void Permi::afficherInfo()
{
    cout << "Numéro permis: " << numeroPermis<< endl;
    cout << "Date délivrance: " << dateDelivrance << endl;
    cout << "Date expiration: " << dateExpiration << endl;
    cout << "Catégories: ";
    vector<string> cats = categorie;
    for(string c : cats)
    {
        cout << c << " ";
    }
    cout << endl;
}

Permi::Permi(string numeroPermis, string dateDelivrance, string dateExpiration, vector<string> categorie)
{
    this->numeroPermis = numeroPermis;
    this->dateDelivrance = dateDelivrance;
    this->dateExpiration = dateExpiration;
    this->categorie = categorie;
}

Permi::~Permi()
{
    cout<<"Destruction du Permi\n";
}