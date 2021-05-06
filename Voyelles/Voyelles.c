#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// fonction for compaire if content of char c is voyelle
bool estVoyelle (char c) {
	int i, flag = 0;
	char voyelle[12] = "AEIOUYaeiouy";
	for (i=0; i<12; i++) {
		if (c == voyelle[i]) {
			return true;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return false;
}
int main(int argc, char *argv[]) {
	// open first file
	FILE *pf1 = NULL;
	pf1 = fopen ("source.txt","r");
	if (pf1 == NULL) {
		printf ("Erreur !");
		exit (1);
	}
	else {
		// open second file
		FILE *pf2 = NULL;
		pf2 = fopen ("voyelles.txt","w");
		if (pf2 == NULL) {
			printf ("Erreur !");
			fclose (pf1);
			exit (1);
		}
		else {
			// open theerd file
			FILE *pf3 = NULL;
			pf3 = fopen ("consonnes.txt","w");
			if (pf3 == NULL) {
				printf ("Erreur !");
				fclose (pf1);
				fclose (pf2);
				exit (1);
			}
			else {
				while (!feof(pf1)) {
					char c = fgetc (pf1); // puts content of file source.txt in char c;
					if (estVoyelle(c) == true) // calling the fonction, if return TRUE thats means its voyelle
						fputc (c,pf2);
					else
						if (c != EOF) fputc (c,pf3);
				}
				fclose (pf1);
				fclose (pf2);
				fclose (pf3);
				printf ("\nOperation effectuee avec succes");
			}			
		}
	}
	return 0;
}
