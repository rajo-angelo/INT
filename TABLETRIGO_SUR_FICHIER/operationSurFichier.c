#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void ecritureTableTrigo()
{
    FILE *fichier;
    fichier = fopen("./TableTrigo.xlsx","w");

    if(fichier!=NULL)
    {
        printf("Ouverture de fichier reussite\n");
        fprintf(fichier,"degres\tsinus\tcosinus\tangante");
        for (int deg=0;deg<=360;deg++)
        {
            float rad = deg*M_PI/180;
            if(deg==90 || deg==270) fprintf(fichier,"\n%d\t%f\t%f",deg,sin(rad),cos(rad));
            else fprintf(fichier,"\n%d\t%f\t%f\t%f",deg,sin(rad),cos(rad),tan(rad));
        }

        fclose(fichier);
    }
    else
    {
        printf("erreur d'ouvertur de fichier\n");
        exit(1);
    }
}

void lireFicher(const char *leFichier)
{
    FILE *fichier;
    fichier = fopen(leFichier,"r");

    if(fichier!=NULL)
    {
        printf("Fichier bien ouvert!\n");
        while (feof(fichier)==0)
        {
            char ligne[1000];
            fgets(ligne,1000,fichier);
            printf("%s",ligne);
        }
        fclose(fichier);
    }
    else
    {
        printf("erreur d'ouvertur de fichier!\n");
        exit(1);
    }
}
