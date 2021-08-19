#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nbrOne, nbrTwo, otherNbr;
	printf ("Enter other number : ");
	scanf ("%d",&otherNbr);
	printf ("Enter first number : ");
	scanf ("%d",&nbrOne);
	printf ("Enter seconde number : ");
	scanf ("%d",&nbrTwo);
	int i, sum = 0, res = 0, val;
	for (i=1; i<=otherNbr; i++) {
		if (i >= nbrOne && i <= nbrTwo)
			res += i;
		else if (i > 9) {
			val = i;
			while (val != 0) {
				sum += (val % 10);
				val /= 10;
			}
			if (sum >= nbrOne && sum <= nbrTwo)
				res += i;
		}
		sum = 0;
	}
	printf ("Result is : %d",res);	
	return 0;
}
