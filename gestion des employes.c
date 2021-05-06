#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int i, Nbr2=0;
typedef struct {
	int jour;
	int mois;
	int annee;
}Date;

typedef struct {
	Date daten;
	char nom[30];
	char prenom[30];
	int salaire;	
}Employe;

void info_emp (int Nbr ,Employe info[]) {
	
	if (Nbr2-Nbr > 0)
		printf ("\nNote : \nVous avez deja enregistre %d employe(s). \n\n",Nbr2-Nbr);
	for (i=Nbr2-Nbr ; i<Nbr2 ; i++) {
		printf ("\nLes informations de employe %d : \n\n",i+1);
		printf ("Entrez nom et prenom : ");
		scanf ("%s %s",info[i].prenom ,info[i].nom);
		strlwr(info[i].prenom); strlwr(info[i].nom);
		do {
			printf ("Entrez salaire : ");
			scanf ("%d",&info[i].salaire);
			if (info[i].salaire <= 0)
				printf ("Le salaire ne peut pas etre inferieur ou egal zero. \n");
		} while (info[i].salaire <= 0);
		do {
			printf ("Entrez la date d'embauche (jour/mois/annee): ");
			scanf ("%d/%d/%d",&info[i].daten.jour ,&info[i].daten.mois ,&info[i].daten.annee);
			if (info[i].daten.annee <= 0)
	    	printf ("L'annee que vous avez saisie n'est pas logique. \n");
		    if (info[i].daten.mois <= 0 || info[i].daten.mois > 12)
		    	printf ("Le mois que vous avez saisie n'est pas logique. \n");
		    if (info[i].daten.jour <= 0 || info[i].daten.jour > 31)
		    	printf ("La jour que vous avez saisie n'est pas logique. \n");
		    if (info[i].daten.mois == 4 && info[i].daten.jour > 30)
		    	printf ("Le mois avril ne peut exceder 30 jours. \n");
			if (info[i].daten.mois == 6 && info[i].daten.jour > 30)
				printf ("Le mois juin ne peut exceder 30 jours. \n");
			if (info[i].daten.mois == 9 && info[i].daten.jour > 30)
				printf ("Le mois septembre ne peut exceder 30 jours. \n");
			if (info[i].daten.mois == 11 && info[i].daten.jour > 30)
				printf ("Le mois novembre ne peut exceder 30 jours. \n");
			if (((info[i].daten.annee % 4 != 0 && info[i].daten.annee % 100 == 0 || info[i].daten.annee % 400 != 0) && info[i].daten.mois == 2 && info[i].daten.jour > 28))
				printf ("Le mois fevrier de annee %d ne peut exceder 28 jours. \n", info[i].daten.annee);
		} while (info[i].daten.annee <= 0 || (info[i].daten.mois <= 0 || info[i].daten.mois > 12) || (info[i].daten.jour <= 0 || info[i].daten.jour > 31) || 
			(info[i].daten.mois == 2 && info[i].daten.jour > 29) ||	(info[i].daten.mois == 4 && info[i].daten.jour > 30 || info[i].daten.mois == 6 && info[i].daten.jour > 30 || 
			info[i].daten.mois == 9 && info[i].daten.jour > 30 || info[i].daten.mois == 11 && info[i].daten.jour > 30) ||
			((info[i].daten.annee % 4 != 0 && info[i].daten.annee % 100 == 0 || info[i].daten.annee % 400 != 0) && info[i].daten.mois == 2 && info[i].daten.jour > 28));
	}
}

void afficher_info (int Nbr ,Employe info[]) {
	
	for (i=0 ; i<Nbr2 ; i++) {
		printf ("\nEmployee %d :\n",i+1);
		printf ("\nNom et prenom   : %s %s \n",info[i].prenom ,info[i].nom);
		printf ("Salaire 	: %d DHS\n",info[i].salaire);
		printf ("Date d'embauche : %.2d/%.2d/%d \n",info[i].daten.jour ,info[i].daten.mois ,info[i].daten.annee);
	}
}

