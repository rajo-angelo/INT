#include<stdio.h>
#include<stdlib.h>

void entreeDimensionMatrice(int *n,int * m)
{
    printf("Entrer le nombre de lignes de la Matrice \nlignes =");
    scanf("%d",n);
    printf("Entrer le nombre de collons de la Matrice \ncollons =");
    scanf("%d",m);
}

int **remplirMatrice(int lignes,int collones)
{
    int **Matrice =(int**)malloc(lignes * sizeof(int));
    for(int i=0;i<lignes;i++)
    {
        Matrice[i]= (int*)malloc(lignes*sizeof(int));
        for(int j=0;j<collones;j++)
        {
            printf("Matrice[%d][%d] = ",i,j);
            scanf("%d",&Matrice[i][j]);
        }
    }
    return Matrice;
}

int **sommeMatricielle(int lignes,int collones,int **Matrice1,int **Matrice2)
{
    int **somme =(int**)malloc(lignes * sizeof(int));
    for(int i=0; i<lignes;i++)
    {
        somme[i] =(int*)malloc(collones * sizeof(int));
        for(int j=0; j<collones;j++)
        {
            somme[i][j]= Matrice1[i][j]+ Matrice2[i][j];
        }
    }
    return somme;
}

int **produitMatricielle(int lignes,int collones, int **Matrice1 , int **Matrice2)
{
    int **produit = (int**)malloc(lignes * sizeof(int));
    for(int i=0;i<lignes;i++)
    {
        produit[i] = (int*)malloc(collones*sizeof(int));
        for(int k=0;k<lignes;k++)
        {
            produit[i][k]=0;
            for(int j=0;j<collones;j++)
            {
                produit[i][k]+=Matrice1[i][j]*Matrice2[j][k];
            }
        }
    }
    return produit;
}

void afficheMatrice(int lignes,int collones, int **Matrice,char nomMatrice[])
{
    printf("\n %s est :\n",nomMatrice);
    for(int i=0;i<lignes;i++)
    {
        printf("[");
        for (int j=0;j<collones;j++)    
        {        
            if(j==collones-1) printf("%d]\n",Matrice[i][j]);
            else printf("%d\t",Matrice[i][j]);
        }
    }
}





