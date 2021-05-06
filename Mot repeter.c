#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	char textun[20], textdeux[20];
	int i, j, k;
	printf ("donnee premier text : ");
	scanf ("%s",textun);
	printf ("donnee deuxieme text : ");
	scanf ("%s",textdeux);
	int lenun=strlen(textun);
	int lendeux=strlen(textdeux);
	for (i=0; i<lenun; i++) {
		if (i == 0) 
			goto comp;
			for (j=i-1; j>=0; j--) {
				if (textun[i] == textun[j])
					break;
				if (j == 0) {
					comp :
					for (k=0; k<lendeux; k++) {
						if (textun[i] == textdeux[k]) {
							printf ("la lettre '%c' est repeter a deux mots.\n",textun[i]);
							break;
					}
				}
			}		
		}
	}
return 0;
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
	char textun[20], textdeux[20];
	int i, j, k;
	int drp;
	printf ("donnee premier text : ");
	scanf ("%s",textun);
	printf ("donnee deuxieme text : ");
	scanf ("%s",textdeux);
	int lenun=strlen(textun);
	int lendeux=strlen(textdeux);
	// homme  femme
	for (i=0; i<lenun; i++) {
		drp = 0;
		for (k=i-1; k>=0; k--)
			if (textun[i] == textun[k]) {
				drp = 1;
				break;
			}
		if (drp == 0)
			for (j=0; j<lendeux; j++)
				if (textun[i] == textdeux[j]) {
					printf ("la lettre '%c' est repeter a deux mots.\n",textun[i]);
					break;
				}
	}
return 0;
}
*/
