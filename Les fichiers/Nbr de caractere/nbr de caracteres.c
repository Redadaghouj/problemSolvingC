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
		char caractere;
		while ((caractere = fgetc(pf)) != EOF) {
			if (caractere != '\n')
				cmpt++;
		}
		fclose (pf);
		return cmpt;
	}
}
int main(int argc, char *argv[]) {
	char fichier[30];
	printf ("Entrez la nom de fichier (.TXT) : ");
	scanf ("%s",fichier);
	printf ("Le nombre de caractere dans '%s' est : %d",fichier,search(fichier));
			
	return 0;
}
