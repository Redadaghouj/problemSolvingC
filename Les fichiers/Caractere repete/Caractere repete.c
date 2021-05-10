#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int stringthree (char c, char string[]) {
	int i, cmpt = 0;
		for (i=0; i<strlen(string); i++)
			if (string[i] == c)
				cmpt++;
	return cmpt;
}
int main(int argc, char *argv[]) {
	FILE *pf = fopen ("source.txt","r");
	if (pf == NULL) {
		printf ("Erreur! <source.txt> mode r.");
		exit (1);
	}
	else {
		char c, string[30];
		int flag = 0;
		printf ("Enterz un caractere : ");
		scanf (" %c",&c);
		while (fgets (string,30,pf) != NULL) {
			if (stringthree (c,string) == 3) {
				printf ("\n%s",string);	
				flag = 1;
			}
		}
		fclose (pf);
		if (flag == 0)
			printf ("\nAucun !");
	}	
	return 0;
}
