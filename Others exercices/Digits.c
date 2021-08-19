#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nbr, i;
	printf ("how much numbers you want to add ? : ");
	scanf ("%d",&nbr);
	int arr[10];
	for (i=0; i<nbr; i++) {
		printf ("Enter number %d : ",i+1);
		scanf ("%d",&arr[i]);
	}
	int value;
	for (i=0; i<nbr; i++) {	
		printf ("\n");
		if (arr[i] == 0) {
			printf ("0 ");
			continue;
		}
		while (arr[i] != 0) {
			value = arr[i] % 10;
			printf ("%d ",value);
			arr[i] /= 10;
		}
	}
	
	return 0;
}
