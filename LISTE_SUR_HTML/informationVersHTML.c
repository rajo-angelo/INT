#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
typedef struct {
    char nom[100];
    char prenom[100];
    char github[100];
    char mail[100];
}Personne;

void EcrireEnHTML(const char *nomFichierExel,const char *nomFichierHTML)
{   
    Personne newInfo;
    FILE *fichierEXEL,*fichierHTML;
    fichierHTML= fopen(nomFichierHTML,"w");
    fichierEXEL = fopen(nomFichierExel, "r");
    char ligne[1024];
    int numeroLigne = 0;
    if(fichierEXEL==NULL || fichierHTML ==NULL)
    {   
        printf("erreur d'ouvertur des fichier!\n");
        exit(1);
    }
        fprintf(fichierHTML,"<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n<meta charset=\"UTF-8\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>test</title>\n<link rel=\"stylesheet\" href=\"style.css\">\n</head>\n<body>\n<table>\n");
        fprintf(fichierHTML,"<h1>LISTE DES ETUDIANTS</h1>\n");
        while (fgets(ligne, sizeof(ligne),fichierEXEL)) {
            numeroLigne++;
            sscanf(ligne," %[^,],%[^,],%[^,],%[^\n]",&newInfo.nom,&newInfo.prenom,&newInfo.github,&newInfo.mail); 
            if(numeroLigne==1)
                fprintf(fichierHTML,"<tr>\n<th>%s</th>\n<th>%s</th>\n<th>%s</th>\n<th>%s</th>\n</tr>\n",newInfo.nom,newInfo.prenom,newInfo.github,newInfo.mail);
            else
                fprintf(fichierHTML,"<tr>\n<td>%s</td>\n<td>%s</td>\n<td>%s</td>\n<td>%s</td>\n</tr>\n",newInfo.nom,newInfo.prenom,newInfo.github,newInfo.mail);
        }
        printf("Fichier bien ouverture\n");
        
        fprintf(fichierHTML,"</table>\n</body>");
        fclose(fichierEXEL);
        fclose(fichierHTML);
}






