#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *pf1 = NULL;
	pf1 = fopen ("F1.txt","r"); // open first file
	if (pf1 == NULL) {
		printf ("Erreur! <F1.txt>");
		exit(1);
	}
	else {
		FILE *pf2 = NULL;
		pf2 = fopen ("F2.txt","r"); // open second file
		if (pf2 == NULL) {
			printf ("Erreur! <F2.txt>");
			fclose (pf1);
			exit(1);
		}
		else {
			FILE *pf = NULL;
			pf = fopen ("F.txt","w"); // open third file
			if (pf == NULL) {
				printf ("Erreur! <F.txt>");
				fclose (pf1);
				fclose (pf2);
				exit(1);
			}
			else {
				char text[50];
				while (!feof(pf1)) { 
					fgets (text,50,pf1); // get ligne from first file and put the data in char text
					fputs (text,pf); // print data inside char text in pf pointeur ( pf point on F.txt )
				}
				fputs ("\n",pf);
				while (!feof(pf2)) {
					fgets (text,50,pf2); // same here with pf2
					fputs (text,pf);
				}
				fclose (pf1);
				fclose (pf2);
				fclose (pf);
				printf ("\n DONE.\n");
			}
		}
	}
	return 0;
}
