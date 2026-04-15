#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

char *conversation_date(char *andro,char *numero_jours,char *volana,char *annee)
{
	char *resultat=NULL;
	resultat = (char*)malloc((strlen(andro)+strlen(numero_jours)+strlen(volana)+strlen(annee)+4)*sizeof(char));
	strcpy(resultat,andro);
	strcat(resultat," ");
	strcat(resultat,numero_jours);
	strcat(resultat," ");
	strcat(resultat,volana);
	strcat(resultat," ");
	strcat(resultat,annee);

	return resultat;
}

void entreeDate(char *jours,char *numeroJours,char *mois,char *annee)
{
    char text[100];
	printf("Entrez la date (ex: lundi 25 mars 2003) : ");
	fgets(text,100,stdin);
    char *token = strtok(text," ");
    int k=0;
    while(token !=NULL)
    {
        switch (k)
        {
        case 0 :
            strcpy(jours,token);			
            break;

		case 1:
			strcpy(numeroJours,token);					
			break;

        case 2 :
            strcpy(mois,token);			
            break;

        case 3 :
            strcpy(annee,token);
            break;
        
        default:
            break;
        }

        token = strtok(NULL," ");
        k++;
    }
}

char *Andro(const char *jours )
{	
	char JOURS[7][15]= {"lundi","mardi","mercredi","jeudi","vendredi","samedi","dimanche"};
	char ANDRO[7][15]= {"alatsinainy","talata","alarobia","alakamisy","zoma","sabotsy","alahady"};
	char *andro = NULL;
	for (int  i = 0; i < 7; i++)
	{
		if (strcmp(jours,JOURS[i])==0)
		{
			andro=(char*)malloc((strlen(ANDRO[i])+1)*sizeof(char));
			strcpy(andro,ANDRO[i]);
			break;
		}		
	}

	return andro;
}

char *Volana(const char *mois )
{	
	char MOIS[12][15]= {"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};
	char VOLANA[12][15]= {"janoary","febroary","martsa","aprily","mey","jona","jolay","aogositra","septambra","oktobra","novambra","desambra"};
	char *volana = NULL;
	for (int  i = 0; i < 12; i++)
	{
		if (strcmp(mois,MOIS[i])==0)
		{
			volana=(char*)malloc((strlen(VOLANA[i])+1)*sizeof(char));
			strcpy(volana,VOLANA[i]);
			break;
		}		
	}
	
	return volana;
}

