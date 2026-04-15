#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char *creatFichierInforamtion()
{
    char nomInformation[10],*nomRenvoi=NULL;
    printf("Entrez le nom et le type de ficher d'information (ex: Etudiants.txt)\nfichier: ");
    scanf("%s",&nomInformation);
    nomRenvoi = (char*)malloc((strlen(nomInformation)+1)*sizeof(char));
    strcpy(nomRenvoi,nomInformation);
    FILE *fichier;
    fichier =fopen(nomInformation,"w");
    if(fichier!=NULL) 
    {
        fprintf(fichier,"Nom\tPrenoms\tTel\tGenre\n");        
        fclose(fichier);
        return nomRenvoi;
    }
    else {
        printf("erreur sur la creation du ficher");
        exit(1);
        return NULL;
    };
}

void viderligne()
{
    int c;
    c = fgetc(stdin);
    if(c=='\n' || c==EOF) {
        return ;
    }
    ungetc(c,stdin);
    while( (c = getchar())!='\n' && c!=EOF);
}

char *remplierInformaton()
{
    char nom[100],prenoms[100],tel[15],genre[10];
    char *lesInformation=NULL;
    lesInformation = (char*)malloc((strlen(nom)+strlen(tel)+strlen(prenoms)+strlen(genre)+1)*sizeof(char));    
    viderligne();
    printf("\nNom: ");
    fgets(nom,sizeof(nom),stdin);
    nom[strcspn(nom,"\n")] = '\0';
    printf("Prenom(s):");
    fgets(prenoms,sizeof(prenoms),stdin);
    prenoms[strcspn(prenoms,"\n")] = '\0';
    printf("Tel: ");
    fgets(tel,sizeof(tel),stdin);
    tel[strcspn(tel,"\n")] = '\0';
    printf("Genre: ");
    fgets(genre,sizeof(genre),stdin);
    genre[strcspn(genre,"\n")] = '\0';
    lesInformation = (char*)malloc((strlen(nom)+strlen(tel)+strlen(prenoms)+strlen(genre)+4)*sizeof(char));
    strcpy(lesInformation,nom);
    strcat(lesInformation,"\t");
    strcat(lesInformation,prenoms);
    strcat(lesInformation,"\t");
    strcat(lesInformation,tel);
    strcat(lesInformation,"\t");
    strcat(lesInformation,genre);
    lesInformation[strcspn(lesInformation,"\n")]='\0';
    
    return lesInformation;
}

void ajouterInformation(const char *fichierDInformation)
{
    char nom[100],prenoms[100],tel[15],genre[10];
    FILE *fichier;
    fichier = fopen(fichierDInformation,"a");
    if(fichier!=NULL)
    {
        char *lesInfo = remplierInformaton();
        fprintf(fichier,"%s\n",lesInfo);
        free(lesInfo);
        fclose(fichier);       
    } else
    {
        printf("erreur d'ouvertur de fichier %s\n",fichierDInformation);
        exit(1);
    }  
}

void afficherFicherDInformation(const char *leFicherDInformation)
{
    FILE *fichier;
    fichier = fopen(leFicherDInformation,"r");
    if (fichier!=NULL)
    {
        printf("\n-------- LISTE DES INFORMATION SUR %s -------\n\n",leFicherDInformation);
        while(feof(fichier)==0)
        {
            char ligne[1000]="";
            fgets(ligne,sizeof(ligne),fichier);
            printf("%s",ligne);
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur de l'ouverture de %s\n",leFicherDInformation);
        exit(1);
    }   
}

char *rechecheUnInformation(const char *leFichier,const char *element)
{
    FILE *fichier;
    fichier = fopen(leFichier,"r");
    char *InformationTrouveer = NULL;
    if(fichier!=NULL)
    {
        while (feof(fichier)==0)
        {
            char ligne[1000]="",ligneTrouver[1000]="";
            char *unElement;
            fgets(ligne,1000,fichier);
            ligne[strcspn(ligne,"\n")]='\0';
            strcpy(ligneTrouver,ligne);
            unElement = strtok(ligne,"\t");
            if(strcmp(element,unElement) == 0) {
                ligneTrouver[strcspn(ligneTrouver,"\n")]='\0';
                InformationTrouveer = (char*)malloc((strlen(ligneTrouver)+1)*sizeof(char));
                strcpy(InformationTrouveer,ligneTrouver);
                InformationTrouveer[strcspn(InformationTrouveer,"\n")]='\0';
                break;
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur de l'ouverture de fichier!\n");
        exit(1);
    }
    return InformationTrouveer==NULL?"":InformationTrouveer;
}

void modifierLigneParContenu(const char *nomFichier, const char *ancienTexte, const char *nouveauTexte) {
    FILE *fichierOriginal = fopen(nomFichier, "r");
    FILE *fichierTemp = fopen("temp.txt", "w");
    
    if (fichierOriginal == NULL || fichierTemp == NULL) {
        printf("\nErreur sur le chargement sur modification!\n");
        exit(1);
    }
    
    char ligne[1024];
    bool modifie = false;
    
    while (fgets(ligne, sizeof(ligne), fichierOriginal) != NULL) {
        ligne[strcspn(ligne, "\n")] = '\0';
        
        if (strcmp(ligne, ancienTexte) == 0) {
            fprintf(fichierTemp, "%s\n", nouveauTexte);
            modifie = true;
        } else {
            fprintf(fichierTemp, "%s\n", ligne);
        }
    }
    
    fclose(fichierOriginal);
    fclose(fichierTemp);
    
    if (modifie) {
        remove(nomFichier);
        rename("temp.txt", nomFichier);
    }  
    remove("temp.txt");
}

void supprimerUnInformation(const char *nomFichier, const char *ancienTexte) {
    FILE *fichierOriginal = fopen(nomFichier, "r");
    FILE *fichierTemp = fopen("temp.txt", "w");
    if (fichierOriginal == NULL || fichierTemp == NULL) {
        printf("\nErreur de chargement sur la suppresion!\n");
        exit(1);
    }
   
    char ligne[1024];
    bool supprimer = false;
    while (fgets(ligne, sizeof(ligne), fichierOriginal) != NULL) {
        ligne[strcspn(ligne, "\n")] = '\0';
        if (strcmp(ligne, ancienTexte) == 0) {
            supprimer = true;
            continue;
        } else {
            fprintf(fichierTemp, "%s\n", ligne);
        }
    }
    
    fclose(fichierOriginal);
    fclose(fichierTemp);
    if (supprimer) {
        remove(nomFichier);
        rename("temp.txt", nomFichier);
        printf("\n suppresion de %s succes\n",ancienTexte);
    }   
    remove("temp.txt");
}