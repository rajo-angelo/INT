#include<stdio.h>
#include"resolution.h"

int main()
{
    float borneinferiuer,bornesuperieur,erreur;
    entreeBorne(&borneinferiuer,&bornesuperieur,&erreur);
    printf("La solution dichotomie est : f(%f) = %f \n",dichotomie(borneinferiuer,bornesuperieur,erreur),f(dichotomie(borneinferiuer,bornesuperieur,erreur)));
    printf("La solution Descarts est : f(%f) = %f \n",methode_de_Descarte(borneinferiuer,bornesuperieur,erreur),f(methode_de_Descarte(borneinferiuer,bornesuperieur,erreur)));
    printf("La solution Newton est : f(%f) = %f \n",methode_de_Newton(borneinferiuer,bornesuperieur,erreur),f(methode_de_Newton(borneinferiuer,bornesuperieur,erreur)));
    return 0;
}
