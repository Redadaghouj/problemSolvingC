#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int A, B;
	printf ("Entrez la valeur de A : ");
	scanf ("%d",&A);
	printf ("Entrez la valeur de B : ");
	scanf ("%d",&B);
	
	int helpA = A, helpB = B;
	
	while (helpA != helpB) {
		if (helpA < helpB)
			helpA += A;
		else
			helpB += B;			
	}
	printf ("le PPCM de %d et %d : %d",A,B,helpA);
		
		// A = 15 et B = 10 : 10+10 = 20 (helpA) et 15 + 15 = 30 (helpB) et 20 + 10 = 30 (helpA) :::: helpA = 30 et helpB = 30 donc le PPCM est 30
		
	return 0;
}
