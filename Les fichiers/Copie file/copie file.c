#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *pf1 = NULL;
	pf1 = fopen ("source.txt","r");
	if (pf1 == NULL) {
		printf ("Erreur! <source.txt>");
		exit(1);
	}
	else {
		FILE *pf2 = NULL;
		pf2 = fopen ("copie.txt","w");
		if (pf2 == NULL) {
			printf ("Erreur! <copie.txt>");
			fclose (pf1);
			exit(1);
		}
		else {
			char text[50];
			while (!feof(pf1)) { // ! = not | feof = file end of file | pf1 = is our pointur
				fscanf (pf1,"%s",text); // stock data in char text
				fprintf (pf2,"%s ",text); // print data from char text in our new file <copie.txt>
				
				/* or you can use fonction gets and puts
				gets (text,50,pf1);
				fputs (text,pf2); 		*/
			}
			fclose (pf1);
			fclose (pf2);
			printf ("\n DONE.\n");
		}
	}
	return 0;
}
