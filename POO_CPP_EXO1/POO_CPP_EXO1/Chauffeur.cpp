#include"Chauffeur.h"
#include<iostream>
#include<algorithm>
using namespace std;

Chauffeur::Chauffeur(string nom, string prenoms, string datenais, Permi& permi)
    :Personne(nom,prenoms,datenais),
    permi(permi.getnumeroPermis(),permi.getdateDelivrance(),permi.getdateExpiration(),permi.getCategorie())
{

}

Chauffeur::~Chauffeur()
{
    
}

void Chauffeur::conduire(Moto& moto,string option){  
    vector<string> monPermis = permi.getCategorie();
    if (find(monPermis.begin(), monPermis.end(), "A") != monPermis.end()) {
        if (option=="demmarer")
        {
            moto.demmarerMoteur();
        }
        else if(option=="arreter")
        {
            moto.arretMoteur();
        }
        else if (option == "accelerer")
        {
            if(moto.getEtatMoteur())
                cout << "Le chauffeur accélère." << endl;
            else cout<<"Le moteur n'est pas encore marchee\n";
        }
        else if (option == "freiner")
        {
            cout << "Le chauffeur freine." << endl;
        }
        else if ("avancer")
        {
            moto.avancer();
        }
        else if ("retourner")
        {
            moto.retourner();
        }
        else
        {
            cout << "Option inconnue pour conduire." << endl;
        }
    }
    else {
        cout<<"Vous ne pouvez pas conduirer ce moto!\n";
    }

}

void Chauffeur::conduireCammion(Cammion& cammion,string option){
    vector<string> monPermis = permi.getCategorie();
    if (find(monPermis.begin(), monPermis.end(), "C") != monPermis.end()) {
        if (option=="demmarer")
        {
            cammion.demmarerMoteur();
        }
        else if(option=="arreter")
        {
            cammion.arretMoteur();
        }
        else if (option == "accelerer")
        {
            if(cammion.getEtatMoteur())
                cout << "Le chauffeur accélère." << endl;
            else cout<<"Le moteur n'est pas encore marchee\n";
        }
        else if (option == "freiner")
        {
            cout << "Le chauffeur freine." << endl;
        }
        else if ("avancer")
        {
            cammion.avancer();
        }
        else if ("retourner")
        {
            cammion.retourner();
        }
        else
        {
            cout << "Option inconnue pour conduire." << endl;
        }
    }
    else {
        cout<<"Vous ne pouvez pas conduirer ce Cammion!\n";
    }
}

void Chauffeur::setPermiNumber(string num)
{
    permi.setnumeroPermis(num);
}

void Chauffeur::setPermiDelivrance(string date)
{
    permi.setdateDelivrance(date);
}

void Chauffeur::setPermiExpiration(string date)
{
    permi.setdateExpiration(date);
}

void Chauffeur::setPermiCategories(vector<string> cats)
{
    permi.setCategorie(cats);
}


string Chauffeur::getPermiNumber()
{
    return permi.getnumeroPermis();
}

string Chauffeur::getPermiDelivrance()
{
    return permi.getdateDelivrance();
}

string Chauffeur::getPermiExpiration()
{
    return permi.getdateExpiration();
}

vector<string> Chauffeur::getPermiCategories()
{
    return permi.getCategorie();
}


void Chauffeur::afficherPermi()
{
    cout<<" === Information de permis de "<< nom<<"    === \n";
    permi.afficherInfo();
}

void Chauffeur::afficherInfo()
{
    presentation();
    permi.afficherInfo();
}


