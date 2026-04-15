#include<stdio.h>
#include"information.h"
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    char *fichierDInformation = NULL;
    bool operation=true;
    do
    {
       int choix;
       char nom[50]="",chemain[100]="";;
       printf("\n ---------\n Choix sur le fichier :\n 0-Quitter\n1-changer le fichier d'information\n2-Ajouter un information sur %s\n3-chercher un information sur %s\n4-Modifier un information sur %s\n5-supprimer un information sur %s\n6-affichier la liste sur %s\n7-creer nouveau fichier d'information \n----------- \n  Votre choix: ",fichierDInformation,fichierDInformation,fichierDInformation,fichierDInformation,fichierDInformation);
       scanf("%d",&choix);
       switch (choix)
       {
        case 0:
            operation =false;
            break;

        case 1:       
            free(fichierDInformation);
            printf("\nCHANGEMENT DE FICHIER\n");
            printf("Entrer le chemin ou le nom de votre fichier : ");
            scanf("%s",&chemain);
            fichierDInformation = (char*)malloc((strlen(chemain)+1)*sizeof(char));
            strcpy(fichierDInformation,chemain);      
            break;

        case 2:
            printf("\nNOUVELLE INFORMATION\n");
            ajouterInformation(fichierDInformation);
            break;

        case 3:
            printf("\nRECHERCHE\n");
            printf("Entrer le nom : ");
            scanf("%s",&nom);
            char *resultatRecherche = rechecheUnInformation(fichierDInformation,nom);
            if (rechecheUnInformation) printf("\n%s",resultatRecherche);
            free(resultatRecherche);
            
            break;

        case 4:
            printf("\nMODIFICATION\n");
            printf("\nEntrer le nom sur l'information modifier : ");
            scanf("%s",&nom);
            char *resultatRecherchemodifier = rechecheUnInformation(fichierDInformation,nom);
            char *newInformation = remplierInformaton();
            modifierLigneParContenu(fichierDInformation,resultatRecherchemodifier,newInformation);
            free(newInformation);
            free(resultatRecherchemodifier);
            break;
        
        case 5:
            printf("\nSUPPRESSION\n");
            printf("\nRecherche nom sur l'information supprimer: ");
            scanf("%s",&nom);
            char *resultatRechercheSuppr = rechecheUnInformation(fichierDInformation,nom);
            printf("\n%s",resultatRecherche);
            supprimerUnInformation(fichierDInformation,resultatRechercheSuppr);
            free(resultatRechercheSuppr);
            break;

        case 6:
            afficherFicherDInformation(fichierDInformation);
            break;
        case 7:
            free(fichierDInformation);       
            strcpy(fichierDInformation,creatFichierInforamtion());
            break;
       default:
        break;
       } 
    } while (operation);
    
    free(fichierDInformation);
    return 0;
}