#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int j = 0, i;
typedef struct {
	int code,
	prix;
	char nom[30];
}Livre;

void Enregistrer_Livre (Livre lvr, int nbr){
	FILE *pf = fopen ("Livre.txt","a");
	for (i=0; i<nbr; i++) {
		printf ("\nLivre %d : \n",++j);
		printf ("\tCode : ");
		scanf ("%d",&lvr.code);
		printf ("\tNom  : ");
		scanf ("%s",lvr.nom);
		printf ("\tPrix : ");
		scanf ("%d",&lvr.prix);
		fprintf (pf,"\n%d %s %d",lvr.code,lvr.nom,lvr.prix);
	}
	fclose (pf);
}
void Insertion_Livre (Livre lvr) {
	FILE *pf = fopen ("Livre.txt","a");
	printf ("\nLivre %d : \n",++j);
	printf ("\tCode : ");
	scanf ("%d",&lvr.code);
	printf ("\tNom  : ");
	scanf ("%s",lvr.nom);
	printf ("\tPrix : ");
	scanf ("%d",&lvr.prix);
	fprintf (pf,"\n%d %s %d",lvr.code,lvr.nom,lvr.prix);
	fclose (pf);
}
void Modifier_Livre (Livre lvr, int codeX) {
	int flag = 0;
	FILE *pf = fopen ("Livre.txt","r");
	FILE *pf2 = fopen ("Livre2.txt","a");
	while (fscanf (pf,"%d %s %d",&lvr.code,lvr.nom,&lvr.prix) != EOF) {
		if (codeX != lvr.code)
			fprintf (pf2,"\n%d %s %d",lvr.code,lvr.nom,lvr.prix);
		else {
			printf ("\nNouveau Nom : ");
			scanf ("%s",lvr.nom);
			printf ("Nouveau Prix  : ");
			scanf ("%d",&lvr.prix);
			fprintf (pf2,"\n%d %s %d",lvr.code,lvr.nom,lvr.prix);
			flag = 1;
		}
	}
	fclose (pf);
	fclose (pf2);
	remove ("Livre.txt");
	rename("Livre2.txt","Livre.txt");
	if (flag == 0)
		printf ("\nCode %d n'est pas exister\n\n",codeX);	
}
void Update_Livre (Livre lvr) {
	FILE *pf = fopen ("Livre.txt","r");
	FILE *pf2 = fopen ("Livre2.txt","a");
	while (fscanf (pf,"%d %s %d",&lvr.code,lvr.nom,&lvr.prix) != EOF) {
		if (lvr.prix >= 100)
			fprintf (pf2,"\n%d %s %d",lvr.code,lvr.nom,lvr.prix);
		else {
			lvr.prix = lvr.prix + (lvr.prix * 0.5);
			fprintf (pf2,"\n%d %s %d",lvr.code,lvr.nom,lvr.prix);
		}
	}
	fclose (pf);
	fclose (pf2);
	remove ("Livre.txt");
	rename("Livre2.txt","Livre.txt");
}

Triee_Livre (Livre lvr) {
	Livre arr[50], cmpt;
	int j;
	i = 0;
	FILE *pf = fopen ("Livre.txt","r");
	while (fscanf (pf,"%d %s %d",&lvr.code,lvr.nom,&lvr.prix) != EOF) {
			arr[i].code = lvr.code;
			strcpy(arr[i].nom,lvr.nom);
			arr[i].prix = lvr.prix;
			i++;
		}
	fclose (pf);
	int taille = i;		
	pf = fopen ("Livre.txt","w");
	for (i=0; i<taille; i++) {
		for (j=i+1; j<taille; j++) {
			if (strcmp(arr[i].nom,arr[j].nom) == 1) {
				cmpt.code = arr[i].code;
				arr[i].code = arr[j].code;
				arr[j].code = cmpt.code;
				
				strcpy(cmpt.nom,arr[i].nom);
				strcpy(arr[i].nom,arr[j].nom);
				strcpy(arr[j].nom,cmpt.nom);
				
				cmpt.prix = arr[i].prix;
				arr[i].prix = arr[j].prix;
				arr[j].prix = cmpt.prix;
			}
		}
		fprintf (pf,"\n%d %s %d",arr[i].code,arr[i].nom,arr[i].prix);
	}
	fclose (pf);		
}
int main(int argc, char *argv[]) {
	Livre lvr;
	int nbr, codeX;
	printf ("\t*** Ecriture ***\n\n");
	printf ("Saisez le nombre de les livres : ");
	scanf ("%d",&nbr);
	Enregistrer_Livre (lvr,nbr);
	printf ("\n\t*** Insertion ***\n");
	Insertion_Livre (lvr);
	system ("cls");
	printf ("\n\t*** Modification ***\n\n");
	printf ("Saisez le code que vous modifie : ");
	scanf ("%d",&codeX);
	Modifier_Livre (lvr,codeX);
	Update_Livre (lvr);
	printf ("\nUpdate done.\n");
	Triee_Livre (lvr);
	printf ("\nTriee done.");
	return 0;
}
