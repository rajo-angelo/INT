#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include"conversation.h"

void date(int*numeroJours,int*numeroMois,int*annee);
bool  estBisxt(int annee);
int *nombres_des_jours(int annee);	
char *lemois(int numeroMois);
char *lejours(int numeroJours,int numeroMois,int annee,int nombreJourParMois[12]);
void cretionCalendrier(int annee, int *nombreJours);
int dacalageDate(int jourActuel, int moisActuel , int anneeActuel,int jourEstimer, int moisEstimer, int anneeEstimer);

int main()
{
    printf("\n la jours restant est : %d\n",dacalageDate(1,1,2024,31,12,2025));
    // int numeroJours=12,numeroMois=04,annee=2026;
    // date(&numeroJours,&numeroMois,&annee);
    // int *nombreJourParMois = nombres_des_jours(annee);
    // char *jours = lejours(numeroJours,numeroMois,annee,nombreJourParMois);
    // char *mois = lemois(numeroMois);
    // char jourChar[3];
    // char anneeChar[5];
    // itoa(annee,anneeChar,10);//conversation annee en char sous le nom anneeChar
    // itoa(numeroJours,jourChar,10);
    // printf("\n En francais : %s \n",conversation_date(jours,jourChar,mois,anneeChar));
    // printf("\n Malagasy : %s",conversation_date(Andro(jours),jourChar,Volana(mois),anneeChar));
    // cretionCalendrier(annee,nombreJourParMois);

    // free(nombreJourParMois);
    // free(jours);
    // free(mois);
	return 0;
}

void date(int*numeroJours,int*numeroMois,int*annee)
{
	printf(" jours ");
	scanf("%d",numeroJours);
	printf(" mois ");
	scanf("%d",numeroMois);
	printf(" annee ");
	scanf("%d",annee);
	printf("\n %d/%d/%d \n",*numeroJours,*numeroMois,*annee);
}

bool estBisxt(int annee)
{
	if(annee%4==0 && annee%100!=0)
		return true;
	else
	{
		if(annee%400==0)
			return true;
		else 
			return false;
	}
    
}


int *nombres_des_jours(int annee)
{
    int njm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int *nombreJourParMois=NULL;
    nombreJourParMois = (int*)malloc(12*sizeof(int));
    if(estBisxt(annee))
    {
        njm[1]=29;
    }
    for (int i = 0; i < 12; i++)
    {
        nombreJourParMois[i]=njm[i];
    }
    return nombreJourParMois;
}


char *lemois(int numeroMois)
{   
    char MOIS[13][20]={"","janvier","fevrier","mars","avril","mai","juin","juillet","auot","septembre","octobre","novembre","decembre"};
    char *mois = (char*)malloc((strlen(MOIS[numeroMois])+1)*sizeof(char));
    strcpy(mois,MOIS[numeroMois]);
    return mois ;
} 



int premier_jours(int annee)
{
	int r =annee%28;
	if(r==2 || r==8 ||  r==13 || r==19)
		return 0;//lundi
	if(r==3 || r==14 ||  r==20 || r==25)
		return 1;//mardi
	if(r==4 || r==9 ||  r==15 || r==26)
		return 2;//mercredi
	if(r==10 || r==16 ||  r==21 || r==27)
		return 3;//jeudi
	if(r==0 || r==3 ||  r==11 || r==22)
		return 4;//vendredi
	if(r==6 || r==12 ||  r==17 || r==23)
		return 5;//samedi
    if(r==1 || r==7 ||  r==18 || r==24)
		return 6;//dimanche
}


char *lejours(int numeroJours,int numeroMois,int annee,int nj[12])
{
	int AQ=numeroJours;
	for (int i=0;i<numeroMois-1;i++)
	{
		AQ=AQ+nj[i];
	}
    char JOURS[7][15]= {"lundi","mardi","mercredi","jeudi","vendredi","samedi","dimanche"};
    char *jours = (char*)malloc((strlen(JOURS[(AQ-1+premier_jours(annee))%7])+1)*sizeof(char));
    strcpy(jours,JOURS[(AQ-1+premier_jours(annee))%7]);
    return jours;
}

void cretionCalendrier(int annee, int *nombreJours){ 
    int indexPremier = premier_jours(annee);
    int tabulation=indexPremier+1;  
    char MOIS[12][20]={"janvier","fevrier","mars","avril","mai","juin","juillet","auot","septembre","octobre","novembre","decembre"};   
    for (int i = 1; i <=12 ; i++){
        printf("\n\n ------------ \n %s\n",MOIS[i-1]);

        printf("L\tM\t M\tJ\tV\tS\tD\n");
         for(int numeroJours = 1;numeroJours<=nombreJours[i-1]+indexPremier;numeroJours++){
           
            if (tabulation==8) {
                tabulation = 1;
                printf("\n");
            }  
            if(numeroJours<=indexPremier) { 
                printf("\t");
            }
            else {
                printf("%d\t",numeroJours-indexPremier);            
                tabulation +=1;
            }                    
        }
        if(tabulation==8) tabulation = 1;
        indexPremier = tabulation-1;
    }
}


int dacalageDate(int jourActuel, int moisActuel , int anneeActuel,int jourEstimer, int moisEstimer, int anneeEstimer)
{
    int jourRestant=0;
    int decalageAnnee = anneeEstimer-anneeActuel;
    printf("\n decalage annee : %d \n",decalageAnnee);
    int nombreJoursActuel = 365;
    int nombreJoursEstimer = 0;
    int njm[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=1; i<decalageAnnee;i++)
    {     
        if(estBisxt(anneeActuel+i)) jourRestant += 365;
        else jourRestant += 366;
    }
    if(estBisxt(anneeEstimer)) njm[1]=29;  
    for(int i=0;i<moisEstimer;i++) nombreJoursEstimer += njm[i]; 
    njm[1]=28;

    if(estBisxt(anneeActuel)) {
        njm[1]=29;
        nombreJoursActuel = 366;
    }
    for(int i=0;i<moisActuel;i++) nombreJoursActuel -= njm[i];
    njm[1]=28;

    jourRestant += nombreJoursActuel - jourActuel+nombreJoursEstimer+jourActuel;
    return jourRestant;
}

int resteSecond(int second,int minutes, int heur)
{
    return 24*3600-(heur*3600+minutes*60+second);
}

int secondEstimer(int second, int minutes, int heur)
{
    return heur*3600+minutes*60+second;
}