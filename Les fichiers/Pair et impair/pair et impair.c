#include <stdio.h>
#include <stdlib.h>
// procedure for stock numbers on file
void Typing (char nom[30], int nbr) {
	FILE *pf = NULL;
	int i, elem;
	pf = fopen (nom,"w");
	if (pf == NULL) {
		printf ("Erreur! <%s.txt> <w>",nom);
		exit(1);
	}
	else {
		for (i=0; i<nbr; i++) {
			printf ("Element %d : ",i+1);
			scanf ("%d",&elem);
			fprintf (pf,"%d ",elem);
		}
		fclose (pf);
	}
}
int main(int argc, char *argv[]) {
	FILE *pf = NULL;
	int nbr;
	char nom[30];
	printf ("Donnee le nom de fichier (.TXT): ");
	scanf ("%s",nom);
	printf ("Donnee combien des nombres : ");
	scanf ("%d",&nbr);
	Typing (nom,nbr);
	pf = fopen (nom,"r");
	if (pf == NULL) {
		printf ("Erreur! <%s.txt> <r>",nom);
		exit(1);
	}
	else {
		int test; 
		while (!feof(pf)) {
			fscanf (pf,"%d",&test); // stock number from file to int test
			if (test % 2 != 0) {
				printf ("Le fichier <%s> comporte un ou plusieurs entiere(s) impair.",nom); // if there is impair numbre in the file, the message showing
				fclose (pf);
				exit(0); // if there is impair numbre in the file, the programme exit
			}	
		}
		printf ("Le fichier <%s> comporte que des entiers pairs.",nom); // if there is no impair numbres the message showing
		fclose (pf);
	}
	return 0;
}
