#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// gloabl declaration
int i;
// fonction for dynamic memory allocation and stock int val in array
int* alloue_vecteur (int dimension, int val) {
	int *tab = malloc(dimension*sizeof(int));
	for (i=0; i<dimension; i++)
		*(tab+i)=val;
	return tab;
}
// procedure for display the array
void affiche_valeur (int *tab, int dimension) {
	for (i=0; i<dimension; i++)
		printf ("\nElement %d = %d",i+1,*(tab+i));
}
// edit array by value chosen from user
int modifier_valeur (int *tab, int indice, int nouvelle_val) {
	*(tab+indice-1) = nouvelle_val;
	return tab; 
}
// search for value chosen from user
int recherche_valeur (int *tab, int dimension) {
	int valeurX;
	bool trouve = false;
	printf ("\n\nRecherche : \n");
	printf ("\nEntrez une valeur : ");
	scanf ("%d",&valeurX);
	for (i=0; i<dimension; i++) {
		if (valeurX == *(tab+i)) {
			printf ("L'indice de %d est : %d\n",valeurX,i+1);
			trouve = true; // like notification that the number has been found
		}
	}
	if (trouve == false) // thats means that the number doesn't exist
		printf ("\nLa valeur %d n'existe pas.",valeurX);
	return i;
}
// delete number from array
int supp_valeur (int *tab, int *dimension, int indice) {
	for (i=indice-1; i<*dimension; i++) // i start from indice-1 because my array started from zero '0'
		*(tab+i) = *(tab+i+1);
	*dimension -= 1; // short hand of *dimension = *dimension -1;
	return tab; 
}
// free array
int* liberer_tab(int *tab, int dimension) {
	free(tab);
	return tab;
}
int main(int argc, char** argv) {
	int *tab, dimension, val, indice, nouvelle_val;
	printf ("Entrez la taille de tableau : ");
	scanf ("%d",&dimension);
	printf ("Entrez une valeur : ");
	scanf ("%d",&val);
	tab = alloue_vecteur(dimension, val);
	affiche_valeur(tab, dimension);
	printf ("\n\nModification : \n");
	printf ("\nEntrez une nouvelle valeur : ");
	scanf ("%d",&nouvelle_val);
	do {
		printf ("Choiser l'indice : ");
		scanf ("%d",&indice);
	} while (indice <= 0 || indice > dimension);
	tab = modifier_valeur(tab, indice, nouvelle_val);
	affiche_valeur(tab, dimension);
	recherche_valeur(tab,dimension);
	printf ("\n\nSuppression : \n");
	do {
		printf ("\nChoiser l'indice : ");
		scanf ("%d",&indice);
	} while (indice <= 0 || indice > dimension);
	tab = supp_valeur(tab,&dimension,indice);
	affiche_valeur(tab,dimension);
	tab = liberer_tab(tab,dimension);
	return 0;
}

