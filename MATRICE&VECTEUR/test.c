#include<stdio.h>
#include"VECTEUR/vecteur.h"
#include"MATRICE/matrice.h"

int main()
{
    //VECTEURS
    printf("\n\n +++++++++++++ VECTEURS +++++++++++\n\n");
    int dimensionVeceur ,produit_scalaire;
    entreeTailleVeceteur(&dimensionVeceur);
    int *Vecteur1 = remplirVecteur(dimensionVeceur);
    int *Vecteur2 = remplirVecteur(dimensionVeceur);
    int *sommeVecteur = sommeVectorielle(dimensionVeceur,Vecteur1,Vecteur2);
    produit_scalaire = produitScalaire(dimensionVeceur,Vecteur1,Vecteur2);
    resultatVecteur(dimensionVeceur,"Vecteur1","Vecteur2",produit_scalaire,sommeVecteur);

    //MATRICES
    printf("\n\n +++++++++++++ MATRICE +++++++++++\n\n");
    int lignes,collones;
    entreeDimensionMatrice(&lignes,&collones);
    int **Matrice1 = remplirMatrice(lignes,collones);
    int **Matrice2 = remplirMatrice(lignes,collones);
    int **sommeMatrice = sommeMatricielle(lignes,collones,Matrice1,Matrice2);
    afficheMatrice(lignes,collones,sommeMatrice,"Somme matricielle");
    int **produit_matrice = produitMatricielle(lignes,collones,Matrice1,Matrice2);
    afficheMatrice(lignes,collones,produit_matrice,"Produit matricielle");    
 
    return 0;
}