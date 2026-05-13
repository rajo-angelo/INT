#include"Vehicule.h"
#include<iostream>
using namespace std;


Vehicule::Vehicule()
{

}

Vehicule::~Vehicule()
{
    
}

void Vehicule::avancer()
{
    std::cout<<"vehicule avance!**********\n";
}

void Vehicule::retourner()
{
    std::cout<<"Vehicule retourne!\n";
}