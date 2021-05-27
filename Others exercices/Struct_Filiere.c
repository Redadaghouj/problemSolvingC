#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int flag=0, taille2=0, cmpt=0;;
typedef struct {
	int code_filiere;
	char nom_filiere[30];
}Filiere;
Filiere tab2[100];
Filiere lecture (Filiere fil) {
	printf ("\nSaisez les informations : \n");
	debut :
	printf ("\tCode de filiere : ");
	scanf ("%d",&fil.code_filiere);
	if (taille2 != 0) {
		int j=0;
		do {
			if (fil.code_filiere == tab2[j].code_filiere) {
				printf ("\t\tCode deja exister !\n");
				goto debut;
			}
			else 
				j++;
		} while (j != taille2);
	}
	printf ("\tNom de filiere : ");
	scanf ("%s",fil.nom_filiere);
	taille2++;
	return fil;
}
void affichage (Filiere *pfil) {
	printf ("\nLes informations : \n");
	printf ("\tCode de filiere : %d \n",pfil->code_filiere);
	printf ("\tNom de filiere : %s \n",pfil->nom_filiere);
}
int search (Filiere *pfil, int code) {
	if (flag == 0) {
		if (code == (pfil+cmpt)->code_filiere) {
			printf ("\tFiliere de CODE '%d' est %s \n",(pfil+cmpt)->code_filiere,(pfil+cmpt)->nom_filiere);
			flag = 1;
		}
	}
	return flag;
}
Filiere tri (Filiere *pfil, int taille) {
	char change[30];
	int cmpt2, i;
	for (i=0; i<taille; i++) {
		for (cmpt=i+1; cmpt<taille; cmpt++) {
			if ((pfil+i)->code_filiere > (pfil+cmpt)->code_filiere) {
				cmpt2 = (pfil+i)->code_filiere;
				(pfil+i)->code_filiere = (pfil+cmpt)->code_filiere;
				(pfil+cmpt)->code_filiere = cmpt2;
				strcpy(change,(pfil+i)->nom_filiere);
				strcpy((pfil+i)->nom_filiere,(pfil+cmpt)->nom_filiere);
				strcpy((pfil+cmpt)->nom_filiere,change);
			}
		}
	}
	return *pfil;
}
int main(int argc, char *argv[]) {
	int taille, code, i;
	Filiere fil;
	printf ("Entrez la taille de tableau : ");
	scanf ("%d",&taille);
	printf ("\n**** Lecture ****\n");
	Filiere tab[taille];
	Filiere *pfil = tab; 
	for (i=0; i<taille; i++) {
		tab[i] = lecture (fil);
		tab2[i] = tab[i];
	}
	system ("cls");
	printf ("\n**** Affichage ****\n");
	for (i=0; i<taille; i++)
		affichage (&pfil[i]);
	printf ("\n**** Recherche ****\n");
	printf ("\nEntrez le numero que vous recherchez : ");
	scanf ("%d",&code);
	for (i=0; i<taille; i++) {
		search (&pfil[i],code);
		if (search(pfil,code) == 1)
			break;
	}
	if (search(pfil,code) == 0)
		printf ("\tCode '%d' n'existe pas.\n",code);
	printf ("\n**** Trie ****\n");
	tri (pfil,taille);
	for (i=0; i<taille; i++)
		affichage (&pfil[i]);
	
	return 0;
}