void rechercher_emp (int Nbr ,Employe info[]) {
	
	char rechr[30];
	char nom[30];
	int c=0;
	bool trouve = false;
	printf ("Entrez prenom de employee qui vous rechercher : ");
	scanf ("%s",rechr); strlwr(rechr);
	for (i=0 ; i<Nbr2 ; i++) {
		if (strcmp(rechr,info[i].prenom) == 0)	
			c++;	
	}
	if (c == 0)
		goto aucun;
	else if (c == 1) {
		for (i=0 ; i<Nbr2 ; i++) {
			if (strcmp(rechr,info[i].prenom) == 0) {
				found :				
				printf ("\nNom et prenom   : %s %s \n",info[i].prenom ,info[i].nom);
				printf ("Salaire 	: %d DHS\n",info[i].salaire);
				printf ("Date d'embauche : %.2d/%.2d/%d \n",info[i].daten.jour ,info[i].daten.mois ,info[i].daten.annee);
				trouve = true;
				break;
			}}}
	else {
		printf ("Il y a %d personnes avec ce prenom, veuillez egalement entrer le nom de famille. \nEntrez le nom : ",c);
		scanf ("%s",nom); strlwr(nom);
		for (i=0 ; i<Nbr2 ; i++) {
			if (strcmp(nom,info[i].nom) == 0 && strcmp(rechr,info[i].prenom) == 0)
				goto found;
			}}	
	aucun :
	if (trouve == false)
		printf ("\nIl n'y a aucun employe avec ce prenom.\n");
}

int main(int argc, char *argv[]) {
	
	int Nbr=0;
	Employe info[100];
	int choix;
	char rep[10];
	do {
		debut :
		system("cls");
		printf (" \t \t \t \t \t  *****Gestion des employes*****\n\n");
		printf (" 1 : Enregistrer des employes \n 2 : Afficher les informations \n 3 : Rechercher un employe \n 4 : Exit \n\n");
		printf (" Tapez votre choix : ");
		scanf ("%d",&choix);
		system ("cls");
	} while (choix <= 0 || choix > 4);
	if (choix == 1) {
		saisez :
		printf ("\nEntrez nombre des employes : ");
		scanf ("%d",&Nbr);
		Nbr2+=Nbr;
		info_emp(Nbr, info);
		system ("cls");
		printf ("\nVous avez termine de remplir les informations.\n");
		continuer :
		do {
			printf ("\nVoulez-vous continuer (OUI/NON) ? \nReponse: ");
			scanf ("%s",rep); strlwr(rep);
			if (strcmp(rep,"oui") != 0 && strcmp(rep,"non") != 0)
				printf ("\nCette option n'est pas disponible.\n");
		} while (strcmp(rep,"oui") != 0 && strcmp(rep,"non") != 0);
		if (strcmp(rep,"oui") == 0)
			goto debut;
		else {
			finish :
			system ("cls");
			printf ("\n\n\t\t\t*** Nous esperons que vous avez eu une experience agreable, merci. ***\n\n");
			exit (0);
		}}
	else if (choix == 2 || choix == 3) {
		if (Nbr == 0) {
			char reponse[10];
			printf ("\nIl n'y a aucune information. Voulez-vous saisir a nouveau les informations (OUI/NON) ? \nReponse: ");
			scanf ("%s",reponse); strlwr(reponse);
			if (strcmp(reponse,"oui") == 0) {
				system ("cls");
				goto saisez;
			}
			else 
				goto continuer;
		}
		else {
			if (choix == 2) {
				system ("cls");
				afficher_info(Nbr, info);
				goto continuer;
			}
			else {
				system ("cls");
				rechercher_emp(Nbr, info);	
				goto continuer;
			}}}
	else
		goto finish;

return 0;
}
