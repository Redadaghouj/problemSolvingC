#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int anneeDn, moisDn, jourDn;
	int annee, mois, jour;
	
	do {
	    printf ("Entrez votre date de naissance comme suit (jour/mois/annee): ");
	    scanf ("%d/%d/%d",&jourDn,&moisDn,&anneeDn);
	    if (anneeDn <= 0)
	    	printf ("L'annee que vous avez saisie n'est pas logique. \n");
	    if (moisDn <= 0 || moisDn > 12)
	    	printf ("Le mois que vous avez saisie n'est pas logique. \n");
	    if (jourDn <= 0 || jourDn > 31)
	    	printf ("La jour que vous avez saisie n'est pas logique. \n");
	    if (moisDn == 2 && jourDn > 29)
	    	printf ("Le mois fevrier ne peut exceder 29 jours. \n");
	    if (moisDn == 4 && jourDn > 30)
	    	printf ("Le mois avril ne peut exceder 30 jours. \n");
		if (moisDn == 6 && jourDn > 30)
			printf ("Le mois juin ne peut exceder 30 jours. \n");
		if (moisDn == 9 && jourDn > 30)
			printf ("Le mois septembre ne peut exceder 30 jours. \n");
		if (moisDn == 11 && jourDn > 30)
			printf ("Le mois novembre ne peut exceder 30 jours. \n");
		if (((anneeDn % 4 != 0 && anneeDn % 100 == 0 || anneeDn % 400 != 0) && moisDn == 2 && jourDn > 28))
			printf ("Le mois fevrier de annee %d ne peut exceder 28 jours. \n", anneeDn);
    } while (anneeDn <= 0 || (moisDn <= 0 || moisDn > 12) || (jourDn <= 0 || jourDn > 31) || (moisDn == 2 && jourDn > 29) ||
			(moisDn == 4 && jourDn > 30 || moisDn == 6 && jourDn > 30 ||moisDn == 9 && jourDn > 30 ||moisDn == 11 && jourDn > 30) ||
			((anneeDn % 4 != 0 && anneeDn % 100 == 0 || anneeDn % 400 != 0) && moisDn == 2 && jourDn > 28));
    
    do {
	    printf ("Entrez date en cours comme suit (jour/mois/annee): ");
	    scanf ("%d/%d/%d", &jour,&mois,&annee);
	    if (annee <= 0)
	    	printf ("L'annee que vous avez saisie n'est pas logique. \n");
	    if (annee < anneeDn)
	    	printf ("L'annee que vous avez saisie est inferieure a l'annee de votre naissance. \n");
	    if (mois <= 0 || mois > 12)
	    	printf ("Le mois que vous avez saisie n'est pas logique. \n");
	    if (jour <= 0 || jour > 31)
	    	printf ("La jour que vous avez saisie n'est pas logique. \n");
	    if (mois == 2 && jour > 29)
	    	printf ("Le mois fevrier ne peut exceder 29 jours. \n");
	    if (mois == 4 && jour > 30)
	    	printf ("Le mois avril ne peut exceder 30 jours. \n");
		if (mois == 6 && jour > 30)
			printf ("Le mois juin ne peut exceder 30 jours. \n");
		if (mois == 9 && jour > 30)
			printf ("Le mois septembre ne peut exceder 30 jours. \n");
		if (mois == 11 && jour > 30)
			printf ("Le mois novembre ne peut exceder 30 jours. \n");
		if (((annee % 4 != 0 && annee % 100 == 0 || annee % 400 != 0) && mois == 2 && jour > 28))
			printf ("Le mois fevrier de annee %d ne peut exceder 28 jours. \n", annee);
	} while ((annee <= 0 || annee < anneeDn) || (mois <= 0 || mois > 12) || (jour <= 0 || jour > 31) || (mois == 2 && jour > 29) ||
			(mois == 4 && jour > 30 || mois == 6 && jour > 30 ||mois == 9 && jour > 30 ||mois == 11 && jour > 30) ||
			((annee % 4 != 0 && annee % 100 == 0 || annee % 400 != 0) && mois == 2 && jour > 28));
	
	if (anneeDn == annee && jourDn == jour && moisDn == mois ) {
    	printf ("Cette date est ton date de naissance");
    	exit (0);
	}
    if (jour < jourDn) {
    	if (mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12)
    		jour+=31;
    	else if (mois == 4 || mois == 6 || mois == 9 || mois == 11)
    		jour+=30;
    	else if (mois == 2){
    		if (annee % 4 == 0 && annee % 100 != 0 || annee % 400 == 0)
    			jour+=29;
    		else
    			jour+=28;
		}
    	mois--;
	}
    if (mois < moisDn) {
    	mois+=12;
    	annee--;
	}
	
	annee -= anneeDn;
	mois -= moisDn;
	jour -= jourDn;
	
	printf ("votre age est : %d ans, %d mois, %d jour",annee,mois,jour);
	
	return 0;
}
