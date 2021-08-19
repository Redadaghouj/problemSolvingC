#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int mynum;
	printf ("Enter a number : ");
	scanf ("%d",&mynum);
	int i, j;
	for (i=1; j<=mynum; i++) {
		if (i % 4 != 0)
			printf ("%d ",i);
		else {
			printf ("PUM\n");
			j++;
		}
	}
	return 0;
}
