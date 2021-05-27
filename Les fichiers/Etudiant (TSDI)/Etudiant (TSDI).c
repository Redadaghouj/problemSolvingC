#include <stdio.h>
#include <stdlib.h>
int j=0;
typedef struct {
	int CNE;
	char nom[30],
	prenom[30];
}etudiant;

void Ecriture (etudiant etd) {
	FILE *pf = fopen ("info.txt","a");
	printf ("\nEtudiant %d : \n",++j);
	printf ("\t    CNE : ");
	scanf ("%d",&etd.CNE);
	printf ("\t    Prenom : ");
	scanf ("%s",etd.prenom);
	printf ("\t    Nom : ");
	scanf ("%s",etd.nom);
	fprintf (pf,"%d %s %s\n",etd.CNE,etd.prenom,etd.nom);
	fclose (pf);
}

void Lecture (etudiant etd, FILE *pf) {
	j = 0;
	pf = fopen ("info.txt","r");
	while (fscanf (pf,"%d %s %s",&etd.CNE,etd.prenom,etd.nom) != EOF) {
		printf ("Etudiant %d : ",++j);
		printf ("\n\t    CNE : %d\n\t    Prenom : %s\n\t    Nom : %s\n\n",etd.CNE,etd.prenom,etd.nom);
	}
	fclose (pf);
}

void rechercher (etudiant etd, FILE *pf, int rech) {
	int flag = 0;
	pf = fopen ("info.txt","r");
	while (fscanf (pf,"%d %s %s",&etd.CNE,etd.prenom,etd.nom) != EOF) {
		if (etd.CNE == rech) {
			printf ("\nCNE    : %d\nPrenom : %s\nNom    : %s\n\n",etd.CNE,etd.prenom,etd.nom);
			flag = 1;
		}
	}
	fclose (pf);
	if (flag == 0)
		printf ("\nCNE %d n'est pas exister\n\n",rech);
}

void modification (etudiant etd, FILE *pf, int cne2) {
	int flag = 0;
	pf = fopen ("info.txt","r");
	FILE *pf2 = fopen ("info2.txt","a");
	while (fscanf (pf,"%d %s %s",&etd.CNE,etd.prenom,etd.nom) != EOF) {
		if (cne2 != etd.CNE)
			fprintf (pf2,"\n%d %s %s",etd.CNE,etd.prenom,etd.nom);
		else {
			printf ("\nNouveau CNE : ");
			scanf ("%d",&etd.CNE);
			printf ("Nouveau Prenom : ");
			scanf ("%s",etd.prenom);
			printf ("Nouveau Nom : ");
			scanf ("%s",etd.nom);
			fprintf (pf2,"\n%d %s %s",etd.CNE,etd.prenom,etd.nom);
			flag = 1;
		}
	}
	fclose (pf);
	fclose (pf2);
	remove ("info.txt");
	rename("info2.txt","info.txt");
	system ("cls");
	if (flag == 0)
		printf ("\nCNE %d n'est pas exister\n\n",cne2);	
}

void suppression () {
	remove ("info.txt");
}

int main(int argc, char *argv[]) {
	etudiant etd;
	FILE *pf;
	int rech, cne2, nbr, i;
	printf ("\t*** Ecriture ***\n\n");
	printf ("Entrez le nombre de etudiant : ");
	scanf ("%d",&nbr);
	for (i=0; i<nbr; i++)
		Ecriture (etd);
	system ("cls");
	printf ("\t*** Lecture ***\n\n");
	Lecture (etd,pf);
	printf ("\t*** Recherche ***\n");
	printf ("\nSaisez CNE de etudiant : ");
	scanf ("%d",&rech);
	rechercher (etd,pf,rech);
	printf ("\t*** Modification ***\n");
	printf ("\nSaisez CNE de etudiant pour modifie : ");
	scanf ("%d",&cne2);
	modification (etd,pf,cne2);
	printf ("\t*** Lecture ***\n");
	Lecture (etd,pf);
	//suppression ();
	printf ("\nLe fichier est supprimer.");
	return 0;
}
