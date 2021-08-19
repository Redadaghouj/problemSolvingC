#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int nbr;
	printf ("Enter a number : ");
	scanf ("%d",&nbr);
	int sum=0;
	sum = (nbr * (nbr+1)) / 2; 
	printf ("Result is : %d",sum);
	return 0;
}
