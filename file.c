#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i=0, j, taille, arr[50];
	// open first file
	FILE *pf1 = NULL;
	pf1 = fopen ("F1.txt","r");
	if (pf1 == NULL) {
		printf ("Erreur! <F1.txt>");
		exit(1);
	}
	else {
		// open second file
		FILE *pf2 = NULL;
		pf2 = fopen ("F2.txt","r");
		if (pf2 == NULL) {
			printf ("Erreur! <F2.txt>");
			fclose (pf1);
			exit(1);
		}
		else {
			// puts all files data in array
			while (!feof(pf1)) {
				fscanf (pf1,"%d",&arr[i]);
				i++;
			}
			fclose (pf1);
			while (!feof(pf2)) {
				fscanf (pf2,"%d",&arr[i]);
				i++;
			}
			fclose (pf2);
			taille = i;
			// start sort the array
			for (i=0; i<taille; i++) {
				for (j=i+1; j<taille; j++) {
					if (arr[i] > arr[j]) {
						int tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}
			// open theerd file
			FILE *pf3 = NULL;
			pf3 = fopen ("F.txt","w");
			if (pf3 == NULL) {
				printf ("Erreur! <F.txt>");
				exit(1);
			}
			// print in the file from the array
			else {
				for (i=0; i<taille; i++)
					fprintf (pf3,"%d ",arr[i]);
			}
			fclose (pf3);
		}
		printf ("\nOperation effectue success ");
	}
	return 0;
}
