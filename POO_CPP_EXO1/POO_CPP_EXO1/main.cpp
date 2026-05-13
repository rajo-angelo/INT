#include"Chauffeur.h"

int main(){
    Permi monPermis = Permi("B12345678","01/01/2020","01/01/2030",{"A","B","C"});
    Moteur moteurMoto = Moteur(110,"A000700T","essence",8);
    Moto moto = Moto("HONDA","CBF","1022 TBF",moteurMoto);
    moto.afficheInfo();

    Moteur moteurCam = Moteur(12,"OD0002485FG","Gasoil",50);
    Cammion cammion = Cammion("KAIAMBA","MERCEDECE","000001 WWT",50000,145265800,moteurCam);
    cammion.afficheInfo();

    Chauffeur chauffeur1 = Chauffeur("RAJOMANDIMBY","Joel Angelo","20/12/2011",monPermis);
    chauffeur1.setPoids(45.3);
    chauffeur1.afficherInfo();
   

    chauffeur1.conduire(moto,"demmarer");
    chauffeur1.conduire(moto,"accelerer");
    chauffeur1.conduire(moto,"avancer");
    chauffeur1.conduire(moto,"freiner");
    chauffeur1.conduire(moto,"arreter");


    chauffeur1.conduireCammion(cammion,"demmarer");
    chauffeur1.conduireCammion(cammion,"accelerer");
    chauffeur1.conduireCammion(cammion,"retourner");
    chauffeur1.conduireCammion(cammion,"freiner");
    chauffeur1.conduireCammion(cammion,"arreter");
    
    return 0;
}

