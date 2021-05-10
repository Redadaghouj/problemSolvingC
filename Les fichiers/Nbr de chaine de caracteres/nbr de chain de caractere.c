#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search (char fichier[]) {
	FILE *pf = fopen (fichier,"r");
	if (pf == NULL) {
		printf ("Erreur! <source.txt> mode r.");
		return -1;
	}
	else {
		int cmpt = 0;
		char chain[100];
		while (fscanf(pf,"%s",chain) != EOF)
				cmpt++;
		fclose (pf);
		return cmpt;
	}
}
int main(int argc, char *argv[]) {
	char fichier[30];
	printf ("Entrez la nom de fichier (.TXT) : ");
	scanf ("%s",fichier);
	printf ("Le nombre de chain de caracters dans fichier '%s' est : %d",fichier,search(fichier));
			
	return 0;
}
