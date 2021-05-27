#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int len, i;
typedef struct {
	int type;
	char nbr[30];
}Stock;

void calcul (Stock found) {
	int arr[len], result=0, j=-1;
	system("cls");
	for (i=len; i>=0; i--)
		arr[j++]=found.nbr[i]-'0';	
	if (found.type == 1) {
		for (i=0; i<len; i++)
			result+=arr[i]*pow(8,i);
		printf (" \nNombre decimal : %d \n",result);
	}
	else if (found.type == 2) {
		for (i=0; i<len; i++)
			result+=arr[i]*pow(2,i);
		printf (" \nNombre decimal : %d \n",result);
		}
	else {
		j=0;
		for (i=len-1; i>=0; i--)
			if (found.nbr[i] == 'a')
				result+=10*pow(16,j++);
			else if (found.nbr[i] == 'b')
				result+=11*pow(16,j++);
			else if (found.nbr[i] == 'c')
				result+=12*pow(16,j++);
			else if (found.nbr[i] == 'd')
				result+=13*pow(16,j++);
			else if (found.nbr[i] == 'e')
				result+=14*pow(16,j++);
			else if (found.nbr[i] == 'f')		
				result+=15*pow(16,j++);
			else
				result+=found.nbr[i]-'0'*pow(16,j++);
		printf (" \nNombre decimal : %d \n",result);
	}
}
int main(int argc, char *argv[]) {
	Stock found;
	bool trouve;
	char rep[5];
	do {
		debut :
		system("cls");
		printf ("\nChoisir le type de codage : \n\n");
		printf (" 1 : Octale. \n 2 : Binaire. \n 3 : Hexadicimal.\n\n Reponse: ");
		scanf ("%d",&found.type);
		system ("cls");
	} while (found.type < 1 || found.type > 3);
	tapez :
	trouve = true;
	printf ("Tapez le nombre : ");
	if (found.type == 1) {
		scanf ("%s",found.nbr);
		len=strlen(found.nbr);
		for (i=0; i<len; i++) {
			if (found.nbr[i] < '0' || found.nbr[i] > '7') {
				boucle :
				system("cls");
				printf ("Tu n'etais pas respecte format de type qui choisir.\n");
				trouve = false;
				break;
			}
		}
		if (trouve == false)
			goto tapez;
		else calcul(found);
		do {
			continu :
			printf ("\nVoulez-vous continuer (OUI/NON) ? \nReponse: ");
			scanf ("%s",rep); strlwr(rep);
		} while (strcmp(rep,"oui") != 0 && strcmp(rep,"non") != 0);
		if (strcmp(rep,"oui") == 0)
			goto debut;
	}
	else if (found.type == 2) {
		scanf ("%s",&found.nbr);
		len=strlen(found.nbr);
		for (i=0; i<len; i++) {
			if (found.nbr[i] != '1' && found.nbr[i] != '0')
				goto boucle;
		}
		calcul(found);
		goto continu;	
	}
	else {
		scanf ("%s",&found.nbr); strlwr(found.nbr);
		len=strlen(found.nbr);
		for (i=0; i<len; i++) {
			if (found.nbr[i] < '0' && found.nbr[i] < 'a' || found.nbr[i] > 'f')
				goto boucle;
		}
		calcul(found);	
		goto continu;
	}
		
return 0;
}
