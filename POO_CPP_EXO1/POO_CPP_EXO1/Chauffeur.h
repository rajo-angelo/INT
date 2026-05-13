#pragma once

#include"Personne.h"
#include"Permi.h"
#include"Moto.h"
#include"Cammion.h"

class Chauffeur : public Personne
{
    private:
        Permi permi;
        
    public:
        Chauffeur(string nom, string prenoms, string datenais,Permi& permi);
        ~Chauffeur();
       
        void setPermiNumber(string num);
        void setPermiDelivrance(string date);
        void setPermiExpiration(string date);
        void setPermiCategories(vector<string> cats);
        
        string getPermiNumber();
        string getPermiDelivrance();
        string getPermiExpiration();
        vector<string> getPermiCategories();  
        void afficherInfo(); 
        void afficherPermi();
        void conduire(Moto& moto,string option);
        void conduireCammion(Cammion& cammion,string option);
};