#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int i;
typedef struct {
	char nom[30],
		prenom[30],
		tel[20];
}Contact;
void creer (char fichier[]) {
	char rep[10];
	FILE *pf = NULL;
	Contact contact;
	pf = fopen (fichier,"wb");
	if (pf == NULL) {
		printf ("Erreur! <%s> mode 'W'",fichier);
		exit(1);
	}
	else {
		i=1;
		do {
			printf ("\nContact %d :\n\n",i++);
			printf ("Nom : ");
			scanf ("%s",contact.nom);
			printf ("Prenom : ");
			scanf ("%s",contact.prenom);
			printf ("Tel : ");
			scanf ("%s",contact.tel);
			fwrite (&contact,sizeof(Contact),1,pf);
			printf ("\nVous voulez saisez autre contact ? (OUI / NON).\nReponse : ");
			scanf ("%s",rep); strlwr(rep);
			system ("cls");
		} while (strcmp(rep,"oui") == 0);
		fclose (pf);
	}
}
void affichage (char fichier[]) {
	FILE *pf = NULL;
	Contact contact;
	pf = fopen (fichier,"rb");
	if (pf == NULL) {
		printf ("Erreur! <%s> mode 'R'",fichier);
		exit (1);
	}
	else {
		i=1;
		while (fread (&contact,sizeof(Contact),1,pf) == 1) {
			printf ("\nContact %d :\n\n",i++);
			printf ("Nom : %s \n",contact.nom);
			printf ("Prenom : %s \n",contact.prenom);
			printf ("Tel : %s \n",contact.tel);
		}
		fclose (pf);
	}
}
void ajouter (char fichier[]) {
	FILE *pf = NULL;
	Contact contact;
	pf = fopen (fichier,"ab");
	if (pf == NULL) {
		printf ("Erreur! <%s> mode 'AB'",fichier);
		exit (1);
	}
	else {
		printf ("Nom : ");
		scanf ("%s",contact.nom);
		printf ("Prenom : ");
		scanf ("%s",contact.prenom);
		printf ("Tel : ");
		scanf ("%s",contact.tel);
		fwrite (&contact,sizeof(Contact),1,pf);
		system ("cls");
	}
	fclose (pf);
}
int rechercher (char fichier[], char nomX[]) {
	bool trouve = false;
	int pos = 0;
	Contact contact;
	FILE *pf = NULL;
	pf = fopen (fichier,"rb");
	if (pf == NULL) {
		printf ("Erreur! <%s> mode 'AB'",fichier);
		exit (1);
	}
	else {
		while (fread(&contact,sizeof(Contact),1,pf) == 1) {
			if (strcmp(nomX,contact.nom) == 0) {
				fclose (pf);
				trouve = true;
				return pos;
				break;
			}
			else
				pos++;
		}
		if (trouve == false)
			return -1;
	}
}
void modifie (char fichier[], char nomX[]) {
	FILE *pf = NULL;
	Contact contact;
	char rep[10];
	int pos = rechercher (fichier,nomX);
	if (pos != -1) {
		pf = fopen (fichier,"rb+");
		if (pf == NULL) {
			printf ("Erreur! <%s> mode 'RB' rech",fichier);
			exit (1);
		}
		else {
			fseek (pf,pos * sizeof(Contact),SEEK_SET);
			fread (&contact,sizeof(Contact),1,pf);
			printf ("\nVous voulez modifie le nom ? (OUI / NON).\nReponse : ");
			scanf ("%s",rep); strlwr(rep);
			if (strcmp(rep,"oui") == 0) {
				printf ("Nom : ");
				scanf ("%s",contact.nom);
			}
			printf ("\nVous voulez modifie le prenom ? (OUI / NON).\nReponse : ");
			scanf ("%s",rep); strlwr(rep);
			if (strcmp(rep,"oui") == 0) {
				printf ("Prenom : ");
				scanf ("%s",contact.prenom);
			}
			printf ("\nVous voulez modifie le numero de tel ? (OUI / NON).\nReponse : ");
			scanf ("%s",rep); strlwr(rep);
			if (strcmp(rep,"oui") == 0) {
				printf ("Tel : ");
				scanf ("%s",contact.tel);
			}
			fseek (pf,-sizeof(Contact),SEEK_CUR);
			fwrite (&contact,sizeof(Contact),1,pf);
			fclose (pf);
			system ("cls");	
		}
	}
	else 
		printf ("\nLe nom %s n'existe pas dans les contacts \n",nomX);
}
void supprimer (char fichier[], char nomX[]) {
	FILE *pf = NULL, *pf2 = NULL;
	Contact contact;
	system ("cls");
	int pos = rechercher (fichier,nomX);
	if (pos != -1) {
		pf = fopen (fichier,"rb+");
		if (pf == NULL) {
			printf ("Erreur! <%s> mode 'RB' supp",fichier);
			exit (1);
		}
		else {
			pf2 = fopen ("tempo.bin","wb");
			if (pf2 == NULL) {
				printf ("Erreur! <%s> mode 'RB' supp2",fichier);
				exit (1);
			}
			else {
				while (fread(&contact,sizeof(Contact),1,pf) == 1) {
					if (strcmp(nomX,contact.nom) != 0)
						fwrite(&contact,sizeof(Contact),1,pf2);
				}
				fclose (pf);
				fclose (pf2);
				remove (fichier);
				rename ("tempo.bin",fichier);
			}	
		}
	}
	else
		printf ("\nLe nom %s n'existe pas dans les contacts \n",nomX);
}
int main(int argc, char *argv[]) {
	char fichier[30], nomX[30], rep[10];
	printf ("Entrez le nom de fichier (.BIN) : ");
	scanf ("%s",fichier);
	printf ("\n*** Lecteur ***\n");
	creer (fichier);
	printf ("\n*** Affichage ***\n");
	affichage (fichier);
	printf ("\n*** Ajouter ***\n\n");
	ajouter (fichier);
	printf ("\n*** Nouveau Affichage ***\n");
	affichage (fichier);
	printf ("\n*** Rechercher ***\n");
	printf ("\nEntrez le nom que vous recherchez : ");
	scanf ("%s",nomX);
	int pos = rechercher (fichier,nomX);
	if (pos != -1)
		printf ("\nPosition de %s est : %d \n",nomX,++pos);
	else
		printf ("\nLe nom %s n'existe pas dans les contacts \n",nomX);	
	printf ("\n*** Modifer ***\n");
	printf ("\nVous voulez modifie un contact ? (OUI / NON).\nReponse : ");
	scanf ("%s",rep); strlwr(rep);
	if (strcmp(rep,"oui") == 0) {
		printf ("\nEntrez le nom de contact que vous modifie : ");
		scanf ("%s",nomX);
		system ("cls");
		modifie (fichier,nomX);
		printf ("\n*** Affichage ***\n");
		affichage (fichier);
	}
	printf ("\n*** Supprimer ***\n");
	printf ("\nEntrez le nom que vous recherchez : ");
	scanf ("%s",nomX);
	supprimer (fichier,nomX);
	printf ("\n*** Affichage ***\n");
	affichage (fichier);	
	return 0;
}
