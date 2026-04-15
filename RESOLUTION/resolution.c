#include<stdio.h>
#include<math.h>

float f(float x)
{
    return (exp(-x)-x)/x;
}

float approximation_derivee(float x)
{
    float h=0.000001;
	return ((f(x+h)-f(x))/h);
}

void entreeBorne(float *borneinferiuer, float *bornesuperieur, float *erreur)
{
    do
    {   
        printf("\nEntrez les bornes d'intervalle qu'on admet la solution\n"); 
        printf("borne inferieur : ");
        scanf("%f",borneinferiuer);
        printf("borne superieur: ");
        scanf("%f",bornesuperieur);
    }while (f(*borneinferiuer)*f(*bornesuperieur)>0);

    
    printf("Entrez l'erreur d'approximation: ");
    scanf("%f",erreur);
}

float dichotomie(float borneinferiuer,float bornesuperieur,float erreur)
{
    float solution;
    do
    {
        solution = (borneinferiuer+bornesuperieur)/2;
        if (f(solution)*f(borneinferiuer)>0) borneinferiuer = solution;
        else bornesuperieur = solution;
    } while(fabs(f(solution))>erreur);

    return solution;
}

float methode_de_Descarte(float borneinferiuer,float bornesuperieur,float erreur)
{
   float solution;
   while(fabs(bornesuperieur - borneinferiuer)>erreur)
   {
    solution = bornesuperieur - f(bornesuperieur)*(bornesuperieur - borneinferiuer)/(f(bornesuperieur) - f(borneinferiuer));
    borneinferiuer = bornesuperieur;
    bornesuperieur = solution;
   }
   return solution;
}

float methode_de_Newton(float borneinferiuer,float bornesuperieur,float erreur)
{
    float solution ;
    float fixe = f(borneinferiuer)*approximation_derivee(approximation_derivee(borneinferiuer));
    if (fixe>0) bornesuperieur = borneinferiuer;
    while (fabs(f(bornesuperieur))>erreur)
    {
        solution = bornesuperieur - f(bornesuperieur)/approximation_derivee(bornesuperieur);
        bornesuperieur = solution;
    }

    return solution;
}

