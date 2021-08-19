#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
	char colors[100], stones[100];
	printf ("Enter the colors : "); // RRRBGBRBBB
	scanf ("%s",colors);
	printf ("Enter the stones : "); // BBBRR
	scanf ("%s",stones);
	int i, j=0;
	for (i=0; i<=strlen(stones); i++)
		if (colors[j] == stones[i]) 
			j++;
		
	printf ("POSITION is : %d",j+1); // 3
	return 0;
}
