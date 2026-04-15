#include<stdio.h>
#include<stdlib.h>

void entreeTailleVeceteur(int *n)
{
    printf("Entrer la dimension de la vecteur \nn =");
    scanf("%d",n);
}

int *remplirVecteur(int taille)
{
    int *Vecteur =(int*)malloc(taille * sizeof(int));


    if (Vecteur == NULL){
        printf("erreur d'allocation!");
        return NULL;
    }

    for(int i=0;i<taille;i++)
    {
        printf("Vecteur[%d] = ",i);
        scanf("%d",&Vecteur[i]);
    }

    return Vecteur;
}

int *sommeVectorielle(int taille , int *Vecteur1, int *Vecteur2)
{
    int *somme =(int*)malloc(taille * sizeof(int));
    for(int i=0; i<taille;i++)
    {
        somme[i]= Vecteur1[i]+ Vecteur2[i];
    }
    return somme;
}

int produitScalaire(int taille, int *Vecteur1 , int *Vecteur2)
{
    int produit = 0;
    for(int i=0;i<taille;i++)
    {
        produit += Vecteur1[i]*Vecteur2[i];
    }
    return produit;
}

void afficheVecteur(int taille, int *Vecteur,char nomVecteur[])
{
    printf("\n %s est :\n[",nomVecteur);
    for(int i=0;i<taille;i++)
    {
        if(i==taille-1) printf("%d]\n",Vecteur[i]);
        else printf("%d\t",Vecteur[i]);
    }
}

void resultatVecteur(int taille,char nomVecteur1[],char nomVecteur2[], int produit_scalaire,int *sommeVecteur)
{
    printf("le produit saclaire vaut:\n %s x %s = %d\n",nomVecteur1,nomVecteur2,produit_scalaire);
    printf("\n  %s + %s vaut :\n ",nomVecteur1,nomVecteur2);
    afficheVecteur(taille,sommeVecteur,"Somme");
}


