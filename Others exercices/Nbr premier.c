#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int A, i, flag = 0;
	printf ("Entrez la valeur de A : ");
	scanf ("%d",&A);
	for (i=2; i<=A/2; i++) {
		if (A % i == 0 ) {
			flag = 1;
			break;
		}
	}	
	if (flag == 1)		
		printf ("le nombre %d n'est pas premier ",A);	
	else
		printf ("le nombre %d est premier ",A);
	return 0;
}
