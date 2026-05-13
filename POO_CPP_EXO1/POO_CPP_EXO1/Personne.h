#pragma once


#include<iostream>
using namespace std;
class Personne
{
    protected:
        string nom;
        string prenoms;
        string datenais;
        float poids;
        
    public:      
        Personne( string nom, string prenoms, string datenais);
        ~Personne();
        void setNom(string nom);
        void setPrenom(string prenom);
        void setDatenais(string datenais);
        void setPoids(float poids);   
        string getNom();
        string getPrenom();
        string getDatenais();
        float getPoids();
        void presentation();
};







