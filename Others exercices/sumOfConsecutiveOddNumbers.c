#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int line;
	printf ("how much lines you want ? : ");
	scanf ("%d",&line);
	int i, j, val1, val2;
	for (i=0; i<line; i++) {
		int sum = 0;
		printf ("Line %d : \n",i+1);
		printf ("Number 1 : ");
		scanf ("%d",&val1);
		printf ("Number 2 : ");
		scanf ("%d",&val2);
		if (val1 > val2) {
			int cmpt = val1;
			val1 = val2;
			val2 = cmpt;
		}
		for (j=val1+1; j<val2; j++)
			if (j % 2 == 1)
				sum += j;		
		printf ("%d\n",sum);
	}
	return 0;
}
