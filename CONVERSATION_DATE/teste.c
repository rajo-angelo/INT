#include<stdio.h>
#include"conversation.h"

int main()
{
    char jours[20],mois[20],numeroJours[4],annee[6];
    entreeDate(jours,numeroJours,mois,annee);
	char *andro= Andro(jours);
	char *volana= Volana(mois);
	char *resultat = conversation_date(andro,numeroJours,volana,annee);
    printf("\n\nResultat : %s",resultat);

	return 0;	
}