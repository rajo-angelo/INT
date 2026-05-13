#pragma once

#include<iostream>
#include<vector>
using namespace std;
class Permi
{
    private:
        string numeroPermis;
        string dateDelivrance;
        string dateExpiration;
        vector<string> categorie;   
        
    public:
        void setnumeroPermis(string);
        void setdateDelivrance(string);
        void setdateExpiration(string);
        void setCategorie(vector<string>);
        string getnumeroPermis();
        string getdateDelivrance();
        string getdateExpiration();
        vector<string> getCategorie();
        void afficherInfo();
        Permi(string numeroPermis, string dateDelivrance, string dateExpiration, vector<string> categorie);
        ~Permi();
};
