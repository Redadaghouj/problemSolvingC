#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int *taillepl=malloc(sizeof(int));
	int *taille=malloc(sizeof(int));
	printf ("entrez la taille de tableau : ");
	scanf ("%d",taille);
	
	float *T=malloc(*taille*sizeof(float));
	printf ("saisez les elements de tableau : \n");
	int i;
	float *S=malloc(sizeof(float));
	*S=0;
	for (i=0 ; i<*taille ; i++) {
		printf ("element %d : ",i+1);
		scanf ("%f",T+i);
		*S=*S+*(T+i);
	}
	float *M=malloc(sizeof(float));
	*M=*S/ *taille;
	printf ("la moyennne est : %.2f \n",*M);
	char R[10];
	do {
		printf ("Veux-tu ajouter d'autres elements (OUI/NON) ?\n");
		scanf ("%s",R);
		strlwr(R);
		if (strcmp(R,"oui")!=0) {
			printf ("Merci");
			exit(0);
		}
		else {
			printf ("entrez le nombre de elements a ajouter : ");
			scanf ("%d",taillepl);
			*taille+=*taillepl;
			T=realloc(T,*taille*sizeof(int));
			for (i=0 ; i<*taille-*taillepl ; i++)
				printf ("element %d : %.2f \n",i+1,*(T+i));
			printf ("saisir les nouveaux elements : \n");
			for (i=*taille-*taillepl ; i<*taille ; i++) {
				printf ("element %d : ",i+1);
				scanf ("%f",T+i);
				*S+=*(T+i);
			}
			*M=*S/ *taille;
			printf ("la moyennne est : %.2f \n",*M);			
		}
	} while (strcmp(R,"oui")==0);
	
	free(taille);
	free(taillepl);
	free(T);
	free(S);
	free(M);
	
	return 0;
}
