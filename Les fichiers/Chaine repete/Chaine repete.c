#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int stringthree (char c[], char string[]) {
	int i = 0, cmpt = 0;
	while (string[i] != '\0') {
		if (string[i] == c[0]) {
			int j = i+1, k = 1;
			while (c[k] != '\0' && string[j] != '\0') {
				if (string[j] != c[k])
					break;
				else {
					j++;
					k++;
				}
			}
			if (c[k] == '\0') 
				cmpt++;
			i = j;
		}
		else
			i++;
	}
		
	return cmpt;
}
int main(int argc, char *argv[]) {
	FILE *pf = fopen ("source.txt","r");
	if (pf == NULL) {
		printf ("Erreur! <source.txt> mode r.");
		exit (1);
	}
	else {
		char c[10], string[100];
		printf ("Enterz une chaine caractere : ");
		scanf ("%s",c);
		int flag = 0;
		while (fgets (string,100,pf) != NULL) {
			if (stringthree (c,string) == 3) {
				printf ("\n%s",string);
				flag++;
			}
		}
		fclose (pf);
	}	
	return 0;
}
